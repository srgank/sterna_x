#include "artiklilista.h"
#include "ui_artiklilista.h"



ArtikliLista::ArtikliLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ArtikliLista)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    m_row = 0;
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    ui->tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    ui->tableView->setSelectionMode( QAbstractItemView::SingleSelection );
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    numOffset = 0;
//    QString vOffset = QString::number(numOffset);
//    QString vLimit = "50";
//    QString vSName = "%";
//    QString vSearchBy = "artikal";

    BaseInstallEventFilter(ui->gridLayout);
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, this);

    ui->tableView->setFont(this->font());

    QStringList tempVals = s->Get_Art_HeaderState();
    colWidth = s->loadWidthList(tempVals, COL);

    numOffset = 0;
    ui->tableView->setModel(model);
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
}


void ArtikliLista::initProc(int searchIDList, QString& searchStrList, int searchOffsetList)
{
    seTableSelected_Offset(searchOffsetList);
    ui->LE_prebaraj->setText(searchStrList);
    on_LE_prebaraj_textChanged(searchStrList);
    seTableSelectedRow(searchIDList);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

ArtikliLista::~ArtikliLista()
{
    disconnect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    disconnect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));

    Singleton *s = Singleton::Instance();
    QStringList tempVals = s->saveWidthList(colWidth);
    s->Set_Art_HeaderState(tempVals);
    delete ui;
    delete model;
    delete header;
}


void ArtikliLista::pressF2()
{
    emit signalpressF2();
}
void ArtikliLista::pressF3()
{
    emit signalpressF3();
}
void ArtikliLista::pressEscape()
{
    emit signalpressEscape();
}

void ArtikliLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString ArtikliLista::getSearchString()
{
    return ui->LE_prebaraj->text();
}
void ArtikliLista::setSearchString(QString& searchText)
{
    ui->LE_prebaraj->setText(searchText);
}


void ArtikliLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}


void ArtikliLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    int i = modelX.row();
    m_row = modelX.row();
    ui->le_id->setText(model->item(i, 0)->text());
    ui->le_sifra->setText(model->item(i, 1)->text());
    ui->le_artikal_naziv->setText(model->item(i, 2)->text());
    ui->le_edm->setText(model->item(i, 3)->text());
    ui->le_referenca->setText(model->item(i, 4)->text());
    ui->le_kataloski_broj->setText(model->item(i, 5)->text());
    ui->le_ddv->setText(model->item(i, 6)->text());
    m_selectedID = model->item(i, 0)->text();
    int stop = 0;
}

void ArtikliLista::on_pushButton_5_clicked()
{
    numOffset -= 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text();
    QString vSearchBy = "artikal";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    resArtikliTemp = res;
    b.ShowData(res, model, header, ui->tableView, colWidth);
}

void ArtikliLista::on_pushButton_6_clicked()
{
    numOffset += 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text();
    QString vSearchBy = "artikal";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    resArtikliTemp = res;
    b.ShowData(res, model, header, ui->tableView, colWidth);
}

void ArtikliLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
    numOffset = 0;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text();
    QString vSearchBy = "artikal";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    resArtikliTemp = res;
    b.ShowData(res, model, header, ui->tableView, colWidth);
}


void ArtikliLista::on_pb_vnesi_nov_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void ArtikliLista::on_pb_koregiraj_postoecki_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F3, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void ArtikliLista::pressReturn()
{
    if(ui->tableView->hasFocus())
    {
        artikalT currentArtikal = b.getCurrentArtikalKomintentData(resArtikliTemp, ui->le_id->text());
        emit signalReturnResult( currentArtikal);
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}

void ArtikliLista::updateFont()
{
    Singleton *s = Singleton::Instance();
    QString str_font = "font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
    BaseUpdateFonts(ui->gridLayout, str_font);
}

bool ArtikliLista::eventFilter(QObject *object, QEvent *event)
{
    Singleton *s = Singleton::Instance();
    if (event->type() == QEvent::FocusIn)
    {
        QString str_yellow = "background-color: lightyellow; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
        ((QWidget*)object)->setStyleSheet(str_yellow);
    }
    if (event->type() == QEvent::FocusOut)
    {
        str_none = "background-color: none; font-size: "+QString::number(s->getGlobalFontSize())+"pt;";
        ((QWidget*)object)->setStyleSheet(str_none);
    }
    return false;
}

void ArtikliLista::Refresh()
{
    updateFont();
}
