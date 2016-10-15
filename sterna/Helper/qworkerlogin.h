#ifndef QWORKERLOGIN_H
#define QWORKERLOGIN_H

#include <QUrlQuery>
#include <QWidget>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include "xx.h"
#include "Struct/struct.h"




class QWorkerLogin : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerLogin(QWidget *parent = 0);
    void getLoginData(QString &username, QString &password);
    QList<loginDataT> listRes;
    QString urlhost;
private:
    QNetworkAccessManager networkManager;
signals:
    void finishedSearch();
public slots:
    void onPostList(QNetworkReply *rep);
};

#endif // QWORKERLOGIN_H
