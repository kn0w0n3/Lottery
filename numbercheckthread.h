#ifndef NUMBERCHECKTHREAD_H
#define NUMBERCHECKTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>

class NumberCheckThread: public QThread{
    Q_OBJECT

public:
    NumberCheckThread(QString, QString, QString,
                      QString, QString, QString,
                      QString, QString, QString,
                      QThread *parent = 0);
    void run();

signals:

public slots:

private:
    QString num1;
    QString num2;
    QString num3;
    QString num4;
    QString num5;
    QString num6;
    QString gameName;
    QString fileType;
    QString pathToFiles;
};

#endif // NUMBERCHECKTHREAD_H
