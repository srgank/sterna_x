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
    webview->setFocusPolicy(Qt::StrongFocus );
    webview->setFocus();
    ui->gridLayout->addWidget(webview);
    connect(page, SIGNAL(loadFinished(bool)),this, SLOT(showLoad(bool)));
    connect(webview, SIGNAL(windowCloseRequested()), this,SLOT(CloseProc()));
    PrintDocumentText();
}

PrinterLista::~PrinterLista()
{
    delete ui;
    delete page;
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

    page->setHtml(text, baseUrl);
    page->setView(webview);
}


void PrinterLista::showLoad(bool a)
{
    webview->hide();
    webview->show();
    SavePdf();
}

void PrinterLista::SavePdf()
{
    QString fileName = "l.pdf";
    page->printToPdf(fileName);
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
    QProcess sh;
    sh.waitForStarted(1000);
    sh.start("acroread", QStringList() << "/n /s /o /h " << "l.pdf" );
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

void PrinterLista::CloseProc()
{

}

void PrinterLista::wheelEvent ( QWheelEvent * event )
{

}
