#ifndef ProFakturiVNES_H
#define ProFakturiVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>
#include "qbtemplate.h"

#define COL_DETAIL 28

namespace Ui {
class ProFakturiVnes;
}

class ProFakturiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit ProFakturiVnes(BaseForm *parent = 0);
    ~ProFakturiVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    void initProc(profaktura_trans m_data);
    void setFocusKomintent(QString t);
    void setFocusArtikal(artikalT t);

private:
    Ui::ProFakturiVnes *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QBTemplate<profakturiDetailT> bd;
    QList<profakturiDetailT> resFakturaItems;\
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

#endif // ProFakturiVNES_H
