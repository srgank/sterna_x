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
#include "Struct/struct.h"

class QWorkerMagacin : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerMagacin(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    QList<dokumentDetailT> listRes;
    int stat_finished;
    void insert(QList<dokumentDetailT>& itemDokList);
    void update(QList<dokumentDetailT>& itemDokList);
    void delete_(QList<dokumentDetailT>& itemDokList);
private:
    QNetworkAccessManager networkManager;
    QString urlhost;
    QString base64_decode(QString string);
signals:
    void finishedSearch();
    void finishedInsert();
    void finishedUpdate();
    void finishedDelete();

public slots:
    void onPostList(QNetworkReply *rep);
    void onPostInsert(QNetworkReply *rep);
    void onPostUpdate(QNetworkReply *rep);
    void onPostDelete(QNetworkReply *rep);
};

#endif // QWORKERMAGACIN_H
