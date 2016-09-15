#include "qworker_magacin.h"

QWorkerMagacin::QWorkerMagacin(QWidget *parent) : QWidget(parent)
{
    Singleton *s = Singleton::Instance();
    urlhost = s->Get_UrlHost();
}
QString QWorkerMagacin::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}


void QWorkerMagacin::getList( QString &vOffset, QString &vLimit,QString &vDokID, QString &vDokTip )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_dokumenti_detail_list");
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

void QWorkerMagacin::onPostList(QNetworkReply *rep)
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
        dokumentDetailT docdetail_temp ;
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        docdetail_temp.tid = QString::number(obj["TID"].toInt());
        docdetail_temp.dokument_id = QString::number(obj["DOCUMENT_ID"].toInt());
        docdetail_temp.dokument_tip = QString::number(obj["DOCUMENT_TIP"].toInt());
        docdetail_temp.komintent_id = QString::number(obj["KOMINTENT_ID"].toInt());
        docdetail_temp.artikal_id = QString::number(obj["ARTIKAL_ID"].toInt());
        docdetail_temp.artikal_naziv = obj["ARTIKAL"].toString();
        docdetail_temp.tip_artikal = QString::number(obj["TIP_ARTIKAL"].toInt());
        docdetail_temp.link_artikal = QString::number(obj["LINK_ARTIKAL"].toInt());
        docdetail_temp.edm = base64_decode(obj["EDM"].toString());
        docdetail_temp.vlez_nab_cena_bez_ddv = QString::number(obj["V_NAB_CENA_BEZ_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_nab_cena_so_ddv = QString::number(obj["V_NAB_CENA_SO_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_prenesen_ddv = QString::number(obj["V_PREN_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_prenesen_ddv_denari = QString::number(obj["V_PREN_DDV_DEN"].toDouble(), 'f', 2);
        docdetail_temp.vlez_rabat = QString::number(obj["V_RABAT"].toDouble(), 'f', 2);
        docdetail_temp.vlez_nabaven_iznos_so_ddv = QString::number(obj["V_NAB_IZNOS_SO_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_marza = QString::number(obj["V_MARZA"].toDouble(), 'f', 2);
        docdetail_temp.vlez_marza_den = QString::number(obj["V_MARZA_DEN"].toDouble(), 'f', 2);
        docdetail_temp.vlez_prod_cena_bez_ddv = QString::number(obj["V_PROD_CENA_BEZ_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_presmetan_ddv = QString::number(obj["V_PRESMETAN_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_prod_cena_so_ddv = QString::number(obj["V_PROD_CENA_SO_DDV"].toDouble(), 'f', 2);
        docdetail_temp.vlez_prod_iznos_so_ddv = QString::number(obj["V_PROD_IZNOS_SO_DDV"].toDouble(), 'f', 2);
        docdetail_temp.izl_cena_bez_ddv_calc = QString::number(obj["I_CENA_BEZ_DDV_KALK"].toDouble(), 'f', 2);
        docdetail_temp.izl_cena_so_ddv_calc = QString::number(obj["I_CENA_SO_DDV_KALK"].toDouble(), 'f', 2);
        docdetail_temp.izl_cena_so_ddv_prod = QString::number(obj["I_CENA_SO_DDV_PROD"].toDouble(), 'f', 2);
        docdetail_temp.izl_ddv_prod = QString::number(obj["I_DDV_PROD"].toDouble(), 'f', 2);
        docdetail_temp.kol = QString::number(obj["KOL"].toDouble(), 'f', 2);
        docdetail_temp.mag_id = QString::number(obj["MAG_ID"].toInt());
        docdetail_temp.status = QString::number(obj["STATUS"].toInt());


        if(docdetail_temp.tid == "end")
        {
            continue;
        }
        else
        {
            listRes << docdetail_temp;
        }
    }
    emit finishedSearch();
}

void QWorkerMagacin::insert(QList<dokumentDetailT>& itemDokList)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsert(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_dokumenti_detail");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json_all;
    QJsonArray tt_jsonArray;
    for (int i = 0; i < itemDokList.count(); i++)
    {
        QJsonObject tt_json;
        tt_json["TID"] = itemDokList.at(i).tid;
        tt_json["DOCUMENT_ID"]= itemDokList.at(i).dokument_id;
        tt_json["DOCUMENT_TIP"]= itemDokList.at(i).dokument_tip;
        tt_json["KOMINTENT_ID"]= itemDokList.at(i).komintent_id;
        tt_json["ARTIKAL_ID"]= itemDokList.at(i).artikal_id;
        tt_json["ARTIKAL"]= itemDokList.at(i).artikal_naziv;
        tt_json["TIP_ARTIKAL"]= itemDokList.at(i).tip_artikal;
        tt_json["LINK_ARTIKAL"]= itemDokList.at(i).link_artikal;
        tt_json["EDM"]= itemDokList.at(i).edm;
        tt_json["V_NAB_CENA_BEZ_DDV"]= itemDokList.at(i).vlez_nab_cena_bez_ddv;
        tt_json["V_NAB_CENA_SO_DDV"]= itemDokList.at(i).vlez_nab_cena_so_ddv;
        tt_json["V_PREN_DDV"]= itemDokList.at(i).vlez_prenesen_ddv;
        tt_json["V_PREN_DDV_DEN"]= itemDokList.at(i).vlez_prenesen_ddv_denari;
        tt_json["V_RABAT"]= itemDokList.at(i).vlez_rabat;
        tt_json["V_NAB_IZNOS_SO_DDV"]= itemDokList.at(i).vlez_nabaven_iznos_so_ddv;
        tt_json["V_MARZA"]= itemDokList.at(i).vlez_marza;
        tt_json["V_MARZA_DEN"]= itemDokList.at(i).vlez_marza_den;
        tt_json["V_PROD_CENA_BEZ_DDV"]= itemDokList.at(i).vlez_prod_cena_bez_ddv;
        tt_json["V_PRESMETAN_DDV"]= itemDokList.at(i).vlez_presmetan_ddv;
        tt_json["V_PROD_CENA_SO_DDV"]= itemDokList.at(i).vlez_prod_cena_so_ddv;
        tt_json["V_PROD_IZNOS_SO_DDV"]= itemDokList.at(i).vlez_prod_iznos_so_ddv;
        tt_json["I_CENA_BEZ_DDV_KALK"]= itemDokList.at(i).izl_cena_bez_ddv_calc;
        tt_json["I_CENA_SO_DDV_KALK"]= itemDokList.at(i).izl_cena_so_ddv_calc;
        tt_json["I_CENA_SO_DDV_PROD"]= itemDokList.at(i).izl_cena_so_ddv_prod;
        tt_json["I_DDV_PROD"]= itemDokList.at(i).izl_ddv_prod;
        tt_json["KOL"]= itemDokList.at(i).kol;
        tt_json["MAG_ID"]= itemDokList.at(i).mag_id;
        tt_json["STATUS"]= itemDokList.at(i).status;

        tt_jsonArray.append(tt_json);
    }

    tt_json_all["properties"] = tt_jsonArray;

    QJsonDocument doc(tt_json_all);
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
void QWorkerMagacin::onPostInsert(QNetworkReply *rep)
{
    emit finishedInsert();
}

void QWorkerMagacin::update(QList<dokumentDetailT>& itemDokList)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdate(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;

    QJsonObject tt_json_all;
    QJsonArray tt_jsonArray;
    for (int i = 0; i < itemDokList.count(); i++)
    {
        QJsonObject tt_json;
        tt_json["TID"] = itemDokList.at(i).tid;
        tt_json["DOCUMENT_ID"]= itemDokList.at(i).dokument_id;
        tt_json["DOCUMENT_TIP"]= itemDokList.at(i).dokument_tip;
        tt_json["KOMINTENT_ID"]= itemDokList.at(i).komintent_id;
        tt_json["ARTIKAL_ID"]= itemDokList.at(i).artikal_id;
        tt_json["ARTIKAL"]= itemDokList.at(i).artikal_naziv;
        tt_json["TIP_ARTIKAL"]= itemDokList.at(i).tip_artikal;
        tt_json["LINK_ARTIKAL"]= itemDokList.at(i).link_artikal;
        tt_json["EDM"]= itemDokList.at(i).edm;
        tt_json["V_NAB_CENA_BEZ_DDV"]= itemDokList.at(i).vlez_nab_cena_bez_ddv;
        tt_json["V_NAB_CENA_SO_DDV"]= itemDokList.at(i).vlez_nab_cena_so_ddv;
        tt_json["V_PREN_DDV"]= itemDokList.at(i).vlez_prenesen_ddv;
        tt_json["V_PREN_DDV_DEN"]= itemDokList.at(i).vlez_prenesen_ddv_denari;
        tt_json["V_RABAT"]= itemDokList.at(i).vlez_rabat;
        tt_json["V_NAB_IZNOS_SO_DDV"]= itemDokList.at(i).vlez_nabaven_iznos_so_ddv;
        tt_json["V_MARZA"]= itemDokList.at(i).vlez_marza;
        tt_json["V_MARZA_DEN"]= itemDokList.at(i).vlez_marza_den;
        tt_json["V_PROD_CENA_BEZ_DDV"]= itemDokList.at(i).vlez_prod_cena_bez_ddv;
        tt_json["V_PRESMETAN_DDV"]= itemDokList.at(i).vlez_presmetan_ddv;
        tt_json["V_PROD_CENA_SO_DDV"]= itemDokList.at(i).vlez_prod_cena_so_ddv;
        tt_json["V_PROD_IZNOS_SO_DDV"]= itemDokList.at(i).vlez_prod_iznos_so_ddv;
        tt_json["I_CENA_BEZ_DDV_KALK"]= itemDokList.at(i).izl_cena_bez_ddv_calc;
        tt_json["I_CENA_SO_DDV_KALK"]= itemDokList.at(i).izl_cena_so_ddv_calc;
        tt_json["I_CENA_SO_DDV_PROD"]= itemDokList.at(i).izl_cena_so_ddv_prod;
        tt_json["I_DDV_PROD"]= itemDokList.at(i).izl_ddv_prod;
        tt_json["KOL"]= itemDokList.at(i).kol;
        tt_json["MAG_ID"]= itemDokList.at(i).mag_id;
        tt_json["STATUS"]= itemDokList.at(i).status;

        tt_jsonArray.append(tt_json);
    }

    tt_json_all["properties"] = tt_jsonArray;

    QJsonDocument doc(tt_json_all);
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
void QWorkerMagacin::onPostUpdate(QNetworkReply *rep)
{
    emit finishedUpdate();
}
