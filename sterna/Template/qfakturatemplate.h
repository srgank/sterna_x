#ifndef QFAKTURATEMPLATE_H
#define QFAKTURATEMPLATE_H

#include <QWidget>
#include "Struct/struct.h"


class QFakturaTemplate : public QWidget
{
    Q_OBJECT
public:
    explicit QFakturaTemplate(QWidget *parent = 0);
    QString SetHtmlStyle();
    QString setHtmlHead(QString stype);
    QString setHtmlBody();
    QString setTopHtml();
    QString setEndHtml();

    QString setFaktura();
    QString setFaktura2(faktura_trans& fakturaData);


signals:

public slots:
};

#endif // QFAKTURATEMPLATE_H
