#ifndef Lager_H
#define Lager_H

#include "Base/baseform.h"
#include "lagervnes.h"
#include "lagerkorekcija.h"
#include "lagerlista.h"

namespace Ui {
class Lager;
}

class Lager : public BaseForm
{
    Q_OBJECT

public:
    explicit Lager(BaseForm *parent = 0);
    ~Lager();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    Lager_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::Lager *ui;
    LagerLista        *m_LagerLista;
    LagerVnes         *m_LagerVnes;
    LagerKorekcija    *m_LagerKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    Lager_trans m_data;

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

#endif // Lager_H
