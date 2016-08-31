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
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    void insert(
        QString &v_document_id,
        QString &v_document_tip,
        QString &v_td,
        QString &v_tds,
        QString &v_komintent_id,
        QString &v_prevoznik_id,
        QString &v_valuta,
        QString &v_kurs,
        QString &v_iznos_val,
        QString &v_ddv_val,
        QString &v_rabat_val,
        QString &v_iznos_plakanje_val,
        QString &v_iznos_ddv_den,
        QString &v_rabat_den,
        QString &v_iznos_plakanje_den,
        QString &v_transport_den,
        QString &v_carina_den,
        QString &v_ddv_den,
        QString &v_drugi_trosoci_den,
        QString &v_dok_status,
        QString &v_user_id,
        QString &v_komentar,
        QString &v_mag_id,
        QString &v_object_id
        );

    void update(
        QString &v_tid,
        QString &v_document_id,
        QString &v_document_tip,
        QString &v_td,
        QString &v_tds,
        QString &v_komintent_id,
        QString &v_prevoznik_id,
        QString &v_valuta,
        QString &v_kurs,
        QString &v_iznos_val,
        QString &v_ddv_val,
        QString &v_rabat_val,
        QString &v_iznos_plakanje_val,
        QString &v_iznos_ddv_den,
        QString &v_rabat_den,
        QString &v_iznos_plakanje_den,
        QString &v_transport_den,
        QString &v_carina_den,
        QString &v_ddv_den,
        QString &v_drugi_trosoci_den,
        QString &v_dok_status,
        QString &v_user_id,
        QString &v_komentar,
        QString &v_mag_id,
        QString &v_object_id
        );



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
