#ifndef IntIspratniciLISTA_H
#define IntIspratniciLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"


#include "xx.h"
#include "qbtemplate.h"

#define COL 27
#define COL_DETAIL 28

namespace Ui {
class IntIspratniciLista;
}

class IntIspratniciLista : public BaseForm
{
    Q_OBJECT

public:
    explicit IntIspratniciLista(BaseForm *parent = 0);
    ~IntIspratniciLista();
    virtual void pressF2();
    virtual void pressF3();

    virtual void pressEscape();
    virtual void updateFont();
    virtual void Refresh();
    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);

    QString getSearchString();
    void setSearchString(QString& searchText);

    IntIspratnici_trans getFakturaData();

    int geTableSelected_Offset(){return numOffset;}
    void seTableSelected_Offset(int t_numOffset){numOffset = t_numOffset;}
    void initProc(int searchIDList, QString& searchStrList, int searchOffsetList);

private:
    Ui::IntIspratniciLista *ui;
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

    QBTemplate<IntIspratniciT> *b;
    QBTemplate<dokumentDetailT> *bd;
    QBTemplate<IntIspratniciDetailT> *bc;

    QItemSelectionModel *sm;

    QList<IntIspratniciT> resFakturaTemp;
    IntIspratniciT currentData;
    QList<IntIspratniciDetailT> resFakturaDetailTemp;
    QString str_yellow;
    QString str_none;
    bool enableClose;
protected:
    bool eventFilter(QObject *object, QEvent *event);
signals:
    void signalpressF2();
    void signalpressF3();
    void signalpressEscape();

private slots:
    void selectionChanged(QModelIndex,QModelIndex);
    void procSectionResized(int a, int b, int c);
    void procSectionResizedDetail(int a, int b, int c);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_prebaruvanje_po_komintent_textChanged(const QString &arg1);
};

#endif // IntIspratniciLISTA_H
