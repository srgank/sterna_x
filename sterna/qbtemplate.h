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

    void ShowData(QList<T>& tlist, QStandardItemModel* model, QHeaderView* header, QTableView *table, QList<int> colWidth)
    {
        QStringList headerNames;
        if (typeid(T) == typeid(artikalT)) {
            GetHeaderArtikal(headerNames);
        }else if (typeid(T) == typeid(komintentT)) {
            GetHeaderKomintent(headerNames);
        }else if (typeid(T) == typeid(dokumentT)) {
            GetHeaderDokument(headerNames);
        }else if (typeid(T) == typeid(dokumentDetailT)) {
            GetHeaderDokumentDetail(headerNames);
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
            }else if (typeid(T) == typeid(dokumentT)) {
                  GetDokumentData( itemRecord, tempItem);
            }else if (typeid(T) == typeid(dokumentDetailT)) {
                GetDokumentDetailData( itemRecord, tempItem);
            }


            for (int i = 0; i < c; i++)
            {
                QStandardItem *item = new QStandardItem(itemRecord.at(i));
                item->setTextAlignment(Qt::AlignLeft);
                item->setEditable(false);
                //ui->tableView->setRowHeight(row, 20);
                table->setColumnWidth(i, colWidth.at(i));
                item->setEditable(false);
                model->setItem(row, i, item);
            }
            itemRecord.clear();
            row++;
        }
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

    void GetHeaderDokument( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
                    << QObject::trUtf8("td")
                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
                    << QObject::trUtf8("prevoznik_id")
                    << QObject::trUtf8("prevoznik_naziv")
                    << QObject::trUtf8("valuta")
                    << QObject::trUtf8("kurs")
                    << QObject::trUtf8("t_iznos_val")
                    << QObject::trUtf8("t_ddv_val")
                    << QObject::trUtf8("t_rabat_val")
                    << QObject::trUtf8("t_iznos_plakanje_val")
                    << QObject::trUtf8("t_iznos_ddv_den")
                    << QObject::trUtf8("t_rabat_den")
                    << QObject::trUtf8("t_iznos_plakanje_den")
                    << QObject::trUtf8("t_transport_den")
                    << QObject::trUtf8("t_carina_den")
                    << QObject::trUtf8("t_ddv_den")
                    << QObject::trUtf8("t_drugi_trosoci_den")
                    << QObject::trUtf8("t_dok_status")
                    << QObject::trUtf8("t_user_id")
                    << QObject::trUtf8("t_komentar")
                    << QObject::trUtf8("t_mag_id")
                    << QObject::trUtf8("t_object_id")
                   ;
    }

    void GetDokumentData( QStringList& itemRecord, T &tItemT){
        dokumentT& tItem = (dokumentT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
                << tItem.td
                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
                << tItem.prevoznik_id
                << tItem.prevoznik_naziv
                << tItem.valuta
                << tItem.kurs
                << tItem.iznos_val
                << tItem.ddv_val
                << tItem.rabat_val
                << tItem.iznos_plakanje_val
                << tItem.iznos_ddv_den
                << tItem.rabat_den
                << tItem.iznos_plakanje_den
                << tItem.transport_den
                << tItem.carina_den
                << tItem.ddv_den
                << tItem.drugi_trosoci_den
                << tItem.dok_status
                << tItem.user_id
                << tItem.komentar
                << tItem.mag_id
                << tItem.object_id;
    }

    void GetHeaderDokumentDetail( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
                    << QObject::trUtf8("t_komintent_id")
                    << QObject::trUtf8("t_artikal_id")
                    << QObject::trUtf8("t_artikal_naziv")
                    << QObject::trUtf8("t_tip_artikal")
                    << QObject::trUtf8("t_link_artikal")
                    << QObject::trUtf8("t_edm")
                    << QObject::trUtf8("t_vlez_nab_cena_bez_ddv")
                    << QObject::trUtf8("t_vlez_nab_cena_so_ddv")
                    << QObject::trUtf8("t_vlez_prenesen_ddv")
                    << QObject::trUtf8("t_vlez_prenesen_ddv_denari")
                    << QObject::trUtf8("t_vlez_rabat")
                    << QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")
                    << QObject::trUtf8("t_vlez_marza")
                    << QObject::trUtf8("t_vlez_marza_den")
                    << QObject::trUtf8("t_vlez_prod_cena_bez_ddv")
                    << QObject::trUtf8("t_vlez_presmetan_ddv")
                    << QObject::trUtf8("t_vlez_prod_cena_so_ddv")
                    << QObject::trUtf8("t_vlez_prod_iznos_so_ddv")
                    << QObject::trUtf8("t_izl_cena_bez_ddv_calc")
                    << QObject::trUtf8("t_izl_cena_so_ddv_calc")
                    << QObject::trUtf8("t_izl_cena_so_ddv_prod")
                    << QObject::trUtf8("t_izl_ddv_prod")
                    << QObject::trUtf8("t_kol")
                    << QObject::trUtf8("t_mag_id")
                    << QObject::trUtf8("t_status")
                   ;
    }

    void GetDokumentDetailData( QStringList& itemRecord, T &tItemT){
        dokumentDetailT& tItem = (dokumentDetailT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
                << tItem.komintent_id
                << tItem.artikal_id
                << tItem.artikal_naziv
                << tItem.tip_artikal
                << tItem.link_artikal
                << tItem.edm
                << tItem.vlez_nab_cena_bez_ddv
                << tItem.vlez_nab_cena_so_ddv
                << tItem.vlez_prenesen_ddv
                << tItem.vlez_prenesen_ddv_denari
                << tItem.vlez_rabat
                << tItem.vlez_nabaven_iznos_so_ddv
                << tItem.vlez_marza
                << tItem.vlez_marza_den
                << tItem.vlez_prod_cena_bez_ddv
                << tItem.vlez_presmetan_ddv
                << tItem.vlez_prod_cena_so_ddv
                << tItem.vlez_prod_iznos_so_ddv
                << tItem.izl_cena_bez_ddv_calc
                << tItem.izl_cena_so_ddv_calc
                << tItem.izl_cena_so_ddv_prod
                << tItem.izl_ddv_prod
                << tItem.kol
                << tItem.mag_id
                << tItem.status;
    }

};

#endif // QBTEMPLATE_H
