#include "artiklivnes.h"
#include "ui_artiklivnes.h"

ArtikliVnes::ArtikliVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ArtikliVnes)
    ,hlp(0)

{
    ui->setupUi(this);
    ui->sifraArtikalEdit->setFocus();
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    hlp = new QHelperC(this);
    connect(hlp, SIGNAL(signalResultInsertArticle(QStringList &)), this, SLOT(getResultEX(QStringList &)));
}

ArtikliVnes::~ArtikliVnes()
{
    delete hlp;
    delete ui;
}
void ArtikliVnes::pressEscape()
{
    emit signalpressEscape();
}



void ArtikliVnes::getResultEX(QStringList& tlist)
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(trUtf8("Information"));
    msgBox->setText(trUtf8("Податокот е успешно внесен"));
    msgBox->setStandardButtons(QMessageBox::Yes);
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->exec();
    delete msgBox;
    setFocus();
    ui->pushButton->setEnabled(true);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}


void ArtikliVnes::on_pushButton_clicked()
{

    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->sifraArtikalEdit->text();
    QString a2 = ui->nazivArtikalEdit->text();
    QString a3 = ui->edmArtikalEdit->text();
    QString a4 = ui->kataloskiArtikalEdit->text();
    QString a5 = ui->refArtikalEdit->text();

//
}

void ArtikliVnes::pressEnter()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void ArtikliVnes::pressReturn()
{
    if(ui->pushButton->hasFocus())
    {
        on_pushButton_clicked();
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}
