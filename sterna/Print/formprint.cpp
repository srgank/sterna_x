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
}

void FormPrint::pressEscapeFromLista()
{
    disconnect(m_PrinterLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PrinterLista = deleteMyWidget<PrinterLista>(m_PrinterLista);
    m_PrinterLista = 0;
    setFocus();
    emit signCloseMyWidget();
}

void FormPrint::PrintDocument(QString &text){
    if (m_PrinterLista){
        m_PrinterLista = deleteMyWidget<PrinterLista>(m_PrinterLista);
        m_PrinterLista = 0;
    }
    m_PrinterLista = showMyWidget<PrinterLista, FormPrint>(m_PrinterLista, this);
    m_PrinterLista->setCategoryWidget(this);
    connect(m_PrinterLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_PrinterLista->SetBaseText(text);
    m_PrinterLista->PrintDocumentText();

}

