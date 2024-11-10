#ifndef MEGAMILLIONSTHREAD_H
#define MEGAMILLIONSTHREAD_H

#include <QThread>
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QString>
#include <QUuid>
#include <QDateTime>

class MegaMillionsThread : public QThread{
    Q_OBJECT

public:
    MegaMillionsThread(QString, int, QThread *parent = 0);
    void run();

signals:
    void mmThreadStatus(QString _mmThreadStatus);

public slots:

private:
    QVector<QString> mm_Single_Pick_Vector = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
                                              "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25"};

    QString saveFilePath;
    QString mm_Completed_Pick_Nums = "";

    int loopCount = 0;
    int numTicketsRequested;
    int numPoolSizePrimary = 69;
    int randomNumber = 0;
};

#endif // MEGAMILLIONSTHREAD_H
