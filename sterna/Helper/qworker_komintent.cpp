#include "qworker_komintent.h"

QWorkerKomintent::QWorkerKomintent(QWidget *parent) : QWidget(parent)
  ,stat_finished(0)
{
    Singleton *s = Singleton::Instance();
    urlhost = s->Get_UrlHost();
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

    Singleton *s = Singleton::Instance();
    QByteArray HeaderVar = "Authorization";
    QByteArray HeaderValue = s->getToken().toUtf8();
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
        komintentT kom_temp;
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
         kom_temp.id = (obj["id"].toString());
         kom_temp.sifra = (obj["sifra"].toString());
         kom_temp.naziv = (obj["naziv"].toString());
         kom_temp.adresa = (obj["adresa"].toString());
         kom_temp.tel = (obj["tel"].toString());
         kom_temp.mobil = (obj["mobil"].toString());
         kom_temp.zirosmetka = (obj["zirosmetka"].toString());
         kom_temp.edb = (obj["edb"].toString());
         kom_temp.deponent = (obj["deponent"].toString());
         kom_temp.sifra_dejnost = (obj["sifdejnost"].toString());
         kom_temp.mb = (obj["mb"].toString());
         kom_temp.zabeleska1 = (obj["zabeleska1"].toString());
         kom_temp.zabeleska2 = (obj["zabeleska2"].toString());
         kom_temp.rabat = (obj["rabat"].toString());
         kom_temp.grad = (obj["grad"].toString());


        if(kom_temp.id == "end")
        {
            continue;
        }
        else
        {
            listRes << kom_temp;
        }

    }

    emit finishedSearch();
}


void QWorkerKomintent::insert(komintentT& komItem )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsert(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_komintent");
    Singleton *s = Singleton::Instance();
    QByteArray HeaderVar = "Authorization";
    QByteArray HeaderValue = s->getToken().toUtf8();
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["sifra"] = komItem.sifra;
    tt_json["naziv"] = komItem.naziv;
    tt_json["adresa"] = komItem.adresa;
    tt_json["tel"] = komItem.tel;
    tt_json["mobil"] = komItem.mobil;
    tt_json["zirismetka"] = komItem.zirosmetka;
    tt_json["edb"] = komItem.edb;
    tt_json["deponent"] = komItem.deponent;
    tt_json["sifradejnost"] = komItem.sifra_dejnost;
    tt_json["mb"] = komItem.mb;
    tt_json["zabeleska1"] = komItem.zabeleska1;
    tt_json["zabeleska2"] = komItem.zabeleska2;
    tt_json["rabat"] = komItem.rabat;
    tt_json["grad"] = komItem.grad;


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

void QWorkerKomintent::update(komintentT &komItem)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdate(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_komintent");
    Singleton *s = Singleton::Instance();
    QByteArray HeaderVar = "Authorization";
    QByteArray HeaderValue = s->getToken().toUtf8();
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["id"] = komItem.id;
    tt_json["sifra"] = komItem.sifra;
    tt_json["naziv"] = komItem.naziv;
    tt_json["adresa"] = komItem.adresa;
    tt_json["tel"] = komItem.tel;
    tt_json["mobil"] = komItem.mobil;
    tt_json["zirismetka"] = komItem.zirosmetka;
    tt_json["edb"] = komItem.edb;
    tt_json["deponent"] = komItem.deponent;
    tt_json["sifradejnost"] = komItem.sifra_dejnost;
    tt_json["mb"] = komItem.mb;
    tt_json["zabeleska1"] = komItem.zabeleska1;
    tt_json["zabeleska2"] = komItem.zabeleska2;
    tt_json["rabat"] = komItem.rabat;
    tt_json["grad"] = komItem.grad;

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



