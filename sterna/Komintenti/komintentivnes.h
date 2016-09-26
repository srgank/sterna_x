#ifndef KomintentiVNES_H
#define KomintentiVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class KomintentiVnes;
}

class KomintentiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiVnes(BaseForm *parent = 0);
    ~KomintentiVnes();
    virtual void pressEscape();
    virtual void pressEnter();
    virtual void pressReturn();
    virtual void updateFont();

private:
    Ui::KomintentiVnes *ui;
    QHelperC *hlp;
    bool eventFilter(QObject *sender, QEvent *event);
    QString str_yellow;
    QString str_none;
    void on_SifraKomintentEdit_EditingFinished();
signals:
    void signalpressEscape();

private slots:
    void on_pushButton_clicked();
};

#endif // KomintentiVNES_H
