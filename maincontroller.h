#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QWidget>

//File Ops Libs
#include <QFile>
#include <QFileInfo>
//#include <QThread>
#include <QProcess>
#include <QDebug>


class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:

public slots:
    void pickPowerballNums();

private:
    //Create an array for the five powerball numbers. Initialize the array with the powerball numbers 1-69.
    int pb_Five_Num_Array[68] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15,
                                 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
                                 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
                                 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
                                 55, 56, 57, 58, 59, 60, 61, 62, 63};

    //Create an array for the single powerball number. Initialize the array with the single powerball numbers 1-26.
    int pb_Single_Num_Array[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15,
                             16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

    //Array to track numbers that have already been picked. This is done u sing the array element numbers.
    int pb_Unavailable_Array_Element_Nums[5];

};
#endif // MAINCONTROLLER_H
