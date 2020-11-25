//Luke Shoulders

#ifndef DATABASEMANAGERARRAYQ_H
#define DATABASEMANAGERARRAYQ_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <fstream>
#include <vector>
#include <QString>
#include "DataBaseManagerObject.hpp"


class DataBaseManagerArrayQ: public QObject {
    Q_OBJECT
    QNetworkAccessManager *manager;
private slots:
    void replyFinished(QNetworkReply *);

signals:
    void ok();
    void failure(QString err);

public:
    DataBaseManagerArrayQ(QObject *parent = nullptr);
    ~DataBaseManagerArrayQ();
    std::vector<DataBaseManagerObject *> *listOfDataObjects() { return _listOfDataObjects; }
    virtual DataBaseManagerObject *dataBaseManagerObject() = 0;
    void fileDownload(QString urlPath);
    int numJSONObjects();
    void parseJSONArray(std::fstream &stream);
    void setFilePath(QString _filePath);
protected:
    std::vector<DataBaseManagerObject *> *_listOfDataObjects;
private:
    QString filePath;
};


#endif // DATABASEMANAGERARRAYQ_H
