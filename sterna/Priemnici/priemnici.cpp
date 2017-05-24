#include "priemnici.h"
#include "ui_priemnici.h"

Priemnici::Priemnici(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Priemnici)
  ,m_PriemniciLista(0)
  ,m_PriemniciVnes(0)
  ,m_PriemniciKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

Priemnici::~Priemnici()
{
    if (ui){
        delete ui;
    }
}

void Priemnici::pressF2()
{
    if (!m_PriemniciLista) {
        return;
    }
    searchIDList = m_PriemniciLista->geTableSelectedRow();
    searchStrList = m_PriemniciLista->getSearchString();
    searchOffsetList = m_PriemniciLista->geTableSelected_Offset();


    disconnect(m_PriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PriemniciLista = deleteMyWidget<PriemniciLista>(m_PriemniciLista);
    m_PriemniciVnes = showMyWidget<PriemniciVnes, Priemnici>(m_PriemniciVnes, this);
    m_PriemniciVnes->setCategoryWidget(this);
    connect(m_PriemniciVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_PriemniciVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_PriemniciVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Priemnici::pressF3()
{
    if (m_PriemniciLista){
        m_data = m_PriemniciLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_PriemniciLista->geTableSelectedRow();
    searchStrList = m_PriemniciLista->getSearchString();
    searchOffsetList = m_PriemniciLista->geTableSelected_Offset();
    disconnect(m_PriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PriemniciLista = deleteMyWidget<PriemniciLista>(m_PriemniciLista);
    m_PriemniciKorekcija = showMyWidget<PriemniciKorekcija, Priemnici>(m_PriemniciKorekcija, this);
    m_PriemniciKorekcija->setCategoryWidget(this);
    connect(m_PriemniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_PriemniciKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_PriemniciKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_PriemniciKorekcija->initProc(m_data);
}

void Priemnici::pressF4()
{
    m_PriemniciLista = showMyWidget<PriemniciLista, Priemnici>(m_PriemniciLista, this);
    m_PriemniciLista->setCategoryWidget(this);
    connect(m_PriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_PriemniciLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_PriemniciLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_PriemniciLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void Priemnici::pressEscape()
{

}
void Priemnici::closeAllForm()
{
}

void Priemnici::pressF2FromLista()
{
    pressF2();
}
void Priemnici::pressF3FromLista()
{
    pressF3();
}

void Priemnici::pressEscapeFromLista()
{
    disconnect(m_PriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PriemniciLista = deleteMyWidget<PriemniciLista>(m_PriemniciLista);
    setFocus();
    emit signCloseMyWidget();
}
void Priemnici::pressEscapeFromVnes()
{
    m_PriemniciVnes = deleteMyWidget<PriemniciVnes>(m_PriemniciVnes);
    pressF4();
}
void Priemnici::pressEscapeFromKorekcija()
{
    disconnect(m_PriemniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_PriemniciKorekcija = deleteMyWidget<PriemniciKorekcija>(m_PriemniciKorekcija);
    pressF4();
}

void Priemnici::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Priemnici::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void Priemnici::Refresh()
{
    if (m_PriemniciLista){
        PressKeyF12(m_PriemniciLista);
    }else if(m_PriemniciVnes){
        PressKeyF12(m_PriemniciVnes);
    }else if(m_PriemniciKorekcija){
        PressKeyF12(m_PriemniciKorekcija);
    }else{
    }
}

Priemnici_trans& Priemnici::getFaktTransData(){
    if (m_PriemniciLista){
        m_data = m_PriemniciLista->getFakturaData();
    }else{
    }
    return m_data;
}
