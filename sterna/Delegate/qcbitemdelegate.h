#ifndef QCBITEMDELEGATE_H
#define QCBITEMDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>


class QCBItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    QCBItemDelegate(QWidget *parent);
    ~QCBItemDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index );

signals:
private:
private:

};

#endif // QCBITEMDELEGATE_H
