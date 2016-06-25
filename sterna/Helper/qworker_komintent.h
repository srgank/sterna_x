#ifndef QWORKER1_H
#define QWORKER1_H
#include <QUrlQuery>
#include <QWidget>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QNetworkAccessManager>

class QWorkerKomintent : public QWidget
{
    Q_OBJECT
public:
    explicit QWorkerKomintent(QWidget *parent = 0);
    void getList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy );
    QStringList listRes;
    int stat_finished;
private:
    QNetworkAccessManager networkManager;
    QString urlhost;
    QString base64_decode(QString string);

signals:
    void finishedSearch();

public slots:
    void onPostList(QNetworkReply *rep);
};

#endif // QWORKER1_H
