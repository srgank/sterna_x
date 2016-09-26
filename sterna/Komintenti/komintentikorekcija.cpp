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
    BaseInstallEventFilter(ui->gridLayout);
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    connect(this, SIGNAL(finishKorekcija()),this, SLOT(procFinishKorekcija()));
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
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

    hlp->UpdateKomintent(kom_temp);
    pressEscape();
}

bool KomintentiKorekcija::eventFilter(QObject *object, QEvent *event)
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
