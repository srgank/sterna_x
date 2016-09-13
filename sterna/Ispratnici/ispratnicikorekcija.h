#ifndef IspratniciKOREKCIJA_H
#define IspratniciKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>
#include "qbtemplate.h"

#define COL_DETAIL 28

namespace Ui {
class IspratniciKorekcija;
}

class IspratniciKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit IspratniciKorekcija(BaseForm *parent = 0);
    ~IspratniciKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    virtual void updateFont();
    void initProc(ispratnica_trans m_data);
    void setFocusArtikal(artikalT t);
    void setFocusKomintent(QString t);

private:
    Ui::IspratniciKorekcija *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QBTemplate<ispratnicaDetailT> *bd;
    QList<ispratnicaDetailT> resFakturaItems;\
    QList<int> colDetailWidth;
    void procDeleteItem();
    void procAddItem();
    void showData();
    int m_row;
    QItemSelectionModel *sm;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void on_pushButton_released();
    void selectionChanged(QModelIndex modelX,QModelIndex modelY);
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
};

#endif // IspratniciKOREKCIJA_H
