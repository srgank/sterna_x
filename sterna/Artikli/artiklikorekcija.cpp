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
}


bool ArtikliKorekcija::eventFilter(QObject *sender, QEvent *event)
{

    if(event->type()== QEvent::KeyPress)
    {
        QKeyEvent * keyEvent = (QKeyEvent*)(event);
        if( keyEvent->key() == Qt::Key_Tab)
        {
            pressReturn();
            return true;
        }else
        {
             return false;
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if (sender == ui->sifraArtikalEdit)
        {
           ui->sifraArtikalEdit->setStyleSheet(str_yellow);
        }
        if (sender == ui->nazivArtikalEdit)
        {
            ui->nazivArtikalEdit->setStyleSheet(str_yellow);
        }
        if (sender == ui->edmArtikalEdit)
        {
            ui->edmArtikalEdit->setStyleSheet(str_yellow);
        }
        if (sender == ui->refArtikalEdit)
        {
            ui->refArtikalEdit->setStyleSheet(str_yellow);
        }
        if (sender == ui->kataloskiArtikalEdit)
        {
            ui->kataloskiArtikalEdit->setStyleSheet(str_yellow);
        }
    }

    if (event->type() == QEvent::FocusOut)
    {

        if (sender == ui->sifraArtikalEdit)
        {
            ui->sifraArtikalEdit->setStyleSheet(str_none);
        }
        if (sender == ui->nazivArtikalEdit)
        {
            ui->nazivArtikalEdit->setStyleSheet(str_none);
        }
        if (sender == ui->edmArtikalEdit)
        {
            ui->edmArtikalEdit->setStyleSheet(str_none);
        }
        if (sender == ui->refArtikalEdit)
        {
            ui->refArtikalEdit->setStyleSheet(str_none);
        }
        if (sender == ui->kataloskiArtikalEdit)
        {
            ui->kataloskiArtikalEdit->setStyleSheet(str_none);
        }
    }

return QWidget::eventFilter(sender,event);

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
    ui->pushButton->setEnabled(false);
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "sifra";
    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}
//getResultEXUpdate
void ArtikliKorekcija::on_pushButton_released()
{
    statusWait = true;
    ui->pushButton->setEnabled(false);
    QString blankText = "";
    QString blankDdv = "18";
    //
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
    QStringList res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
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
