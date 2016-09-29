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

    page = new QWebEnginePage;
    webview = new QWebEngineView(ui->widget);
    ui->gridLayout->addWidget(webview);
    connect(page, SIGNAL(loadFinished(bool)), SLOT(showLoad(bool)));
    printPDF();
    PressKeyReturn(this);

}

PrinterLista::~PrinterLista()
{
    delete ui;
}

void PrinterLista::printPDF()
{
//    QPrinter printer(QPrinter::HighResolution);
//    printer.setOutputFormat(QPrinter::PdfFormat);
//    printer.setOutputFileName("outputt.pdf");
    // Create webview and load html source

    QString htmlinput = readFile();
    page->setHtml(htmlinput);
    page->setView(webview);
    // *textEdit must remain valid until the lambda function is called.
}


// reading a text file

QString PrinterLista::readFile()
{
    QString out;
    string line;
  ifstream myfile ("invoice.htm");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      out +=  QString::fromStdString(line);
    }
    myfile.close();
  }
  return out;
}

void PrinterLista::showLoad(bool a)
{
    webview->hide();
    webview->show();
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
    page->printToPdf(fileName);
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
