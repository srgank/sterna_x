#ifndef QLEITEMDELEGATE_H
#define QLEITEMDELEGATE_H

#include <QItemDelegate>
#include <QLineEdit>

class QLEItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    QLEItemDelegate(QWidget *parent);
    ~QLEItemDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index );
signals:
    void updateCellLE(const QModelIndex &, QString &) const;
};

#endif // QLEITEMDELEGATE_H
