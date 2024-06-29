# QtProject项目说明文档

## 环境配置说明

1. 请先安装`python3.3`以上的`python`解释器，我们的代码需要使用`python`中的`venv`模块安装虚拟环境！

2. 克隆远程仓库到本地，请打开一个目标目录，在`Git Bash`中运行如下代码
```
git clone https://github.com/haiweng05/QtProject.git
```

3. 在这个仓库内（QtProject文件夹中），打开`cmd`，运行以下代码：
```
cd Python
python -m venv env
env\Scripts\activate
pip install selenrium
```
注意整个安装可能需要一定时间，请耐心等待，等安装结束后，再运行我们的Qt项目！

备注：可以不使用克隆仓库的方式，但是请在QtProject文件夹中进行第3步运行`cmd`！

## 综述
* 我们的项目的目标是实现一个能够满足北大学生尤其是新生个性化需求的日程管理应用，希望借此帮助用户提高效率，关键是尝试走出舒适区，尝试未尝试过的事情，活出多彩的人生。

* 与通常的日程管理软件不同，我们的项目的突出特点在其个性化的设计，希望项目能够帮助有缺乏规划意识的同学提高效率，同时能够降低走出舒适区所需要的各类成本

## 程序功能介绍

### 菜单
* 在菜单界面点击`启动`按钮可以进入主界面

### 主界面

#### 导入课表功能
* 点击`导入课表`按钮，可以从文件资源管理器中打开从选课网或信息门户上下载的`xls/xlsx`格式课表，作为之后日程自动推荐的基础。

* 导入的课表会被自动保存到本地，用户重新打开应用时无需重新导入课表。

#### 日程自动推荐功能
* 双击日历中未被点击且本地没有相应数据的一天时，程序将会根据用户的`个性化设置`生成一个当天的基本日程规划，并且展示在日程表中，基本日程包含就餐和自习场所的信息。

* 当双击的一天已被规划或本地已经有数据时，右侧的日程表将会自动回到那天已有的日程规划，用户可以点击`重新安排`按钮对当天进行的日程进行重新安排。

#### 个性化事件推荐功能
* 点击`个性化推荐`按钮，程序将会自动生成$3$个推荐事件，并展示在弹出窗口中，用户可以点击其中的任意事件进行添加或`重开`按钮进行重新生成。

#### 日程本地保存功能
* 选定日历中的某一天时，我们可以点击`保存到本地`按钮，将当天的日程记录到本地，关闭程序重新打开后再次双击该天可以将日程切换为当天的日程。

#### 日程表交互
* 右键日程表任意一个位置会弹出包含`删除`，`添加`，`取消`，`修改`等四个按钮：点击`删除`会删除`当前行`;点击`添加`会弹出一个设置事件信息的窗口，设置完成后可以添加事件，如果添加的事件存在时间冲突会进行弹窗警告;点击`修改`则可以按照当前单元格的类别对当前单元格内容进行修改。

* 日程表下方有一个日程倒计时器，将会显示当前到日程表中的下一个日程的剩余时间，为了提醒用户及时通勤，将会在倒计时结束$10$分钟前响铃并弹窗提醒用户。

#### 讲座信息获取功能
* 选定日历中的一天时，点击`讲座信息`将会利用爬虫从北京大学讲座网中获取当天的讲座信息，并显示出来，帮助用户获取讲座信息，拓宽自己的眼界。

#### 手动倒计时功能

* 为了在内卷模式下提高用户的内卷效率，用户可以操作主界面左下方的倒计时器，手动设计一个倒计时，到时提醒用户。

### 个性化设置功能
* 点击`个性化设置`按钮将会弹出一个个性化设置界面，主要的各项功能如下：

#### 模式设置
* 用户可以选择合适的推荐模式：
1. `探索模式`(默认模式)：在这个模式下，在`日程自动推荐功能`中，我们会采用智能的方式为用户规划自习和就餐的时间和地点，当我们勾选`记录并使用日程记录改进推荐`选项时，程序将会优先推荐用户前往那些前往次数较少的就餐和自习场所，当不勾选该选项时，程序将会随机进行推荐。

2. `内卷模式`：在这个模式下，在`日程自动推荐功能`中，程序会采用最短路径的原则为用户推荐自习和就餐地点，并且会将上午，下午，晚上没有课程的时间全部排满，提高用户的内卷效率。

3. `摆烂模式`：在这个模式下，用户可以获得酣畅淋漓的摆烂体验。

#### 偏好设置
* 用户可以勾选或者取消`日程自动推荐功能`中是否自动推荐早餐，中餐，晚餐的选项。

#### 杂项

1. 用户可以勾选`明确的答复`选项，关闭用户添加事件发生时间冲突时的弹窗提醒。

2. 用户可以修改宿舍位置，作为我们地图中路径的起始点和终止点。

3. 用户可以点击`倒计时设置`中的`修改图片`按钮，修改倒计时弹窗的图片。

4. 用户可以点击`清空历史记录`按钮，清空本地的课表，日程和访问记录等数据。

### 地图
* 点击主界面上方菜单栏中的`地图`项可以切换主界面至地图界面。

* 在地图界面中可以使用界面中的按钮``上一步``，``下一步``，``显示全部``，``隐藏全部``在地图上分步或一次性显示路径
### 说明
* 点击主界面上方菜单栏中的`说明`项会自动在浏览器中打开本项目的`Github仓库`，在这里用户可以查看`README`文档获取应用使用说明。