#include "nalog.h"
#include "ui_nalog.h"

Nalog::Nalog(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Nalog)
  ,m_NalogLista(0)
  ,m_NalogVnes(0)
  ,m_NalogKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

Nalog::~Nalog()
{
    if (ui){
        delete ui;
    }
}

void Nalog::pressF2()
{
    if (!m_NalogLista) {
        return;
    }
    searchIDList = m_NalogLista->geTableSelectedRow();
    searchStrList = m_NalogLista->getSearchString();
    searchOffsetList = m_NalogLista->geTableSelected_Offset();


    disconnect(m_NalogLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_NalogLista = deleteMyWidget<NalogLista>(m_NalogLista);
    m_NalogVnes = showMyWidget<NalogVnes, Nalog>(m_NalogVnes, this);
    m_NalogVnes->setCategoryWidget(this);
    connect(m_NalogVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_NalogVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_NalogVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Nalog::pressF3()
{
    if (m_NalogLista){
        m_data = m_NalogLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_NalogLista->geTableSelectedRow();
    searchStrList = m_NalogLista->getSearchString();
    searchOffsetList = m_NalogLista->geTableSelected_Offset();
    disconnect(m_NalogLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_NalogLista = deleteMyWidget<NalogLista>(m_NalogLista);
    m_NalogKorekcija = showMyWidget<NalogKorekcija, Nalog>(m_NalogKorekcija, this);
    m_NalogKorekcija->setCategoryWidget(this);
    connect(m_NalogKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_NalogKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_NalogKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_NalogKorekcija->initProc(m_data);
}

void Nalog::pressF4()
{
    m_NalogLista = showMyWidget<NalogLista, Nalog>(m_NalogLista, this);
    m_NalogLista->setCategoryWidget(this);
    connect(m_NalogLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_NalogLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_NalogLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_NalogLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void Nalog::pressEscape()
{

}
void Nalog::closeAllForm()
{
}

void Nalog::pressF2FromLista()
{
    pressF2();
}
void Nalog::pressF3FromLista()
{
    pressF3();
}

void Nalog::pressEscapeFromLista()
{
    disconnect(m_NalogLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_NalogLista = deleteMyWidget<NalogLista>(m_NalogLista);
    setFocus();
    emit signCloseMyWidget();
}
void Nalog::pressEscapeFromVnes()
{
    m_NalogVnes = deleteMyWidget<NalogVnes>(m_NalogVnes);
    pressF4();
}
void Nalog::pressEscapeFromKorekcija()
{
    disconnect(m_NalogKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_NalogKorekcija = deleteMyWidget<NalogKorekcija>(m_NalogKorekcija);
    pressF4();
}

void Nalog::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Nalog::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void Nalog::Refresh()
{
    if (m_NalogLista){
        PressKeyF12(m_NalogLista);
    }else if(m_NalogVnes){
        PressKeyF12(m_NalogVnes);
    }else if(m_NalogKorekcija){
        PressKeyF12(m_NalogKorekcija);
    }else{
    }
}

Nalog_trans& Nalog::getFaktTransData(){
    if (m_NalogLista){
        m_data = m_NalogLista->getFakturaData();
    }else{
    }
    return m_data;
}
