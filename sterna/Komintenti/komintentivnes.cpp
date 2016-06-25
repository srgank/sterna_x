#include "komintentivnes.h"
#include "ui_komintentivnes.h"

KomintentiVnes::KomintentiVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::KomintentiVnes)
{
    ui->setupUi(this);
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
}

KomintentiVnes::~KomintentiVnes()
{
 //   delete hlp;
    delete ui;
}
void KomintentiVnes::pressEscape()
{
    emit signalpressEscape();
}

void KomintentiVnes::getResultEX(QStringList& tlist)
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(trUtf8("Information"));
    msgBox->setText(trUtf8("Податокот е успешно внесен"));
    msgBox->setStandardButtons(QMessageBox::Yes);
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->exec();
    delete msgBox;
    setFocus();
    ui->pushButton->setEnabled(true);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}


void KomintentiVnes::on_pushButton_clicked()
{

    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();

//
}

void KomintentiVnes::pressEnter()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void KomintentiVnes::pressReturn()
{
    if(ui->pushButton->hasFocus())
    {
        on_pushButton_clicked();
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}
