#ifndef KomintentiLISTA_H
#define KomintentiLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"
#include "qbtemplate.h"

#define COL 15

namespace Ui {
class KomintentiLista;
}

class KomintentiLista : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiLista(BaseForm *parent = 0);
    ~KomintentiLista();
    virtual void pressF2();
    virtual void pressF3();
    void pressReturn();
    virtual void pressEscape();
    virtual void updateFont();
    void setTableColumnWidths(int ccolumn);
    void getTableColumnWidths(int ccolumn);
    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);
    QString getSearchString();
    void setSearchString(QString& searchText);
    void initProc(int searchIDList, QString& searchStrList, int searchOffsetList);

    int geTableSelected_Offset(){return numOffset;}
    void seTableSelected_Offset(int t_numOffset){numOffset = t_numOffset;}



private:
    Ui::KomintentiLista *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    int numOffset;
    QList<int> colWidth;
    QString m_selectedID;
    int m_row;
    QBTemplate<komintentT> b;
    QItemSelectionModel *sm;
    QList<komintentT> resKomintentTemp;
    QString str_yellow;
    QString str_none;
protected:
    bool eventFilter(QObject *object, QEvent *event);
signals:
    void signalpressF2();
    void signalpressF3();
    void signalpressEscape();
    void signalReturnResult(komintentT);

private slots:

    void on_pushButton_5_clicked();
    void on_LE_prebaraj_textChanged(const QString &arg1);
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);

    void on_pushButton_4_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_lineEditPrebaraj_textChanged(const QString &arg1);
};

#endif // KomintentiLISTA_H
