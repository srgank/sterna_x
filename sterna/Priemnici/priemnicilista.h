#ifndef PriemniciLISTA_H
#define PriemniciLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"
#include "qbtemplate.h"

#define COL 27
#define COL_DETAIL 28
namespace Ui {
class PriemniciLista;
}

class PriemniciLista : public BaseForm
{
    Q_OBJECT

public:
    explicit PriemniciLista(BaseForm *parent = 0);
    ~PriemniciLista();
    virtual void pressF2();
    virtual void pressF3();

    virtual void pressEscape();

    void setTableColumnWidths(int ccolumn);
    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);
    QString getSearchString();
    void setSearchString(QString& searchText);
    void ShowData(QStringList& tlist);
    void ShowDataDetail(QStringList& tlist);

private:
    QItemSelectionModel *sm;
    Ui::PriemniciLista *ui;
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
    QBTemplate<dokumentT> b;
    QBTemplate<dokumentDetailT> bd;
signals:
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent();
    void signalpressEscape();
    void signalpressF2();
    void signalpressF3();

public slots:
    void procReturn(QString);

private slots:
    void on_pushButton_5_clicked();
    void on_LE_prebaraj_textChanged(const QString &arg1);
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);
    void procSectionResizedDetail(int a, int b, int c);

    void on_pushButton_4_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // PriemniciLISTA_H
