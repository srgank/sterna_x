#include "qcbitemdelegate.h"

QCBItemDelegate::QCBItemDelegate(QWidget *parent)
{

}

QCBItemDelegate::~QCBItemDelegate()
{

}

QWidget *QCBItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const{
    QComboBox *editor = NULL;
    editor = new QComboBox(parent);
    return editor;
}
void QCBItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    int index1 = comboBox->findText(value);
    if ( index1 != -1 )
    {
        comboBox->setCurrentIndex(index1);
    }
}
void QCBItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index)const{

}

void QCBItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const{
    QRect re = option.rect;
    editor->setGeometry(re);
}

void QCBItemDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ){

}
