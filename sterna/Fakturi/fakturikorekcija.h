#ifndef FakturiKOREKCIJA_H
#define FakturiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>
#include "qbtemplate.h"

#define COL_DETAIL 28

namespace Ui {
class FakturiKorekcija;
}

class FakturiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit FakturiKorekcija(BaseForm *parent = 0);
    ~FakturiKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    virtual void updateFont();
    void initProc(faktura_trans m_data);
    void setFocusArtikal(artikalT t);
    void setFocusKomintent(QString t);

private:
    Ui::FakturiKorekcija *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QBTemplate<fakturiDetailT> bd;
    QList<fakturiDetailT> resFakturaItems;\
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

#endif // FakturiKOREKCIJA_H
