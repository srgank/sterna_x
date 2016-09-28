#include "printerlista.h"
#include "ui_printerlista.h"

PrinterLista::PrinterLista(BaseForm *parent) :
    BaseForm(parent),
    webview(0),
    ui(new Ui::PrinterLista)
{
    ui->setupUi(this);

    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));


    webview = new QWebEngineView(ui->widget);
    ui->gridLayout->addWidget(webview);
    connect(webview, SIGNAL(loadFinished(bool)), SLOT(showLoad(bool)));
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
    QString htmlinput = readFile();

    webview->setHtml(htmlinput);
}


// reading a text file

QString PrinterLista::readFile()
{
    QString out;
    string line;
  ifstream myfile ("invoice.txt");
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
