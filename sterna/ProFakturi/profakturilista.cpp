#include "profakturilista.h"
#include "ui_profakturilista.h"



ProFakturiLista::ProFakturiLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ProFakturiLista)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    m_row = 0;
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    connect(hlp, SIGNAL(signalResultFakturi(QStringList &)), this, SLOT(getResultEX(QStringList &)));

    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    numOffset = 0;
    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "%";
    QString vSearchBy = "artikal";
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);
    model_2 = new QStandardItemModel(0,0);
    header_2 = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempVals = s->Get_ProFaktura_HeaderState();
    colWidth = s->loadWidthList(tempVals, COL);


    QStringList tempValsDetail = s->Get_ProFakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);



    ui->tableView->setModel(model);
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    connect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));

}

ProFakturiLista::~ProFakturiLista()
{
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    disconnect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    disconnect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));

    Singleton *s = Singleton::Instance();
    QStringList tempVals = s->saveWidthList(colWidth);
    s->Set_ProFaktura_HeaderState(tempVals);
    QStringList tempdetailVals = s->saveWidthList(colDetailWidth);
    s->Set_ProFakturaDetail_HeaderState(tempdetailVals);

    delete ui;
    delete model;
    delete header;
    delete model_2;

}
void ProFakturiLista::pressF2()
{
    emit signalpressF2();
}
void ProFakturiLista::pressF3()
{
    emit signalpressF3();
}
void ProFakturiLista::pressEscape()
{
    mio_.lock();
    emit signalpressEscape();
    mio_.unlock();
}

void ProFakturiLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString ProFakturiLista::getSearchString()
{
    return ui->lineEdit_7->text();
}
void ProFakturiLista::setSearchString(QString& searchText)
{
    ui->lineEdit_7->setText(searchText);
}

void ProFakturiLista::on_lineEdit_textChanged(const QString &arg1)
{
    mio_.lock();
    QString vLimit = "500";
    QString vOffset = QString::number(numOffset);
    QString vDokID = arg1 + "%";
    QString vDokTip = "80";

    QList<dokumentT> res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip );

    QList<profakturiT> resFaktura;
    b.ConvertDokument(res, resFaktura);
    resFakturaTemp = resFaktura;
    b.ShowData(resFaktura, model, header, ui->tableView, colWidth);
    mio_.unlock();
}


void ProFakturiLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}

void ProFakturiLista::procSectionResizedDetail(int a, int b, int c)
{
    colDetailWidth[a] = c;
}

void ProFakturiLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    mio_.lock();
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    int i = modelX.row();
    m_row = modelX.row();
    QString vLimit = "10000";
    QString vOffset = QString::number(numOffset);
    QString vDok_Id =  model->item(i, 1)->text();
    QString vDok_Tip = model->item(i, 2)->text();

    QList<dokumentDetailT> res = hlp->getallMagacin(vOffset, vLimit, vDok_Id, vDok_Tip);

    QList<profakturiDetailT> resFakturaDetail;
    bc.ConvertDokumentDetail(res, resFakturaDetail);
    resFakturaDetailTemp = resFakturaDetail;

    currentData = b.getCurrentData(resFakturaTemp, m_row);
    bc.ShowData(resFakturaDetail, model_2, header_2, ui->tableView_2, colDetailWidth);
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    mio_.unlock();

}

void ProFakturiLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->lineEdit_7->setText(searchStrList);
    on_lineEdit_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}



void ProFakturiLista::on_pb_vnesi_nov_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void ProFakturiLista::on_pb_koregiraj_postoecki_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F3, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

profaktura_trans ProFakturiLista::getProFakturaData(){
    profaktura_trans temp;
    temp.data1 = currentData;
    temp.data2 = resFakturaDetailTemp;
    return temp;
}
