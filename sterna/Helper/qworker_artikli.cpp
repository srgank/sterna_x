#include "qworker_artikli.h"

QWorkerArtikli::QWorkerArtikli(QWidget *parent) : QWidget(parent)
  ,stat_finished(0)
{
    Singleton *s = Singleton::Instance();
    urlhost = s->Get_UrlHost();
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
        artikalT art_temp;
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        art_temp.id = QString::number(obj["id"].toInt());
        art_temp.sifra = base64_decode(obj["sifra"].toString());
        art_temp.artikal = base64_decode(obj["artikal"].toString());
        art_temp.edm = base64_decode(obj["edm"].toString());
        art_temp.ref = base64_decode(obj["ref"].toString());
        art_temp.kataloski_broj = base64_decode(obj["kataloski_broj"].toString());
        art_temp.ddv = QString::number(obj["ddv"].toInt());
        art_temp.proizvoditel = base64_decode(obj["proizvoditel"].toString());
        art_temp.kategorija = base64_decode(obj["kategorija"].toString());


        if(art_temp.id == "end")
        {
            continue;
        }
        else
        {
            listRes << art_temp ;
        }
    }
    emit finishedSearch();
}


void QWorkerArtikli::insert(
        QString &v_sifra,
        QString &v_artikal,
        QString &v_edm,
        QString &v_ref,
        QString &v_kataloski_broj,
        QString &v_ddv,
        QString &v_proizvoditel,
        QString &v_kategorija
    )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsert(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["sifra"] = v_sifra;
    tt_json["artikal"] = v_artikal;
    tt_json["edm"] = v_edm;
    tt_json["ref"] = v_ref;
    tt_json["kataloski_broj"] = v_kataloski_broj;
    tt_json["ddv"] = v_ddv.toInt();
    tt_json["proizvoditel"] = v_proizvoditel;
    tt_json["kategorija"] = v_kategorija;


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
void QWorkerArtikli::onPostInsert(QNetworkReply *rep)
{
    emit finishedInsert();
}

void QWorkerArtikli::update(
        QString &v_id,
        QString &v_sifra,
        QString &v_artikal,
        QString &v_edm,
        QString &v_ref,
        QString &v_kataloski_broj,
        QString &v_ddv,
        QString &v_proizvoditel,
        QString &v_kategorija
    )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdate(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json;
    tt_json["id"] = v_id.toInt();
    tt_json["sifra"] = v_sifra;
    tt_json["artikal"] = v_artikal;
    tt_json["edm"] = v_edm;
    tt_json["ref"] = v_ref;
    tt_json["kataloski_broj"] = v_kataloski_broj;
    tt_json["ddv"] = v_ddv.toInt();
    tt_json["proizvoditel"] = v_proizvoditel;
    tt_json["kategorija"] = v_kategorija;


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
void QWorkerArtikli::onPostUpdate(QNetworkReply *rep)
{
    emit finishedUpdate();
}



