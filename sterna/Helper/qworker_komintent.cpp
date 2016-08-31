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
        komintentT kom_temp;
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
         kom_temp.id = QString::number(obj["id"].toInt());
         kom_temp.sifra = base64_decode(obj["sifra"].toString());
         kom_temp.naziv = base64_decode(obj["naziv"].toString());
         kom_temp.adresa = base64_decode(obj["adresa"].toString());
         kom_temp.tel = base64_decode(obj["tel"].toString());
         kom_temp.mobil = base64_decode(obj["mobil"].toString());
         kom_temp.zirosmetka = base64_decode(obj["zirosmetka"].toString());
         kom_temp.edb = base64_decode(obj["edb"].toString());
         kom_temp.deponent = base64_decode(obj["deponent"].toString());
         kom_temp.sifra_dejnost = base64_decode(obj["sifdejnost"].toString());
         kom_temp.mb = base64_decode(obj["mb"].toString());
         kom_temp.zabeleska1 = base64_decode(obj["zabeleska1"].toString());
         kom_temp.zabeleska2 = base64_decode(obj["zabeleska2"].toString());
         kom_temp.rabat = QString::number(obj["rabat"].toInt());
         kom_temp.grad = base64_decode(obj["grad"].toString());


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


void QWorkerKomintent::insert(kominte )
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



