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
