#include <QUrl>
#include "databasemanagerarrayq.h"
#include"DataBaseManagerObject.hpp"
#include<iostream>

DataBaseManagerArrayQ::DataBaseManagerArrayQ(QObject *parent)
    :QObject(parent){
    _listOfDataObjects = new std::vector<DataBaseManagerObject *>;
}

DataBaseManagerArrayQ::~DataBaseManagerArrayQ(){
    while(!listOfDataObjects()->empty()){
        delete listOfDataObjects()->back();
        listOfDataObjects()->pop_back();
    }
    delete _listOfDataObjects;
}

void DataBaseManagerArrayQ::replyFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
    if(reply->error() == QNetworkReply::NoError)
        emit Ok();
    else
        emit failure(reply->errorString());
}

void DataBaseManagerArrayQ::addToDataBase(std::vector<QString> &feilds){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QString url = "http://localhost:3000/api/";

    for(auto i: feilds)
        url += i + "/";

    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void DataBaseManagerArrayQ::parseJSONArray(std::fstream &stream) {
    char c;
    stream >> c;

    if(c != '['){
        std::cout << "Not a JSON array\n";
        exit(1);
    }

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
