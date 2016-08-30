#ifndef ARTIKLILISTA_H
#define ARTIKLILISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"
#include "Struct/struct.h"
#include "qbtemplate.h"

#define COL 9

namespace Ui {
class ArtikliLista;
}

class ArtikliLista : public BaseForm
{
    Q_OBJECT

public:
    explicit ArtikliLista(BaseForm *parent = 0);
    ~ArtikliLista();
    virtual void pressF2();
    virtual void pressF3();

    virtual void pressEscape();
    virtual void pressReturn();

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
    artikalT artS;

private:
//    void ShowData(QList<artikalT>&);

    Ui::ArtikliLista *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    int numOffset;
    int colWidth[COL];
    QString m_selectedID;
    int m_row;

    QString searchStrList;
    int searchIDList;
    QBTemplate<artikalT> b;
signals:
    void signalpressF2();
    void signalpressF3();
    void signalpressEscape();
    void signalReturnResult(QString);

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_LE_prebaraj_textChanged(const QString &arg1);
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);
    void on_pb_vnesi_nov_clicked();
    void on_pb_koregiraj_postoecki_clicked();
};

#endif // ARTIKLILISTA_H
