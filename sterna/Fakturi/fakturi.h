#ifndef Fakturi_H
#define Fakturi_H

#include "Base/baseform.h"
#include "fakturivnes.h"
#include "fakturikorekcija.h"
#include "fakturilista.h"

namespace Ui {
class Fakturi;
}

class Fakturi : public BaseForm
{
    Q_OBJECT

public:
    explicit Fakturi(BaseForm *parent = 0);
    ~Fakturi();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Fakturi *ui;
    FakturiLista        *m_FakturiLista;
    FakturiVnes         *m_FakturiVnes;
    FakturiKorekcija    *m_FakturiKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    faktura_trans m_data;


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

#endif // Fakturi_H
