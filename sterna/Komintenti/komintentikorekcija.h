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

class KomintentiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiKorekcija(BaseForm *parent = 0);
    ~KomintentiKorekcija();
    virtual void pressEscape();
    virtual void updateFont();
    void initProc(QString m_searchID);

private:
    bool eventFilter(QObject *sender, QEvent *event);
    Ui::KomintentiKorekcija *ui;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QString str_yellow;
    QString str_none;
    komintentT kom_temp;
    QString komintent_id;
signals:
    void signalpressEscape();
    void signalPrePressEscape();
private slots:

    void on_pushButton_released();
};

#endif // KomintentiKOREKCIJA_H
