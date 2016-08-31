#ifndef QWORKER1_H
#define QWORKER1_H
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

class QWorkerKomintent : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerKomintent(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    QList<komintentT> listRes;
    int stat_finished;

    void insert(komintentT &komItem );
    void update(komintentT &komItem );

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

#endif // QWORKER1_H
