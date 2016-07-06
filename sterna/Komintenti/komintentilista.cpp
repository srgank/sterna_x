#include "komintentilista.h"
#include "ui_komintentilista.h"



KomintentiLista::KomintentiLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::KomintentiLista)
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
    header = new QHeaderView(Qt::Horizontal, this);
    getTableColumnWidths(COL);
    on_lineEditPrebaraj_textChanged("%%");
    pressReturn();
}

KomintentiLista::~KomintentiLista()
{
    delete ui;
    delete model;
    delete header;
}
void KomintentiLista::pressF2()
{
    emit signalpressF2();
}
void KomintentiLista::pressF3()
{
    emit signalpressF3();
}
void KomintentiLista::pressEscape()
{
    emit signalpressEscape();
}

void KomintentiLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString KomintentiLista::getSearchString()
{
    return ui->lineEditPrebaraj->text();
}
void KomintentiLista::setSearchString(QString& searchText)
{
    ui->lineEditPrebaraj->setText(searchText);
}


void KomintentiLista::ShowData(QStringList& tlist)
{
    int r = tlist.count();
    int c = COL;
    model->clear();
    model->setRowCount(r);
    model->setColumnCount(c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Назив"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Адреса"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Тел"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Мобил"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Жиро сметка"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Едб"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Депонент"));
    model->setHeaderData( 9, Qt::Horizontal, trUtf8("Шиф.Дејност"));
    model->setHeaderData( 10, Qt::Horizontal, trUtf8("МБ"));
    model->setHeaderData( 11, Qt::Horizontal, trUtf8("Забелешка"));
    model->setHeaderData( 12, Qt::Horizontal, trUtf8("Забелешка"));
    model->setHeaderData( 13, Qt::Horizontal, trUtf8("Рабат"));
    model->setHeaderData( 14, Qt::Horizontal, trUtf8("Град"));




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


void KomintentiLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}



void KomintentiLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Назив"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Адреса"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Тел"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Мобил"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Жиро сметка"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Едб"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Депонент"));
    model->setHeaderData( 9, Qt::Horizontal, trUtf8("Шиф.Дејност"));
    model->setHeaderData( 10, Qt::Horizontal, trUtf8("МБ"));
    model->setHeaderData( 11, Qt::Horizontal, trUtf8("Забелешка"));
    model->setHeaderData( 12, Qt::Horizontal, trUtf8("Забелешка"));
    model->setHeaderData( 13, Qt::Horizontal, trUtf8("Рабат"));
    model->setHeaderData( 14, Qt::Horizontal, trUtf8("Град"));

    int i = modelX.row();
    m_row = modelX.row();
    ui->lineEdit_2->setText(model->item(i, 0)->text());
    ui->lineEdit_3->setText(model->item(i, 1)->text());
    ui->lineEdit_4->setText(model->item(i, 2)->text());
    ui->lineEdit_5->setText(model->item(i, 3)->text());
    ui->lineEdit_6->setText(model->item(i, 4)->text());
    ui->lineEdit_7->setText(model->item(i, 5)->text());
    ui->lineEdit_8->setText(model->item(i, 6)->text());
//    m_selectedID = model->item(i, 1)->text();
    int stop = 0;
}

void KomintentiLista::on_pushButton_4_clicked()
{
    ui->pushButton_4->setEnabled(false);
    numOffset -= 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->lineEditPrebaraj->text() + "%";
    QString vSearchBy = "artikal";
    QStringList listRes = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    ShowData(listRes);
    ui->pushButton_4->setEnabled(true);
}

void KomintentiLista::on_pushButton_5_clicked()
{
    ui->pushButton_5->setEnabled(false);
    numOffset += 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->lineEditPrebaraj->text() + "%";
    QString vSearchBy = "artikal";
    QStringList listRes = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    ShowData(listRes);
    ui->pushButton_5->setEnabled(true);
}



void KomintentiLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
}

void KomintentiLista::setTableColumnWidths(int ccolumn)
{
    Singleton *s = Singleton::Instance();
    QStringList tempWidth;
    for (int i = 0; i < ccolumn; i++)
    {
        tempWidth << QString::number(ui->tableView->columnWidth(i), 10);
    }
    s->setKomintentiColumnWidth(tempWidth);
}

void KomintentiLista::getTableColumnWidths(int ccolumn)
{
    QLocale loc;
    Singleton *s = Singleton::Instance();
    QStringList sss = s->getKomintentiColumnWidth();
    if (sss.count() == ccolumn)
    {
        for (int i1 = 0; i1 < ccolumn; i1++)
        {
            colWidth[i1] = loc.toInt(sss.at(i1));
        }
    }
    else
    {
        for (int i1 = 0; i1 < ccolumn; i1++)
        {
            colWidth[i1] = 100;
        }
    }
}




void KomintentiLista::on_lineEdit_textChanged(const QString &arg1)
{

}

void KomintentiLista::on_pushButton_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}

void KomintentiLista::on_pushButton_2_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F3, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}


void KomintentiLista::pressReturn()
{
    if(ui->tableView->hasFocus())
    {
        emit signalReturnResult( ui->lineEdit_4->text());
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}

void KomintentiLista::on_lineEditPrebaraj_textChanged(const QString &arg1)
{
    numOffset = 0;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->lineEditPrebaraj->text() + "%";
    QString vSearchBy = "artikal";
    QStringList listRes = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    ShowData(listRes);
}
