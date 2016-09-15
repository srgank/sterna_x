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

void QWorkerDokumenti::insert(dokumentT &item )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsert(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_dokument");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;

    tt_json["TID"] = item.tid;
    tt_json["DOCUMENT_ID"] = item.dokument_id;
    tt_json["DOCUMENT_TIP"] = item.dokument_tip;
    tt_json["TD"] = item.td;
    tt_json["TDS"] = item.tds;
    tt_json["KOMINTENT_ID"] = item.komintent_id;
    tt_json["KOMINTENT_NAZIV"] = item.komintent_naziv;
    tt_json["PREVOZNIK_ID"] = item.prevoznik_id;
    tt_json["PREVOZNIK_NAZIV"] = item.prevoznik_naziv;
    tt_json["VALUTA"] = item.valuta;
    tt_json["KURS"] = item.kurs;
    tt_json["IZNOS_VAL"] = item.iznos_val;
    tt_json["DDV_VAL"] = item.ddv_val;
    tt_json["RABAT_VAL"] = item.rabat_val;
    tt_json["IZNOS_PLAKANJE_VAL"] = item.iznos_plakanje_val;
    tt_json["IZNOS_DDV_DEN"] = item.iznos_ddv_den;
    tt_json["RABAT_DEN"] = item.rabat_den;
    tt_json["IZNOS_PLAKANJE_DEN"] = item.iznos_plakanje_den;
    tt_json["TRANSPORT_DEN"] = item.transport_den;
    tt_json["CARINA_DEN"] = item.carina_den;
    tt_json["DDV_DEN"] = item.ddv_den;
    tt_json["DRUGI_TROSOCI_DEN"] = item.drugi_trosoci_den;
    tt_json["DOK_STATUS"] = item.dok_status;
    tt_json["USER_ID"] = item.user_id;
    tt_json["KOMENTAR"] = item.komentar;
    tt_json["MAG_ID"] = item.mag_id;
    tt_json["OBJECT_ID"] = item.object_id;


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

void QWorkerDokumenti::update(dokumentT & item)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdate(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_dokument");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["TID"] = item.tid;
    tt_json["DOCUMENT_ID"] = item.dokument_id;
    tt_json["DOCUMENT_TIP"] = item.dokument_tip;
    tt_json["TD"] = item.td;
    tt_json["TDS"] = item.tds;
    tt_json["KOMINTENT_ID"] = item.komintent_id;
    tt_json["KOMINTENT_NAZIV"] = item.komintent_naziv;
    tt_json["PREVOZNIK_ID"] = item.prevoznik_id;
    tt_json["PREVOZNIK_NAZIV"] = item.prevoznik_naziv;
    tt_json["VALUTA"] = item.valuta;
    tt_json["KURS"] = item.kurs;
    tt_json["IZNOS_VAL"] = item.iznos_val;
    tt_json["DDV_VAL"] = item.ddv_val;
    tt_json["RABAT_VAL"] = item.rabat_val;
    tt_json["IZNOS_PLAKANJE_VAL"] = item.iznos_plakanje_val;
    tt_json["IZNOS_DDV_DEN"] = item.iznos_ddv_den;
    tt_json["RABAT_DEN"] = item.rabat_den;
    tt_json["IZNOS_PLAKANJE_DEN"] = item.iznos_plakanje_den;
    tt_json["TRANSPORT_DEN"] = item.transport_den;
    tt_json["CARINA_DEN"] = item.carina_den;
    tt_json["DDV_DEN"] = item.ddv_den;
    tt_json["DRUGI_TROSOCI_DEN"] = item.drugi_trosoci_den;
    tt_json["DOK_STATUS"] = item.dok_status;
    tt_json["USER_ID"] = item.user_id;
    tt_json["KOMENTAR"] = item.komentar;
    tt_json["MAG_ID"] = item.mag_id;
    tt_json["OBJECT_ID"] = item.object_id;


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



