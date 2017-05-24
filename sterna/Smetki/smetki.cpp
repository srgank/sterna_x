#include "smetki.h"
#include "ui_smetki.h"

Smetki::Smetki(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Smetki)
  ,m_SmetkiLista(0)
  ,m_SmetkiVnes(0)
  ,m_SmetkiKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

Smetki::~Smetki()
{
    if (ui){
        delete ui;
    }
}

void Smetki::pressF2()
{
    if (!m_SmetkiLista) {
        return;
    }
    searchIDList = m_SmetkiLista->geTableSelectedRow();
    searchStrList = m_SmetkiLista->getSearchString();
    searchOffsetList = m_SmetkiLista->geTableSelected_Offset();


    disconnect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_SmetkiLista = deleteMyWidget<SmetkiLista>(m_SmetkiLista);
    m_SmetkiVnes = showMyWidget<SmetkiVnes, Smetki>(m_SmetkiVnes, this);
    m_SmetkiVnes->setCategoryWidget(this);
    connect(m_SmetkiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_SmetkiVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_SmetkiVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Smetki::pressF3()
{
    if (m_SmetkiLista){
        m_data = m_SmetkiLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_SmetkiLista->geTableSelectedRow();
    searchStrList = m_SmetkiLista->getSearchString();
    searchOffsetList = m_SmetkiLista->geTableSelected_Offset();
    disconnect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_SmetkiLista = deleteMyWidget<SmetkiLista>(m_SmetkiLista);
    m_SmetkiKorekcija = showMyWidget<SmetkiKorekcija, Smetki>(m_SmetkiKorekcija, this);
    m_SmetkiKorekcija->setCategoryWidget(this);
    connect(m_SmetkiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_SmetkiKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_SmetkiKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_SmetkiKorekcija->initProc(m_data);
}

void Smetki::pressF4()
{
    m_SmetkiLista = showMyWidget<SmetkiLista, Smetki>(m_SmetkiLista, this);
    m_SmetkiLista->setCategoryWidget(this);
    connect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_SmetkiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_SmetkiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_SmetkiLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void Smetki::pressEscape()
{

}
void Smetki::closeAllForm()
{
}

void Smetki::pressF2FromLista()
{
    pressF2();
}
void Smetki::pressF3FromLista()
{
    pressF3();
}

void Smetki::pressEscapeFromLista()
{
    disconnect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_SmetkiLista = deleteMyWidget<SmetkiLista>(m_SmetkiLista);
    setFocus();
    emit signCloseMyWidget();
}
void Smetki::pressEscapeFromVnes()
{
    m_SmetkiVnes = deleteMyWidget<SmetkiVnes>(m_SmetkiVnes);
    pressF4();
}
void Smetki::pressEscapeFromKorekcija()
{
    disconnect(m_SmetkiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_SmetkiKorekcija = deleteMyWidget<SmetkiKorekcija>(m_SmetkiKorekcija);
    pressF4();
}

void Smetki::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Smetki::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void Smetki::Refresh()
{
    if (m_SmetkiLista){
        PressKeyF12(m_SmetkiLista);
    }else if(m_SmetkiVnes){
        PressKeyF12(m_SmetkiVnes);
    }else if(m_SmetkiKorekcija){
        PressKeyF12(m_SmetkiKorekcija);
    }else{
    }
}

Smetki_trans& Smetki::getFaktTransData(){
    if (m_SmetkiLista){
        m_data = m_SmetkiLista->getFakturaData();
    }else{
    }
    return m_data;
}
