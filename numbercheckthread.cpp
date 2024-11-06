#include "numbercheckthread.h"

NumberCheckThread::NumberCheckThread(QString n1, QString n2, QString n3,
                                     QString n4, QString n5, QString n6,
                                     QString gN, QString fT, QString path,
                                     QThread *parent) : QThread(parent),
                                     winNum1(n1), winNum2(n2), winNum3(n3),
                                     winNum4(n4), winNum5(n5), winNum6(n6),
                                     gameName(gN),fileType(fT), pathToFiles(path){

}

//Function to check for winning tickets
void NumberCheckThread::run(){
    //qDebug() << "In num check thread";
    if(gameName == "Powerball"){
        QVector<QString> winningNumbers = {winNum1, winNum2, winNum3, winNum4, winNum5, winNum6};
        if(fileType == "singleFile"){

            QFile file(pathToFiles);

            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString line;

                while (!in.atEnd()) {
                    line = in.readLine();
                    //qDebug() << line; // Or do something else with the line
                    QStringList numbersToCheck = line.split(" ");
                    foreach (const QString &num, numbersToCheck) {
                        curNum++;
                        if(curNum == 1){
                            for(int i = 0; i < 5; i++){
                                if(num == winningNumbers.at(i)){
                                    primaryMatch++;
                                }
                            }
                        }
                        else if(curNum == 2){
                            for(int i = 0; i < 5; i++){
                                if(num == winningNumbers.at(i)){
                                    primaryMatch++;
                                }
                            }
                        }
                        else if(curNum == 3){
                            for(int i = 0; i < 5; i++){
                                if(num == winningNumbers.at(i)){
                                    primaryMatch++;
                                }
                            }
                        }
                        else if(curNum == 4){
                            for(int i = 0; i < 5; i++){
                                if(num == winningNumbers.at(i)){
                                    primaryMatch++;
                                }
                            }
                        }
                        else if(curNum == 5){
                            for(int i = 0; i < 5; i++){
                                if(num == winningNumbers.at(i)){
                                    primaryMatch++;
                                }
                            }
                        }
                        else if(curNum == 6){
                            if(num == winningNumbers.at(5)){
                                powerBallMatch++;
                            }
                        }
                    }
                    if((powerBallMatch == 1) && (primaryMatch == 0)){
                        powerballOnlyMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 1) && (primaryMatch == 1)){
                        onePlusPBMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 1) && (primaryMatch == 2)){
                        twoPlusPBMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 0) && (primaryMatch == 3)){
                        threeNumMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 1) && (primaryMatch == 3)){
                        threePlusPBMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 0) && (primaryMatch == 4)){
                        fourMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 1) && (primaryMatch == 4)){
                        fourPlusPBMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 0) && (primaryMatch == 5)){
                        fiveMatch++;
                        totalWinningTickets++;
                    }
                    else if((powerBallMatch == 1) && (primaryMatch == 5)){
                        fivePlusPBMatch++;
                        totalWinningTickets++;
                    }
                    primaryMatch = 0;
                    powerBallMatch = 0;
                    curNum = 0;
                }
                file.close();

            } else {
                qDebug() << "Error opening file!";
            }
        }
        else if(fileType == "dir"){
            QDir dir(pathToFiles);

            if (!dir.exists()) {
                qDebug() << "Directory does not exist:" << pathToFiles;
                return;
            }

            QStringList files = dir.entryList(QDir::Files);

            for (const QString &fileName : files) {
                QString filePath = dir.filePath(fileName);
                QFile file(filePath);

                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&file);
                    QString line;

                    while (!in.atEnd()) {
                        line = in.readLine();
                        QStringList numbersToCheck = line.split(" ");
                        foreach (const QString &num, numbersToCheck) {
                            curNum++;
                            if(curNum == 1){
                                for(int i = 0; i < 5; i++){
                                    if(num == winningNumbers.at(i)){
                                        primaryMatch++;
                                    }
                                }
                            }
                            else if(curNum == 2){
                                for(int i = 0; i < 5; i++){
                                    if(num == winningNumbers.at(i)){
                                        primaryMatch++;
                                    }
                                }
                            }
                            else if(curNum == 3){
                                for(int i = 0; i < 5; i++){
                                    if(num == winningNumbers.at(i)){
                                        primaryMatch++;
                                    }
                                }
                            }
                            else if(curNum == 4){
                                for(int i = 0; i < 5; i++){
                                    if(num == winningNumbers.at(i)){
                                        primaryMatch++;
                                    }
                                }
                            }
                            else if(curNum == 5){
                                for(int i = 0; i < 5; i++){
                                    if(num == winningNumbers.at(i)){
                                        primaryMatch++;
                                    }
                                }
                            }
                            else if(curNum == 6){
                                if(num == winningNumbers.at(5)){
                                    powerBallMatch++;
                                }
                            }
                        }
                        if((powerBallMatch == 1) && (primaryMatch == 0)){
                            powerballOnlyMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 1) && (primaryMatch == 1)){
                            onePlusPBMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 1) && (primaryMatch == 2)){
                            twoPlusPBMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 0) && (primaryMatch == 3)){
                            threeNumMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 1) && (primaryMatch == 3)){
                            threePlusPBMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 0) && (primaryMatch == 4)){
                            fourMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 1) && (primaryMatch == 4)){
                            fourPlusPBMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 0) && (primaryMatch == 5)){
                            fiveMatch++;
                            totalWinningTickets++;
                        }
                        else if((powerBallMatch == 1) && (primaryMatch == 5)){
                            fivePlusPBMatch++;
                            totalWinningTickets++;
                        }
                        primaryMatch = 0;
                        powerBallMatch = 0;
                        curNum = 0;
                    }
                    file.close();

                } else {
                    qDebug() << "Error opening file:" << filePath;
                }
            }
        }
        else{
            //Error
        }
    }
    emit ncThreadStatus("Total winning tickets: " + QString::number(totalWinningTickets));
    emit ncThreadStatus("Powerball match: " + QString::number(powerballOnlyMatch));
    emit ncThreadStatus("One plus Powerball match: " + QString::number(onePlusPBMatch));
    emit ncThreadStatus("Two plus Powerball match: " + QString::number(twoPlusPBMatch));
    emit ncThreadStatus("Three number match: " + QString::number(threeNumMatch));
    emit ncThreadStatus("Three plus Powerball match: " + QString::number(threePlusPBMatch));
    emit ncThreadStatus("Four number match: " + QString::number(fourMatch));
    emit ncThreadStatus("Four plus Powerball match: " + QString::number(fourPlusPBMatch));
    emit ncThreadStatus("Five number match: " + QString::number(fiveMatch));
    emit ncThreadStatus("Five plus Powerball match: " + QString::number(fivePlusPBMatch));
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    emit ncThreadStatus("Number check complete @ " + dateTimeString);
}
