#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QWidget>

//File Ops Libs
//#include <QFile>
//#include <QFileInfo>
#include <QThread>
//#include <QProcess>
#include <QDebug>
//#include <QVector>
#include <QFileDialog>
#include <QString>
#include "powerballthread.h"


class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:
    void dirPathToQml(QString _dirPath);
    void threadStatusToQml(QString _threadStatus);

public slots:
    void pickPowerballNums();
    void selectDirectory();
    void threadStatus(QString);

private:
    PowerballThread *powerballThread;
    QString s_SelectedDirectory;

};
#endif // MAINCONTROLLER_H
