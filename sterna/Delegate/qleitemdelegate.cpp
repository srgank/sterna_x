#include "qleitemdelegate.h"

QLEItemDelegate::QLEItemDelegate(QWidget *parent)
{

}

QLEItemDelegate::~QLEItemDelegate()
{

}

QWidget *QLEItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const{
    QLineEdit *editor = NULL;
    editor = new QLineEdit(parent);
    editor->setFocus();
    return editor;
}
void QLEItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(value);

}
void QLEItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index)const{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString value = lineEdit->text();
    model->setData(index, value);
    emit updateCellLE(index, value);
}

void QLEItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const{
    QRect re = option.rect;
    editor->setGeometry(re);
}

void QLEItemDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ){

}
