#include "priemnicilista.h"
#include "ui_priemnicilista.h"



PriemniciLista::PriemniciLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::PriemniciLista)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    m_row = 0;
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);

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
            colWidth[i] = tempVals.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL; i++)        {
            colWidth[i] = 100;
        }
    }


    QStringList tempValsDetail = s->Get_PriemnicaDetail_HeaderState();
    if (!tempValsDetail.isEmpty()){
        for (int i = 0; i < COL_DETAIL; i++)        {
            colDetailWidth[i] = tempValsDetail.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL_DETAIL; i++)        {
            colDetailWidth[i] = 100;
        }
    }


    getTableColumnWidths(COL);
    on_lineEdit_textChanged("%%");
}

PriemniciLista::~PriemniciLista()
{
    Singleton *s = Singleton::Instance();
    QStringList tempVals;
    for (int i = 0; i < COL; i++)
    {
        tempVals << QString::number(colWidth[i]);
    }

    s->Set_Priemnica_HeaderState(tempVals);

    QStringList tempdetailVals;
    for (int i = 0; i < COL_DETAIL; i++)
    {
        tempdetailVals << QString::number(colDetailWidth[i]);
    }

    s->Set_PriemnicaDetail_HeaderState(tempdetailVals);


    delete ui;
    delete model;
    delete header;
    delete model_2;
    delete header_2;
}


void PriemniciLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}

QString PriemniciLista::getSearchString()
{
    //    return ui->lineEdit->text();
}
void PriemniciLista::setSearchString(QString& searchText)
{
    //    ui->lineEdit->setText(searchText);
}


void PriemniciLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}


void PriemniciLista::procSectionResizedDetail(int a, int b, int c)
{
    colDetailWidth[a] = c;
}

void PriemniciLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    int i = modelX.row();
    m_row = modelX.row();
    ui->lineEdit_4->setText(model->item(i, 2)->text());
    ui->lineEdit_5->setText(model->item(i, 3)->text());
    ui->lineEdit_6->setText(model->item(i, 4)->text());
    ui->lineEdit_7->setText(model->item(i, 5)->text());
    ui->lineEdit_8->setText(model->item(i, 6)->text());
    m_selectedID = model->item(i, 1)->text();

    numOffset = 0;
    QString vLimit = "10000";
    QString vOffset = QString::number(numOffset);
    QString vDok_Id =  model->item(i, 1)->text();
    QString vDok_Tip = model->item(i, 2)->text();

    QStringList res = hlp->getallMagacin(vOffset, vLimit, vDok_Id, vDok_Tip);
    ShowDataDetail(res);
}

void PriemniciLista::on_pushButton_4_clicked()
{

    emit signalGetArtikal("", this);
}

void PriemniciLista::on_pushButton_5_clicked()
{

}

void PriemniciLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
}

void PriemniciLista::setTableColumnWidths(int ccolumn)
{
    Singleton *s = Singleton::Instance();
    QStringList tempWidth;
    for (int i = 0; i < ccolumn; i++)
    {
        tempWidth << QString::number(ui->tableView->columnWidth(i), 10);
    }
    //s->setColumnWidth(tempWidth);
}

void PriemniciLista::getTableColumnWidths(int ccolumn)
{
    //    QLocale loc;
    //    Singleton *s = Singleton::Instance();
    //    QStringList sss = s->getPriemniciColumnWidth();
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

void PriemniciLista::on_lineEdit_textChanged(const QString &arg1)
{
    numOffset = 0;
    QString vLimit = "500";
    QString vOffset = QString::number(numOffset);
    QString vDokID =  "%";
    QString vDokTip = "20";

    QStringList res = hlp->getallDokumenti(vOffset, vLimit,  vDokID,  vDokTip );
    ShowData(res);
}

void PriemniciLista::ShowData(QStringList& tlist)
{
    int r = tlist.count();
    int c = COL;
    model->clear();
    model->setRowCount(r);
    model->setColumnCount(c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("tid."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("dokument_id"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("document_tip"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("td"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("tds"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("komintent_id"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("komintent_naziv"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("prevoznik_id"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("prevoznik_naziv"));
    model->setHeaderData( 9, Qt::Horizontal, trUtf8("valuta"));
    model->setHeaderData( 10, Qt::Horizontal, trUtf8("kurs"));
    model->setHeaderData( 11, Qt::Horizontal, trUtf8("t_iznos_val"));
    model->setHeaderData( 12, Qt::Horizontal, trUtf8("t_ddv_val"));
    model->setHeaderData( 13, Qt::Horizontal, trUtf8("t_rabat_val"));
    model->setHeaderData( 14, Qt::Horizontal, trUtf8("t_iznos_plakanje_val"));
    model->setHeaderData( 15, Qt::Horizontal, trUtf8("t_iznos_ddv_den"));
    model->setHeaderData( 16, Qt::Horizontal, trUtf8("t_rabat_den"));
    model->setHeaderData( 17, Qt::Horizontal, trUtf8("t_iznos_plakanje_den"));
    model->setHeaderData( 18, Qt::Horizontal, trUtf8("t_transport_den"));
    model->setHeaderData( 19, Qt::Horizontal, trUtf8("t_carina_den"));
    model->setHeaderData( 20, Qt::Horizontal, trUtf8("t_ddv_den"));
    model->setHeaderData( 21, Qt::Horizontal, trUtf8("t_drugi_trosoci_den"));
    model->setHeaderData( 22, Qt::Horizontal, trUtf8("t_dok_status"));
    model->setHeaderData( 23, Qt::Horizontal, trUtf8("t_user_id"));
    model->setHeaderData( 24, Qt::Horizontal, trUtf8("t_komentar"));
    model->setHeaderData( 25, Qt::Horizontal, trUtf8("t_mag_id"));
    model->setHeaderData( 26, Qt::Horizontal, trUtf8("t_object_id"));


    ui->tableView->setModel(model);

    ui->tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;

    for(int ii = 0; ii < tlist.count();ii++)
    {
        QStringList itemRecord = tlist.at(ii).split("#;#");
        for (int i = 0; i < c; i++)
        {
            QStandardItem *item = new QStandardItem(itemRecord.at(i));
            item->setTextAlignment(Qt::AlignLeft);
            item->setEditable(false);
//            ui->tableView->setRowHeight(row, 20);
            ui->tableView->setColumnWidth(i, colWidth[i]);
            item->setEditable(false);
            model->setItem(row, i, item);
        }
        itemRecord.clear();
        row++;
    }
    QItemSelectionModel *sm = ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    tlist.clear();
    ui->tableView->show();
}
void PriemniciLista::ShowDataDetail(QStringList& tlist)
{
    int r = tlist.count();
    int c = COL_DETAIL;
    model_2->clear();
    model_2->setRowCount(r);
    model_2->setColumnCount(c);
    model_2->setHeaderData( 0, Qt::Horizontal, trUtf8("t_tid"));
    model_2->setHeaderData( 1, Qt::Horizontal, trUtf8("t_document_id"));
    model_2->setHeaderData( 2, Qt::Horizontal, trUtf8("t_document_tip"));
    model_2->setHeaderData( 3, Qt::Horizontal, trUtf8("t_komintent_id"));
    model_2->setHeaderData( 4, Qt::Horizontal, trUtf8("t_artikal_id"));
    model_2->setHeaderData( 5, Qt::Horizontal, trUtf8("t_artikal_naziv"));
    model_2->setHeaderData( 6, Qt::Horizontal, trUtf8("t_tip_artikal"));
    model_2->setHeaderData( 7, Qt::Horizontal, trUtf8("t_link_artikal"));
    model_2->setHeaderData( 8, Qt::Horizontal, trUtf8("t_edm"));
    model_2->setHeaderData( 9, Qt::Horizontal, trUtf8("t_vlez_nab_cena_bez_ddv"));
    model_2->setHeaderData( 10, Qt::Horizontal, trUtf8("t_vlez_nab_cena_so_ddv"));
    model_2->setHeaderData( 11, Qt::Horizontal, trUtf8("t_vlez_prenesen_ddv"));
    model_2->setHeaderData( 12, Qt::Horizontal, trUtf8("t_vlez_prenesen_ddv_denari"));
    model_2->setHeaderData( 13, Qt::Horizontal, trUtf8("t_vlez_rabat"));
    model_2->setHeaderData( 14, Qt::Horizontal, trUtf8("t_vlez_nabaven_iznos_so_ddv"));
    model_2->setHeaderData( 15, Qt::Horizontal, trUtf8("t_vlez_marza"));
    model_2->setHeaderData( 16, Qt::Horizontal, trUtf8("t_vlez_marza_den"));
    model_2->setHeaderData( 17, Qt::Horizontal, trUtf8("t_vlez_prod_cena_bez_ddv"));
    model_2->setHeaderData( 18, Qt::Horizontal, trUtf8("t_vlez_presmetan_ddv"));
    model_2->setHeaderData( 19, Qt::Horizontal, trUtf8("t_vlez_prod_cena_so_ddv"));
    model_2->setHeaderData( 20, Qt::Horizontal, trUtf8("t_vlez_prod_iznos_so_ddv"));
    model_2->setHeaderData( 21, Qt::Horizontal, trUtf8("t_izl_cena_bez_ddv_calc"));
    model_2->setHeaderData( 22, Qt::Horizontal, trUtf8("t_izl_cena_so_ddv_calc"));
    model_2->setHeaderData( 23, Qt::Horizontal, trUtf8("t_izl_cena_so_ddv_prod"));
    model_2->setHeaderData( 24, Qt::Horizontal, trUtf8("t_izl_ddv_prod"));
    model_2->setHeaderData( 25, Qt::Horizontal, trUtf8("t_kol"));
    model_2->setHeaderData( 26, Qt::Horizontal, trUtf8("t_mag_id"));
    model_2->setHeaderData( 27, Qt::Horizontal, trUtf8("t_status"));

    ui->tableView_2->setModel(model_2);

    ui->tableView_2->setHorizontalHeader(header_2);
    header_2->show();
    int row = 0;

    for(int ii = 0; ii < tlist.count();ii++)
    {
        QStringList itemRecord = tlist.at(ii).split("#;#");
        for (int i = 0; i < c; i++)
        {
            QStandardItem *item = new QStandardItem(itemRecord.at(i));
            item->setTextAlignment(Qt::AlignLeft);
            item->setEditable(false);
//            ui->tableView_2->setRowHeight(row, 20);
            ui->tableView_2->setColumnWidth(i, colDetailWidth[i]);
            item->setEditable(false);
            model_2->setItem(row, i, item);
        }
        itemRecord.clear();
        row++;
    }
    tlist.clear();
    connect(header_2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResizedDetail(int, int, int)));

    ui->tableView_2->show();
}


void PriemniciLista::on_pushButton_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}
void PriemniciLista::on_pushButton_2_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F3, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}
void PriemniciLista::pressF2()
{
    emit signalpressF2();
}
void PriemniciLista::pressF3()
{
    emit signalpressF3();
}
void PriemniciLista::pressEscape()
{
    emit signalpressEscape();
}
void PriemniciLista::procReturn(QString)
{
    int stop;
}


