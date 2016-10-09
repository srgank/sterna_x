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
    webview = new QWebView(ui->widget);
    webview->setFixedSize(QSize(rMain.width()-10, rMain.height()-80));
    ui->gridLayout->addWidget(webview);

    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    connect(webview, SIGNAL(loadFinished(bool)),this, SLOT(showLoad(bool)));
}

PrinterLista::~PrinterLista()
{
    delete ui;
    delete webview;
}



void PrinterLista::printPDF()
{
}


// reading a text file

void PrinterLista::PrintDocumentText()
{
    QString text = GetBaseText();
    QUrl baseUrl = QUrl::fromLocalFile(QDir::current().absoluteFilePath("logo.png"));

    webview->setHtml(text, baseUrl);
//    page->setView(webview);
}


void PrinterLista::showLoad(bool a)
{
    webview->hide();
    webview->show();

}

void PrinterLista::SavePdf()
{
    QPrinter printer(QPrinter::HighResolution); //create your QPrinter (don't need to be high resolution, anyway)
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    webview->print(&printer);
}

void PrinterLista::pressReturn()
{
    emit signalpressEscape();
}

void PrinterLista::on_toolButton_clicked()
{
    pressReturn();
}

void PrinterLista::on_toolButton_2_clicked()
{
//    QProcess sh;
//    sh.waitForStarted(1000);
//    sh.start("acroread", QStringList() << "/n /s /o /h " << "l.pdf" );
//    sh.waitForFinished();
//    sh.close();
    SavePdf();
}

void PrinterLista::on_toolButton_3_clicked()
{
    faktor *= 0.9;
    webview->setZoomFactor(faktor);
}

void PrinterLista::on_toolButton_4_clicked()
{
    faktor *= 1.1;
    webview->setZoomFactor(faktor);
}

void PrinterLista::CloseProc()
{

}

void PrinterLista::wheelEvent ( QWheelEvent * event )
{

}
