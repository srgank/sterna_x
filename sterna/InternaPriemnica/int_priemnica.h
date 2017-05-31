#ifndef IntPriemnici_H
#define IntPriemnici_H

#include "Base/baseform.h"
#include "int_priemnicavnes.h"
#include "int_priemnicakorekcija.h"
#include "int_priemnicalista.h"

namespace Ui {
class IntPriemnici;
}

class IntPriemnici : public BaseForm
{
    Q_OBJECT

public:
    explicit IntPriemnici(BaseForm *parent = 0);
    ~IntPriemnici();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    IntPriemnici_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::IntPriemnici *ui;
    IntPriemniciLista        *m_IntPriemniciLista;
    IntPriemniciVnes         *m_IntPriemniciVnes;
    IntPriemniciKorekcija    *m_IntPriemniciKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    IntPriemnici_trans m_data;

private slots:
    void pressF2FromLista();
    void pressF3FromLista();
    void pressEscapeFromLista();
    void pressEscapeFromVnes();
    void pressEscapeFromKorekcija();
    void procSentGetArtikal(QString text, QWidget* p);
    void procSentGetKomintent(QString text, QWidget* p);

signals:
    void signCloseMyWidget();
    void signArtikal(QString, QWidget* );
    void signKomintent(QString, QWidget*);
    void eupdateNanigator(QWidget*, QWidget*);
};

#endif // IntPriemnici_H
