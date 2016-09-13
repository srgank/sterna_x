#include "fakturilista.h"
#include "ui_fakturilista.h"



FakturiLista::FakturiLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FakturiLista)
  , enableClose(true)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    m_row = 0;
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);

    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "%";
    QString vSearchBy = "artikal";

    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);
    model_2 = new QStandardItemModel(0,0);
    header_2 = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempVals = s->Get_Faktura_HeaderState();

    colWidth = s->loadWidthList(tempVals, COL);

    b = new QBTemplate<fakturiT>();

    bd = new QBTemplate<dokumentDetailT>();
    bc = new QBTemplate<fakturiDetailT>();

    QStringList tempValsDetail = s->Get_FakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);

    ui->tableView->setModel(model);
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    connect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));
}
FakturiLista::~FakturiLista()
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
void FakturiLista::pressF2()
{
    if (enableClose){
        emit signalpressF2();
    }
}
void FakturiLista::pressF3()
{
    if (enableClose){
        emit signalpressF3();
    }
}
void FakturiLista::pressEscape()
{
    if (enableClose){
        emit signalpressEscape();
    }
}
void FakturiLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString FakturiLista::getSearchString()
{
    return ui->lineEdit_7->text();
}
void FakturiLista::setSearchString(QString& searchText)
{
    ui->lineEdit_7->setText(searchText);
}
void FakturiLista::on_lineEdit_textChanged(const QString &arg1)
{
    enableClose = false;
    numOffset = 0;
    QString vLimit = "500";
    QString vOffset = QString::number(numOffset);
    QString vDokID = arg1 + "%";
    QString vDokTip = "40";

    QList<dokumentT> res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip );

    QList<fakturiT> resFaktura;
    b->ConvertDokument(res, resFaktura);
    resFakturaTemp = resFaktura;
    b->ShowData(resFaktura, model, header, ui->tableView, colWidth);
    enableClose = true;
}
void FakturiLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}
void FakturiLista::procSectionResizedDetail(int a, int b, int c)
{
    colDetailWidth[a] = c;
}
void FakturiLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
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

    QList<fakturiDetailT> resFakturaDetail;
    bc->ConvertDokumentDetail(res, resFakturaDetail);
    resFakturaDetailTemp = resFakturaDetail;

    currentData = b->getCurrentData(resFakturaTemp, vDok_Id);
    bc->ShowData(resFakturaDetail, model_2, header_2, ui->tableView_2, colDetailWidth);
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    enableClose = true;
}
void FakturiLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->lineEdit_7->setText(searchStrList);
    on_lineEdit_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    PressKeyTAB(this);
}
faktura_trans FakturiLista::getFakturaData(){
    faktura_trans temp;
    temp.data1 = currentData;
    temp.data2 = resFakturaDetailTemp;
    return temp;
}
void FakturiLista::updateFont()
{
    ui->tableView->setFont(this->font());
    ui->tableView_2->setFont(this->font());
    repaint();
}

