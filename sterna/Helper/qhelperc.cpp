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

void QHelperC::InsertArtikal(
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
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(v_sifra, v_artikal, v_edm, v_ref, v_kataloski_broj, v_ddv, v_proizvoditel, v_kategorija);
    pause.exec();
}


void QHelperC::UpdateArtikal(
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
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(v_sifra, v_artikal, v_edm, v_ref, v_kataloski_broj, v_ddv, v_proizvoditel, v_kategorija);
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

QStringList QHelperC::getallDokumenti(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerDokumenti worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}
