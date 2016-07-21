#ifndef QHELPERC_H
#define QHELPERC_H
#include <QWidget>
#include "qworker_artikli.h"
#include "qworker_komintent.h"
#include "qworker_dokumenti.h"
#include <QEventLoop>

//

class QHelperC : public QWidget
{
    Q_OBJECT
public:
    explicit QHelperC(QWidget *parent = 0);
    ~QHelperC();
    QStringList getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    QStringList getallKomintenti(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    QStringList getallDokumenti(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    void InsertArtikal(
            QString &v_sifra,
            QString &v_artikal,
            QString &v_edm,
            QString &v_ref,
            QString &v_kataloski_broj,
            QString &v_ddv,
            QString &v_proizvoditel,
            QString &v_kategorija
            );
    void UpdateArtikal(
            QString &v_sifra,
            QString &v_artikal,
            QString &v_edm,
            QString &v_ref,
            QString &v_kataloski_broj,
            QString &v_ddv,
            QString &v_proizvoditel,
            QString &v_kategorija
            );
private:

signals:

private slots:


};

#endif // QHELPERC_H
