#include "povratnicivnes.h"
#include "ui_povratnicivnes.h"

PovratniciVnes::PovratniciVnes(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    statusOpenEditor(false),
    ui(new Ui::PovratniciVnes)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();

    BaseInstallEventFilter(ui->gridLayout);


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

    b = new QBTemplate<PovratniciT>();
    bd = new QBTemplate<PovratniciDetailT>();

    ui->tableView->setModel(model);
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    comboboxD = new QCBItemDelegate(Q_NULLPTR);
    connect(comboboxD, SIGNAL(updatePodatoci()), this , SLOT(updatePodatoci()));
    lineeditD = new QLEItemDelegate(Q_NULLPTR);
    connect(lineeditD, SIGNAL(updateCellLE(const QModelIndex &, QString &)), this , SLOT(updateStructCellLineEdit(const QModelIndex &, QString &)));
    updateFont();

    PressKeyTAB(this);
}

PovratniciVnes::~PovratniciVnes()
{
    Singleton *s = Singleton::Instance();
    QStringList tempdetailVals = s->saveWidthList(colDetailWidth);
    s->Set_FakturaDetail_HeaderState(tempdetailVals);

    delete hlp;
    delete ui;
    delete b;
    delete bd;
    b = 0;
    bd = 0;
}
void PovratniciVnes::pressEscape()
{
    emit signalpressEscape();
}



void PovratniciVnes::on_pushButton_released()
{

}



void PovratniciVnes::setFocusArtikal(artikalT t)
{
    ui->artikal->setFocus();
    ui->artikal->selectAll();
    ui->artikal->setText(t.artikal);
    ui->sifra_artikal->setText(t.sifra);
    PressKeyTAB(this);
}

void PovratniciVnes::setFocusKomintent(komintentT t)
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


void PovratniciVnes::pressReturn()
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
        if (procAddItem() == true){
        showData();
        ui->artikal->setFocus();
        }
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

void PovratniciVnes::OpenTablePersistentEditor(QTableView * table, QModelIndex &index)
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

void PovratniciVnes::CloseTablePersistentEditor(QTableView * table, QModelIndex &index)
{
    table->closePersistentEditor(index);
}

void PovratniciVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    m_index = modelX;
    m_row = modelX.row();
}

void PovratniciVnes::selectionChangedDetail(QModelIndex modelX,QModelIndex modelY)
{
    if (modelX != modelY){
        CloseTablePersistentEditor(ui->tableView, m_index);
    }
    m_index = modelX;
}

void PovratniciVnes::updateStructCellLineEdit(const QModelIndex & index, QString & value)
{
    switch (index.column()){
    case 0: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 0)->setText(value);break;
    case 1: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 1)->setText(value);break;
    case 2: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 2)->setText(value);break;
    case 3: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 3)->setText(value);break;
    case 4: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 4)->setText(value);break;
    case 5: resFakturaItems[index.row()].artikal_naziv = value;
        model->item(index.row(), 5)->setText(value);break;

    }
}

void PovratniciVnes::initProc(Povratnici_trans m_data)
{
    resFakturaItems = m_data.data2;
    showData();
}

void PovratniciVnes::procDeleteItem(){
    QList<PovratniciDetailT> data = resFakturaItems;
    bd->RemoveItem(data, m_row);
    resFakturaItems = data;
}

bool PovratniciVnes::procAddItem(){
    QList<PovratniciDetailT> data = resFakturaItems;
    PovratniciDetailT item;
    item.artikal_id = ui->sifra_artikal->text();
    item.artikal_naziv = ui->artikal->text();
    item.komintent_id = ui->sifra_komintent->text();
    item.kol = ui->kolicina->text();
    item.izl_cena_so_ddv_prod = ui->cena_so_ddv->text();

    bool isOk;
    float kolFloat = 0;
    float izl_cena_so_ddv_prod_float = 0;
    Singleton *s = Singleton::Instance();
    s->ConvertStringToFloat(item.kol, kolFloat, &isOk);
    if (!isOk){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Nevalidna vrednost za kolicina");
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(msgBox.exec() == QMessageBox::Ok){
            ui->kolicina->setFocus();
            return false;
        }
    }
    s->ConvertStringToFloat(item.izl_cena_so_ddv_prod, izl_cena_so_ddv_prod_float, &isOk);
    if (!isOk){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Nevalidna vrednost za cena");
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(msgBox.exec() == QMessageBox::Ok){
            ui->cena_so_ddv->setFocus();
            return false;
        }
    }

    item.izl_prod_iznos_so_ddv = QString::number(izl_cena_so_ddv_prod_float * kolFloat, 'f', 2);


    bd->AddItem(data, item);
    resFakturaItems = data;
    ui->sifra_artikal->setText("");
    ui->artikal->setText("");
    ui->kolicina->setText("");
    ui->cena_so_ddv->setText("");
    ui->rabat->setText("");
    ui->rok_za_plakanje_denovi->setText("");
    ui->zaliha->setText("");
    return true;
}


void PovratniciVnes::showData(){
    float vkupna_izl_prod_iznos_so_ddv = 0.f;
    QList<PovratniciDetailT> data = resFakturaItems;
    bd->ShowData(data, model, header, ui->tableView, colDetailWidth);
    data = resFakturaItems;
    for (QList<PovratniciDetailT>::iterator i = data.begin(); i!= data.end(); i++){
        vkupna_izl_prod_iznos_so_ddv += i->izl_prod_iznos_so_ddv.toFloat();
    }
    bool isOk;
    QString vk_iznos;
    vk_iznos = QString::number(vkupna_izl_prod_iznos_so_ddv, 'f', 2 );
    ui->vk_iznos_so_ddv->setText(vk_iznos);
    int stop = 0;
}

void PovratniciVnes::on_pushButton_6_clicked()
{
    PressKeyReturn(this);
}


void PovratniciVnes::on_pushButton_3_clicked()
{
    PressKeyReturn(this);
}

void PovratniciVnes::updateFont()
{
    Singleton *s = Singleton::Instance();
    QString str_font = "font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    BaseUpdateFonts(ui->gridLayout, str_font);
}

void PovratniciVnes::on_pushButton_4_clicked()
{
    resFaktura.dokument_tip = "20";
    QList<dokumentT> dok;
    QList<PovratniciT> PovratniciList;
    PovratniciList.append(resFaktura);

    b->ConvertAnyToDokument(PovratniciList, dok);
    dokumentT itemDoc = dok.at(0);
    itemDoc.iznos_plakanje_den = ui->vk_iznos_so_ddv->text();
    QList<dokumentT> t = hlp->InsertDokumenti(itemDoc);
    dokumentT temp_t = t.at(0);

    QList<dokumentDetailT> dok_detail_new;
    bd->ConvertAnyToDokumentDetail(resFakturaItems, dok_detail_new);

    for (int i = 0; i < dok_detail_new.count(); i++){
        dok_detail_new[i].dokument_id = temp_t.dokument_id;
        dok_detail_new[i].dokument_tip = temp_t.dokument_tip;
    }
    hlp->InsertMagacin(dok_detail_new);
    pressEscape();
}


bool PovratniciVnes::eventFilter(QObject *object, QEvent *event)
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


void PovratniciVnes::Refresh()
{
    updateFont();
}
