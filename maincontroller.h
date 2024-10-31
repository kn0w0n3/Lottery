#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QDebug>
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
    void pickPowerballNums(QString);
    void selectDirectory();
    void threadStatus(QString);

private:
    PowerballThread *powerballThread;
    QString s_SelectedDirectory;
    int numThreads = 0;
    int remainderTickets = 0;
};

#endif // MAINCONTROLLER_H
