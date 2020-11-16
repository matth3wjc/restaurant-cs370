#include "Updater.h"

Updater::Updater(QObject *parent)
    :QObject(parent){
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

Updater::~Updater(){
    disconnect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->deleteLater();
}

void Updater::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        emit ok();
    }
    else
        emit failure(reply->errorString());
}
