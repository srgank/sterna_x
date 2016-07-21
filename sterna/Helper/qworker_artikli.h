#ifndef QWORKER_H
#define QWORKER_H
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

class QWorkerArtikli : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerArtikli(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    void insert(
            QString &v_sifra,
            QString &v_artikal,
            QString &v_edm,
            QString &v_ref,
            QString &v_kataloski_broj,
            QString &v_ddv,
            QString &v_proizvoditel,
            QString &v_kategorija
        );
    void update(
            QString &v_sifra,
            QString &v_artikal,
            QString &v_edm,
            QString &v_ref,
            QString &v_kataloski_broj,
            QString &v_ddv,
            QString &v_proizvoditel,
            QString &v_kategorija
        );

    QStringList listRes;
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

#endif // QWORKER_H
