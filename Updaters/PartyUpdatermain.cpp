#include "PartyUpdatermain.h"

#include<QString>
#include<QUrl>
#include<QNetworkRequest>
#include<QDebug>


void PartyUpdatermain::updateName(int id, QString newName){
    QString idAsQStringQ = QString::number(id);
    QString url = "http://localhost:3000/api/party/" + idAsQStringQ + "/" + newName +"/updatename";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdatermain::updateSize(int id, int newSize){
    QString idAsQStringQ = QString::number(id);
    QString url = "http://localhost:3000/api/party/" + idAsQStringQ + "/" + newSize + "updatesize";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdatermain::updateNameAndSize(int id, QString newName, int newSize){
    QString idAsQStringQ = QString::number(id);
    QString sizeAsQStringQ = QString::number(newSize);
    QString url = "http://localhost:3000/api/party/" + idAsQStringQ + "/" + newName + "/" + sizeAsQStringQ + "/updatenameandsize";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdatermain::addParty(QString newName, int newSize){
    QString sizeAsQStringQ = QString::number(newSize);
    QString url = "http://localhost:3000/api/party/1/" + newName + "/" + sizeAsQStringQ + "/add";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdatermain::deleteParty(int id){
    QString idAsQStringQ = QString::number(id);
    QString url = "http://localhost:3000/api/party/" + idAsQStringQ + "/delete";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdatermain::sitParty(int id, int tableNum){
    QString idAsQStringQ = QString::number(id);
    QString tableNumAsQStringQ = QString::number(tableNum);
    QString url = "http://localhost:3000/api/party/" + idAsQStringQ + "/" + tableNumAsQStringQ + "/sitparty";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}
PartyUpdatermain::PartyUpdatermain()
{

}

// QString sizeAsQStringQ = QString::number(size)
