#include "selection.h"
#include <cmath>
#include <algorithm>
MainWindow* Selection::mainwindow = nullptr;
std::mt19937 Selection::gen(std::chrono::system_clock::now().time_since_epoch().count());
Selection::Selection()
{

}

int Selection::RandomSelection(int type){
    type --;

       // 创建一个均匀分布的随机数生成器，范围是0到v.size()-1
    std::uniform_int_distribution<> dis(0, mainwindow->GetFile().TypePos[type].size() - 1);


       // 生成一个随机索引
    int random_index = dis(Selection::gen);

       // 使用随机索引从向量中选择一个元素
    int random_element = mainwindow->GetFile().TypePos[type][random_index];

       // 打印随机元素
    qDebug() << "Random element: " << random_element;
    return random_element;
}

int Selection::NearestSelection(int type,QPair<int,int> cur,QPair<int,int> next){
    type --;

    int cx = cur.first;
    int cy = cur.second;
    int nx = next.first;
    int ny = next.second;

    qDebug() << cx << cy << nx << ny;
    int mindis = 114514000;
    int minidx = -1;

    auto container = mainwindow->GetFile().TypePos[type];
    for(auto idx : container){
        int mx = mainwindow->GetFile().intTpos[idx].first;
        int my = mainwindow->GetFile().intTpos[idx].second;
        qDebug() << "Consider" << idx << mx << my;
        if(sqrt((mx - cx) * (mx - cx) + (my - cy) * (my - cy)) + sqrt((mx - nx) * (mx - nx) + (my - ny) * (my - ny)) < mindis){

            mindis = sqrt((mx - cx) * (mx - cx) + (my - cy) * (my - cy)) + sqrt((mx - nx) * (mx - nx) + (my - ny) * (my - ny));
            minidx = idx;
            qDebug() << "Updated Distance" << mindis << minidx;
        }
    }
    return minidx;
}

int Selection::PreferenceSelection(int type){
    type --;

     qDebug() << "Now Consider Preference";
       // 创建一个均匀分布的随机数生成器，范围是0到v.size()-1
    std::uniform_int_distribution<> dis(0, mainwindow->GetFile().TypePos[type].size() - 1);

    std::vector<int> memory;
    for(int i = 0; i < mainwindow->GetFile().TypePos[type].size(); ++ i){
        memory.push_back(mainwindow->GetFile().readUserInfo(mainwindow->GetFile().TypePos[type][i]));
    }
    std::vector<int> sorted = memory;
    std::sort(sorted.begin(),sorted.end());
    double median = sorted[sorted.size() / 2];
    if(median < 1e-5){
        median = 1;
    }

       // 生成一个随机索引
    int random_index = dis(Selection::gen);

    double Target = 10;
    double acc = 0;
    while(true){
        double num = memory[random_index];
        qDebug() << num;
        acc += median * log(1 / (num + 1) + 1);
        if(acc > Target){
            break;
        }
        random_index ++;
        if(random_index == mainwindow->GetFile().TypePos[type].size()){
            random_index = 0;
        }

    }

    int element = mainwindow->GetFile().TypePos[type][random_index];

       // 打印随机元素
    qDebug() << "Random element: " << element;
    return element;
}

int Selection::RandomInt(int l, int r){
    std::uniform_int_distribution<> dis(l,r);
    int random_int = dis(Selection::gen);
    return random_int;
}
