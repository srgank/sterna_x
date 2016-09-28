#ifndef PRINTERLISTA_H
#define PRINTERLISTA_H
#include "Base/baseform.h"
#include <QWidget>
#include <QPrinter>
#include "Print/printerlista.h"
#include <QWebEngineView>



namespace Ui {
class PrinterLista;
}

class PrinterLista : public BaseForm
{
    Q_OBJECT

public:
    explicit PrinterLista(BaseForm *parent = 0);
    ~PrinterLista();
    void printPDF();
    virtual void pressEscape();

private:
    Ui::PrinterLista *ui;
signals:
    void signalpressEscape();
};

#endif // PRINTERLISTA_H
