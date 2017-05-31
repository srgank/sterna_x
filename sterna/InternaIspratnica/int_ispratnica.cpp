#include "int_ispratnica.h"
#include "ui_int_ispratnica.h"

IntIspratnici::IntIspratnici(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::IntIspratnici)
  ,m_IntIspratniciLista(0)
  ,m_IntIspratniciVnes(0)
  ,m_IntIspratniciKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

IntIspratnici::~IntIspratnici()
{
    if (ui){
        delete ui;
    }
}

void IntIspratnici::pressF2()
{
    if (!m_IntIspratniciLista) {
        return;
    }
    searchIDList = m_IntIspratniciLista->geTableSelectedRow();
    searchStrList = m_IntIspratniciLista->getSearchString();
    searchOffsetList = m_IntIspratniciLista->geTableSelected_Offset();


    disconnect(m_IntIspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IntIspratniciLista = deleteMyWidget<IntIspratniciLista>(m_IntIspratniciLista);
    m_IntIspratniciVnes = showMyWidget<IntIspratniciVnes, IntIspratnici>(m_IntIspratniciVnes, this);
    m_IntIspratniciVnes->setCategoryWidget(this);
    connect(m_IntIspratniciVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_IntIspratniciVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_IntIspratniciVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void IntIspratnici::pressF3()
{
    if (m_IntIspratniciLista){
        m_data = m_IntIspratniciLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_IntIspratniciLista->geTableSelectedRow();
    searchStrList = m_IntIspratniciLista->getSearchString();
    searchOffsetList = m_IntIspratniciLista->geTableSelected_Offset();
    disconnect(m_IntIspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IntIspratniciLista = deleteMyWidget<IntIspratniciLista>(m_IntIspratniciLista);
    m_IntIspratniciKorekcija = showMyWidget<IntIspratniciKorekcija, IntIspratnici>(m_IntIspratniciKorekcija, this);
    m_IntIspratniciKorekcija->setCategoryWidget(this);
    connect(m_IntIspratniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_IntIspratniciKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_IntIspratniciKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_IntIspratniciKorekcija->initProc(m_data);
}

void IntIspratnici::pressF4()
{
    m_IntIspratniciLista = showMyWidget<IntIspratniciLista, IntIspratnici>(m_IntIspratniciLista, this);
    m_IntIspratniciLista->setCategoryWidget(this);
    connect(m_IntIspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_IntIspratniciLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_IntIspratniciLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_IntIspratniciLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void IntIspratnici::pressEscape()
{

}
void IntIspratnici::closeAllForm()
{
}

void IntIspratnici::pressF2FromLista()
{
    pressF2();
}
void IntIspratnici::pressF3FromLista()
{
    pressF3();
}

void IntIspratnici::pressEscapeFromLista()
{
    disconnect(m_IntIspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IntIspratniciLista = deleteMyWidget<IntIspratniciLista>(m_IntIspratniciLista);
    setFocus();
    emit signCloseMyWidget();
}
void IntIspratnici::pressEscapeFromVnes()
{
    m_IntIspratniciVnes = deleteMyWidget<IntIspratniciVnes>(m_IntIspratniciVnes);
    pressF4();
}
void IntIspratnici::pressEscapeFromKorekcija()
{
    disconnect(m_IntIspratniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_IntIspratniciKorekcija = deleteMyWidget<IntIspratniciKorekcija>(m_IntIspratniciKorekcija);
    pressF4();
}

void IntIspratnici::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void IntIspratnici::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void IntIspratnici::Refresh()
{
    if (m_IntIspratniciLista){
        PressKeyF12(m_IntIspratniciLista);
    }else if(m_IntIspratniciVnes){
        PressKeyF12(m_IntIspratniciVnes);
    }else if(m_IntIspratniciKorekcija){
        PressKeyF12(m_IntIspratniciKorekcija);
    }else{
    }
}

IntIspratnici_trans& IntIspratnici::getFaktTransData(){
    if (m_IntIspratniciLista){
        m_data = m_IntIspratniciLista->getFakturaData();
    }else{
    }
    return m_data;
}
