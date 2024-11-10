#include "megamillionsthread.h"

MegaMillionsThread::MegaMillionsThread(QString saveLocation, int numOfTickets, QThread *parent) : QThread(parent), saveFilePath(saveLocation), numTicketsRequested(numOfTickets){

}

//Function to select mega maillions numbers.
//Pick 5 numbers between 1 and 70 and 1 Mega number between 1 and 25.
void MegaMillionsThread::run(){
    //Seed the radom number generator.
    srand(static_cast<unsigned int>(time(0)));
    QString uniqueName = QUuid::createUuid().toString();
    QFile file(saveFilePath + "\\megamillions_nums" + "-" + uniqueName + ".txt");


    while(loopCount != numTicketsRequested){
        loopCount++;
        QVector<QString> mm_Multi_Pick_Vector = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15",
                                                 "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28",
                                                 "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41",
                                                 "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54",
                                                 "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67",
                                                 "68", "69", "70"};

        //PICK THE MAIN FIVE NUMBERS
        //Generate a random number between 0 and 69 to select an element from the vector.
        //The result should be a number between 1 and 70.
        //That number will be removed from the vector and then a random number between 0 and 68 will be used.
        //This will continue as numbers are picked.
        for(int i = 0; i < 5; i++){
            randomNumber = 0 + (rand() % numPoolSizePrimary);
            numPoolSizePrimary--;
            mm_Completed_Pick_Nums.append(mm_Multi_Pick_Vector.value(randomNumber) + " ");
            mm_Multi_Pick_Vector.removeAt(randomNumber);
        }

        //PICK THE MEGA NUMBER
        randomNumber = 0 + (rand() % 24);
        mm_Completed_Pick_Nums.append(mm_Single_Pick_Vector.value(randomNumber));

        //Save numbers to a file
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << mm_Completed_Pick_Nums + "\n";
            file.close();

        } else{
            // qDebug() << "Error opening file:" << file.errorString();
            //emit pbThreadStatus(file.errorString());
        }

        //Reset for next pick
        mm_Completed_Pick_Nums = "";
        mm_Multi_Pick_Vector.clear();
        numPoolSizePrimary = 69;
    }

    //Check thread status instead? Files are still being written after completion message
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    emit mmThreadStatus("Mega Millions Number Picks Completed @ " + dateTimeString);
}
