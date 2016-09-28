#include "printerlista.h"
#include "ui_printerlista.h"

PrinterLista::PrinterLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::PrinterLista)
{
    ui->setupUi(this);
    setWindowModality(Qt::WindowModal);
    printPDF();
    PressKeyReturn(this);

}

PrinterLista::~PrinterLista()
{
    delete ui;
}

void PrinterLista::printPDF()
{

    QPrinter printer(QPrinter::HighResolution);

    // Create webview and load html source
    QWebEngineView *webview = new QWebEngineView(0);
    webview->resize(1024, 750);
    QString htmlinput = "<P>TEEEEEEE 777777777777777777777777777 EEEEEEEEEEE</P>";
    webview->setHtml(htmlinput);
    webview->show();
    webview->repaint();
}

void PrinterLista::pressEscape()
{
    emit signalpressEscape();
}
