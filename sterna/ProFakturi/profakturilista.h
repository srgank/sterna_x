#ifndef ProFakturiLISTA_H
#define ProFakturiLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"
#include "qbtemplate.h"
#include <QMutex>

#define COL 27
#define COL_DETAIL 28

namespace Ui {
class ProFakturiLista;
}

class ProFakturiLista : public BaseForm
{
    Q_OBJECT

public:
    explicit ProFakturiLista(BaseForm *parent = 0);
    ~ProFakturiLista();
    virtual void pressF2();
    virtual void pressF3();

    virtual void pressEscape();

    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);

    QString getSearchString();
    void setSearchString(QString& searchText);

    profaktura_trans getProFakturaData();

    int geTableSelected_Offset(){return numOffset;}
    void seTableSelected_Offset(int t_numOffset){numOffset = t_numOffset;}
    void initProc(int searchIDList, QString& searchStrList, int searchOffsetList);

private:
    Ui::ProFakturiLista *ui;
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
    QBTemplate<profakturiT> b;
    QBTemplate<dokumentDetailT> bd;
    QBTemplate<profakturiDetailT> bc;
    QItemSelectionModel *sm;
    QMutex mio_;
    QList<profakturiT> resFakturaTemp;
    profakturiT currentData;
    QList<profakturiDetailT> resFakturaDetailTemp;


signals:
    void signalpressF2();
    void signalpressF3();
    void signalpressEscape();

private slots:
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);
    void procSectionResizedDetail(int a, int b, int c);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pb_vnesi_nov_clicked();
    void on_pb_koregiraj_postoecki_clicked();
};

#endif // ProFakturiLISTA_H
