#include "analitikaartikli.h"
#include "ui_analitikaartikli.h"

AnalitikaArtikli::AnalitikaArtikli(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::AnalitikaArtikli)
  ,m_AnalitikaArtikliLista(0)
  ,m_AnalitikaArtikliVnes(0)
  ,m_AnalitikaArtikliKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

AnalitikaArtikli::~AnalitikaArtikli()
{
    if (ui){
        delete ui;
    }
}

void AnalitikaArtikli::pressF2()
{
    if (!m_AnalitikaArtikliLista) {
        return;
    }
    searchIDList = m_AnalitikaArtikliLista->geTableSelectedRow();
    searchStrList = m_AnalitikaArtikliLista->getSearchString();
    searchOffsetList = m_AnalitikaArtikliLista->geTableSelected_Offset();


    disconnect(m_AnalitikaArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_AnalitikaArtikliLista = deleteMyWidget<AnalitikaArtikliLista>(m_AnalitikaArtikliLista);
    m_AnalitikaArtikliVnes = showMyWidget<AnalitikaArtikliVnes, AnalitikaArtikli>(m_AnalitikaArtikliVnes, this);
    m_AnalitikaArtikliVnes->setCategoryWidget(this);
    connect(m_AnalitikaArtikliVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_AnalitikaArtikliVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_AnalitikaArtikliVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void AnalitikaArtikli::pressF3()
{
    if (m_AnalitikaArtikliLista){
        m_data = m_AnalitikaArtikliLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_AnalitikaArtikliLista->geTableSelectedRow();
    searchStrList = m_AnalitikaArtikliLista->getSearchString();
    searchOffsetList = m_AnalitikaArtikliLista->geTableSelected_Offset();
    disconnect(m_AnalitikaArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_AnalitikaArtikliLista = deleteMyWidget<AnalitikaArtikliLista>(m_AnalitikaArtikliLista);
    m_AnalitikaArtikliKorekcija = showMyWidget<AnalitikaArtikliKorekcija, AnalitikaArtikli>(m_AnalitikaArtikliKorekcija, this);
    m_AnalitikaArtikliKorekcija->setCategoryWidget(this);
    connect(m_AnalitikaArtikliKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_AnalitikaArtikliKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_AnalitikaArtikliKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_AnalitikaArtikliKorekcija->initProc(m_data);
}

void AnalitikaArtikli::pressF4()
{
    m_AnalitikaArtikliLista = showMyWidget<AnalitikaArtikliLista, AnalitikaArtikli>(m_AnalitikaArtikliLista, this);
    m_AnalitikaArtikliLista->setCategoryWidget(this);
    connect(m_AnalitikaArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_AnalitikaArtikliLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_AnalitikaArtikliLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_AnalitikaArtikliLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void AnalitikaArtikli::pressEscape()
{

}
void AnalitikaArtikli::closeAllForm()
{
}

void AnalitikaArtikli::pressF2FromLista()
{
    pressF2();
}
void AnalitikaArtikli::pressF3FromLista()
{
    pressF3();
}

void AnalitikaArtikli::pressEscapeFromLista()
{
    disconnect(m_AnalitikaArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_AnalitikaArtikliLista = deleteMyWidget<AnalitikaArtikliLista>(m_AnalitikaArtikliLista);
    setFocus();
    emit signCloseMyWidget();
}
void AnalitikaArtikli::pressEscapeFromVnes()
{
    m_AnalitikaArtikliVnes = deleteMyWidget<AnalitikaArtikliVnes>(m_AnalitikaArtikliVnes);
    pressF4();
}
void AnalitikaArtikli::pressEscapeFromKorekcija()
{
    disconnect(m_AnalitikaArtikliKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_AnalitikaArtikliKorekcija = deleteMyWidget<AnalitikaArtikliKorekcija>(m_AnalitikaArtikliKorekcija);
    pressF4();
}

void AnalitikaArtikli::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void AnalitikaArtikli::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void AnalitikaArtikli::Refresh()
{
    if (m_AnalitikaArtikliLista){
        PressKeyF12(m_AnalitikaArtikliLista);
    }else if(m_AnalitikaArtikliVnes){
        PressKeyF12(m_AnalitikaArtikliVnes);
    }else if(m_AnalitikaArtikliKorekcija){
        PressKeyF12(m_AnalitikaArtikliKorekcija);
    }else{
    }
}

AnalitikaArtikli_trans& AnalitikaArtikli::getFaktTransData(){
    if (m_AnalitikaArtikliLista){
        m_data = m_AnalitikaArtikliLista->getFakturaData();
    }else{
    }
    return m_data;
}
