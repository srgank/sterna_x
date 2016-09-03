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
    numOffset = 0;
    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "%";
    QString vSearchBy = "artikal";
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);
    model_2 = new QStandardItemModel(0,0);
    header_2 = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempVals = s->Get_Priemnica_HeaderState();
    if (!tempVals.isEmpty()){
        for (int i = 0; i < COL; i++)        {
            colWidth << tempVals.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL; i++)        {
            colWidth << 100;
        }
    }


    QStringList tempValsDetail = s->Get_PriemnicaDetail_HeaderState();
    if (!tempValsDetail.isEmpty()){
        for (int i = 0; i < COL_DETAIL; i++)        {
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

    on_lineEdit_textChanged("%%");
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

    s->Set_Priemnica_HeaderState(tempVals);

    QStringList tempdetailVals;
    for (int i = 0; i < colDetailWidth.count(); i++)
    {
        tempdetailVals << QString::number(colDetailWidth.at(i));
    }

    s->Set_PriemnicaDetail_HeaderState(tempdetailVals);


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
    emit signalpressEscape();
}

void FakturiLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString FakturiLista::getSearchString()
{
//    return ui->LE_prebaraj->text();
}
void FakturiLista::setSearchString(QString& searchText)
{
 //   ui->LE_prebaraj->setText(searchText);
}

void FakturiLista::on_lineEdit_textChanged(const QString &arg1)
{
    numOffset = 0;
    QString vLimit = "500";
    QString vOffset = QString::number(numOffset);
    QString vDokID =  "%";
    QString vDokTip = "40";

    QList<dokumentT> res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip );
    QList<fakturiT> resFaktura;
    c.ConvertDokument(res, resFaktura);
    b.ShowData(resFaktura, model, header, ui->tableView, colWidth);

}



void FakturiLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}



void FakturiLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    int i = modelX.row();
    m_row = modelX.row();
    m_selectedID = model->item(i, 1)->text();

    numOffset = 0;
    QString vLimit = "10000";
    QString vOffset = QString::number(numOffset);
    QString vDok_Id =  model->item(i, 1)->text();
    QString vDok_Tip = model->item(i, 2)->text();

    QList<dokumentDetailT> res = hlp->getallMagacin(vOffset, vLimit, vDok_Id, vDok_Tip);
    bd.ShowData(res, model_2, header_2, ui->tableView_2, colDetailWidth);

}

void FakturiLista::on_pushButton_5_clicked()
{
    numOffset -= 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
//    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
//    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}

void FakturiLista::on_pushButton_6_clicked()
{
    numOffset += 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
//    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
//    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}

void FakturiLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
    numOffset = 0;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
//    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
//    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}

void FakturiLista::setTableColumnWidths(int ccolumn)
{
//    Singleton *s = Singleton::Instance();
//    QStringList tempWidth;
//    for (int i = 0; i < ccolumn; i++)
//    {
//        tempWidth << QString::number(ui->tableView->columnWidth(i), 10);
//    }
//    s->setFakturiColumnWidth(tempWidth);
}

void FakturiLista::getTableColumnWidths(int ccolumn)
{
//    QLocale loc;
//    Singleton *s = Singleton::Instance();
//    QStringList sss = s->getFakturiColumnWidth();
//    if (sss.count() == ccolumn)
//    {
//        for (int i1 = 0; i1 < ccolumn; i1++)
//        {
//            colWidth[i1] = loc.toInt(sss.at(i1));
//        }
//    }
//    else
//    {
//        for (int i1 = 0; i1 < ccolumn; i1++)
//        {
//            colWidth[i1] = 100;
//        }
//    }
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
