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

private:
    Ui::KomintentiVnes *ui;
    QHelperC *hlp;

signals:
    void signalpressEscape();

private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);
};

#endif // KomintentiVNES_H
