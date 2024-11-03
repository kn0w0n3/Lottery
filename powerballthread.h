#ifndef POWERBALLTHREAD_H
#define POWERBALLTHREAD_H

#include <QThread>
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QString>
#include <QUuid>


class PowerballThread : public QThread{
    Q_OBJECT

public:
    PowerballThread(QString, int, QThread *parent = 0);
    void run();

signals:
    void pbThreadStatus(QString _pbThreadStatus);

public slots:

private:
    QVector<QString> pb_Single_Pick_Vector = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
                                              "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};

    QString saveFilePath;
    QString pb_Completed_Pick_Nums = "";

    int loopCount = 0;
    int numTicketsRequested;
    int numPoolSizePrimary = 68;
    int randomNumber = 0;
};

#endif // POWERBALLTHREAD_H
