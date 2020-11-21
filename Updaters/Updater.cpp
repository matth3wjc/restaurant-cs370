#include "Updater.h"
#include <QUrl>

Updater::Updater(QObject *parent)
    :QObject(parent){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

Updater::~Updater(){
    disconnect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->deleteLater();
}

void Updater::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200)
            emit ok(reply->readAll().toInt());
        else
            emit ok();
    }
    else
        emit failure(reply->errorString());
}
