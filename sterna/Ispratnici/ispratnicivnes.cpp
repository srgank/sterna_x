#include "ispratnicivnes.h"
#include "ui_ispratnicivnes.h"

IspratniciVnes::IspratniciVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::IspratniciVnes)
  ,hlp(0)

{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, 0);

    QStringList tempValsDetail = s->Get_IspratnicaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);
    bd = new QBTemplate<fakturiDetailT>();
    ui->tableView->setModel(model);
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    PressKeyTAB(this);
}

IspratniciVnes::~IspratniciVnes()
{
    delete hlp;
    delete ui;
    delete bd;
    bd = 0;
}
void IspratniciVnes::pressEscape()
{
    emit signalpressEscape();
}






void IspratniciVnes::on_pushButton_released()
{

    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();

    
}



void IspratniciVnes::setFocusArtikal(artikalT t)
{
    ui->lineEdit_2->setFocus();
    ui->lineEdit_2->selectAll();
    ui->lineEdit_2->setText(t.artikal);
    PressKeyTAB(this);
}

void IspratniciVnes::setFocusKomintent(QString t)
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
    ui->lineEdit->setText(t);
    PressKeyTAB(this);
}

void IspratniciVnes::pressReturn()
{
    if(ui->pushButton_3->hasFocus())
    {
        procAddItem();
        showData();
    }
    if(ui->pushButton_6->hasFocus())
    {
        procDeleteItem();
        showData();
    }
    else if(ui->lineEdit->hasFocus())
    {
        emit signalGetKomintent("", (QWidget*)this);
    }
    else if(ui->lineEdit_2->hasFocus())
    {
        emit signalGetArtikal("", (QWidget*)this);
    }
    else
    {
        PressKeyTAB(this);
    }

}

void IspratniciVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    m_row = modelX.row();
}

void IspratniciVnes::initProc(faktura_trans m_data)
{
    resFakturaItems = m_data.data2;
    showData();
}

void IspratniciVnes::procDeleteItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->RemoveItem(data, m_row);
    resFakturaItems = data;
}

void IspratniciVnes::procAddItem(){
    QList<fakturiDetailT> data = resFakturaItems;
    fakturiDetailT item;
    item.artikal_naziv = ui->lineEdit_2->text();
    bd->AddItem(data, item);
    resFakturaItems = data;
}


void IspratniciVnes::showData(){
    QList<fakturiDetailT> data = resFakturaItems;
    bd->ShowData(data, model, header, ui->tableView, colDetailWidth);
}

void IspratniciVnes::on_pushButton_6_clicked()
{
    PressKeyReturn(this);
}


void IspratniciVnes::on_pushButton_3_clicked()
{
    PressKeyReturn(this);
}
void IspratniciVnes::updateFont()
{
    ui->tableView->setFont(this->font());
    repaint();
}
