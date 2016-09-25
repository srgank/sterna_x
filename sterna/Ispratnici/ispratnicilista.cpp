#include "ispratnicilista.h"
#include "ui_ispratnicilista.h"



IspratniciLista::IspratniciLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::IspratniciLista)
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

    QStringList tempVals = s->Get_Ispratnica_HeaderState();
    colWidth = s->loadWidthList(tempVals, COL);


    b = new QBTemplate<ispratnicaT>();

    bd = new QBTemplate<dokumentDetailT>();
    bc = new QBTemplate<ispratnicaDetailT>();


    QStringList tempValsDetail = s->Get_IspratnicaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);

    ui->tableView->setModel(model);
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    connect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));
}

IspratniciLista::~IspratniciLista()
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
void IspratniciLista::pressF2()
{    if (enableClose){
        emit signalpressF2();
    }
}
void IspratniciLista::pressF3()
{
    if (enableClose){
        emit signalpressF3();
    }
}
void IspratniciLista::pressEscape()
{
    if (enableClose){
        emit signalpressEscape();
    }
}

void IspratniciLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString IspratniciLista::getSearchString()
{
    return ui->lineEdit_7->text();
}
void IspratniciLista::setSearchString(QString& searchText)
{
    ui->lineEdit_7->setText(searchText);
}

void IspratniciLista::on_lineEdit_textChanged(const QString &arg1)
{
    enableClose = false;
//    numOffset = 0;
//    QString vLimit = "500";
//    QString vOffset = QString::number(numOffset);
//    QString vDokID = arg1 + "%";
//    QString vDokTip = "40";

//    QList<dokumentT> res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip );

//    QList<ispratnicaT> resFaktura;
//    b->ConvertDokument(res, resFaktura);
//    resFakturaTemp = resFaktura;
//    b->ShowData(resFaktura, model, header, ui->tableView, colWidth);
    enableClose = true;
}



void IspratniciLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}

void IspratniciLista::procSectionResizedDetail(int a, int b, int c)
{
    colDetailWidth[a] = c;
}


void IspratniciLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
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

    QList<ispratnicaDetailT> resFakturaDetail;
    bc->ConvertDokumentDetail(res, resFakturaDetail);
    resFakturaDetailTemp = resFakturaDetail;

    currentData = b->getCurrentData(resFakturaTemp, m_row);
    bc->ShowData(resFakturaDetail, model_2, header_2, ui->tableView_2, colDetailWidth);
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    enableClose = true;
}


void IspratniciLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->lineEdit_7->setText(searchStrList);
    on_lineEdit_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    PressKeyTAB(this);
}


ispratnica_trans IspratniciLista::getFakturaData(){
    ispratnica_trans temp;
    temp.data1 = currentData;
    temp.data2 = resFakturaDetailTemp;
    return temp;
}

void IspratniciLista::updateFont()
{
    ui->tableView->setFont(this->font());
    ui->tableView_2->setFont(this->font());
    repaint();
}


