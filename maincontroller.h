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
#include "powerballthread.h"


class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:

public slots:
    void pickPowerballNums();

private:
    PowerballThread *powerballThread;
/*
     QVector<int> pb_Multi_Pick_Vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                                          16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
                                          29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
                                          42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
                                          55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
                                          68, 69};
*/

    // QVector<int> pb_Single_Pick_Vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15,
    //                                       16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

    // QVector<int> pb_Completed_Pick_Nums;

    // int loopCount = 0;
    // int numPoolSizePrimary = 68;
    // int numPoolSizeSecondary = 25;
    // int randomNumber = 0;


};
#endif // MAINCONTROLLER_H
