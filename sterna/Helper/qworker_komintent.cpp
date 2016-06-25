#include "qworker_komintent.h"

QWorkerKomintent::QWorkerKomintent(QWidget *parent) : QWidget(parent)
  ,stat_finished(0)
{
   urlhost = "http://127.0.0.1:5002/";
   connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostList(QNetworkReply*)));
}

QString QWorkerKomintent::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

void QWorkerKomintent::getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy )
{
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_komintenti_list");

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

void QWorkerKomintent::onPostList(QNetworkReply *rep)
{
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
        QString t_sif = base64_decode(obj["sifra"].toString());
        QString t_naz = base64_decode(obj["naziv"].toString());
        QString t_adr = base64_decode(obj["adresa"].toString());
        QString t_tel = base64_decode(obj["tel"].toString());
        QString t_mobil = base64_decode(obj["mobil"].toString());
        QString t_zirosmetka = base64_decode(obj["zirosmetka"].toString());
        QString t_edb = base64_decode(obj["edb"].toString());
        QString t_deponent = base64_decode(obj["deponent"].toString());
        QString t_sifradejnost = base64_decode(obj["sifdejnost"].toString());
        QString t_mb = base64_decode(obj["mb"].toString());
        QString t_zabeleska1 = base64_decode(obj["zabeleska1"].toString());
        QString t_zabeleska2 = base64_decode(obj["zabeleska2"].toString());
        QString t_rabat = base64_decode(obj["rabat"].toString());
        QString t_grad = base64_decode(obj["grad"].toString());


        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listRes << t_id  + "#;#" +
                       t_sif + "#;#" +
                       t_naz + "#;#" +
                       t_adr + "#;#" +
                       t_tel + "#;#" +
                       t_mobil + "#;#" +
                       t_zirosmetka + "#;#" +
                       t_edb + "#;#" +
                       t_deponent + "#;#" +
                       t_sifradejnost + "#;#" +
                       t_mb + "#;#" +
                       t_zabeleska1 + "#;#" +
                       t_zabeleska2 + "#;#" +
                       t_rabat + "#;#" +
                       t_grad;
        }

    }

    emit finishedSearch();
}
