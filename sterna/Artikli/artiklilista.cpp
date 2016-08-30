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

    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    numOffset = 0;
    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "%";
    QString vSearchBy = "artikal";
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, this);

    ui->tableView->setFont(this->font());

    QStringList tempVals = s->Get_Art_HeaderState();
    if (!tempVals.isEmpty()){
        for (int i = 0; i < COL; i++)        {
            colWidth[i] = tempVals.at(i).toInt();
        }
    }else{
        for (int i = 0; i < COL; i++)        {
            colWidth[i] = 100;
        }
    }

    numOffset = 0;

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
    Singleton *s = Singleton::Instance();
    QStringList tempVals;
    for (int i = 0; i < COL; i++)
    {
        tempVals << QString::number(colWidth[i]);
    }

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
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Кат.број"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Ддв"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Производител"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Категорија"));

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
    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    b.ShowData(res, model, header, ui->tableView);
}

void ArtikliLista::on_pushButton_6_clicked()
{
    numOffset += 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    b.ShowData(res, model, header, ui->tableView);
}

void ArtikliLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
    QList<artikalT> res = hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
    b.ShowData(res, model, header, ui->tableView);
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
        emit signalReturnResult( ui->le_artikal_naziv->text());
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}

void ArtikliLista::updateFont()
{
    ui->tableView->setFont(this->font());
    repaint();
}
