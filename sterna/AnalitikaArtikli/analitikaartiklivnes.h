#ifndef AnalitikaArtikliVNES_H
#define AnalitikaArtikliVNES_H

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
class AnalitikaArtikliVnes;
}

class AnalitikaArtikliVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit AnalitikaArtikliVnes(BaseForm *parent = 0);
    ~AnalitikaArtikliVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    virtual void updateFont();
    void Refresh();
    void initProc(AnalitikaArtikli_trans m_data);
    void setFocusKomintent(komintentT t);
    void setFocusArtikal(artikalT t);

private:
    Ui::AnalitikaArtikliVnes *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QBTemplate<AnalitikaArtikliT> *b;
    QBTemplate<AnalitikaArtikliDetailT> *bd;
    AnalitikaArtikliT resFaktura;
    QList<AnalitikaArtikliDetailT> resFakturaItems;\
    QList<int> colDetailWidth;
    void procDeleteItem();
    bool procAddItem();
    void showData();
    int m_row;
    QItemSelectionModel *sm;
    QString strDisabled;
    QString str_yellow;
    QString str_none;
    QCBItemDelegate *comboboxD;
    QLEItemDelegate *lineeditD;
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
    void on_pushButton_released();
    void selectionChanged(QModelIndex modelX,QModelIndex modelY);
    void selectionChangedDetail(QModelIndex modelX,QModelIndex modelY);

    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void updateStructCellLineEdit(const QModelIndex & index, QString & value) ;

    void on_pushButton_4_clicked();
};

#endif // AnalitikaArtikliVNES_H
