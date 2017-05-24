#ifndef Nalog_H
#define Nalog_H

#include "Base/baseform.h"
#include "nalogvnes.h"
#include "nalogkorekcija.h"
#include "naloglista.h"

namespace Ui {
class Nalog;
}

class Nalog : public BaseForm
{
    Q_OBJECT

public:
    explicit Nalog(BaseForm *parent = 0);
    ~Nalog();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void Refresh();
    Nalog_trans& getFaktTransData();

    void closeAllForm();

private:
    Ui::Nalog *ui;
    NalogLista        *m_NalogLista;
    NalogVnes         *m_NalogVnes;
    NalogKorekcija    *m_NalogKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;
    QString searchStrList;
    int searchIDList;
    int searchOffsetList;
    Nalog_trans m_data;

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

#endif // Nalog_H
