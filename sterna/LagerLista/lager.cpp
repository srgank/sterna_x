#include "lager.h"
#include "ui_lager.h"

Lager::Lager(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Lager)
  ,m_LagerLista(0)
  ,m_LagerVnes(0)
  ,m_LagerKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

Lager::~Lager()
{
    if (ui){
        delete ui;
    }
}

void Lager::pressF2()
{
    if (!m_LagerLista) {
        return;
    }
    searchIDList = m_LagerLista->geTableSelectedRow();
    searchStrList = m_LagerLista->getSearchString();
    searchOffsetList = m_LagerLista->geTableSelected_Offset();


    disconnect(m_LagerLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_LagerLista = deleteMyWidget<LagerLista>(m_LagerLista);
    m_LagerVnes = showMyWidget<LagerVnes, Lager>(m_LagerVnes, this);
    m_LagerVnes->setCategoryWidget(this);
    connect(m_LagerVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_LagerVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_LagerVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Lager::pressF3()
{
    if (m_LagerLista){
        m_data = m_LagerLista->getLagerData();
    }else{
        return;
    }
    searchIDList = m_LagerLista->geTableSelectedRow();
    searchStrList = m_LagerLista->getSearchString();
    searchOffsetList = m_LagerLista->geTableSelected_Offset();
    disconnect(m_LagerLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_LagerLista = deleteMyWidget<LagerLista>(m_LagerLista);
    m_LagerKorekcija = showMyWidget<LagerKorekcija, Lager>(m_LagerKorekcija, this);
    m_LagerKorekcija->setCategoryWidget(this);
    connect(m_LagerKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_LagerKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_LagerKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_LagerKorekcija->initProc(m_data);
}

void Lager::pressF4()
{
    m_LagerLista = showMyWidget<LagerLista, Lager>(m_LagerLista, this);
    m_LagerLista->setCategoryWidget(this);
    connect(m_LagerLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_LagerLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_LagerLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_LagerLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void Lager::pressEscape()
{

}
void Lager::closeAllForm()
{
}

void Lager::pressF2FromLista()
{
    pressF2();
}
void Lager::pressF3FromLista()
{
    pressF3();
}

void Lager::pressEscapeFromLista()
{
    disconnect(m_LagerLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_LagerLista = deleteMyWidget<LagerLista>(m_LagerLista);
    setFocus();
    emit signCloseMyWidget();
}
void Lager::pressEscapeFromVnes()
{
    m_LagerVnes = deleteMyWidget<LagerVnes>(m_LagerVnes);
    pressF4();
}
void Lager::pressEscapeFromKorekcija()
{
    disconnect(m_LagerKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_LagerKorekcija = deleteMyWidget<LagerKorekcija>(m_LagerKorekcija);
    pressF4();
}

void Lager::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Lager::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void Lager::Refresh()
{
    if (m_LagerLista){
        PressKeyF12(m_LagerLista);
    }else if(m_LagerVnes){
        PressKeyF12(m_LagerVnes);
    }else if(m_LagerKorekcija){
        PressKeyF12(m_LagerKorekcija);
    }else{
    }
}

Lager_trans& Lager::getFaktTransData(){
    if (m_LagerLista){
        m_data = m_LagerLista->getLagerData();
    }else{
    }
    return m_data;
}
