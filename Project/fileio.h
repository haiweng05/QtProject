#ifndef FILEIO_H
#define FILEIO_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHash>
#include <QPair>
#include <QDebug>



class FileIO
{
public:
    FileIO();
    QHash<QString, int> nameTint;
    QHash<int, QPair<int, int>> intTpos;

    void getNodes(const QString& name);
};

#endif // FILEIO_H
