#include "fakturikorekcija.h"
#include "ui_fakturikorekcija.h"

FakturiKorekcija::FakturiKorekcija(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    statusOpenEditor(false),
    ui(new Ui::FakturiKorekcija)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();

    str_yellow = "background-color: yellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    QString strDisabled = "color: blue; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    ui->sifra_artikal->setStyleSheet(strDisabled);
    ui->sifra_komintent->setStyleSheet(strDisabled);
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
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempValsDetail = s->Get_FakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);

    bd = new QBTemplate<fakturiDetailT>();

    ui->tableView->setModel(model);
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    sm = ui->tableView->selectionModel();
    smDetail = ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(smDetail, SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChangedDetail(QModelIndex,QModelIndex)));
    comboboxD = new QCBItemDelegate(Q_NULLPTR);
    connect(comboboxD, SIGNAL(updatePodatoci()), this , SLOT(updatePodatoci()));
    lineeditD = new QLEItemDelegate(Q_NULLPTR);
    connect(lineeditD, SIGNAL(updateCellLE(const QModelIndex &, QString &)), this , SLOT(updateStructCellLineEdit(const QModelIndex &, QString &)));
}

FakturiKorekcija::~FakturiKorekcija()
{
    delete ui;
    delete hlp;
    delete bd;
    delete comboboxD;
    bd = 0;
}
void FakturiKorekcija::pressEscape()
{
    emit signalpressEscape();
}


void FakturiKorekcija::on_pushButton_released()
{

    //
}


void FakturiKorekcija::setFocusArtikal(artikalT t)
{
    ui->artikal->setFocus();
    ui->artikal->selectAll();
    ui->artikal->setText(t.artikal);
    ui->sifra_artikal->setText(t.sifra);
    PressKeyTAB(this);
}

void FakturiKorekcija::setFocusKomintent(komintentT t)
{
    ui->komintent->setFocus();
    ui->komintent->selectAll();
    ui->komintent->setText(t.naziv);
    ui->sifra_komintent->setText(t.sifra);
    PressKeyTAB(this);
}


void FakturiKorekcija::pressReturn()
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


void FakturiKorekcija::OpenTablePersistentEditor(QTableView * table, QModelIndex &index)
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

void FakturiKorekcija::CloseTablePersistentEditor(QTableView * table, QModelIndex &index)
{
    table->closePersistentEditor(index);
}


void FakturiKorekcija::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    m_index = modelX;
    m_row = modelX.row();
}



void FakturiKorekcija::selectionChangedDetail(QModelIndex modelX,QModelIndex modelY)
{
    if (modelX != modelY){
        CloseTablePersistentEditor(ui->tableView, m_index);
    }
    m_index = modelX;
}

void FakturiKorekcija::initProc(faktura_trans m_data)
{
    resFaktura = m_data.data1;
    ui->faktura_id->setText(resFaktura.dokument_id);
    ui->sifra_komintent->setText(resFaktura.komintent_id);
    ui->komintent->setText(resFaktura.komintent_naziv);

    resFakturaItems = m_data.data2;
    resFakturaItems_oldData = m_data.data2;
    showData();
    //PressKeyTAB(this);
    ui->artikal->setFocus();
}

void FakturiKorekcija::procDeleteItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->RemoveItem(data, m_row);
    resFakturaItems = data;
}

void FakturiKorekcija::procAddItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    fakturiDetailT item;
    item.artikal_id = ui->sifra_artikal->text();
    item.artikal_naziv = ui->artikal->text();
    item.komintent_id = ui->sifra_komintent->text();
    item.dokument_id = resFaktura.dokument_id;
    item.dokument_tip = resFaktura.dokument_tip;

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


void FakturiKorekcija::showData(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->ShowData(data, model, header, ui->tableView, colDetailWidth);
}

void FakturiKorekcija::on_pushButton_6_clicked()
{
    PressKeyReturn(this);
}


void FakturiKorekcija::on_pushButton_3_clicked()
{
    PressKeyReturn(this);
}

void FakturiKorekcija::updateFont()
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

void FakturiKorekcija::updateStructCellLineEdit(const QModelIndex & index, QString & value)
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

void FakturiKorekcija::on_pushButton_4_clicked()
{
    // update faktura
    resFaktura.komintent_naziv = ui->komintent->text();

    dokumentT dok;
    dok.tid = resFaktura.tid;
    dok.dokument_id = resFaktura.dokument_id;
    dok.dokument_tip = resFaktura.dokument_tip;
    dok.td = resFaktura.td;
    dok.tds = resFaktura.tds;
    dok.komintent_id = resFaktura.komintent_id;
    dok.komintent_naziv = resFaktura.komintent_naziv;
    dok.prevoznik_id = resFaktura.prevoznik_id;
    dok.prevoznik_naziv = resFaktura.prevoznik_naziv;
    dok.valuta = resFaktura.valuta;
    dok.kurs = resFaktura.kurs;
    dok.iznos_val = resFaktura.iznos_val;
    dok.ddv_val = resFaktura.ddv_val;
    dok.rabat_val = resFaktura.rabat_val;
    dok.iznos_plakanje_val = resFaktura.iznos_plakanje_val;
    dok.iznos_ddv_den = resFaktura.iznos_ddv_den;
    dok.rabat_den = resFaktura.rabat_den;
    dok.iznos_plakanje_den = resFaktura.iznos_plakanje_den;
    dok.transport_den = resFaktura.transport_den;
    dok.carina_den = resFaktura.carina_den;
    dok.ddv_den = resFaktura.ddv_den;
    dok.drugi_trosoci_den = resFaktura.drugi_trosoci_den;
    dok.dok_status = resFaktura.dok_status;
    dok.user_id = resFaktura.user_id;
    dok.komentar = resFaktura.komentar;
    dok.mag_id = resFaktura.mag_id;
    dok.object_id = resFaktura.object_id;

    hlp->UpdateDokumenti(dok);

    QList<dokumentDetailT> dok_detail;
    for (int i = 0; i < resFakturaItems_oldData.count(); i++){
        fakturiDetailT dokDetail_old = resFakturaItems_oldData.at(i);
        dokumentDetailT dokDetail;

        dokDetail.tid = dokDetail_old.tid;
        dokDetail.dokument_id = dokDetail_old.dokument_id;
        dokDetail.dokument_tip = dokDetail_old.dokument_tip;
        dokDetail.komintent_id = dokDetail_old.komintent_id;
        dokDetail.artikal_id = dokDetail_old.artikal_id;
        dokDetail.artikal_naziv = dokDetail_old.artikal_naziv;
        dokDetail.tip_artikal = dokDetail_old.tip_artikal;
        dokDetail.link_artikal = dokDetail_old.link_artikal;
        dokDetail.edm = dokDetail_old.edm;
        dokDetail.vlez_nab_cena_bez_ddv = dokDetail_old.vlez_nab_cena_bez_ddv;
        dokDetail.vlez_nab_cena_so_ddv = dokDetail_old.vlez_nab_cena_so_ddv;
        dokDetail.vlez_prenesen_ddv = dokDetail_old.vlez_prenesen_ddv;
        dokDetail.vlez_prenesen_ddv_denari = dokDetail_old.vlez_prenesen_ddv_denari;
        dokDetail.vlez_rabat = dokDetail_old.vlez_rabat;
        dokDetail.vlez_nabaven_iznos_so_ddv = dokDetail_old.vlez_nabaven_iznos_so_ddv;
        dokDetail.vlez_marza = dokDetail_old.vlez_marza;
        dokDetail.vlez_marza_den = dokDetail_old.vlez_marza_den;
        dokDetail.vlez_prod_cena_bez_ddv = dokDetail_old.vlez_prod_cena_bez_ddv;
        dokDetail.vlez_presmetan_ddv = dokDetail_old.vlez_presmetan_ddv;
        dokDetail.vlez_prod_cena_so_ddv = dokDetail_old.vlez_prod_cena_so_ddv;
        dokDetail.vlez_prod_iznos_so_ddv = dokDetail_old.vlez_prod_iznos_so_ddv;
        dokDetail.izl_cena_bez_ddv_calc = dokDetail_old.izl_cena_bez_ddv_calc;
        dokDetail.izl_cena_so_ddv_calc = dokDetail_old.izl_cena_so_ddv_calc;
        dokDetail.izl_cena_so_ddv_prod = dokDetail_old.izl_cena_so_ddv_prod;
        dokDetail.izl_ddv_prod = dokDetail_old.izl_ddv_prod;
        dokDetail.kol = dokDetail_old.kol;
        dokDetail.mag_id = dokDetail_old.mag_id;
        dokDetail.status  = dokDetail_old.status;
        dok_detail.append(dokDetail);
    }
    hlp->DeleteMagacin(dok_detail);

    QList<dokumentDetailT> dok_detail_new;
    for (int i = 0; i < resFakturaItems.count(); i++){
        fakturiDetailT dokDetail_new = resFakturaItems.at(i);
        dokumentDetailT dokDetail;

        dokDetail.tid = dokDetail_new.tid;
        dokDetail.dokument_id = dokDetail_new.dokument_id;
        dokDetail.dokument_tip = dokDetail_new.dokument_tip;
        dokDetail.komintent_id = dokDetail_new.komintent_id;
        dokDetail.artikal_id = dokDetail_new.artikal_id;
        dokDetail.artikal_naziv = dokDetail_new.artikal_naziv;
        dokDetail.tip_artikal = dokDetail_new.tip_artikal;
        dokDetail.link_artikal = dokDetail_new.link_artikal;
        dokDetail.edm = dokDetail_new.edm;
        dokDetail.vlez_nab_cena_bez_ddv = dokDetail_new.vlez_nab_cena_bez_ddv;
        dokDetail.vlez_nab_cena_so_ddv = dokDetail_new.vlez_nab_cena_so_ddv;
        dokDetail.vlez_prenesen_ddv = dokDetail_new.vlez_prenesen_ddv;
        dokDetail.vlez_prenesen_ddv_denari = dokDetail_new.vlez_prenesen_ddv_denari;
        dokDetail.vlez_rabat = dokDetail_new.vlez_rabat;
        dokDetail.vlez_nabaven_iznos_so_ddv = dokDetail_new.vlez_nabaven_iznos_so_ddv;
        dokDetail.vlez_marza = dokDetail_new.vlez_marza;
        dokDetail.vlez_marza_den = dokDetail_new.vlez_marza_den;
        dokDetail.vlez_prod_cena_bez_ddv = dokDetail_new.vlez_prod_cena_bez_ddv;
        dokDetail.vlez_presmetan_ddv = dokDetail_new.vlez_presmetan_ddv;
        dokDetail.vlez_prod_cena_so_ddv = dokDetail_new.vlez_prod_cena_so_ddv;
        dokDetail.vlez_prod_iznos_so_ddv = dokDetail_new.vlez_prod_iznos_so_ddv;
        dokDetail.izl_cena_bez_ddv_calc = dokDetail_new.izl_cena_bez_ddv_calc;
        dokDetail.izl_cena_so_ddv_calc = dokDetail_new.izl_cena_so_ddv_calc;
        dokDetail.izl_cena_so_ddv_prod = dokDetail_new.izl_cena_so_ddv_prod;
        dokDetail.izl_ddv_prod = dokDetail_new.izl_ddv_prod;
        dokDetail.kol = dokDetail_new.kol;
        dokDetail.mag_id = dokDetail_new.mag_id;
        dokDetail.status  = dokDetail_new.status;
        dok_detail_new.append(dokDetail);
    }
    hlp->InsertMagacin(dok_detail_new);
    pressEscape();
}

bool FakturiKorekcija::eventFilter(QObject *object, QEvent *event)
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
