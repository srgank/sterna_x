#include "fakturilista.h"
#include "ui_fakturilista.h"



FakturiLista::FakturiLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FakturiLista)
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
//    numOffset = 0;
    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "%";
    QString vSearchBy = "artikal";
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);
    model_2 = new QStandardItemModel(0,0);
    header_2 = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempVals = s->Get_Faktura_HeaderState();
    if (!tempVals.isEmpty()){
        for (int i = 0; i < tempVals.count(); i++)        {
            colWidth << tempVals.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL; i++)        {
            colWidth << 100;
        }
    }


    QStringList tempValsDetail = s->Get_FakturaDetail_HeaderState();
    if (!tempValsDetail.isEmpty()){
        for (int i = 0; i < tempValsDetail.count(); i++)        {
            colDetailWidth << tempValsDetail.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL_DETAIL; i++)        {
            colDetailWidth << 100;
        }
    }

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
    QStringList tempVals;
    for (int i = 0; i < colWidth.count(); i++)
    {
        tempVals << QString::number(colWidth.at(i));
    }

    s->Set_Faktura_HeaderState(tempVals);

    QStringList tempdetailVals;
    for (int i = 0; i < colDetailWidth.count(); i++)
    {
        tempdetailVals << QString::number(colDetailWidth.at(i));
    }

    s->Set_FakturaDetail_HeaderState(tempdetailVals);


    delete ui;
    delete model;
    delete header;
    delete model_2;
    delete header_2;
}

void FakturiLista::pressF2()
{
    emit signalpressF2();
}

void FakturiLista::pressF3()
{
    emit signalpressF3();
}

void FakturiLista::pressEscape()
{
    mio_.lock();
    emit signalpressEscape();
    mio_.unlock();
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

    mio_.lock();
//    numOffset = 0;
    QString vLimit = "500";
    QString vOffset = QString::number(numOffset);
    QString vDokID = arg1 + "%";
    QString vDokTip = "40";

    QList<dokumentT> res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip );

    QList<fakturiT> resFaktura;
    c.ConvertDokument(res, resFaktura);
    resFakturaTemp = resFaktura;
    b.ShowData(resFaktura, model, header, ui->tableView, colWidth);
    mio_.unlock();
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
    mio_.lock();
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    int i = modelX.row();
    m_row = modelX.row();
//    m_selectedID = model->item(i, 1)->text();

//    numOffset = 0;
    QString vLimit = "10000";
    QString vOffset = QString::number(numOffset);
    QString vDok_Id =  model->item(i, 1)->text();
    QString vDok_Tip = model->item(i, 2)->text();

    QList<dokumentDetailT> res = hlp->getallMagacin(vOffset, vLimit, vDok_Id, vDok_Tip);

    QList<fakturiDetailT> resFakturaDetail;
    bc.ConvertDokumentDetail(res, resFakturaDetail);
    resFakturaDetailTemp = resFakturaDetail;

    currentData = getCurrentData(resFakturaTemp, vDok_Id);
    bc.ShowData(resFakturaDetail, model_2, header_2, ui->tableView_2, colDetailWidth);
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    mio_.unlock();
}

fakturiT FakturiLista::getCurrentData(QList<fakturiT> &list, QString dok_id)
{
    fakturiT resItem;
    for (int i = 0; i < list.count(); i++){
        if (list.at(i).dokument_id == dok_id){
            resItem = list.at(i);
            break;
        }
    }
    return resItem;
}

void FakturiLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->lineEdit_7->setText(searchStrList);
    on_lineEdit_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void FakturiLista::on_pb_vnesi_nov_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void FakturiLista::on_pb_koregiraj_postoecki_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F3, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

faktura_trans FakturiLista::getFakturaData(){
    faktura_trans temp;
    temp.data1 = currentData;
    temp.data2 = resFakturaDetailTemp;
    return temp;
}
