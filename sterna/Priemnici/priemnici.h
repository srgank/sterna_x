#ifndef Priemnici_H
#define Priemnici_H

#include "Base/baseform.h"
#include "priemnicivnes.h"
#include "priemnicikorekcija.h"
#include "priemnicilista.h"

namespace Ui {
class Priemnici;
}

class Priemnici : public BaseForm
{
    Q_OBJECT

public:
    explicit Priemnici(BaseForm *parent = 0);
    ~Priemnici();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    Priemnici_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::Priemnici *ui;
    PriemniciLista        *m_PriemniciLista;
    PriemniciVnes         *m_PriemniciVnes;
    PriemniciKorekcija    *m_PriemniciKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    Priemnici_trans m_data;

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

#endif // Priemnici_H
