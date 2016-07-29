#include "qhelperc.h"


QHelperC::QHelperC(QWidget *parent) : QWidget(parent)
{
}

QHelperC::~QHelperC()
{

}

QStringList QHelperC::getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}

void QHelperC::InsertArtikal(QString &v_sifra, QString &v_artikal, QString &v_edm, QString &v_ref, QString &v_kataloski_broj, QString &v_ddv, QString &v_proizvoditel, QString &v_kategorija )
{
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(v_sifra, v_artikal, v_edm, v_ref, v_kataloski_broj, v_ddv, v_proizvoditel, v_kategorija);
    pause.exec();
}

void QHelperC::UpdateArtikal(QString &v_id, QString &v_sifra, QString &v_artikal, QString &v_edm, QString &v_ref, QString &v_kataloski_broj, QString &v_ddv, QString &v_proizvoditel, QString &v_kategorija )
{
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(v_id, v_sifra, v_artikal, v_edm, v_ref, v_kataloski_broj, v_ddv, v_proizvoditel, v_kategorija);
    pause.exec();
}

QStringList QHelperC::getallKomintenti(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerKomintent worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}

void QHelperC::InsertKomintent(QString &v_sifra, QString &v_naziv, QString &v_adresa, QString &v_tel, QString &v_mobil, QString &v_zirismetka, QString &v_edb, QString &v_deponent, QString &v_sifradejnost, QString &v_mb, QString &v_zabeleska1, QString &v_zabeleska2, QString &v_rabat, QString &v_grad)
{
    QEventLoop pause;
    QWorkerKomintent worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(v_sifra, v_naziv, v_adresa, v_tel,  v_mobil,  v_zirismetka, v_edb, v_deponent, v_sifradejnost, v_mb, v_zabeleska1, v_zabeleska2, v_rabat, v_grad);
    pause.exec();
}

void QHelperC::UpdateKomintent(QString &v_id, QString &v_sifra, QString &v_naziv, QString &v_adresa, QString &v_tel, QString &v_mobil, QString &v_zirismetka, QString &v_edb, QString &v_deponent, QString &v_sifradejnost, QString &v_mb, QString &v_zabeleska1, QString &v_zabeleska2, QString &v_rabat, QString &v_grad )
{
    QEventLoop pause;
    QWorkerKomintent worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(v_id, v_sifra, v_naziv, v_adresa, v_tel,  v_mobil,  v_zirismetka, v_edb, v_deponent, v_sifradejnost, v_mb, v_zabeleska1, v_zabeleska2, v_rabat, v_grad);
    pause.exec();
}

QStringList QHelperC::getallDokumenti(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerDokumenti worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}

QStringList QHelperC::getallMagacin(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerMagacin worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}
