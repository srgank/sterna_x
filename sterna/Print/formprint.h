#ifndef FORMPRINT_H
#define FORMPRINT_H
#include "Base/baseform.h"
#include <QWidget>
#include "Print/printerlista.h"


namespace Ui {
class FormPrint;
}

class FormPrint : public BaseForm
{
    Q_OBJECT

public:
    explicit FormPrint(BaseForm *parent = 0);
    ~FormPrint();
    virtual void pressEscape();

    void pressF4();

private:
    Ui::FormPrint *ui;
    PrinterLista *m_PrinterLista;
signals:
    void signCloseMyWidget();
private slots:
    void pressEscapeFromLista();

};

#endif // FORMPRINT_H


