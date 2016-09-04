#ifndef FakturiLISTA_H
#define FakturiLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"
#include "qbtemplate.h"

#define COL 27
#define COL_DETAIL 28

namespace Ui {
class FakturiLista;
}

class FakturiLista : public BaseForm
{
    Q_OBJECT

public:
    explicit FakturiLista(BaseForm *parent = 0);
    ~FakturiLista();
    virtual void pressF2();
    virtual void pressF3();

    virtual void pressEscape();

    void setTableColumnWidths(int ccolumn);
    void getTableColumnWidths(int ccolumn);
    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);
    QString getSearchString();
    void setSearchString(QString& searchText);

private:
    Ui::FakturiLista *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QStandardItemModel *model_2;
    QHeaderView *header_2;
    QHelperC *hlp;
    int numOffset;
    QString m_selectedID;
    int m_row;
    QList<int> colWidth;
    QList<int> colDetailWidth;
    QBTemplate<fakturiT> c;
    QBTemplate<fakturiT> b;
    QBTemplate<dokumentDetailT> bd;
    QItemSelectionModel *sm;

signals:
    void signalpressF2();
    void signalpressF3();
    void signalpressEscape();

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_LE_prebaraj_textChanged(const QString &arg1);
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);
    void procSectionResizedDetail(int a, int b, int c);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pb_vnesi_nov_clicked();
    void on_pb_koregiraj_postoecki_clicked();
};

#endif // FakturiLISTA_H
