#include "analitikaartiklilista.h"
#include "ui_analitikaartiklilista.h"



AnalitikaArtikliLista::AnalitikaArtikliLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::AnalitikaArtikliLista)
  , enableClose(true)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    m_row = 0;
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);

    BaseInstallEventFilter(ui->gridLayout);

    ui->tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    ui->tableView->setSelectionMode( QAbstractItemView::SingleSelection );
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);
    model_2 = new QStandardItemModel(0,0);
    header_2 = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempVals = s->Get_Faktura_HeaderState();
    colWidth = s->loadWidthList(tempVals, COL);

    b = new QBTemplate<AnalitikaArtikliT>();
    bd = new QBTemplate<dokumentDetailT>();
    bc = new QBTemplate<AnalitikaArtikliDetailT>();

    QStringList tempValsDetail = s->Get_FakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);

    ui->tableView->setModel(model);
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    connect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));
    updateFont();
}
AnalitikaArtikliLista::~AnalitikaArtikliLista()
{
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    disconnect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    disconnect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));


    Singleton *s = Singleton::Instance();
    QStringList tempVals = s->saveWidthList(colWidth);
    s->Set_Faktura_HeaderState(tempVals);
    QStringList tempdetailVals = s->saveWidthList(colDetailWidth);
    s->Set_FakturaDetail_HeaderState(tempdetailVals);


    delete ui;
    delete model;
    delete header;
    delete model_2;
    delete header_2;
    delete b;
    b = 0;
    delete bc;
    bc = 0;
    delete bd;
    bd = 0;
}
void AnalitikaArtikliLista::pressF2()
{
    if (enableClose){
        emit signalpressF2();
    }
}
void AnalitikaArtikliLista::pressF3()
{
    if (enableClose){
        emit signalpressF3();
    }
}
void AnalitikaArtikliLista::pressEscape()
{
    if (enableClose){
        emit signalpressEscape();
    }
}
void AnalitikaArtikliLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString AnalitikaArtikliLista::getSearchString()
{
    return ui->prebaruvanje_po_komintent->text();
}

void AnalitikaArtikliLista::setSearchString(QString& searchText)
{
    ui->prebaruvanje_po_komintent->setText(searchText);
}

void AnalitikaArtikliLista::on_lineEdit_textChanged(const QString &arg1)
{
    enableClose = false;
    numOffset = 0;
    QString vLimit = "500";
    QString vOffset = QString::number(numOffset);
    QString vSearchName = arg1 ;
    QString vSearchBy = "artikal";
    QString vDokTip = "20";
    QString vDokID = "";

    QList<dokumentT> res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip, vSearchBy, vSearchName );

    QList<AnalitikaArtikliT> resFaktura;
    b->ConvertDokument(res, resFaktura);
    resFakturaTemp = resFaktura;
    b->ShowData(resFaktura, model, header, ui->tableView, colWidth);
    enableClose = true;
}
void AnalitikaArtikliLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}
void AnalitikaArtikliLista::procSectionResizedDetail(int a, int b, int c)
{
    colDetailWidth[a] = c;
}
void AnalitikaArtikliLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    enableClose = false;
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    int i = modelX.row();
    m_row = modelX.row();

    QString vLimit = "10000";
    QString vOffset = QString::number(numOffset);
    QString vDok_Id =  model->item(i, 1)->text();
    QString vDok_Tip = model->item(i, 2)->text();

    QList<dokumentDetailT> res = hlp->getallMagacin(vOffset, vLimit, vDok_Id, vDok_Tip);

    QList<AnalitikaArtikliDetailT> resFakturaDetail;
    bc->ConvertDokumentDetail(res, resFakturaDetail);
    resFakturaDetailTemp = resFakturaDetail;

    currentData = b->getCurrentData(resFakturaTemp, m_row);
    bc->ShowData(resFakturaDetail, model_2, header_2, ui->tableView_2, colDetailWidth);
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));



    float vkupna_izl_prod_iznos_so_ddv = 0.f;

    bc->ConvertDokumentDetail(res, resFakturaDetail);
    resFakturaDetailTemp = resFakturaDetail;

    QList<AnalitikaArtikliDetailT> data = resFakturaDetail;
    for (QList<AnalitikaArtikliDetailT>::iterator i = data.begin(); i!= data.end(); i++){
        vkupna_izl_prod_iznos_so_ddv += i->izl_prod_iznos_so_ddv.toFloat();
    }

    bool isOk;
    QString vk_iznos;
    vk_iznos = QString::number(vkupna_izl_prod_iznos_so_ddv, 'f', 2 );
    ui->vk_iznos_so_ddv->setText(vk_iznos);
    int stop = 0;

    enableClose = true;
}
void AnalitikaArtikliLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->prebaruvanje_po_komintent->setText(searchStrList);
    on_lineEdit_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    PressKeyTAB(this);
}
AnalitikaArtikli_trans AnalitikaArtikliLista::getFakturaData(){
    AnalitikaArtikli_trans temp;
    temp.data1 = currentData;
    temp.data2 = resFakturaDetailTemp;
    return temp;
}
void AnalitikaArtikliLista::updateFont()
{
    Singleton *s = Singleton::Instance();
    QString str_font = "font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    BaseUpdateFonts(ui->gridLayout, str_font);
}


void AnalitikaArtikliLista::on_prebaruvanje_po_komintent_textChanged(const QString &arg1)
{
    on_lineEdit_textChanged(arg1);
}

bool AnalitikaArtikliLista::eventFilter(QObject *object, QEvent *event)
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


void AnalitikaArtikliLista::Refresh()
{
    updateFont();
}
