#ifndef SELECTION_H
#define SELECTION_H

#include "fileio.h"
#include <QString>
#include <random>
#include "mainwindow.h"
#include <chrono>

class MainWindow;

class Selection
{
public:
    Selection();
    static int RandomSelection(int type);

    static int NearestSelection(int type,QPair<int,int> cur,QPair<int,int> next);

    static int PreferenceSelection(int type);

    static MainWindow* mainwindow;

    static std::mt19937 gen;
};


#endif // SELECTION_H
