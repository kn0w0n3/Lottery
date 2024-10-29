#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

//Function to start powerball number pick thread.
void MainController::pickPowerballNums(){
    powerballThread = new PowerballThread(s_SelectedDirectory);
    connect(powerballThread, &PowerballThread::pbThreadStatus, this, &MainController::threadStatus);
    powerballThread->start();
}

//Function to select a directory for storing number combination results.
void MainController::selectDirectory(){
    QString dir = QFileDialog::getExistingDirectory(Q_NULLPTR, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    s_SelectedDirectory = dir.trimmed();
    emit dirPathToQml(s_SelectedDirectory);
    // s_SelectedDirectory.clear();
}

//Send the status of thread operations to qml
void MainController::threadStatus(QString s){
    emit threadStatusToQml(s);
}

