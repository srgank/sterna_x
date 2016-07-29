#include "qworker_dokumenti.h"

QWorkerDokumenti::QWorkerDokumenti(QWidget *parent) : QWidget(parent)
{
    urlhost = "http://92.53.51.86:5002/";
}
QString QWorkerDokumenti::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

void QWorkerDokumenti::getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy )
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

void QWorkerDokumenti::onPostList(QNetworkReply *rep)
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
        QString t_td = (obj["TD"].toString());
        QString t_tds = (obj["TDS"].toString());
        QString t_komintent_id = QString::number(obj["KOMINTENT_ID"].toInt());
        QString t_prevoznik_id = QString::number(obj["PREVOZNIK_ID"].toInt());
        QString t_valuta = (obj["VALUTA"].toString());
        QString t_kurs = QString::number(obj["KURS"].toDouble(), 'f', 2);
        QString t_iznos_val = QString::number(obj["IZNOS_VAL"].toDouble(), 'f', 2);
        QString t_ddv_val = QString::number(obj["DDV_VAL"].toDouble(), 'f', 2);
        QString t_rabat_val = QString::number(obj["RABAT_VAL"].toDouble(), 'f', 2);
        QString t_iznos_plakanje_val = QString::number(obj["IZNOS_PLAKANJE_VAL"].toDouble(), 'f', 2);
        QString t_iznos_ddv_den = QString::number(obj["IZNOS_DDV_DEN"].toDouble(), 'f', 2);
        QString t_rabat_den = QString::number(obj["RABAT_DEN"].toDouble(), 'f', 2);
        QString t_iznos_plakanje_den = QString::number(obj["IZNOS_PLAKANJE_DEN"].toDouble(), 'f', 2);

        QString t_transport_den = QString::number(obj["TRANSPORT_DEN"].toDouble(), 'f', 2);
        QString t_carina_den = QString::number(obj["CARINA_DEN"].toDouble(), 'f', 2);
        QString t_ddv_den = QString::number(obj["DDV_DEN"].toDouble(), 'f', 2);
        QString t_drugi_trosoci_den = QString::number(obj["DRUGI_TROSOCI_DEN"].toDouble(), 'f', 2);
        QString t_dok_status = base64_decode(obj["DOK_STATUS"].toString());
        QString t_user_id = QString::number(obj["USER_ID"].toInt());
        QString t_komentar = base64_decode(obj["KOMENTAR"].toString());
        QString t_mag_id = QString::number(obj["MAG_ID"].toInt());
        QString t_object_id = QString::number(obj["OBJECT_ID"].toInt());

        if(t_tid == "end")
        {
            continue;
        }
        else
        {
            listRes << t_tid + "#;#"
                       + t_document_id + "#;#"
                       + t_document_tip + "#;#"
                       + t_td + "#;#"
                       + t_tds + "#;#"
                       + t_komintent_id + "#;#"
                       + t_prevoznik_id + "#;#"
                       + t_valuta + "#;#"
                       + t_kurs + "#;#"
                       + t_iznos_val + "#;#"
                       + t_ddv_val + "#;#"
                       + t_rabat_val + "#;#"
                       + t_iznos_plakanje_val + "#;#"
                       + t_iznos_ddv_den + "#;#"
                       + t_rabat_den + "#;#"
                       + t_iznos_plakanje_den + "#;#"
                       + t_transport_den + "#;#"
                       + t_carina_den + "#;#"
                       + t_ddv_den + "#;#"
                       + t_drugi_trosoci_den + "#;#"
                       + t_dok_status + "#;#"
                       + t_user_id + "#;#"
                       + t_mag_id + "#;#"
                       + t_user_id + "#;#"
                       + t_object_id ;
        }
    }
    emit finishedSearch();
}
