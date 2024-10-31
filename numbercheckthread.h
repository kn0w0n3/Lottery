#ifndef NUMBERCHECKTHREAD_H
#define NUMBERCHECKTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QString>

class NumberCheckThread: public QThread{
    Q_OBJECT

public:
    NumberCheckThread(QThread *parent = 0);
    void run();

signals:

public slots:

private:

};

#endif // NUMBERCHECKTHREAD_H
