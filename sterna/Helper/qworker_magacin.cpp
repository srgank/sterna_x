#include "qworker_magacin.h"

QWorkerMagacin::QWorkerMagacin(QWidget *parent) : QWidget(parent)
{
    Singleton *s = Singleton::Instance();
    urlhost = s->Get_UrlHost();
}
QString QWorkerMagacin::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

void QWorkerMagacin::getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_dokumenti_list");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["offset"] = vOffset;
    tt_json["limit"] = vLimit;
    tt_json["search_name"] = vSearchName;
    tt_json["search_by"] = vSearchBy;

    QJsonDocument doc(tt_json);
    QByteArray tt = doc.toJson();


    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest,postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}

void QWorkerMagacin::onPostList(QNetworkReply *rep)
{
    disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostList(QNetworkReply*)));
    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["properties"].toArray();



    for (int a = 0; a < jsonArray.count(); a++)
    {
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        QString t_tid = QString::number(obj["TID"].toInt());
        QString t_document_id = QString::number(obj["DOCUMENT_ID"].toInt());
        QString t_document_tip = QString::number(obj["DOCUMENT_TIP"].toInt());
        QString t_komintent_id = QString::number(obj["KOMINTENT_ID"].toInt());
        QString t_artikal_id = QString::number(obj["ARTIKAL_ID"].toInt());
        QString t_tip_artikal = QString::number(obj["TIP_ARTIKAL"].toInt());
        QString t_link_artikal = QString::number(obj["LINK_ARTIKAL"].toInt());
        QString t_edm = base64_decode(obj["EDM"].toString());
        QString t_vlez_nab_cena_bez_ddv = QString::number(obj["V_NAB_CENA_BEZ_DDV"].toDouble(), 'f', 2);
        QString t_vlez_nab_cena_so_ddv = QString::number(obj["V_NAB_CENA_SO_DDV"].toDouble(), 'f', 2);
        QString t_vlez_prenesen_ddv = QString::number(obj["V_PREN_DDV"].toDouble(), 'f', 2);
        QString t_vlez_prenesen_ddv_denari = QString::number(obj["V_PREN_DDV_DEN"].toDouble(), 'f', 2);
        QString t_vlez_rabat = QString::number(obj["V_RABAT"].toDouble(), 'f', 2);
        QString t_vlez_nabaven_iznos_so_ddv = QString::number(obj["V_NAB_IZNOS_SO_DDV"].toDouble(), 'f', 2);
        QString t_vlez_marza = QString::number(obj["V_MARZA"].toDouble(), 'f', 2);
        QString t_vlez_marza_den = QString::number(obj["V_MARZA_DEN"].toDouble(), 'f', 2);
        QString t_vlez_prod_cena_bez_ddv = QString::number(obj["V_PROD_CENA_BEZ_DDV"].toDouble(), 'f', 2);
        QString t_vlez_presmetan_ddv = QString::number(obj["V_PRESMETAN_DDV"].toDouble(), 'f', 2);
        QString t_vlez_prod_cena_so_ddv = QString::number(obj["V_PROD_CENA_SO_DDV"].toDouble(), 'f', 2);
        QString t_vlez_prod_iznos_so_ddv = QString::number(obj["V_PROD_IZNOS_SO_DDV"].toDouble(), 'f', 2);
        QString t_izl_cena_bez_ddv_calc = QString::number(obj["I_CENA_BEZ_DDV_KALK"].toDouble(), 'f', 2);
        QString t_izl_cena_so_ddv_calc = QString::number(obj["I_CENA_SO_DDV_KALK"].toDouble(), 'f', 2);
        QString t_izl_cena_so_ddv_prod = QString::number(obj["I_CENA_SO_DDV_PROD"].toDouble(), 'f', 2);
        QString t_izl_ddv_prod = QString::number(obj["I_DDV_PROD"].toDouble(), 'f', 2);
        QString t_kol = QString::number(obj["KOL"].toDouble(), 'f', 2);
        QString t_mag_id = QString::number(obj["MAG_ID"].toInt());
        QString t_status = QString::number(obj["STATUS"].toInt());


        if(t_tid == "end")
        {
            continue;
        }
        else
        {
            listRes << t_tid + "#;#"
                       + t_document_id + "#;#"
                       + t_document_tip + "#;#"
                       + t_komintent_id + "#;#"
                       + t_artikal_id + "#;#"
                       + t_tip_artikal + "#;#"
                       + t_link_artikal + "#;#"
                       + t_edm + "#;#"
                       + t_vlez_nab_cena_bez_ddv + "#;#"
                       + t_vlez_nab_cena_so_ddv + "#;#"
                       + t_vlez_prenesen_ddv + "#;#"
                       + t_vlez_prenesen_ddv_denari + "#;#"
                       + t_vlez_rabat + "#;#"
                       + t_vlez_nabaven_iznos_so_ddv + "#;#"
                       + t_vlez_marza + "#;#"
                       + t_vlez_marza_den + "#;#"
                       + t_vlez_prod_cena_bez_ddv + "#;#"
                       + t_vlez_presmetan_ddv + "#;#"
                       + t_vlez_prod_cena_so_ddv + "#;#"
                       + t_vlez_prod_iznos_so_ddv + "#;#"
                       + t_izl_cena_bez_ddv_calc + "#;#"
                       + t_izl_cena_so_ddv_calc + "#;#"
                       + t_izl_cena_so_ddv_prod + "#;#"
                       + t_izl_ddv_prod + "#;#"
                       + t_kol + "#;#"
                       + t_mag_id + "#;#"
                       + t_status ;
        }
    }
    emit finishedSearch();
}
