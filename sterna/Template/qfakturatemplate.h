#ifndef QFAKTURATEMPLATE_H
#define QFAKTURATEMPLATE_H

#include <QWidget>

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


signals:

public slots:
};

#endif // QFAKTURATEMPLATE_H
