#include "qworker_dokumenti.h"

QWorkerDokumenti::QWorkerDokumenti(QWidget *parent) : QWidget(parent)
{
   urlhost = "http://127.0.0.1:5002/";
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
        QString t_id = QString::number(obj["id"].toInt());
        QString t_dok_id = QString::number(obj["dok_id"].toInt());
        QString t_dok_tip = QString::number(obj["dok_tip"].toInt());
        QString t_dok_tip_link = QString::number(obj["dok_tip_link"].toInt());
//        QString t_datum = QString::number(obj["datum"].toDate());
        QString t_faktura_id = QString::number(obj["faktura_id"].toInt());
        QString t_mag_id = QString::number(obj["mag_id"].toInt());

        QString t_komintent_id = QString::number(obj["komintent_id"].toInt());
        QString t_carina = QString::number(obj["carina"].toDouble(), 'f', 2);
        QString t_transport = QString::number(obj["transport"].toDouble(), 'f', 2);
        QString t_drugi_trosoci = QString::number(obj["drugi_trosoci"].toDouble(), 'f', 2);
        QString t_doc_creator = obj["doc_creator"].toString();
        QString t_dok_status = QString::number(obj["dok_status"].toInt());
        QString t_dok_opis = obj["dok_opis"].toString();



        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listRes << t_id + "#;#"
                       + t_dok_id + "#;#"
                       + t_dok_tip + "#;#"
                       + t_dok_tip_link + "#;#"
//                       + t_datum + "#;#"
                       + t_faktura_id + "#;#"
                       + t_mag_id + "#;#"
                       + t_komintent_id + "#;#"
                       + t_carina + "#;#"
                       + t_transport + "#;#"
                       + t_drugi_trosoci + "#;#"
                       + t_doc_creator + "#;#"
                       + t_dok_status + "#;#"
                       + t_dok_opis ;
        }
    }
    emit finishedSearch();
}
