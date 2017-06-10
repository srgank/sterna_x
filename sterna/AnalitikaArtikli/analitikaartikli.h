#ifndef AnalitikaArtikli_H
#define AnalitikaArtikli_H

#include "Base/baseform.h"
#include "analitikaartiklivnes.h"
#include "analitikaartiklikorekcija.h"
#include "analitikaartiklilista.h"

namespace Ui {
class AnalitikaArtikli;
}

class AnalitikaArtikli : public BaseForm
{
    Q_OBJECT

public:
    explicit AnalitikaArtikli(BaseForm *parent = 0);
    ~AnalitikaArtikli();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    AnalitikaArtikli_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::AnalitikaArtikli *ui;
    AnalitikaArtikliLista        *m_AnalitikaArtikliLista;
    AnalitikaArtikliVnes         *m_AnalitikaArtikliVnes;
    AnalitikaArtikliKorekcija    *m_AnalitikaArtikliKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    AnalitikaArtikli_trans m_data;

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

#endif // AnalitikaArtikli_H
