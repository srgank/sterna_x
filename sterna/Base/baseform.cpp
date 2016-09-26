#include "baseform.h"
#include "ui_baseform.h"

#define fontsize 11

BaseForm::BaseForm(QWidget *parent) :
    QWidget(parent)
  ,ui(new Ui::BaseForm)

{

    ui->setupUi(this);
    Singleton *s = Singleton::Instance();
    int gDFont = s->getGlobalFontSize();
    QFont f;
    f.setPointSize(gDFont);
    this->setFont(f);
    scale = gDFont;
}

BaseForm::~BaseForm()
{
    delete ui;
}


void BaseForm::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    switch (key)
    {
    case Qt::Key_F2: pressF2(); break;
    case Qt::Key_F3: pressF3(); break;
    case Qt::Key_F4: pressF4(); break;
    case Qt::Key_Escape: pressEscape(); break;
    case Qt::Key_Return: pressReturn(); break;
    case Qt::Key_Enter: pressEnter(); break;
    case Qt::Key_F12: Refresh(); break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void BaseForm::pressF2()
{

}
void BaseForm::pressF3()
{

}
void BaseForm::pressF4()
{

}
void BaseForm::pressEscape()
{

}
void BaseForm::pressEnter()
{

}
void BaseForm::pressReturn()
{

}

void BaseForm::updateFont()
{

}

void BaseForm::Refresh()
{

}


QWidget* BaseForm::getSourceWidget()
{
    return m_sourceWidget;
}
void BaseForm::setSourceWidget(QWidget *sourceWidget)
{
    m_sourceWidget = sourceWidget;
}

void BaseForm::wheelEvent ( QWheelEvent * event )
{
    setUpdatesEnabled(false);
   if( event->modifiers() & Qt::ControlModifier )
    {
    Singleton *s = Singleton::Instance();

    scale += (event->delta()/120)*2; //or use any other step for zooming
    if (scale < 6) {
        scale = 6;
    }
    else if (scale > 22)
    {
        scale = 22;
    }
    QFont f;
    f.setPointSize(scale);
    this->setFont(f);
    QFontMetrics fm(f);
    int s_height = fm.height();
    s->setGlobalFontSize(scale);
    }
    setUpdatesEnabled(true);
    updateFont();
}
void BaseForm::PressKeyTAB(QObject *receiver){
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(receiver, event);
}

void BaseForm::PressKeyF12(QObject *receiver){
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F12, Qt::NoModifier);
    QCoreApplication::postEvent(receiver, event);
}

void BaseForm::PressKeyReturn(QObject *receiver){
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void BaseForm::BaseInstallEventFilter(QGridLayout *receiver){
    for(int idx = 0; idx < receiver->count(); idx++)
    {
      QLayoutItem * const item = receiver->itemAt(idx);
       if(dynamic_cast<QWidgetItem *>(item))
        item->widget()->installEventFilter(this);
    }
}

void BaseForm::BaseUpdateFonts(QGridLayout* receiver, QString& str_font){
    for(int idx = 0; idx < receiver->count(); idx++)
    {
      QLayoutItem * const item = receiver->itemAt(idx);
      if(dynamic_cast<QWidgetItem *>(item))
        item->widget()->setStyleSheet(str_font);
    }
}


