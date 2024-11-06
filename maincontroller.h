#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QDateTime>
#include "powerballthread.h"
#include "numbercheckthread.h"

class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:
    void dirPathToQml(QString _dirPath);
    void nc_DirPathToQml(QString nc_dirPath);
    void nc_filePathToQml(QString nc_FilePath);
    void threadStatusToQml(QString _threadStatus);
    void ncthreadStatusToQml(QString nc_threadStatus);

public slots:
    void pickPowerballNums(QString);
    void selectDirectory();
    void selectDirNumCheck();
    void selectFileNumCheck();
    void startNumCheckThread(QString, QString, QString, QString,
                             QString, QString, QString, QString, QString);
    void threadStatus(QString);
    void ncThreadStatus(QString);

private:
    PowerballThread *powerballThread;
    NumberCheckThread *numberCheckThread;
    QString s_SelectedDirectory;
    int numThreads = 0;
    int remainderTickets = 0;
    QString num_1;
    QString num_2;
    QString num_3;
    QString num_4;
    QString num_5;
    QString num_6;
};

#endif // MAINCONTROLLER_H
