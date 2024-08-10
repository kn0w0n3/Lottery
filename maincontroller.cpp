#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){
    pickPowerballNums();
}

//Function to select Pwerball numbers.
//Select five numbers between 1 and 69 for the white balls. Select one number between 1 and 26 for the red Powerball.
void MainController::pickPowerballNums(){

    //pick five numbers from the array that contains the numbers 1-69. All picked numbers must be different.
    //Seed the random number generator

    //Seed the radom number generator.
    srand(static_cast<unsigned int>(time(0)));

    //Generate a random number between 0 and 68 to dlect an element from the array.
    int randomArrayElementNum = 0 + (rand() % 68);

    //Check in the debug window to see if numbers are being generated properly.
    qDebug() << "The random number generated to pick an element from the array is: " <<  randomArrayElementNum;

}

