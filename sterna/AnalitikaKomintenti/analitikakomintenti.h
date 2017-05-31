#ifndef AnalitikaKomintenti_H
#define AnalitikaKomintenti_H

#include "Base/baseform.h"
#include "analitikakomintentivnes.h"
#include "analitikakomintentikorekcija.h"
#include "analitikakomintentilista.h"

namespace Ui {
class AnalitikaKomintenti;
}

class AnalitikaKomintenti : public BaseForm
{
    Q_OBJECT

public:
    explicit AnalitikaKomintenti(BaseForm *parent = 0);
    ~AnalitikaKomintenti();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    AnalitikaKomintenti_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::AnalitikaKomintenti *ui;
    AnalitikaKomintentiLista        *m_AnalitikaKomintentiLista;
    AnalitikaKomintentiVnes         *m_AnalitikaKomintentiVnes;
    AnalitikaKomintentiKorekcija    *m_AnalitikaKomintentiKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    AnalitikaKomintenti_trans m_data;

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

#endif // AnalitikaKomintenti_H
