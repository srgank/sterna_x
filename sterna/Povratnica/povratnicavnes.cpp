#include "povratnicavnes.h"
#include "ui_povratnicavnes.h"

PovratniciVnes::PovratniciVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::PovratniciVnes)
    ,hlp(0)

{
    ui->setupUi(this);
    ui->lineEdit_2->setFocus();
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    hlp = new QHelperC(this);
    connect(hlp, SIGNAL(signalResultInsertArticle(QStringList &)), this, SLOT(getResultEX(QStringList &)));
}

PovratniciVnes::~PovratniciVnes()
{
    delete hlp;
    delete ui;
}
void PovratniciVnes::pressEscape()
{
    emit signalpressEscape();
}



void PovratniciVnes::getResultEX(QStringList& tlist)
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(trUtf8("Information"));
    msgBox->setText(trUtf8("Податокот е успешно внесен"));
    msgBox->setStandardButtons(QMessageBox::Yes);
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->exec();
    delete msgBox;
    setFocus();
//    ui->pushButton->setEnabled(true);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}


void PovratniciVnes::on_pushButton_clicked()
{

    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();

    
}

void PovratniciVnes::setFocusArtikal(artikalT t)
{
    ui->lineEdit_2->setFocus();
    ui->lineEdit_2->selectAll();
    ui->lineEdit_2->setText(t.artikal);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void PovratniciVnes::setFocusKomintent(QString t)
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
    ui->lineEdit->setText(t);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void PovratniciVnes::pressReturn()
{
    if(ui->pushButton_4->hasFocus())
    {
        //on_pushButton_released();
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

