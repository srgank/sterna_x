#include "povratnici.h"
#include "ui_povratnici.h"

Povratnici::Povratnici(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Povratnici)
  ,m_PovratniciLista(0)
  ,m_PovratniciVnes(0)
  ,m_PovratniciKorekcija(0)
  ,searchIDList(0)
  ,searchStrList("")
  ,searchOffsetList(0)

{
    ui->setupUi(this);
    pressF4();
}

Povratnici::~Povratnici()
{
    if (ui){
        delete ui;
    }
}

void Povratnici::pressF2()
{
    if (!m_PovratniciLista) {
        return;
    }
    searchIDList = m_PovratniciLista->geTableSelectedRow();
    searchStrList = m_PovratniciLista->getSearchString();
    searchOffsetList = m_PovratniciLista->geTableSelected_Offset();


    disconnect(m_PovratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PovratniciLista = deleteMyWidget<PovratniciLista>(m_PovratniciLista);
    m_PovratniciVnes = showMyWidget<PovratniciVnes, Povratnici>(m_PovratniciVnes, this);
    m_PovratniciVnes->setCategoryWidget(this);
    connect(m_PovratniciVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_PovratniciVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_PovratniciVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Povratnici::pressF3()
{
    if (m_PovratniciLista){
        m_data = m_PovratniciLista->getFakturaData();
    }else{
        return;
    }
    searchIDList = m_PovratniciLista->geTableSelectedRow();
    searchStrList = m_PovratniciLista->getSearchString();
    searchOffsetList = m_PovratniciLista->geTableSelected_Offset();
    disconnect(m_PovratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PovratniciLista = deleteMyWidget<PovratniciLista>(m_PovratniciLista);
    m_PovratniciKorekcija = showMyWidget<PovratniciKorekcija, Povratnici>(m_PovratniciKorekcija, this);
    m_PovratniciKorekcija->setCategoryWidget(this);
    connect(m_PovratniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_PovratniciKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_PovratniciKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_PovratniciKorekcija->initProc(m_data);
}

void Povratnici::pressF4()
{
    m_PovratniciLista = showMyWidget<PovratniciLista, Povratnici>(m_PovratniciLista, this);
    m_PovratniciLista->setCategoryWidget(this);
    connect(m_PovratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_PovratniciLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_PovratniciLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
    m_PovratniciLista->initProc(searchIDList, searchStrList, searchOffsetList);
}

void Povratnici::pressEscape()
{

}
void Povratnici::closeAllForm()
{
}

void Povratnici::pressF2FromLista()
{
    pressF2();
}
void Povratnici::pressF3FromLista()
{
    pressF3();
}

void Povratnici::pressEscapeFromLista()
{
    disconnect(m_PovratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PovratniciLista = deleteMyWidget<PovratniciLista>(m_PovratniciLista);
    setFocus();
    emit signCloseMyWidget();
}
void Povratnici::pressEscapeFromVnes()
{
    m_PovratniciVnes = deleteMyWidget<PovratniciVnes>(m_PovratniciVnes);
    pressF4();
}
void Povratnici::pressEscapeFromKorekcija()
{
    disconnect(m_PovratniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_PovratniciKorekcija = deleteMyWidget<PovratniciKorekcija>(m_PovratniciKorekcija);
    pressF4();
}

void Povratnici::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Povratnici::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


void Povratnici::Refresh()
{
    if (m_PovratniciLista){
        PressKeyF12(m_PovratniciLista);
    }else if(m_PovratniciVnes){
        PressKeyF12(m_PovratniciVnes);
    }else if(m_PovratniciKorekcija){
        PressKeyF12(m_PovratniciKorekcija);
    }else{
    }
}

Povratnici_trans& Povratnici::getFaktTransData(){
    if (m_PovratniciLista){
        m_data = m_PovratniciLista->getFakturaData();
    }else{
    }
    return m_data;
}
