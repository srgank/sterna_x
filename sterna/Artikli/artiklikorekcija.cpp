#include "artiklikorekcija.h"
#include "ui_artiklikorekcija.h"

ArtikliKorekcija::ArtikliKorekcija(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    ui(new Ui::ArtikliKorekcija)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();
    str_yellow = "background-color: yellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    BaseInstallEventFilter(ui->gridLayout);
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    connect(this, SIGNAL(finishKorekcija()),this, SLOT(procFinishKorekcija()));
    ui->sifraArtikalEdit->installEventFilter(this);
    ui->nazivArtikalEdit->installEventFilter(this);
    ui->edmArtikalEdit->installEventFilter(this);
    ui->ddvCombo->installEventFilter(this);
    ui->kataloskiArtikalEdit->installEventFilter(this);
    ui->refArtikalEdit->installEventFilter(this);
    ui->kataloskiArtikalEdit->installEventFilter(this);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

ArtikliKorekcija::~ArtikliKorekcija()
{
    delete ui;
    delete hlp;
}
void ArtikliKorekcija::pressEscape()
{
    emit signalpressEscape();
}

void ArtikliKorekcija::initProc(QString m_searchID)
{
    statusWait = true;
    ui->pushButton->setEnabled(true);
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "id";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    artikalT itemRecord = res.at(0);
    artikal_id = m_searchID;
    ui->sifraArtikalEdit->setText(itemRecord.sifra);
    ui->nazivArtikalEdit->setText(itemRecord.artikal);
    ui->edmArtikalEdit->setText(itemRecord.edm);
    ui->refArtikalEdit->setText(itemRecord.ref);
    ui->kataloskiArtikalEdit->setText(itemRecord.kataloski_broj);
    ui->kataloskiArtikalEdit_2->setText(itemRecord.proizvoditel);
    ui->kataloskiArtikalEdit_3->setText(itemRecord.kategorija);
    int stop = 0;
}
//getResultEXUpdate
void ArtikliKorekcija::on_pushButton_released()
{

    QString blankText = "";
    QString blankDdv = "18";
    art_temp.id = artikal_id;
    art_temp.sifra = ui->sifraArtikalEdit->text();
    art_temp.artikal = ui->nazivArtikalEdit->text();
    art_temp.edm = ui->edmArtikalEdit->text();
    art_temp.ref = ui->refArtikalEdit->text();
    art_temp.kataloski_broj = ui->kataloskiArtikalEdit->text();
    art_temp.ddv = ui->ddvCombo->lineEdit()->text();
    art_temp.proizvoditel = ui->kataloskiArtikalEdit_2->text();
    art_temp.kategorija = ui->kataloskiArtikalEdit_3->text();

    hlp->UpdateArtikal(art_temp);
    pressEscape();
}

void ArtikliKorekcija::pressEnter()
{
    pressReturn();
}

void ArtikliKorekcija::pressReturn()
{
    if(ui->pushButton->hasFocus())
    {
//        on_pushButton_clicked();
    }
    else if(ui->sifraArtikalEdit->hasFocus()){
        on_SifraArtikalEdit_EditingFinished();
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}


void ArtikliKorekcija::on_SifraArtikalEdit_EditingFinished()
{
    int numOffset = 0;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->sifraArtikalEdit->text();
    QString vSearchBy = "sifra";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    if (res.count() != 0) {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setWindowTitle(trUtf8("Information"));
        msgBox->setText(trUtf8("Постои артикал со таа шифра"));
        msgBox->setStandardButtons(QMessageBox::Yes);
        msgBox->setDefaultButton(QMessageBox::Yes);
        msgBox->exec();
        delete msgBox;
        ui->sifraArtikalEdit->setFocus();
    }else{
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}

bool ArtikliKorekcija::eventFilter(QObject *object, QEvent *event)
{
    Singleton *s = Singleton::Instance();
    if (event->type() == QEvent::FocusIn)
    {
        str_yellow = "background-color: lightyellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
        ((QWidget*)object)->setStyleSheet(str_yellow);
    }
    if (event->type() == QEvent::FocusOut)
    {
        str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
        ((QWidget*)object)->setStyleSheet(str_none);
    }
    return false;
}
