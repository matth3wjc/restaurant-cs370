//Luke Shoulders

#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>

class Updater: public QObject {
    QNetworkAccessManager *manager;
    Q_OBJECT
private slots:
    void replyFinished(QNetworkReply *);

signals:
    void ok();
    void ok(int id);
    void failure(QString err);
public:
    Updater(QObject *parent = nullptr);
    ~Updater();
};

#endif // UPDATER_H
