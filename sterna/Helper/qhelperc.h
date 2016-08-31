#ifndef QHELPERC_H
#define QHELPERC_H
#include <QWidget>
#include "qworker_artikli.h"
#include "qworker_komintent.h"
#include "qworker_dokumenti.h"
#include "qworker_magacin.h"

#include <QEventLoop>

//

class QHelperC : public QWidget
{
    Q_OBJECT
public:
    explicit QHelperC(QWidget *parent = 0);
    ~QHelperC();
    QList<artikalT> getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    QList<komintentT> getallKomintenti(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    QList<dokumentT> getallDokumenti(QString& offset, QString& limit, QString& vDokID, QString& vDokTip );
    void InsertArtikal(artikalT &art);
    void UpdateArtikal(artikalT &art);

    void InsertKomintent(komintentT &komItem);
    void UpdateKomintent(komintentT &komItem);
    QList<dokumentDetailT> getallMagacin(QString& offset, QString& limit, QString &vDokID, QString &vDokTip );
private:

signals:

private slots:


};

#endif // QHELPERC_H
