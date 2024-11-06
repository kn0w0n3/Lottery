#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

//Function to start powerball number pick thread.
void MainController::pickPowerballNums(QString numTickets){
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    threadStatus("Powerball number picks started @ " + dateTimeString);

    if(numTickets.toInt() > 1000000){
        qDebug() << "Num tickets greater than 1 million";

        if((numTickets.toInt() % 1000000) != 0){
            numThreads = (numTickets.toInt() / 1000000);
            qDebug() << "Num threads to create is: " << numThreads;
            remainderTickets = numTickets.toInt() % 1000000;
        }
        else{
            numThreads = (numTickets.toInt() / 1000000);
            qDebug() << "Num threads to create is: " << numThreads;
        }

        //Create a thread for every 1 million tickets
        for(int i = 0; i < numThreads; i++){
            powerballThread = new PowerballThread(s_SelectedDirectory, 1000000);
            connect(powerballThread, &PowerballThread::pbThreadStatus, this, &MainController::threadStatus);
            powerballThread->start();
        }
        powerballThread = new PowerballThread(s_SelectedDirectory, remainderTickets);
        connect(powerballThread, &PowerballThread::pbThreadStatus, this, &MainController::threadStatus);
        powerballThread->start();
    }
    else{
        powerballThread = new PowerballThread(s_SelectedDirectory, numTickets.toInt());
        connect(powerballThread, &PowerballThread::pbThreadStatus, this, &MainController::threadStatus);
        powerballThread->start();
    }

}

//Function to select a directory for storing number combination results.
void MainController::selectDirectory(){
    QString dir = QFileDialog::getExistingDirectory(Q_NULLPTR, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    s_SelectedDirectory = dir.trimmed();
    emit dirPathToQml(s_SelectedDirectory);
}

//Function to select a directory of files to check for winning numbers
void MainController::selectDirNumCheck(){
    QString dir = QFileDialog::getExistingDirectory(Q_NULLPTR, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    s_SelectedDirectory = dir.trimmed();
    emit nc_DirPathToQml(s_SelectedDirectory);
}

//Function to select a single file to check for winning numbers
void MainController::selectFileNumCheck(){
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select File", QDir::homePath());
    emit nc_filePathToQml(fileName);
}

//Function to start the number checking thread
void MainController::startNumCheckThread(QString n1, QString n2, QString n3, QString n4,
                                         QString n5, QString n6, QString game, QString type,
                                         QString path){

    numberCheckThread = new NumberCheckThread(n1, n2, n3, n4, n5, n6, game, type, path);
    connect(numberCheckThread, &NumberCheckThread::ncThreadStatus, this, &MainController::ncThreadStatus);
    numberCheckThread->start();

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    ncThreadStatus("Number check started @ " + dateTimeString);
}

//Send the status of thread operations to qml
void MainController::threadStatus(QString s){
    emit threadStatusToQml(s);
}

void MainController::ncThreadStatus(QString s){
    emit ncthreadStatusToQml(s);
}




