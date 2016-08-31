#include "qhelperc.h"


QHelperC::QHelperC(QWidget *parent) : QWidget(parent)
{
}

QHelperC::~QHelperC()
{

}

QList<artikalT> QHelperC::getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}

void QHelperC::InsertArtikal(artikalT& artItem )
{
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(artItem);
    pause.exec();
}

void QHelperC::UpdateArtikal(artikalT& artItem)
{
    QEventLoop pause;
    QWorkerArtikli worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(artItem);
    pause.exec();
}

QList<komintentT> QHelperC::getallKomintenti(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    QEventLoop pause;
    QWorkerKomintent worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, searchName, searchBy);
    pause.exec();
    return worker.listRes;
}

void QHelperC::InsertKomintent(komintentT &komItem)
{
    QEventLoop pause;
    QWorkerKomintent worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(komItem);
    pause.exec();
}

void QHelperC::UpdateKomintent(komintentT &komItem)
{
    QEventLoop pause;
    QWorkerKomintent worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(komItem);
    pause.exec();
}

QList<dokumentT> QHelperC::getallDokumenti(QString& offset, QString& limit, QString& vDokID, QString& vDokTip )
{
    QEventLoop pause;
    QWorkerDokumenti worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, vDokID, vDokTip );
    pause.exec();
    return worker.listRes;
}

QList<dokumentDetailT> QHelperC::getallMagacin(QString& offset, QString& limit, QString& vDokID, QString& vDokTip )
{
    QEventLoop pause;
    QWorkerMagacin worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, vDokID, vDokTip);
    pause.exec();
    return worker.listRes;
}
