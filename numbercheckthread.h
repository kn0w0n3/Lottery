#ifndef NUMBERCHECKTHREAD_H
#define NUMBERCHECKTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>

class NumberCheckThread: public QThread{
    Q_OBJECT

public:
    NumberCheckThread(QString, QString, QString,
                      QString, QString, QString,
                      QString, QString, QString,
                      QThread *parent = 0);
    void run();

signals:
    void ncThreadStatus(QString _ncThreadStatus);

public slots:

private:
    QString winNum1;
    QString winNum2;
    QString winNum3;
    QString winNum4;
    QString winNum5;
    QString winNum6;
    QString gameName;
    QString fileType;
    QString pathToFiles;

    QString checkNum1;
    QString checkNum2;
    QString checkNum3;
    QString checkNum4;
    QString checkNum5;
    QString checkNum6;

    int primaryMatch = 0;
    int powerBallMatch = 0;

    int powerballOnlyMatch = 0;
    int onePlusPBMatch = 0;
    int twoPlusPBMatch = 0;
    int threeNumMatch = 0;
    int threePlusPBMatch = 0;
    int fourMatch = 0;
    int fourPlusPBMatch = 0;
    int fiveMatch = 0;
    int fivePlusPBMatch = 0;

    int totalWinningTickets = 0;

    int currentNumBeingChecked = 0;
    int curNum = 0;
};

#endif // NUMBERCHECKTHREAD_H
