#include "komintentivnes.h"
#include "ui_komintentivnes.h"

KomintentiVnes::KomintentiVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::KomintentiVnes)
{
    ui->setupUi(this);
    Singleton *s = Singleton::Instance();
    str_yellow = "background-color: yellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";

    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    hlp = new QHelperC(this);

    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

bool KomintentiVnes::eventFilter(QObject *sender, QEvent *event)
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
//        if (sender == ui->sifraArtikalEdit)
//        {
//           ui->sifraArtikalEdit->setStyleSheet(str_yellow);
//        }
//        if (sender == ui->nazivArtikalEdit)
//        {
//            ui->nazivArtikalEdit->setStyleSheet(str_yellow);
//        }
//        if (sender == ui->edmArtikalEdit)
//        {
//            ui->edmArtikalEdit->setStyleSheet(str_yellow);
//        }
//        if (sender == ui->refArtikalEdit)
//        {
//            ui->refArtikalEdit->setStyleSheet(str_yellow);
//        }
//        if (sender == ui->kataloskiArtikalEdit)
//        {
//            ui->kataloskiArtikalEdit->setStyleSheet(str_yellow);
//        }
    }

    if (event->type() == QEvent::FocusOut)
    {

//        if (sender == ui->sifraArtikalEdit)
//        {
//            ui->sifraArtikalEdit->setStyleSheet(str_none);
//        }
//        if (sender == ui->nazivArtikalEdit)
//        {
//            ui->nazivArtikalEdit->setStyleSheet(str_none);
//        }
//        if (sender == ui->edmArtikalEdit)
//        {
//            ui->edmArtikalEdit->setStyleSheet(str_none);
//        }
//        if (sender == ui->refArtikalEdit)
//        {
//            ui->refArtikalEdit->setStyleSheet(str_none);
//        }
//        if (sender == ui->kataloskiArtikalEdit)
//        {
//            ui->kataloskiArtikalEdit->setStyleSheet(str_none);
//        }
    }

return QWidget::eventFilter(sender,event);

}


KomintentiVnes::~KomintentiVnes()
{
    delete hlp;
    delete ui;
}
void KomintentiVnes::pressEscape()
{
    emit signalpressEscape();
}


void KomintentiVnes::on_pushButton_clicked()
{
    komintentT komItem;
    QString blankText = "";
    QString blankDdv = "18";
    komItem.sifra = ui->sifra_Edit->text();
    komItem.naziv = ui->naziv_Edit->text();
    komItem.adresa = ui->adresa_Edit->text();
    komItem.tel = ui->tefefon_Edit->text();
    komItem.mobil = ui->mobilen_Edit->text();
    komItem.zirosmetka = ui->ziro_Edit->text();
    komItem.edb = ui->edb_Edit->text();
    komItem.deponent = ui->banka_Edit->text();
    komItem.sifra_dejnost = ui->dejnost_Edit->text();
    komItem.mb = ui->maticen_Edit->text();
    komItem.zabeleska1 = "";
    komItem.zabeleska2 = "";
    komItem.rabat = ui->rabat_Edit->text();
    komItem.grad = ui->grad_Edit->text();
    hlp->InsertKomintent(komItem);
    pressEscape();
}

void KomintentiVnes::pressEnter()
{
    pressReturn();
}

void KomintentiVnes::pressReturn()
{
    if(ui->pushButton->hasFocus())
    {
        on_pushButton_clicked();
    }
    else if(ui->sifra_Edit->hasFocus()){
        on_SifraKomintentEdit_EditingFinished();
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}



void KomintentiVnes::on_SifraKomintentEdit_EditingFinished()
{
    int numOffset = 0;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->sifra_Edit->text();
    QString vSearchBy = "sifra";
    QList<komintentT> res = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    if (res.count() != 0) {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setWindowTitle(trUtf8("Information"));
        msgBox->setText(trUtf8("Постои коминтент со таа шифра"));
        msgBox->setStandardButtons(QMessageBox::Yes);
        msgBox->setDefaultButton(QMessageBox::Yes);
        msgBox->exec();
        delete msgBox;
        ui->sifra_Edit->setFocus();
    }else{
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}
