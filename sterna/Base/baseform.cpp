#include "baseform.h"
#include "ui_baseform.h"

#define fontsize 11

BaseForm::BaseForm(QWidget *parent) :
    QWidget(parent)
  ,ui(new Ui::BaseForm)
  , scale(0)
{

    ui->setupUi(this);
    Singleton *s = Singleton::Instance();
    int gDFont = s->getGlobalFontSize();
    QFont f;
    f.setPointSize(gDFont);
    this->setFont(f);
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
}
