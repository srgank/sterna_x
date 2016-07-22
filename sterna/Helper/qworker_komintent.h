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

class QWorkerKomintent : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerKomintent(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    QStringList listRes;
    int stat_finished;

    void insert(
            QString &v_sifra,
            QString &v_naziv,
            QString &v_adresa,
            QString &v_tel,
            QString &v_mobil,
            QString &v_zirismetka,
            QString &v_edb,
            QString &v_deponent,
            QString &v_sifradejnost,
            QString &v_mb,
            QString &v_zabeleska1,
            QString &v_zabeleska2,
            QString &v_rabat,
            QString &v_grad
        );
    void update(
            QString &v_sifra,
            QString &v_naziv,
            QString &v_adresa,
            QString &v_tel,
            QString &v_mobil,
            QString &v_zirismetka,
            QString &v_edb,
            QString &v_deponent,
            QString &v_sifradejnost,
            QString &v_mb,
            QString &v_zabeleska1,
            QString &v_zabeleska2,
            QString &v_rabat,
            QString &v_grad        );

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
