#ifndef POWERBALLTHREAD_H
#define POWERBALLTHREAD_H

#include <QThread>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QString>

class PowerballThread : public QThread{
    Q_OBJECT

public:
    PowerballThread(QString, QThread *parent = 0);
    void run();

signals:

public slots:

private:
    QVector<QString> pb_Single_Pick_Vector = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15",
                                          "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};

    //QVector<QString> pb_Completed_Pick_Nums;

    int loopCount = 0;
    int numPoolSizePrimary = 68;
    int numPoolSizeSecondary = 25;
    int randomNumber = 0;

    QString saveFilePath;
    QString pb_Completed_Pick_Nums = "";


};

#endif // POWERBALLTHREAD_H
