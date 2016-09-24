#include "fakturivnes.h"
#include "ui_fakturivnes.h"

FakturiVnes::FakturiVnes(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    statusOpenEditor(false),
    ui(new Ui::FakturiVnes)
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
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->installEventFilter(this);
    ui->pushButton_6->installEventFilter(this);
    ui->pushButton_5->installEventFilter(this);
    ui->pushButtonA->installEventFilter(this);

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
    comboboxD = new QCBItemDelegate(Q_NULLPTR);
    connect(comboboxD, SIGNAL(updatePodatoci()), this , SLOT(updatePodatoci()));
    lineeditD = new QLEItemDelegate(Q_NULLPTR);
    connect(lineeditD, SIGNAL(updateCellLE(const QModelIndex &, QString &)), this , SLOT(updateStructCellLineEdit(const QModelIndex &, QString &)));


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
    if(ui->pushButton_6->hasFocus())
    {
        procDeleteItem();
        showData();
    }
    else if(ui->tableView->hasFocus())
    {
        if (!statusOpenEditor){
            OpenTablePersistentEditor(ui->tableView, m_index);
        }else{
            CloseTablePersistentEditor(ui->tableView, m_index);
        }
        statusOpenEditor = !statusOpenEditor;
    }

    else if(ui->komintent->hasFocus())
    {
        emit signalGetKomintent("", (QWidget*)this);
    }
    else if(ui->artikal->hasFocus())
    {
        emit signalGetArtikal("", (QWidget*)this);
    }
    else if(ui->pushButton_3->hasFocus())
    {
        procAddItem();
        showData();
        ui->artikal->setFocus();
    }

    else
    {
        if (statusOpenEditor){
            CloseTablePersistentEditor(ui->tableView, m_index);
            statusOpenEditor = !statusOpenEditor;

        }else{
            PressKeyTAB(this);
        }
    }
}

void FakturiVnes::OpenTablePersistentEditor(QTableView * table, QModelIndex &index)
{
    switch (index.column()){
    case 0:  table->setItemDelegate(lineeditD);break;
    case 1:  table->setItemDelegate(lineeditD);break;
    case 2:  table->setItemDelegate(lineeditD);break;
    case 3:  table->setItemDelegate(lineeditD);break;
    case 4:  table->setItemDelegate(comboboxD);break;
    case 5:  table->setItemDelegate(comboboxD);break;
    case 6:  table->setItemDelegate(comboboxD);break;
    case 7:  table->setItemDelegate(comboboxD);break;
    case 8:  table->setItemDelegate(comboboxD);break;
    case 9:  table->setItemDelegate(comboboxD);break;
    }
    table->openPersistentEditor(index);
}

void FakturiVnes::CloseTablePersistentEditor(QTableView * table, QModelIndex &index)
{
    table->closePersistentEditor(index);
}

void FakturiVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    m_index = modelX;
    m_row = modelX.row();
}

void FakturiVnes::selectionChangedDetail(QModelIndex modelX,QModelIndex modelY)
{
    if (modelX != modelY){
        CloseTablePersistentEditor(ui->tableView, m_index);
    }
    m_index = modelX;
}

void FakturiVnes::updateStructCellLineEdit(const QModelIndex & index, QString & value)
{
    switch (index.column()){
    case 0: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;
    case 1: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;
    case 2: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;
    case 3: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;
    case 4: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;
    case 5: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;

    }
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
    item.artikal_id = ui->sifra_artikal->text();
    item.artikal_naziv = ui->artikal->text();
    item.komintent_id = ui->sifra_komintent->text();

    bd->AddItem(data, item);
    resFakturaItems = data;
    ui->sifra_artikal->setText("");
    ui->artikal->setText("");
    ui->kolicina->setText("");
    ui->cena_so_ddv->setText("");
    ui->rabat->setText("");
    ui->rok_za_plakanje_denovi->setText("");
    ui->zaliha->setText("");
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
    Singleton *s = Singleton::Instance();
    QString str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    QString strDisabled = "color: blue; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    ui->tableView->setStyleSheet(str_none);
    ui->sifra_artikal->setStyleSheet(strDisabled);
    ui->artikal->setStyleSheet(str_none);
    ui->cena_so_ddv->setStyleSheet(str_none);
    ui->dateTimeDatum->setStyleSheet(str_none);
    ui->dateTimeValuta->setStyleSheet(str_none);
    ui->kolicina->setStyleSheet(str_none);
    ui->sifra_komintent->setStyleSheet(strDisabled);
    ui->komintent->setStyleSheet(str_none);
    ui->rabat->setStyleSheet(str_none);
    ui->rok_za_plakanje_denovi->setStyleSheet(str_none);
    ui->vk_ddv_iznos->setStyleSheet(str_none);
    ui->vk_iznos_bez_ddv->setStyleSheet(str_none);
    ui->vk_iznos_so_ddv->setStyleSheet(str_none);
    ui->zaliha->setStyleSheet(str_none);
}

void FakturiVnes::on_pushButton_4_clicked()
{
    // vnesi faktura
    QString blankText = "";
    QString blankDdv = "18";
    dokumentT dok;
    dok.komintent_id = ui->sifra_komintent->text();
    dok.komintent_naziv = ui->komintent->text();
    dok.dokument_tip = "20";

    QList<dokumentT> t = hlp->InsertDokumenti(dok);
    QList<dokumentDetailT> listDokDetail;

    dokumentT item = t.at(0);

    for (int i = 0; i < resFakturaItems.count(); i++){

        dokumentDetailT dokDetail;
        dokDetail.dokument_id = item.dokument_id;
        dokDetail.dokument_tip = "20";

        dokDetail.artikal_id = resFakturaItems.at(i).artikal_id;
        dokDetail.artikal_naziv = resFakturaItems.at(i).artikal_naziv;
        listDokDetail.append(dokDetail);
    }
    hlp->InsertMagacin(listDokDetail);
    pressEscape();

}
bool FakturiVnes::eventFilter(QObject *object, QEvent *event)
{
    Singleton *s = Singleton::Instance();
    if (event->type() == QEvent::FocusIn)
    {
        str_yellow = "background-color: yellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
        ((QWidget*)object)->setStyleSheet(str_yellow);
    }
    if (event->type() == QEvent::FocusOut)
    {
        str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
        ((QWidget*)object)->setStyleSheet(str_none);
    }

    return false;
}
