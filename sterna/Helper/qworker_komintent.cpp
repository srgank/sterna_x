#include "qworker_komintent.h"

QWorkerKomintent::QWorkerKomintent(QWidget *parent) : QWidget(parent)
  ,stat_finished(0)
{
   urlhost = "http://92.53.51.86:5002/";
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
    QUrl serviceUrl = QUrl(urlhost + "get_komintent_list");

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
        QString t_rabat = QString::number(obj["rabat"].toInt());
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


void QWorkerKomintent::insert(
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
    )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsert(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_komintent");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["sifra"] = v_sifra;
    tt_json["naziv"] = v_naziv;
    tt_json["adresa"] = v_adresa;
    tt_json["tel"] = v_tel;
    tt_json["mobil"] = v_mobil;
    tt_json["zirismetka"] = v_zirismetka;
    tt_json["edb"] = v_edb;
    tt_json["deponent"] = v_deponent;
    tt_json["sifradejnost"] = v_sifradejnost;
    tt_json["mb"] = v_mb;
    tt_json["zabeleska1"] = v_zabeleska1;
    tt_json["zabeleska2"] = v_zabeleska2;
    tt_json["rabat"] = v_rabat.toInt();
    tt_json["grad"] = v_grad;


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
void QWorkerKomintent::onPostInsert(QNetworkReply *rep)
{
    emit finishedInsert();
}

void QWorkerKomintent::update(
        QString &v_id,
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
    )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdate(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_komintent");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["id"] = v_id.toInt();
    tt_json["sifra"] = v_sifra;
    tt_json["naziv"] = v_naziv;
    tt_json["adresa"] = v_adresa;
    tt_json["tel"] = v_tel;
    tt_json["mobil"] = v_mobil;
    tt_json["zirismetka"] = v_zirismetka;
    tt_json["edb"] = v_edb;
    tt_json["deponent"] = v_deponent;
    tt_json["sifradejnost"] = v_sifradejnost;
    tt_json["mb"] = v_mb;
    tt_json["zabeleska1"] = v_zabeleska1;
    tt_json["zabeleska2"] = v_zabeleska2;
    tt_json["rabat"] = v_rabat.toInt();
    tt_json["grad"] = v_grad;


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
void QWorkerKomintent::onPostUpdate(QNetworkReply *rep)
{
    emit finishedUpdate();
}



