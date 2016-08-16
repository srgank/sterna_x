#include "qworker_dokumenti.h"

QWorkerDokumenti::QWorkerDokumenti(QWidget *parent) : QWidget(parent)
{
    Singleton *s = Singleton::Instance();
    urlhost = s->Get_UrlHost();
}
QString QWorkerDokumenti::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

void QWorkerDokumenti::getList( QString &vOffset, QString &vLimit,QString &vDokID, QString &vDokTip )
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
    tt_json["dok_id"] = vDokID;
    tt_json["dok_tip"] = vDokTip;

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
        QString t_komintent_naziv = obj["KOMINTENT_NAZIV"].toString();
        QString t_prevoznik_id = QString::number(obj["PREVOZNIK_ID"].toInt());
        QString t_prevoznik_naziv = obj["PREVOZNIK_NAZIV"].toString();
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
                       + t_komintent_naziv + "#;#"
                       + t_prevoznik_id + "#;#"
                       + t_prevoznik_naziv + "#;#"
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
                       + t_komentar + "#;#"
                       + t_mag_id + "#;#"
                       + t_object_id ;
        }
    }
    emit finishedSearch();
}

void QWorkerDokumenti::insert(
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
    )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsert(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["document_id"] = v_document_id.toInt();
    tt_json["document_tip"] = v_document_tip.toInt();
    tt_json["td"] = v_td;
    tt_json["tds"] = v_tds;
    tt_json["komintent_id"] = v_komintent_id.toInt();
    tt_json["prevoznik_id"] = v_prevoznik_id.toInt();
    tt_json["valuta"] = v_valuta;
    tt_json["kurs"] = v_kurs.toDouble();
    tt_json["iznos_val"] = v_iznos_val.toDouble();
    tt_json["ddv_val"] = v_ddv_val.toDouble();
    tt_json["rabat_val"] = v_rabat_val.toDouble();
    tt_json["iznos_plakanje_val"] = v_iznos_plakanje_val.toDouble();
    tt_json["iznos_ddv_den"] = v_iznos_ddv_den.toDouble();
    tt_json["rabat_den"] = v_rabat_den.toDouble();
    tt_json["iznos_plakanje_den"] = v_iznos_plakanje_den.toDouble();
    tt_json["transport_den"] = v_transport_den.toDouble();
    tt_json["carina_den"] = v_carina_den.toDouble();
    tt_json["ddv_den"] = v_ddv_den.toDouble();
    tt_json["drugi_trosoci_den"] = v_drugi_trosoci_den.toDouble();
    tt_json["dok_status"] = v_dok_status.toInt();
    tt_json["user_id"] = v_user_id.toInt();
    tt_json["komentar"] = v_komentar.toInt();
    tt_json["mag_id"] = v_mag_id.toInt();
    tt_json["object_id"] = v_object_id.toInt();


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
void QWorkerDokumenti::onPostInsert(QNetworkReply *rep)
{
    emit finishedInsert();
}

void QWorkerDokumenti::update(
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

    )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdate(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["document_id"] = v_document_id.toInt();
    tt_json["document_tip"] = v_document_tip.toInt();
    tt_json["td"] = v_td;
    tt_json["tds"] = v_tds;
    tt_json["komintent_id"] = v_komintent_id.toInt();
    tt_json["prevoznik_id"] = v_prevoznik_id.toInt();
    tt_json["valuta"] = v_valuta;
    tt_json["kurs"] = v_kurs.toDouble();
    tt_json["iznos_val"] = v_iznos_val.toDouble();
    tt_json["ddv_val"] = v_ddv_val.toDouble();
    tt_json["rabat_val"] = v_rabat_val.toDouble();
    tt_json["iznos_plakanje_val"] = v_iznos_plakanje_val.toDouble();
    tt_json["iznos_ddv_den"] = v_iznos_ddv_den.toDouble();
    tt_json["rabat_den"] = v_rabat_den.toDouble();
    tt_json["iznos_plakanje_den"] = v_iznos_plakanje_den.toDouble();
    tt_json["transport_den"] = v_transport_den.toDouble();
    tt_json["carina_den"] = v_carina_den.toDouble();
    tt_json["ddv_den"] = v_ddv_den.toDouble();
    tt_json["drugi_trosoci_den"] = v_drugi_trosoci_den.toDouble();
    tt_json["dok_status"] = v_dok_status.toInt();
    tt_json["user_id"] = v_user_id.toInt();
    tt_json["komentar"] = v_komentar.toInt();
    tt_json["mag_id"] = v_mag_id.toInt();
    tt_json["object_id"] = v_object_id.toInt();


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
void QWorkerDokumenti::onPostUpdate(QNetworkReply *rep)
{
    emit finishedUpdate();
}



