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
    statusWait = true;
    //    ui->pushButton->setEnabled(false);
    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();
    //
}


void FakturiKorekcija::setFocusArtikal(artikalT t)
{
    ui->lineEdit_2->setFocus();
    ui->lineEdit_2->selectAll();
    ui->lineEdit_2->setText(t.artikal);
    ui->lineEdit_13->setText(t.sifra);
    PressKeyTAB(this);
}

void FakturiKorekcija::setFocusKomintent(QString t)
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
    ui->lineEdit->setText(t);
    PressKeyTAB(this);
}

void FakturiKorekcija::pressReturn()
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
    if(ui->tableView->hasFocus())
    {
        if (!statusOpenEditor){
            OpenTablePersistentEditor(ui->tableView, m_index);
        }else{
            CloseTablePersistentEditor(ui->tableView, m_index);
        }
        statusOpenEditor = !statusOpenEditor;
    }

    else if(ui->lineEdit->hasFocus())
    {
        emit signalGetKomintent("", (QWidget*)this);
    }
    else if(ui->lineEdit_2->hasFocus())
    {
        emit signalGetArtikal("", (QWidget*)this);
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
    resFakturaItems = m_data.data2;
    showData();
    PressKeyTAB(this);
}

void FakturiKorekcija::procDeleteItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->RemoveItem(data, m_row);
    resFakturaItems = data;
}

void FakturiKorekcija::procAddItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    fakturiDetailT item;
    item.artikal_naziv = ui->lineEdit_2->text();
    bd->AddItem(data, item);
    resFakturaItems = data;
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
    ui->tableView->setFont(this->font());
    repaint();
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
    resFaktura.komintent_naziv = ui->lineEdit->text();

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


    pressEscape();
}
