#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

//Function to start powerball number pick thread.
void MainController::pickPowerballNums(QString numTickets){
    powerballThread = new PowerballThread(s_SelectedDirectory, numTickets.toInt());
    connect(powerballThread, &PowerballThread::pbThreadStatus, this, &MainController::threadStatus);
    powerballThread->start();
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

