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


    strDisabled = "color: blue; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    ui->sifra_artikal->setStyleSheet(strDisabled);
    ui->sifra_komintent->setStyleSheet(strDisabled);
    BaseInstallEventFilter(ui->gridLayout);



    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempValsDetail = s->Get_FakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);


    b = new QBTemplate<fakturiT>();
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
    delete b;
    delete bd;
    delete comboboxD;
    b = 0;
    bd = 0;
}
void FakturiKorekcija::pressEscape()
{
    emit signalpressEscape();
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
    resFaktura.komintent_id = t.sifra;
    resFaktura.komintent_naziv = t.naziv;
    for (int i = 0; i < resFakturaItems.count(); i++){\
        resFakturaItems[i].komintent_id = resFaktura.komintent_id;
    }
    showData();
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
    QString str_font = "font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    for(int idx = 0; idx < ui->gridLayout->count(); idx++)
    {
      QLayoutItem * const item = ui->gridLayout->itemAt(idx);
      if(dynamic_cast<QWidgetItem *>(item))
        item->widget()->setStyleSheet(str_font);
    }
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
    resFaktura.dokument_tip = "20";
    QList<dokumentT> dok;
    QList<fakturiT> fakturiList;
    fakturiList.append(resFaktura);


    b->ConvertAnyToDokument(fakturiList, dok);
    dokumentT itemDoc = dok.at(0);
    hlp->UpdateDokumenti(itemDoc);

    QList<dokumentDetailT> dok_detail_old;
    bd->ConvertAnyToDokumentDetail(resFakturaItems_oldData, dok_detail_old);
    hlp->DeleteMagacin(dok_detail_old);

    QList<dokumentDetailT> dok_detail_new;
    bd->ConvertAnyToDokumentDetail(resFakturaItems, dok_detail_new);
    hlp->InsertMagacin(dok_detail_new);
    pressEscape();
}


bool FakturiKorekcija::eventFilter(QObject *object, QEvent *event)
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
