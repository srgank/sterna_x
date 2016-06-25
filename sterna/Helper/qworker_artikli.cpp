#include "qworker_artikli.h"

QWorkerArtikli::QWorkerArtikli(QWidget *parent) : QWidget(parent)
  ,stat_finished(0)
{
   urlhost = "http://127.0.0.1:5002/";
}

QString QWorkerArtikli::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

void QWorkerArtikli::getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_article_list");
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
void QWorkerArtikli::onPostList(QNetworkReply *rep)
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
        QString t_sifra = base64_decode(obj["sifra"].toString());
        QString t_ar = base64_decode(obj["artikal"].toString());
        QString t_edm = base64_decode(obj["edm"].toString());
        QString t_ref = base64_decode(obj["ref"].toString());
        QString t_kataloski_broj = base64_decode(obj["kataloski_broj"].toString());
        QString t_ddv = QString::number(obj["ddv"].toInt());
        QString t_proizvoditel = base64_decode(obj["proizvoditel"].toString());
        QString t_kategorija = base64_decode(obj["kategorija"].toString());


        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listRes << t_id + "#;#"
                       + t_sifra + "#;#"
                       + t_ar + "#;#"
                       + t_edm + "#;#"
                       + t_ref + "#;#"
                       + t_kataloski_broj + "#;#"
                       + t_ddv + "#;#"
                       + t_proizvoditel + "#;#"
                       + t_kategorija ;
        }
    }
    //    emit retValueArtikli(listArt);
    emit finishedSearch();
}
