#include "analitikakomintenti.h"
#include "ui_analitikakomintenti.h"

AnalitikaKomintenti::AnalitikaKomintenti(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::AnalitikaKomintenti)
  ,m_AnalitikaKomintentiLista(0)
  ,m_AnalitikaKomintentiVnes(0)
  ,m_AnalitikaKomintentiKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

AnalitikaKomintenti::~AnalitikaKomintenti()
{
    if (ui){
        delete ui;
    }
}

void AnalitikaKomintenti::pressF2()
{
    if (!m_AnalitikaKomintentiLista) {
        return;
    }
    searchIDList = m_AnalitikaKomintentiLista->geTableSelectedRow();
    searchStrList = m_AnalitikaKomintentiLista->getSearchString();
    searchOffsetList = m_AnalitikaKomintentiLista->geTableSelected_Offset();


    disconnect(m_AnalitikaKomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_AnalitikaKomintentiLista = deleteMyWidget<AnalitikaKomintentiLista>(m_AnalitikaKomintentiLista);
    m_AnalitikaKomintentiVnes = showMyWidget<AnalitikaKomintentiVnes, AnalitikaKomintenti>(m_AnalitikaKomintentiVnes, this);
    m_AnalitikaKomintentiVnes->setCategoryWidget(this);
    connect(m_AnalitikaKomintentiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_AnalitikaKomintentiVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_AnalitikaKomintentiVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void AnalitikaKomintenti::pressF3()
{
    if (m_AnalitikaKomintentiLista){
        m_data = m_AnalitikaKomintentiLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_AnalitikaKomintentiLista->geTableSelectedRow();
    searchStrList = m_AnalitikaKomintentiLista->getSearchString();
    searchOffsetList = m_AnalitikaKomintentiLista->geTableSelected_Offset();
    disconnect(m_AnalitikaKomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_AnalitikaKomintentiLista = deleteMyWidget<AnalitikaKomintentiLista>(m_AnalitikaKomintentiLista);
    m_AnalitikaKomintentiKorekcija = showMyWidget<AnalitikaKomintentiKorekcija, AnalitikaKomintenti>(m_AnalitikaKomintentiKorekcija, this);
    m_AnalitikaKomintentiKorekcija->setCategoryWidget(this);
    connect(m_AnalitikaKomintentiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_AnalitikaKomintentiKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_AnalitikaKomintentiKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_AnalitikaKomintentiKorekcija->initProc(m_data);
}

void AnalitikaKomintenti::pressF4()
{
    m_AnalitikaKomintentiLista = showMyWidget<AnalitikaKomintentiLista, AnalitikaKomintenti>(m_AnalitikaKomintentiLista, this);
    m_AnalitikaKomintentiLista->setCategoryWidget(this);
    connect(m_AnalitikaKomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_AnalitikaKomintentiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_AnalitikaKomintentiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_AnalitikaKomintentiLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void AnalitikaKomintenti::pressEscape()
{

}
void AnalitikaKomintenti::closeAllForm()
{
}

void AnalitikaKomintenti::pressF2FromLista()
{
    pressF2();
}
void AnalitikaKomintenti::pressF3FromLista()
{
    pressF3();
}

void AnalitikaKomintenti::pressEscapeFromLista()
{
    disconnect(m_AnalitikaKomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_AnalitikaKomintentiLista = deleteMyWidget<AnalitikaKomintentiLista>(m_AnalitikaKomintentiLista);
    setFocus();
    emit signCloseMyWidget();
}
void AnalitikaKomintenti::pressEscapeFromVnes()
{
    m_AnalitikaKomintentiVnes = deleteMyWidget<AnalitikaKomintentiVnes>(m_AnalitikaKomintentiVnes);
    pressF4();
}
void AnalitikaKomintenti::pressEscapeFromKorekcija()
{
    disconnect(m_AnalitikaKomintentiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_AnalitikaKomintentiKorekcija = deleteMyWidget<AnalitikaKomintentiKorekcija>(m_AnalitikaKomintentiKorekcija);
    pressF4();
}

void AnalitikaKomintenti::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void AnalitikaKomintenti::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void AnalitikaKomintenti::Refresh()
{
    if (m_AnalitikaKomintentiLista){
        PressKeyF12(m_AnalitikaKomintentiLista);
    }else if(m_AnalitikaKomintentiVnes){
        PressKeyF12(m_AnalitikaKomintentiVnes);
    }else if(m_AnalitikaKomintentiKorekcija){
        PressKeyF12(m_AnalitikaKomintentiKorekcija);
    }else{
    }
}

AnalitikaKomintenti_trans& AnalitikaKomintenti::getFaktTransData(){
    if (m_AnalitikaKomintentiLista){
        m_data = m_AnalitikaKomintentiLista->getFakturaData();
    }else{
    }
    return m_data;
}
