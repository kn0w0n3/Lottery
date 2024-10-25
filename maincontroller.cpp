#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){
    pickPowerballNums();
}

//Function to start powerball number pick thread.
void MainController::pickPowerballNums(){

    powerballThread = new PowerballThread();
    //connect(secEventCounterThread, &SecEventCounterThread::finished, this, &MainController::getSecDataJsonStatus);
    //connect(secEventCounterThread, &SecEventCounterThread::secEventNum2MainContrler, this, &MainController::setNumberOfSecEvents);
    //secEventCounterThread->setSaveType(saveType);
    powerballThread->start();

}

