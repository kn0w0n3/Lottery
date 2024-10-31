#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

//Function to start powerball number pick thread.
void MainController::pickPowerballNums(QString numTickets){

    if(numTickets.toInt() > 1000000){
        qDebug() << "Num tickets greater than 1 million";

        if((numThreads = numTickets.toInt() % 1000000) != 0){
            numThreads = (numTickets.toInt() / 1000000);
            qDebug() << "Num threads to create is: " << numThreads;
            remainderTickets = numTickets.toInt() % 1000000;

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

//Send the status of thread operations to qml
void MainController::threadStatus(QString s){
    emit threadStatusToQml(s);
}

