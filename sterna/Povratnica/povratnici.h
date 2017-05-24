#ifndef Povratnici_H
#define Povratnici_H

#include "Base/baseform.h"
#include "povratnicivnes.h"
#include "povratnicikorekcija.h"
#include "povratnicilista.h"

namespace Ui {
class Povratnici;
}

class Povratnici : public BaseForm
{
    Q_OBJECT

public:
    explicit Povratnici(BaseForm *parent = 0);
    ~Povratnici();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    Povratnici_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::Povratnici *ui;
    PovratniciLista        *m_PovratniciLista;
    PovratniciVnes         *m_PovratniciVnes;
    PovratniciKorekcija    *m_PovratniciKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    Povratnici_trans m_data;

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

#endif // Povratnici_H
