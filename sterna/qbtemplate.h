#ifndef QBTEMPLATE_H
#define QBTEMPLATE_H

#include <QObject>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QTableView>
#include "Struct/struct.h"
#include <typeinfo>

template <class T>
class QBTemplate
{
public:
    QBTemplate(){
    }

    void ShowData(QList<T>& tlist, QStandardItemModel* model, QHeaderView* header, QTableView *table)
    {
        QStringList headerNames;
        if (typeid(T) == typeid(artikalT)) {
            GetHeaderArtikal(headerNames);
        }else if (typeid(T) == typeid(komintentT)) {
            GetHeaderKomintent(headerNames);
        }
        int r = tlist.count();
        int c = headerNames.count();
        model->clear();
        model->setRowCount(r);
        model->setColumnCount(c);

        for (int m = 0; m < c; m++){
            model->setHeaderData( m, Qt::Horizontal, headerNames.at(m));
        }

        table->setModel(model);

        table->setHorizontalHeader(header);
        header->show();
        int row = 0;

        for(int ii = 0; ii < tlist.count();ii++)
        {
            QStringList itemRecord;
            T tempItem = ((QList<T>)tlist).at(ii);
            if (typeid(T) == typeid(artikalT)) {
                  GetArtikalData( itemRecord, tempItem);
            }else if (typeid(T) == typeid(komintentT)) {
                  GetKomintentData( itemRecord, tempItem);
            }


            for (int i = 0; i < c; i++)
            {
                QStandardItem *item = new QStandardItem(itemRecord.at(i));
                item->setTextAlignment(Qt::AlignLeft);
                item->setEditable(false);
                //ui->tableView->setRowHeight(row, 20);
    //            table->setColumnWidth(i, colWidth[i]);
                item->setEditable(false);
                model->setItem(row, i, item);
            }
            itemRecord.clear();
            row++;
        }
//        QItemSelectionModel *sm =table->selectionModel();
//        connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
//        connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
        tlist.clear();
        table->show();
    }
    void GetHeaderArtikal( QStringList& headerNames){
        headerNames << QObject::trUtf8("Id.")
                    << QObject::trUtf8("Шифра")
                    << QObject::trUtf8("Артикал")
                    << QObject::trUtf8("Едм")
                    << QObject::trUtf8("Реф")
                    << QObject::trUtf8("Кат.број")
                    << QObject::trUtf8("Ддв")
                    << QObject::trUtf8("Производител")
                    << QObject::trUtf8("Категорија");
    }

    void GetArtikalData( QStringList& itemRecord, T &tItemT){
        artikalT& tItem = (artikalT&)tItemT;
        itemRecord << tItem.id
                       << tItem.sifra
                       << tItem.artikal
                       << tItem.edm
                       << tItem.ref
                       << tItem.kataloski_broj
                       << tItem.ddv
                       << tItem.proizvoditel
                       << tItem.kategorija;
    }

    void GetHeaderKomintent( QStringList& headerNames){
        headerNames << QObject::trUtf8("Id.")
                    << QObject::trUtf8("Шифра")
                    << QObject::trUtf8("Назив")
                    << QObject::trUtf8("Адреса")
                    << QObject::trUtf8("Тел")
                    << QObject::trUtf8("Мобил")
                    << QObject::trUtf8("Жиро сметка")
                    << QObject::trUtf8("Едб")
                    << QObject::trUtf8("Депонент")
                    << QObject::trUtf8("Шиф.Дејност")
                    << QObject::trUtf8("МБ")
                    << QObject::trUtf8("Забелешка")
                    << QObject::trUtf8("Забелешка")
                    << QObject::trUtf8("Рабат")
                    << QObject::trUtf8("Град")
                       ;
    }

    void GetKomintentData( QStringList& itemRecord, T &tItemT){
        komintentT& tItem = (komintentT&)tItemT;
        itemRecord << tItem.id
                   << tItem.sifra
                   << tItem.naziv
                   << tItem.adresa
                   << tItem.tel
                   << tItem.mobil
                   << tItem.zirosmetka
                   << tItem.edb
                   << tItem.deponent
                   << tItem.sifra_dejnost
                   << tItem.mb
                   << tItem.zabeleska1
                   << tItem.zabeleska2
                   << tItem.rabat
                   << tItem.grad;
    }


};

#endif // QBTEMPLATE_H
