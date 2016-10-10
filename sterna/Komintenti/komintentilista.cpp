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

    ui->tableView->setFont(this->font());
    ui->tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    ui->tableView->setSelectionMode( QAbstractItemView::SingleSelection );
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    numOffset = 0;
    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "";
    QString vSearchBy = "naziv";
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, this);
    BaseInstallEventFilter(ui->gridLayout);
    QStringList tempVals = s->Get_Kom_HeaderState();
    if (!tempVals.isEmpty()){
        for (int i = 0; i < tempVals.count(); i++)        {
            colWidth << tempVals.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL; i++)        {
            colWidth << 100;
        }
    }

    numOffset = 0;
    numOffset = 0;
    ui->tableView->setModel(model);
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    updateFont();

}

void KomintentiLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->lineEditPrebaraj->setText(searchStrList);

    on_lineEditPrebaraj_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}


KomintentiLista::~KomintentiLista()
{
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    disconnect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));

    Singleton *s = Singleton::Instance();
    QStringList tempVals;
    for (int i = 0; i < colWidth.count(); i++)
    {
        tempVals << QString::number(colWidth.at(i));
    }

    s->Set_Kom_HeaderState(tempVals);

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




void KomintentiLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}



void KomintentiLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{

    int i = modelX.row();
    m_row = modelX.row();
    ui->lineEdit_2->setText(model->item(i, 0)->text());
    ui->lineEdit_3->setText(model->item(i, 1)->text());
    ui->lineEdit_4->setText(model->item(i, 2)->text());
    ui->lineEdit_5->setText(model->item(i, 3)->text());
    ui->lineEdit_6->setText(model->item(i, 4)->text());
    ui->lineEdit_7->setText(model->item(i, 5)->text());
    ui->lineEdit_8->setText(model->item(i, 6)->text());
    m_selectedID = model->item(i, 0)->text();
    int stop = 0;
}

void KomintentiLista::on_pushButton_4_clicked()
{
    ui->pushButton_4->setEnabled(false);
    numOffset -= 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->lineEditPrebaraj->text() + "";
    QString vSearchBy = "naziv";
    QList<komintentT> listRes = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    resKomintentTemp = listRes;
    b.ShowData(listRes, model, header, ui->tableView, colWidth);
    ui->pushButton_4->setEnabled(true);
}

void KomintentiLista::on_pushButton_5_clicked()
{
    ui->pushButton_5->setEnabled(false);
    numOffset += 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->lineEditPrebaraj->text() + "";
    QString vSearchBy = "naziv";
    QList<komintentT> listRes = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    resKomintentTemp = listRes;
    b.ShowData(listRes, model, header, ui->tableView, colWidth);
    ui->pushButton_5->setEnabled(true);
}



void KomintentiLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
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
        komintentT currentKomintent = b.getCurrentArtikalKomintentData(resKomintentTemp, m_selectedID);

        emit signalReturnResult( currentKomintent);
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
    QString vSName = ui->lineEditPrebaraj->text() + "";
    QString vSearchBy = "naziv";
    QList<komintentT> listRes = hlp->getallKomintenti(vOffset, vLimit, vSName, vSearchBy);
    resKomintentTemp = listRes;
    b.ShowData(listRes, model, header, ui->tableView, colWidth);
}

void KomintentiLista::updateFont()
{
    Singleton *s = Singleton::Instance();
    QString str_font = "font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    BaseUpdateFonts(ui->gridLayout, str_font);
}
bool KomintentiLista::eventFilter(QObject *object, QEvent *event)
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
void KomintentiLista::Refresh()
{
    updateFont();
}
