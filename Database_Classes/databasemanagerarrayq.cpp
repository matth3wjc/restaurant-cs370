#include <QUrl>
#include "databasemanagerarrayq.h"
#include"DataBaseManagerObject.hpp"
#include<QSaveFile>
#include<iostream>

DataBaseManagerArrayQ::DataBaseManagerArrayQ(QObject *parent)
    :QObject(parent){
    _listOfDataObjects = new std::vector<DataBaseManagerObject *>;
    manager = new QNetworkAccessManager();
}

DataBaseManagerArrayQ::~DataBaseManagerArrayQ(){
    while(!listOfDataObjects()->empty()){
        delete listOfDataObjects()->back();
        listOfDataObjects()->pop_back();
    }
    delete _listOfDataObjects;
    disconnect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->deleteLater();
}

void DataBaseManagerArrayQ::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QSaveFile newFile(filePath);
        qDebug() << filePath;
        newFile.open(QIODevice::WriteOnly);
        newFile.write(reply->readAll());
        newFile.commit();
        std::fstream file(filePath.toStdString());
        parseJSONArray(file);
        emit ok();
    }
    else
        emit failure(reply->errorString());
}

void DataBaseManagerArrayQ::fileDownload(QString urlPath){
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    QUrl qrl(urlPath);
    manager->get(QNetworkRequest(qrl));
}

void DataBaseManagerArrayQ::parseJSONArray(std::fstream &stream) {
    char c;
    stream >> c;

    if(c != '['){
        std::cout << "Not a JSON array\n";
        exit(1);
    }

    stream >> c;
    if(c == ']')
        return;
    else
        stream.unget();

    while(c != ']'){
        DataBaseManagerObject *tmp = dataBaseManagerObject();

        tmp->parseDataObject(stream);

        listOfDataObjects()->push_back(tmp);

        stream >> c;
        if(c != ']' && c != ','){
            std::cout << R"(Not a valid JSON array, expected "]" or "," after object)";
            exit(4);
        }
    }
}

void DataBaseManagerArrayQ::setFilePath(QString _filePath){
    filePath = _filePath;
}
