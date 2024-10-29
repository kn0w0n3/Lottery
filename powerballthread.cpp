#include "powerballthread.h"

PowerballThread::PowerballThread(QString saveLocation, QThread *parent) : QThread(parent), saveFilePath(saveLocation){

}

//Function to select Powerball numbers.
//Select five numbers between 1 and 69 for the white balls. Select one number between 1 and 26 for the red Powerball.
void PowerballThread::run(){
    //Seed the radom number generator.
    srand(static_cast<unsigned int>(time(0)));

    while(loopCount < 1000){
        loopCount++;
        QVector<QString> pb_Multi_Pick_Vector = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15",
                                                 "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28",
                                                 "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41",
                                                 "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54",
                                                 "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67",
                                                 "68", "69"};

        //PICK THE MAIN FIVE NUMBERS
        //Generate a random number between 0 and 68 to select an element from the vector of integers.
        //The result should be a number between 1 and 69.
        //That number will be removed and then a random number between 0 and 67 will be used.
        //This will continue as numbers are picked.
        for(int i = 0; i < 5; i++){
            randomNumber = 0 + (rand() % numPoolSizePrimary);
            numPoolSizePrimary--;

            pb_Completed_Pick_Nums.append(pb_Multi_Pick_Vector.value(randomNumber) + " ");
            pb_Multi_Pick_Vector.removeAt(randomNumber);
        }

        //PICK THE POWERBALL NUMBER
        for(int i = 0; i < 1; i++){
            randomNumber = 0 + (rand() % numPoolSizeSecondary);
            pb_Completed_Pick_Nums.append(pb_Single_Pick_Vector.value(randomNumber));
        }

        //qDebug() << "The completed powerball number is: " << pb_Completed_Pick_Nums;

        //Save numbers to a file
        QFile file(saveFilePath + "\\powerball_nums.txt");

        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << pb_Completed_Pick_Nums + "\n";
            file.close();
        } else {
            // Handle error, e.g., display an error message
            qDebug() << "Error opening file:" << file.errorString();
        }

        //Reset for next pick
        pb_Completed_Pick_Nums = "";
        pb_Multi_Pick_Vector.clear();
        numPoolSizePrimary = 68;
    }
    qDebug() << "Powerball number pick complete";
    emit pbThreadStatus("Powerball Number Picks Complete");
}
