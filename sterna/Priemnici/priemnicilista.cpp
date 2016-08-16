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

    getTableColumnWidths(COL);
    on_lineEdit_textChanged("%%");
}

PriemniciLista::~PriemniciLista()
{
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
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName =  "%";
    QString vSearchBy = "artikal";

    QStringList res = hlp->getallDokumenti(vOffset, vLimit, vSName, vSearchBy);
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
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName =  "%";
    QString vSearchBy = "artikal";

    QStringList res = hlp->getallDokumenti(vOffset, vLimit, vSName, vSearchBy);
    ShowData(res);
}

void PriemniciLista::ShowData(QStringList& tlist)
{
    int r = tlist.count();
    int c = COL;
    model->clear();
    model->setRowCount(r);
    model->setColumnCount(c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Кат.број"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Ддв"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Производител"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Категорија"));

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
            ui->tableView->setRowHeight(row, 20);
//            ui->tableView->setColumnWidth(i, colWidth[i]);
            ui->tableView->setColumnWidth(i, 100);
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
    int c = COL;
    model_2->clear();
    model_2->setRowCount(r);
    model_2->setColumnCount(c);
    model_2->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model_2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model_2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model_2->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model_2->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
    model_2->setHeaderData( 5, Qt::Horizontal, trUtf8("Кат.број"));
    model_2->setHeaderData( 6, Qt::Horizontal, trUtf8("Ддв"));
    model_2->setHeaderData( 7, Qt::Horizontal, trUtf8("Производител"));
    model_2->setHeaderData( 8, Qt::Horizontal, trUtf8("Категорија"));

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
            ui->tableView_2->setRowHeight(row, 20);
            ui->tableView_2->setColumnWidth(i, colWidth[i]);
            item->setEditable(false);
            model_2->setItem(row, i, item);
        }
        itemRecord.clear();
        row++;
    }
    tlist.clear();
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


