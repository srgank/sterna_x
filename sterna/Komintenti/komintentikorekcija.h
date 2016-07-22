#ifndef KomintentiKOREKCIJA_H
#define KomintentiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class KomintentiKorekcija;
}

struct kom{
    QString id;
    QString sifra;
    QString naziv;
    QString adresa;
    QString tel;
    QString mobil;
    QString ziro;
    QString edb;
    QString deponent;
    QString sifradejnost;
    QString mb;
    QString zabeleska1;
    QString zabeleska2;
    QString rabat;
    QString grad;
};

class KomintentiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiKorekcija(BaseForm *parent = 0);
    ~KomintentiKorekcija();
    virtual void pressEscape();
    void initProc(QString m_searchID);

private:
    bool eventFilter(QObject *sender, QEvent *event);
    Ui::KomintentiKorekcija *ui;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QString str_yellow;
    QString str_none;
    kom kom_temp;
signals:
    void signalpressEscape();
    void signalPrePressEscape();
private slots:

    void on_pushButton_released();
};

#endif // KomintentiKOREKCIJA_H
