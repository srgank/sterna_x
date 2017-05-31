#ifndef IntIspratnici_H
#define IntIspratnici_H

#include "Base/baseform.h"
#include "int_ispratnicavnes.h"
#include "int_ispratnicakorekcija.h"
#include "int_ispratnicalista.h"

namespace Ui {
class IntIspratnici;
}

class IntIspratnici : public BaseForm
{
    Q_OBJECT

public:
    explicit IntIspratnici(BaseForm *parent = 0);
    ~IntIspratnici();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    IntIspratnici_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::IntIspratnici *ui;
    IntIspratniciLista        *m_IntIspratniciLista;
    IntIspratniciVnes         *m_IntIspratniciVnes;
    IntIspratniciKorekcija    *m_IntIspratniciKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    IntIspratnici_trans m_data;

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

#endif // IntIspratnici_H
