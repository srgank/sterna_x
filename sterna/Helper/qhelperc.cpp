#include "qhelperc.h"


QHelperC::QHelperC(QWidget *parent) : QWidget(parent)
{
}

QHelperC::~QHelperC()
{

}
//-----------------------------artikli-------------------------------------------------
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
//-----------------------------komintenti-------------------------------------------------
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

//-----------------------------dokumenti-------------------------------------------------
QList<dokumentT> QHelperC::getallDokumenti(QString& offset, QString& limit, QString& vDokID, QString& vDokTip )
{
    QEventLoop pause;
    QWorkerDokumenti worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, vDokID, vDokTip );
    pause.exec();
    return worker.listRes;
}
void QHelperC::InsertDokumenti(dokumentT &Item)
{
    QEventLoop pause;
    QWorkerDokumenti worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(Item);
    pause.exec();
}

void QHelperC::UpdateDokumenti(dokumentT &Item)
{
    QEventLoop pause;
    QWorkerDokumenti worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(Item);
    pause.exec();
}

//-----------------------------dokumenti detail-------------------------------------------------
QList<dokumentDetailT> QHelperC::getallMagacin(QString& offset, QString& limit, QString& vDokID, QString& vDokTip )
{
    QEventLoop pause;
    QWorkerMagacin worker;
    connect(&worker, SIGNAL(finishedSearch()), &pause, SLOT(quit()));
    worker.getList(offset, limit, vDokID, vDokTip);
    pause.exec();
    return worker.listRes;
}

void QHelperC::InsertMagacin(QList<dokumentDetailT> &ItemList)
{
    QEventLoop pause;
    QWorkerMagacin worker;
    connect(&worker, SIGNAL(finishedInsert()), &pause, SLOT(quit()));
    worker.insert(ItemList);
    pause.exec();
}

void QHelperC::UpdateMagacin(QList<dokumentDetailT> &ItemList)
{
    QEventLoop pause;
    QWorkerMagacin worker;
    connect(&worker, SIGNAL(finishedUpdate()), &pause, SLOT(quit()));
    worker.update(ItemList);
    pause.exec();
}
