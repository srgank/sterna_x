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
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "id";
    komintent_id = m_searchID;
    QList<komintentT> res = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    komintentT itemRecord = res.at(0);

    ui->sifra_Edit->setText(itemRecord.sifra);
    ui->naziv_Edit->setText(itemRecord.naziv);
    ui->adresa_Edit->setText(itemRecord.adresa);
    ui->telefon_Edit->setText(itemRecord.tel);
    ui->mobilen_Edit->setText(itemRecord.mobil);
    ui->ziro_Edit->setText(itemRecord.zirosmetka);
    ui->danocen_Edit->setText(itemRecord.edb);
    ui->banka_Edit->setText(itemRecord.deponent);
    ui->dejnost_Edit->setText(itemRecord.sifra_dejnost);
    ui->mb_Edit->setText(itemRecord.mb);
    ui->zab1_Edit->setText(itemRecord.zabeleska1);
    ui->zab2_Edit->setText(itemRecord.zabeleska2);
    ui->rabat_Edit->setText(itemRecord.rabat);
    ui->grad_Edit->setText(itemRecord.grad);
}
void KomintentiKorekcija::on_pushButton_released()
{
    QString blankText = "";
    QString blankDdv = "18";
    kom_temp.id = komintent_id;
    kom_temp.sifra = ui->sifra_Edit->text();
    kom_temp.naziv = ui->naziv_Edit->text();
    kom_temp.adresa = ui->adresa_Edit->text();
    kom_temp.tel = ui->telefon_Edit->text();
    kom_temp.mobil = ui->mobilen_Edit->text();
    kom_temp.zirosmetka = ui->ziro_Edit->text();
    kom_temp.edb = ui->danocen_Edit->text();
    kom_temp.deponent = ui->banka_Edit->text();
    kom_temp.sifra_dejnost = ui->dejnost_Edit->text();
    kom_temp.mb = ui->mb_Edit->text();
    kom_temp.zabeleska1 = ui->zab1_Edit->text();
    kom_temp.zabeleska2 = ui->zab2_Edit->text();
    kom_temp.rabat = ui->rabat_Edit->text();
    kom_temp.grad = ui->grad_Edit->text();

    hlp->UpdateKomintent(
            kom_temp.id,
            kom_temp.sifra,
            kom_temp.naziv,
            kom_temp.adresa,
            kom_temp.tel,
            kom_temp.mobil,
            kom_temp.zirosmetka,
            kom_temp.edb,
            kom_temp.deponent,
            kom_temp.sifra_dejnost,
            kom_temp.mb,
            kom_temp.zabeleska1,
            kom_temp.zabeleska2,
            kom_temp.rabat,
            kom_temp.grad
                         );
    pressEscape();
}

