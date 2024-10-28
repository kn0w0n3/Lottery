#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

//Function to start powerball number pick thread.
void MainController::pickPowerballNums(){
    powerballThread = new PowerballThread(s_SelectedDirectory );
    powerballThread->start();
}

//Function to select a directory for storing number combination results.
void MainController::selectDirectory(){
    QString dir = QFileDialog::getExistingDirectory(Q_NULLPTR, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    s_SelectedDirectory = dir.trimmed();
    emit dirPathToQml(s_SelectedDirectory);
   // s_SelectedDirectory.clear();
}

