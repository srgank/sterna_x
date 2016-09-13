#include "profakturivnes.h"
#include "ui_profakturivnes.h"

ProFakturiVnes::ProFakturiVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ProFakturiVnes)
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

    QStringList tempValsDetail = s->Get_ProFakturaDetail_HeaderState();
    colDetailWidth = s->loadWidthList(tempValsDetail, COL_DETAIL);

    ui->tableView->setModel(model);
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    sm =ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
}

ProFakturiVnes::~ProFakturiVnes()
{
    delete hlp;
    delete ui;
}
void ProFakturiVnes::pressEscape()
{
    emit signalpressEscape();
}
void ProFakturiVnes::on_pushButton_released()
{

    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();

    
}
void ProFakturiVnes::setFocusArtikal(artikalT t)
{
    ui->lineEdit_2->setFocus();
    ui->lineEdit_2->selectAll();
    ui->lineEdit_2->setText(t.artikal);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void ProFakturiVnes::setFocusKomintent(QString t)
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
    ui->lineEdit->setText(t);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void ProFakturiVnes::pressReturn()
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
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }

}
void ProFakturiVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    m_row = modelX.row();
}
void ProFakturiVnes::initProc(profaktura_trans m_data)
{
    resFakturaItems = m_data.data2;
    showData();
}
void ProFakturiVnes::procDeleteItem(){
    QList<profakturiDetailT> data = resFakturaItems;
    bd.RemoveItem(data, m_row);
    resFakturaItems = data;
}
void ProFakturiVnes::procAddItem(){
    QList<profakturiDetailT> data = resFakturaItems;
    profakturiDetailT item;
    item.artikal_naziv = ui->lineEdit_2->text();
    bd.AddItem(data, item);
    resFakturaItems = data;
}
void ProFakturiVnes::showData(){
    QList<profakturiDetailT> data = resFakturaItems;
    bd.ShowData(data, model, header, ui->tableView, colDetailWidth);
}
void ProFakturiVnes::on_pushButton_6_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void ProFakturiVnes::on_pushButton_3_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

