#include "komintentikorekcija.h"
#include "ui_komintentikorekcija.h"

KomintentiKorekcija::KomintentiKorekcija(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    ui(new Ui::KomintentiKorekcija)
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
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}


bool KomintentiKorekcija::eventFilter(QObject *sender, QEvent *event)
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



KomintentiKorekcija::~KomintentiKorekcija()
{
    delete ui;
    delete hlp;
}
void KomintentiKorekcija::pressEscape()
{
    emit signalpressEscape();
}

void KomintentiKorekcija::initProc(QString m_searchID)
{
    statusWait = true;
    ui->pushButton->setEnabled(false);
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "sifra";
    QStringList res = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    QStringList itemRecord = res.at(0).split("#;#");
    kom_temp.sifra = itemRecord.at(0);
    kom_temp.naziv = itemRecord.at(1);
    kom_temp.adresa = itemRecord.at(2);
    kom_temp.tel = itemRecord.at(3);
    kom_temp.mobil = itemRecord.at(4);
    kom_temp.ziro = itemRecord.at(5);
    kom_temp.edb = itemRecord.at(6);
    kom_temp.deponent = itemRecord.at(7);
    kom_temp.sifradejnost = itemRecord.at(8);
    kom_temp.mb = itemRecord.at(9);
    kom_temp.zabeleska1 = itemRecord.at(10);
    kom_temp.zabeleska2 = itemRecord.at(11);
    kom_temp.rabat = itemRecord.at(12);
    kom_temp.grad = itemRecord.at(13);
    ui->sifra_Edit->setText(kom_temp.sifra);
    ui->naziv_Edit->setText(kom_temp.naziv);
    ui->adresa_Edit->setText(kom_temp.adresa);
    ui->telefon_Edit->setText(kom_temp.tel);
    ui->mobilen_Edit->setText(kom_temp.mobil);
    ui->ziro_Edit->setText(kom_temp.ziro);
    ui->danocen_Edit->setText(kom_temp.edb);
    ui->banka_Edit->setText(kom_temp.deponent);
    ui->dejnost_Edit->setText(kom_temp.sifradejnost);
    ui->mb_Edit->setText(kom_temp.mb);
    ui->zab1_Edit->setText(kom_temp.zabeleska1);
    ui->zab2_Edit->setText(kom_temp.zabeleska2);
    ui->rabat_Edit->setText(kom_temp.rabat);
    ui->grad_Edit->setText(kom_temp.grad);
}
void KomintentiKorekcija::on_pushButton_released()
{
    QString blankText = "";
    QString blankDdv = "18";

    kom_temp.sifra = ui->sifra_Edit->text();
    kom_temp.naziv = ui->naziv_Edit->text();
    kom_temp.adresa = ui->adresa_Edit->text();
    kom_temp.tel = ui->telefon_Edit->text();
    kom_temp.mobil = ui->mobilen_Edit->text();
    kom_temp.ziro = ui->ziro_Edit->text();
    kom_temp.edb = ui->danocen_Edit->text();
    kom_temp.deponent = ui->banka_Edit->text();
    kom_temp.sifradejnost = ui->dejnost_Edit->text();
    kom_temp.mb = ui->mb_Edit->text();
    kom_temp.zabeleska1 = ui->zab1_Edit->text();
    kom_temp.zabeleska2 = ui->zab2_Edit->text();
    kom_temp.rabat = ui->rabat_Edit->text();
    kom_temp.grad = ui->grad_Edit->text();

    hlp->UpdateKomintent(kom_temp.sifra,
                       kom_temp.naziv,
                         kom_temp.adresa,
                         kom_temp.tel,
                         kom_temp.mobil,
                         kom_temp.ziro,
                         kom_temp.edb,
                         kom_temp.deponent,
                         kom_temp.sifradejnost,
                         kom_temp.mb,
                         kom_temp.zabeleska1,
                         kom_temp.zabeleska2,
                         kom_temp.rabat,
                         kom_temp.grad
                         );
    pressEscape();
}

