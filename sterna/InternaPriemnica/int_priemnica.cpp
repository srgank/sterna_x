#include "int_priemnica.h"
#include "ui_int_priemnica.h"

IntPriemnici::IntPriemnici(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::IntPriemnici)
  ,m_IntPriemniciLista(0)
  ,m_IntPriemniciVnes(0)
  ,m_IntPriemniciKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

IntPriemnici::~IntPriemnici()
{
    if (ui){
        delete ui;
    }
}

void IntPriemnici::pressF2()
{
    if (!m_IntPriemniciLista) {
        return;
    }
    searchIDList = m_IntPriemniciLista->geTableSelectedRow();
    searchStrList = m_IntPriemniciLista->getSearchString();
    searchOffsetList = m_IntPriemniciLista->geTableSelected_Offset();


    disconnect(m_IntPriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IntPriemniciLista = deleteMyWidget<IntPriemniciLista>(m_IntPriemniciLista);
    m_IntPriemniciVnes = showMyWidget<IntPriemniciVnes, IntPriemnici>(m_IntPriemniciVnes, this);
    m_IntPriemniciVnes->setCategoryWidget(this);
    connect(m_IntPriemniciVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_IntPriemniciVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_IntPriemniciVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void IntPriemnici::pressF3()
{
    if (m_IntPriemniciLista){
        m_data = m_IntPriemniciLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_IntPriemniciLista->geTableSelectedRow();
    searchStrList = m_IntPriemniciLista->getSearchString();
    searchOffsetList = m_IntPriemniciLista->geTableSelected_Offset();
    disconnect(m_IntPriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IntPriemniciLista = deleteMyWidget<IntPriemniciLista>(m_IntPriemniciLista);
    m_IntPriemniciKorekcija = showMyWidget<IntPriemniciKorekcija, IntPriemnici>(m_IntPriemniciKorekcija, this);
    m_IntPriemniciKorekcija->setCategoryWidget(this);
    connect(m_IntPriemniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_IntPriemniciKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_IntPriemniciKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_IntPriemniciKorekcija->initProc(m_data);
}

void IntPriemnici::pressF4()
{
    m_IntPriemniciLista = showMyWidget<IntPriemniciLista, IntPriemnici>(m_IntPriemniciLista, this);
    m_IntPriemniciLista->setCategoryWidget(this);
    connect(m_IntPriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_IntPriemniciLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_IntPriemniciLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_IntPriemniciLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void IntPriemnici::pressEscape()
{

}
void IntPriemnici::closeAllForm()
{
}

void IntPriemnici::pressF2FromLista()
{
    pressF2();
}
void IntPriemnici::pressF3FromLista()
{
    pressF3();
}

void IntPriemnici::pressEscapeFromLista()
{
    disconnect(m_IntPriemniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IntPriemniciLista = deleteMyWidget<IntPriemniciLista>(m_IntPriemniciLista);
    setFocus();
    emit signCloseMyWidget();
}
void IntPriemnici::pressEscapeFromVnes()
{
    m_IntPriemniciVnes = deleteMyWidget<IntPriemniciVnes>(m_IntPriemniciVnes);
    pressF4();
}
void IntPriemnici::pressEscapeFromKorekcija()
{
    disconnect(m_IntPriemniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_IntPriemniciKorekcija = deleteMyWidget<IntPriemniciKorekcija>(m_IntPriemniciKorekcija);
    pressF4();
}

void IntPriemnici::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void IntPriemnici::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void IntPriemnici::Refresh()
{
    if (m_IntPriemniciLista){
        PressKeyF12(m_IntPriemniciLista);
    }else if(m_IntPriemniciVnes){
        PressKeyF12(m_IntPriemniciVnes);
    }else if(m_IntPriemniciKorekcija){
        PressKeyF12(m_IntPriemniciKorekcija);
    }else{
    }
}

IntPriemnici_trans& IntPriemnici::getFaktTransData(){
    if (m_IntPriemniciLista){
        m_data = m_IntPriemniciLista->getFakturaData();
    }else{
    }
    return m_data;
}
