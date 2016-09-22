#include "fakturivnes.h"
#include "ui_fakturivnes.h"

FakturiVnes::FakturiVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FakturiVnes)
  ,hlp(0)

{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();

    str_yellow = "background-color: yellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    ui->artikal->installEventFilter(this);
    ui->cena_so_ddv->installEventFilter(this);
    ui->dateTimeDatum->installEventFilter(this);
    ui->dateTimeValuta->installEventFilter(this);
    ui->kolicina->installEventFilter(this);
    ui->komintent->installEventFilter(this);
    ui->rabat->installEventFilter(this);
    ui->rok_za_plakanje_denovi->installEventFilter(this);
    ui->vk_ddv_iznos->installEventFilter(this);
    ui->vk_iznos_bez_ddv->installEventFilter(this);
    ui->vk_iznos_so_ddv->installEventFilter(this);
    ui->zaliha->installEventFilter(this);



    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    strDisabled = "color: blue; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    ui->sifra_artikal->setStyleSheet(strDisabled);
    ui->sifra_komintent->setStyleSheet(strDisabled);

    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempValsDetail = s->Get_FakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);

    bd = new QBTemplate<fakturiDetailT>();

    ui->tableView->setModel(model);
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    PressKeyTAB(this);
}

FakturiVnes::~FakturiVnes()
{
    delete hlp;
    delete ui;
    delete bd;
    bd = 0;
}
void FakturiVnes::pressEscape()
{
    emit signalpressEscape();
}



void FakturiVnes::on_pushButton_released()
{




}



void FakturiVnes::setFocusArtikal(artikalT t)
{
    ui->artikal->setFocus();
    ui->artikal->selectAll();
    ui->artikal->setText(t.artikal);
    ui->sifra_artikal->setText(t.sifra);
    PressKeyTAB(this);
}

void FakturiVnes::setFocusKomintent(komintentT t)
{
    ui->komintent->setFocus();
    ui->komintent->selectAll();
    ui->komintent->setText(t.naziv);
    ui->sifra_komintent->setText(t.sifra);
    PressKeyTAB(this);
}


void FakturiVnes::pressReturn()
{
    if(ui->pushButton_3->hasFocus())
    {
        procAddItem();
        showData();
    }
    if(ui->pushButton_6->hasFocus())
    {
        procDeleteItem();
        showData();
    }
    else if(ui->komintent->hasFocus())
    {
        emit signalGetKomintent("", (QWidget*)this);
    }
    else if(ui->artikal->hasFocus())
    {
        emit signalGetArtikal("", (QWidget*)this);
    }
    else
    {
        PressKeyTAB(this);
    }

}

void FakturiVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    m_row = modelX.row();
}

void FakturiVnes::initProc(faktura_trans m_data)
{
    resFakturaItems = m_data.data2;
    showData();
}

void FakturiVnes::procDeleteItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->RemoveItem(data, m_row);
    resFakturaItems = data;
}

void FakturiVnes::procAddItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    fakturiDetailT item;
    item.artikal_naziv = ui->artikal->text();
    bd->AddItem(data, item);
    resFakturaItems = data;
}


void FakturiVnes::showData(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->ShowData(data, model, header, ui->tableView, colDetailWidth);
}

void FakturiVnes::on_pushButton_6_clicked()
{
    PressKeyReturn(this);
}


void FakturiVnes::on_pushButton_3_clicked()
{
    PressKeyReturn(this);
}

void FakturiVnes::updateFont()
{
    ui->tableView->setFont(this->font());
    repaint();
}

void FakturiVnes::on_pushButton_4_clicked()
{
    // vnesi faktura
    QString blankText = "";
    QString blankDdv = "18";
    dokumentT dok;
    dok.komintent_naziv = "Test";
    dok.dokument_id = "1";
    dok.dokument_tip = "20";
    hlp->InsertDokumenti(dok);

    QList<dokumentDetailT> listDokDetail;
    dokumentDetailT dokDetail;
    dokDetail.dokument_id = "1";
    dokDetail.dokument_tip = "20";
    dokDetail.artikal_naziv = "TEST ART";
    listDokDetail.append(dokDetail);
    hlp->InsertMagacin(listDokDetail);
    pressEscape();

}
bool FakturiVnes::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        ((QWidget*)object)->setStyleSheet(str_yellow);
    }
    if (event->type() == QEvent::FocusOut)
    {
        ((QWidget*)object)->setStyleSheet(str_none);
    }

    return false;
}
