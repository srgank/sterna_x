#ifndef IntPriemniciKOREKCIJA_H
#define IntPriemniciKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>
#include "qbtemplate.h"
#include "Delegate/qcbitemdelegate.h"
#include "Delegate/qleitemdelegate.h"

#define COL_DETAIL 28

namespace Ui {
class IntPriemniciKorekcija;
}

class IntPriemniciKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit IntPriemniciKorekcija(BaseForm *parent = 0);
    ~IntPriemniciKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    virtual void updateFont();
    virtual void Refresh();
    void initProc(IntPriemnici_trans m_data);
    void setFocusArtikal(artikalT t);
    void setFocusKomintent(komintentT t);

private:
    Ui::IntPriemniciKorekcija *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QBTemplate<IntPriemniciT> *b;
    QBTemplate<IntPriemniciDetailT> *bd;
    IntPriemniciT resFaktura;
    QList<IntPriemniciDetailT> resFakturaItems;\
    QList<IntPriemniciDetailT> resFakturaItems_oldData;\


    QList<int> colDetailWidth;
    void procDeleteItem();
    bool procAddItem();
    void showData();
    int m_row;
    QItemSelectionModel *sm;
    QItemSelectionModel *smDetail;
    QCBItemDelegate *comboboxD;
    QLEItemDelegate *lineeditD;
    QString str_yellow;
    QString str_none;
    QString strDisabled;
    QModelIndex m_index;
    bool statusOpenEditor;
    void OpenTablePersistentEditor(QTableView * table, QModelIndex &index);
    void CloseTablePersistentEditor(QTableView * table, QModelIndex &index);
protected:
    bool eventFilter(QObject *obj, QEvent *ev);

signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void selectionChanged(QModelIndex modelX,QModelIndex modelY);
    void selectionChangedDetail(QModelIndex modelX,QModelIndex modelY);
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void updateStructCellLineEdit(const QModelIndex & index, QString & value) ;
    void on_pushButton_4_clicked();
};

#endif // IntPriemniciKOREKCIJA_H
