#ifndef QHELPERC_H
#define QHELPERC_H
#include <QWidget>
#include "qworker_artikli.h"
#include "qworker_komintent.h"
#include "qworker_dokumenti.h"
#include "qworker_magacin.h"
#include "qworkerlogin.h"

#include <QEventLoop>

//

class QHelperC : public QWidget
{
    Q_OBJECT
public:
    explicit QHelperC(QWidget *parent = 0);
    ~QHelperC();
    QList<artikalT> getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    void InsertArtikal(artikalT &art);
    void UpdateArtikal(artikalT &art);

    QList<komintentT> getallKomintenti(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    void InsertKomintent(komintentT &komItem);
    void UpdateKomintent(komintentT &komItem);

    QList<dokumentT> getallDokumenti(QString& offset, QString& limit, QString& vDokID, QString& vDokTip, QString& vSearchBy, QString& vSearchName );
    QList<dokumentT> InsertDokumenti(dokumentT &Item);
    void UpdateDokumenti(dokumentT &Item);

    QList<dokumentDetailT> getallMagacin(QString& offset, QString& limit, QString &vDokID, QString &vDokTip );
    void InsertMagacin(QList<dokumentDetailT> &ItemList);
    void UpdateMagacin(QList<dokumentDetailT> &ItemList);
    void DeleteMagacin(QList<dokumentDetailT> &ItemList);

    QList<loginDataT> getLoginData(QString& username, QString& password);

private:

signals:

private slots:


};

#endif // QHELPERC_H
