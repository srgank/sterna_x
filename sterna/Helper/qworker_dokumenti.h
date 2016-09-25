#ifndef QWORKERDOKUMENTI_H
#define QWORKERDOKUMENTI_H

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

class QWorkerDokumenti : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerDokumenti(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vDokID, QString &vDokTip, QString &vSearchBy, QString &vSearchName );
    void insert(dokumentT & item);
    void update(dokumentT & item);
    QList<dokumentT> listRes;
    int stat_finished;

private:
    QNetworkAccessManager networkManager;
    QString urlhost;
    QString base64_decode(QString string);
signals:
    void finishedSearch();
    void finishedInsert();
    void finishedUpdate();

public slots:
    void onPostList(QNetworkReply *rep);
    void onPostInsert(QNetworkReply *rep);
    void onPostUpdate(QNetworkReply *rep);

};

#endif // QWORKERDOKUMENTI_H
