#include "printerlista.h"
#include "ui_printerlista.h"



PrinterLista::PrinterLista(BaseForm *parent) :
    BaseForm(parent),
    webview(0),
    faktor(1),
    ui(new Ui::PrinterLista)
{
    ui->setupUi(this);

    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    page = new QWebEnginePage();
    webview = new QWebEngineView(ui->widget);
    ui->gridLayout->addWidget(webview);
    connect(page, SIGNAL(loadFinished(bool)),this, SLOT(showLoad(bool)));
    PrintDocumentText();
}

PrinterLista::~PrinterLista()
{
    delete ui;

}

void PrinterLista::printPDF()
{
}


// reading a text file

void PrinterLista::PrintDocumentText()
{
    QString text = GetBaseText();

    page->setHtml(text);
    page->setView(webview);
}


void PrinterLista::showLoad(bool a)
{
    webview->hide();
    webview->show();
    disconnect(page, SIGNAL(loadFinished(bool)),this,  SLOT(showLoad(bool)));
    emit finishedPrinting_();
}

void PrinterLista::pressEscape()
{
    emit signalpressEscape();
}

void PrinterLista::on_toolButton_clicked()
{
    pressEscape();
}

void PrinterLista::on_toolButton_2_clicked()
{
    QString fileName = "l.pdf";
//    page->printToPdf(fileName);
    QProcess sh;
    sh.start("acroread", QStringList() << "/h /p" << "l.pdf" );

    sh.waitForFinished();
    sh.close();
}
void PrinterLista::on_toolButton_3_clicked()
{
    faktor *= 0.9;
    page->setZoomFactor(faktor);
}

void PrinterLista::on_toolButton_4_clicked()
{
    faktor *= 1.1;
    page->setZoomFactor(faktor);
}
