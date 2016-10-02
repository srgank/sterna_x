#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xx.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    ,m_artikliModul(0)
    ,m_komintentiModul(0)
    ,m_priemnicaModul(0)
    ,m_fakturaModul(0)
    ,m_ispratnicaModul(0)
    ,m_smetkaModul(0)
    ,m_profakturaModul(0)
    ,m_povratnicaModul(0)
    ,m_narackaModul(0)
    ,m_printModul(0)
{
    ui->setupUi(this);
    m_artikliModul_description = trUtf8("Артикли");
    m_komintentiModul_description = trUtf8("Коминтенти");
    m_priemnicaModul_description = trUtf8("Приемници");
    m_fakturaModul_description = trUtf8("Фактура");
    m_ispratnicaModul_description = trUtf8("Испратница");
    m_smetkaModul_description = trUtf8("Сметка");
    m_profakturaModul_description = trUtf8("Про-Фактура");
    m_povratnicaModul_description = trUtf8("Повратница");
    m_narackaModul_description = trUtf8("Нарачка");
    m_printModul_description = trUtf8("Print");


    dock = new QDockWidget(this);
    m_left = new Left(dock);
    loadRecordsFromFile();

}

MainWindow::~MainWindow()
{
    Singleton *s = Singleton::Instance();
    QStringList art_HeaderState = s->Get_Art_HeaderState();
    QStringList kom_HeaderState = s->Get_Kom_HeaderState();

    QStringList priemnica_HeaderState = s->Get_Priemnica_HeaderState();
    QStringList priemnicaDetail__HeaderState = s->Get_PriemnicaDetail_HeaderState();

    QStringList ispratnica_HeaderState = s->Get_Ispratnica_HeaderState();
    QStringList ispratnicaDetail__HeaderState = s->Get_IspratnicaDetail_HeaderState();

    QStringList povratnica_HeaderState = s->Get_Povratnica_HeaderState();
    QStringList povratnicaDetail__HeaderState = s->Get_PovratnicaDetail_HeaderState();

    QStringList faktura_HeaderState = s->Get_Faktura_HeaderState();
    QStringList fakturaDetail__HeaderState = s->Get_FakturaDetail_HeaderState();

    QStringList profaktura_HeaderState = s->Get_ProFaktura_HeaderState();
    QStringList profakturaDetail__HeaderState = s->Get_ProFakturaDetail_HeaderState();

    QStringList nalog_HeaderState = s->Get_Nalog_HeaderState();
    QStringList nalogDetail__HeaderState = s->Get_NalogDetail_HeaderState();

    QStringList naracka_HeaderState = s->Get_Naracka_HeaderState();
    QStringList narackaDetail__HeaderState = s->Get_NarackaDetail_HeaderState();

    QStringList smetka_HeaderState = s->Get_Smetka_HeaderState();
    QStringList smetkaDetail__HeaderState = s->Get_SmetkaDetail_HeaderState();

    saveRecordsFromFile(
         art_HeaderState,
         kom_HeaderState,
         priemnica_HeaderState,
         priemnicaDetail__HeaderState,
         ispratnica_HeaderState,
         ispratnicaDetail__HeaderState,
         povratnica_HeaderState,
         povratnicaDetail__HeaderState,
         faktura_HeaderState,
         fakturaDetail__HeaderState,
         profaktura_HeaderState,
         profakturaDetail__HeaderState,
         nalog_HeaderState,
         nalogDetail__HeaderState,
         naracka_HeaderState,
         narackaDetail__HeaderState,
         smetka_HeaderState,
         smetkaDetail__HeaderState
       );
    delete ui;
}

void MainWindow::createDockWindows()
{
    dock->setWindowTitle(tr("Navigate"));
    dock->setFixedWidth(210);
    dock->setFixedHeight(500);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(m_left);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    ui->centralWidget->showMaximized();
    QDesktopWidget *desk = new QDesktopWidget();
    QRect screenRect = desk->screenGeometry();
    delete desk;
    int  mLeftW = m_left->width();
    rMain = QRect(0, 0, screenRect.width() - mLeftW, screenRect.height() - 100);
    Singleton *s = Singleton::Instance();
    s->setGlobalFontSize(10);
    s->setMainRect(rMain);
    s->Set_Art_HeaderState(art);
    s->Set_Kom_HeaderState(kom);
    s->Set_Priemnica_HeaderState(priemnica);
    s->Set_PriemnicaDetail_HeaderState(priemnicaDetail);
    s->Set_Ispratnica_HeaderState(ispratnica);
    s->Set_IspratnicaDetail_HeaderState(ispratnicaDetail);
    s->Set_Povratnica_HeaderState(povratnica);
    s->Set_PovratnicaDetail_HeaderState(povratnicaDetail);
    s->Set_Faktura_HeaderState(faktura);
    s->Set_FakturaDetail_HeaderState(fakturaDetail);
    s->Set_ProFaktura_HeaderState(profaktura);
    s->Set_ProFakturaDetail_HeaderState(profakturaDetail);
    s->Set_Nalog_HeaderState(nalog);
    s->Set_NalogDetail_HeaderState(nalogDetail);
    s->Set_Naracka_HeaderState(naracka);
    s->Set_NarackaDetail_HeaderState(narackaDetail);
    s->Set_Smetka_HeaderState(smetka);
    s->Set_SmetkaDetail_HeaderState(smetkaDetail);
    s->Set_UrlHost("http://92.53.51.86:5002/");
//    s->Set_UrlHost("http://127.0.0.1:5002/");
}


void MainWindow::loadRecordsFromFile()
{
    QString filename = "config.bin";
    QFile file( filename);
    if( !file.open( QIODevice::ReadOnly ) )
        return;
    QDataStream stream( &file );
    stream.setVersion( QDataStream::Qt_4_2 );

    stream >> art;
    stream >> kom;
    stream >>  priemnica;
    stream >>  priemnicaDetail;
    stream >>  ispratnica;
    stream >>  ispratnicaDetail;
    stream >>  povratnica;
    stream >>  povratnicaDetail;
    stream >>  faktura;
    stream >>  fakturaDetail;
    stream >>  profaktura;
    stream >>  profakturaDetail;
    stream >>  nalog;
    stream >>  nalogDetail;
    stream >>  naracka;
    stream >>  narackaDetail;
    stream >>  smetka;
    stream >>  smetkaDetail;

    file.close();
}

void MainWindow::saveRecordsFromFile(
    QStringList &art_HeaderState,
    QStringList & kom_HeaderState,

    QStringList & priemnica_HeaderState,
    QStringList & priemnicaDetail__HeaderState,

    QStringList & ispratnica_HeaderState,
    QStringList & ispratnicaDetail__HeaderState,

    QStringList & povratnica_HeaderState,
    QStringList & povratnicaDetail__HeaderState,

    QStringList & faktura_HeaderState,
    QStringList & fakturaDetail__HeaderState,

    QStringList & profaktura_HeaderState,
    QStringList & profakturaDetail__HeaderState,

    QStringList & nalog_HeaderState,
    QStringList & nalogDetail__HeaderState,

    QStringList & naracka_HeaderState,
    QStringList & narackaDetail__HeaderState,

    QStringList & smetka_HeaderState,
    QStringList & smetkaDetail__HeaderState
   )
{
    QString filename = "config.bin";
    QFile file( filename);
    if( !file.open( QIODevice::WriteOnly ) )
        return;
    QDataStream stream( &file );
    stream.setVersion( QDataStream::Qt_4_2 );
    stream <<  art_HeaderState;
    stream <<  kom_HeaderState;

    stream <<  priemnica_HeaderState;
    stream <<  priemnicaDetail__HeaderState;

    stream <<  ispratnica_HeaderState;
    stream <<  ispratnicaDetail__HeaderState;

    stream <<  povratnica_HeaderState;
    stream <<  povratnicaDetail__HeaderState;

    stream <<  faktura_HeaderState;
    stream <<  fakturaDetail__HeaderState;

    stream <<  profaktura_HeaderState;
    stream <<  profakturaDetail__HeaderState;

    stream <<  nalog_HeaderState;
    stream <<  nalogDetail__HeaderState;

    stream <<  naracka_HeaderState;
    stream <<  narackaDetail__HeaderState;

    stream <<  smetka_HeaderState;
    stream <<  smetkaDetail__HeaderState;

    file.close();
}




void MainWindow::on_actionClose_triggered()
{
    if (m_left)
    {
        m_left->setFocus();
        m_left->getSelection();
    }
    closeMyWidget();
}


void MainWindow::updateNavigator(QWidget* a, QWidget* b)
{
    b->setFocus();
    on_actionClose_triggered();
    a->setFocus();
    ((BaseForm*)a)->Refresh();
    m_left->updateSelection(a);
}

void MainWindow::closeMyWidget()
{
    if (qobject_cast<FormPrint*>(qApp->focusWidget()))
    {
        deleteMyWidget<FormPrint>((FormPrint*)qApp->focusWidget(), false);
        m_printModul = NULL;

    }
    if (qobject_cast<Artikli*>(qApp->focusWidget()))
    {
        deleteMyWidget<Artikli>((Artikli*)qApp->focusWidget(),true);
        m_artikliModul = NULL;
    }
    if (qobject_cast<Komintenti*>(qApp->focusWidget()))
    {
        deleteMyWidget<Komintenti>((Komintenti*)qApp->focusWidget(), true);
        m_komintentiModul = NULL;
    }
    if (qobject_cast<Priemnici*>(qApp->focusWidget()))
    {
        deleteMyWidget<Priemnici>((Priemnici*)qApp->focusWidget(), true);
        m_priemnicaModul = NULL;
    }
    if (qobject_cast<Fakturi*>(qApp->focusWidget()))
    {
        deleteMyWidget<Fakturi>((Fakturi*)qApp->focusWidget(), true);
        m_fakturaModul = NULL;
    }
    if (qobject_cast<Ispratnici*>(qApp->focusWidget()))
    {
        deleteMyWidget<Ispratnici>((Ispratnici*)qApp->focusWidget(), true);
        m_ispratnicaModul = NULL;
    }
    if (qobject_cast<Smetki*>(qApp->focusWidget()))
    {
        deleteMyWidget<Smetki>((Smetki*)qApp->focusWidget(), true);
        m_smetkaModul = NULL;
    }
    if (qobject_cast<ProFakturi*>(qApp->focusWidget()))
    {
        deleteMyWidget<ProFakturi>((ProFakturi*)qApp->focusWidget(), true);
        m_profakturaModul = NULL;
    }
    if (qobject_cast<Povratnici*>(qApp->focusWidget()))
    {
        deleteMyWidget<ProFakturi>((ProFakturi*)qApp->focusWidget(), true);
        m_povratnicaModul = NULL;
    }
}
//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionArtikal_triggered()
{
    QString text = "";
    procCreateModulArtikal(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionKomintent_triggered()
{
    QString text = "";
    procCreateModulKomintent(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionPriemnica_triggered()
{
    QString text = "";
    procCreateModulPriemnica(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionFaktura_triggered()
{
    QString text = "";
    procCreateModulFaktura(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::procCreateModulArtikal(QString, QWidget *p)
{
    m_artikliModul = showMyWidget<Artikli, BaseForm, QWidget>(m_artikliModul, m_artikliModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_artikliModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}

void MainWindow::procCreateModulKomintent(QString, QWidget *p)
{
    m_komintentiModul = showMyWidget<Komintenti, BaseForm, QWidget>(m_komintentiModul, m_komintentiModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_komintentiModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}
void MainWindow::procCreateModulPriemnica(QString, QWidget *p)
{
    m_priemnicaModul = showMyWidget<Priemnici, BaseForm, QWidget>(m_priemnicaModul, m_priemnicaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_priemnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_priemnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_priemnicaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}
void MainWindow::procCreateModulFaktura(QString, QWidget *p)
{
    ui->actionFaktura->setEnabled(false);
    m_fakturaModul = showMyWidget<Fakturi, BaseForm, QWidget>(m_fakturaModul, m_fakturaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_fakturaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_fakturaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_fakturaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    ui->actionFaktura->setEnabled(true);
}

void MainWindow::procCreateModulIspratnica(QString, QWidget *p)
{
    m_ispratnicaModul = showMyWidget<Ispratnici, BaseForm, QWidget>(m_ispratnicaModul, m_ispratnicaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_ispratnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_ispratnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_ispratnicaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}

void MainWindow::procCreateModulSmetka(QString, QWidget *p)
{
    m_smetkaModul = showMyWidget<Smetki, BaseForm, QWidget>(m_smetkaModul, m_smetkaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_smetkaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_smetkaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_smetkaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}


void MainWindow::procCreateModulProFaktura(QString, QWidget *p)
{
    m_profakturaModul = showMyWidget<ProFakturi, BaseForm, QWidget>(m_profakturaModul, m_profakturaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_profakturaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_profakturaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_profakturaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

}

void MainWindow::procCreateModulPovratnica(QString, QWidget *p)
{
    m_povratnicaModul = showMyWidget<Povratnici, BaseForm, QWidget>(m_povratnicaModul, m_povratnicaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_povratnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_povratnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_povratnicaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

}


void MainWindow::procCreateModulNaracka(QString, QWidget *p)
{
    m_narackaModul = showMyWidget<Naracki, BaseForm, QWidget>(m_narackaModul, m_narackaModul_description, (BaseForm*)ui->centralWidget, p, true);
    connect(m_narackaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_narackaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_narackaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}

void MainWindow::on_actionIspretnicia_triggered()
{
    QString text = "";
    procCreateModulIspratnica(text, NULL);
}

void MainWindow::on_actionSmetka_triggered()
{
    QString text = "";
    procCreateModulSmetka(text, NULL);
}

void MainWindow::on_actionProFaktura_triggered()
{
    QString text = "";
    procCreateModulProFaktura(text, NULL);
}

void MainWindow::on_actionPovratnica_triggered()
{
    QString text = "";
    procCreateModulPovratnica(text, NULL);
}

void MainWindow::on_actionNaracka_triggered()
{
    QString text = "";
    procCreateModulNaracka(text, NULL);
}

void MainWindow::on_actionPrint_Form_triggered()
{
    QString text = procGetPrintText();
    procCreateModulPrint(text, NULL);
}

void MainWindow::procCreateModulPrint(QString text, QWidget *p)
{
    m_printModul = showMyWidget<FormPrint, BaseForm, QWidget>(m_printModul, m_printModul_description, (BaseForm*)ui->centralWidget, p, false);
    connect(m_printModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_printModul->PrintDocument(text);
}


QString MainWindow::procGetPrintText()
{
    m_left->getSelection();
    if (qobject_cast<Artikli*>(qApp->focusWidget()))
    {
        QString text = "<P>Artikli</P>";
        return text;
    }
    else if (qobject_cast<Komintenti*>(qApp->focusWidget()))
    {
        QString text = "<P>Komintenti</P>";
        return text;
    }
    else if (qobject_cast<Fakturi*>(qApp->focusWidget()))
    {
        QFakturaTemplate ft;
        QString text = ft.setFaktura2(((Fakturi*)qApp->focusWidget())->getFaktTransData());
        return text;
    }
    else{
        QString text = "<p>Facebook: <a href=\"https://www.facebook.com/\">Facebook</a></p>"
                       "<p>Yahoo: <a href=\"https://www.yahoo.com/\">Yahoo</a></p>"
                       "<p>Google: <a href=\"https://www.google.com/\">Google</a></p>"
                       "<p>Hotmail: <a href=\"https://www.hotmail.com/\">Hotmail</a></p>"
                       "<p>GMail: <a href=\"https://www.gmail.com/\">GMail</a></p>";
        return text;
    }
}

