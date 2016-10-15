#include "qworkerlogin.h"

QWorkerLogin::QWorkerLogin(QWidget *parent) : QWidget(parent)
{
    Singleton *s = Singleton::Instance();
    urlhost = s->Get_UrlHost();
}

void QWorkerLogin::getLoginData(QString &username, QString &password)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "login");

    Singleton *s = Singleton::Instance();

    QByteArray postData;

    QJsonObject tt_json;
    tt_json["user_name"] = username;
    tt_json["password"] = password;

    QJsonDocument doc(tt_json);
    QByteArray tt = doc.toJson();


    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkManager.post(networkRequest,postData);

    postData.clear();
}

void QWorkerLogin::onPostList(QNetworkReply *rep)
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
        loginDataT loginData;
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        loginData.token = (obj["token"].toString());
        loginData.database_prefix = (obj["database_prefix"].toString());
        loginData.valid_to = (obj["valid_to"].toString());
        loginData.company = (obj["company"].toString());

        if(loginData.token == "end")
        {
            continue;
        }
        else
        {
            listRes <<  loginData;
        }
    }
    emit finishedSearch();
}
