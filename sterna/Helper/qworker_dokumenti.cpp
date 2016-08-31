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
        dokumentT doc_temp;
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        doc_temp.tid = QString::number(obj["TID"].toInt());
        doc_temp.dokument_id = QString::number(obj["DOCUMENT_ID"].toInt());
        doc_temp.dokument_tip = QString::number(obj["DOCUMENT_TIP"].toInt());
        doc_temp.td = (obj["TD"].toString());
        doc_temp.tds = (obj["TDS"].toString());
        doc_temp.komintent_id = QString::number(obj["KOMINTENT_ID"].toInt());
        doc_temp.komintent_naziv = obj["KOMINTENT_NAZIV"].toString();
        doc_temp.prevoznik_id = QString::number(obj["PREVOZNIK_ID"].toInt());
        doc_temp.prevoznik_naziv = obj["PREVOZNIK_NAZIV"].toString();
        doc_temp.valuta = (obj["VALUTA"].toString());
        doc_temp.kurs = QString::number(obj["KURS"].toDouble(), 'f', 2);
        doc_temp.iznos_val = QString::number(obj["IZNOS_VAL"].toDouble(), 'f', 2);
        doc_temp.ddv_val = QString::number(obj["DDV_VAL"].toDouble(), 'f', 2);
        doc_temp.rabat_val = QString::number(obj["RABAT_VAL"].toDouble(), 'f', 2);
        doc_temp.iznos_plakanje_val = QString::number(obj["IZNOS_PLAKANJE_VAL"].toDouble(), 'f', 2);
        doc_temp.iznos_ddv_den = QString::number(obj["IZNOS_DDV_DEN"].toDouble(), 'f', 2);
        doc_temp.rabat_den = QString::number(obj["RABAT_DEN"].toDouble(), 'f', 2);
        doc_temp.iznos_plakanje_den = QString::number(obj["IZNOS_PLAKANJE_DEN"].toDouble(), 'f', 2);

        doc_temp.transport_den = QString::number(obj["TRANSPORT_DEN"].toDouble(), 'f', 2);
        doc_temp.carina_den = QString::number(obj["CARINA_DEN"].toDouble(), 'f', 2);
        doc_temp.ddv_den = QString::number(obj["DDV_DEN"].toDouble(), 'f', 2);
        doc_temp.drugi_trosoci_den = QString::number(obj["DRUGI_TROSOCI_DEN"].toDouble(), 'f', 2);
        doc_temp.dok_status = base64_decode(obj["DOK_STATUS"].toString());
        doc_temp.user_id = QString::number(obj["USER_ID"].toInt());
        doc_temp.komentar = base64_decode(obj["KOMENTAR"].toString());
        doc_temp.mag_id = QString::number(obj["MAG_ID"].toInt());
        doc_temp.object_id = QString::number(obj["OBJECT_ID"].toInt());

        if(doc_temp.tid == "end")
        {
            continue;
        }
        else
        {
            listRes << doc_temp;
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



