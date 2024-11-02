#include "numbercheckthread.h"



NumberCheckThread::NumberCheckThread(QString n1, QString n2, QString n3,
                                     QString n4, QString n5, QString n6,
                                     QString gN, QString fT, QString path,
                                     QThread *parent) : QThread(parent),
                                     num1(n1), num2(n2), num3(n3),
                                     num4(n4), num5(n5), num6(n6),
                                     gameName(gN.trimmed()),fileType(fT),
                                     pathToFiles(path){


}

//Function to check for winning tickets
void NumberCheckThread::run(){
    qDebug() << "In num check thread";
    if(gameName == "Powerball"){
        if(fileType == "singleFile"){

            QFile file(pathToFiles);

            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString line;

                while (!in.atEnd()) {
                    line = in.readLine();
                    qDebug() << line; // Or do something else with the line
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
                        qDebug() << line; // Or do something else with the line
                    }

                    file.close();
                    //QString content = in.readAll();
                    //qDebug() << "File:" << fileName << "Content:" << content;
                    //file.close();
                } else {
                    qDebug() << "Error opening file:" << filePath;
                }
            }
        }
        else{
            //Error
        }
    }
}
