#include "formprint.h"
#include "ui_formprint.h"

FormPrint::FormPrint(BaseForm *parent) :
    BaseForm(parent),
    m_PrinterLista(0),
    ui(new Ui::FormPrint)
{
    ui->setupUi(this);
    pressF4();
}

FormPrint::~FormPrint()
{
    if (ui){
        delete ui;
    }
}


void FormPrint::pressEscape()
{

}



void FormPrint::pressF4()
{
    m_PrinterLista = showMyWidget<PrinterLista, FormPrint>(m_PrinterLista, this);
    m_PrinterLista->setCategoryWidget(this);
    connect(m_PrinterLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PrinterLista->setFocus();
}

void FormPrint::pressEscapeFromLista()
{
    disconnect(m_PrinterLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PrinterLista = deleteMyWidget<PrinterLista>(m_PrinterLista);
    setFocus();
    emit signCloseMyWidget();
}
