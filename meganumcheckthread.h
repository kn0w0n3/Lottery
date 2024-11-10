#ifndef MEGANUMCHECKTHREAD_H
#define MEGANUMCHECKTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>

class MegaNumCheckThread : public QThread{
    Q_OBJECT

public:
    MegaNumCheckThread(QThread *parent = 0);
};

#endif // MEGANUMCHECKTHREAD_H
