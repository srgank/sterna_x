#ifndef QWORKERMAGACIN_H
#define QWORKERMAGACIN_H

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

class QWorkerMagacin : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerMagacin(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    QStringList listRes;
    int stat_finished;

private:
    QNetworkAccessManager networkManager;
    QString urlhost;
    QString base64_decode(QString string);
signals:
    void finishedSearch();

public slots:
    void onPostList(QNetworkReply *rep);
};

#endif // QWORKERMAGACIN_H
