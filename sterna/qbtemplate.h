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

     void ConvertDokument(QList<dokumentT>& inputlist, QList<T>& outputList){
        if (typeid(T) == typeid(fakturiT)) {

            for (int i = 0; i < inputlist.count(); i++){
                fakturiT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;

                outputList << (const T&) tempItem;
            }

        } else if (typeid(T) == typeid(profakturiT)) {

            for (int i = 0; i < inputlist.count(); i++){
                profakturiT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;
                outputList << (const T&) tempItem;

            }

        } else if (typeid(T) == typeid(ispratnicaT)) {

            for (int i = 0; i < inputlist.count(); i++){
                ispratnicaT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;

                outputList << (const T&) tempItem;
            }

        } else if (typeid(T) == typeid(priemnicaT)) {

            for (int i = 0; i < inputlist.count(); i++){
                priemnicaT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;

                outputList << (const T&) tempItem;
            }

        } else if (typeid(T) == typeid(povratnicaT)) {

            for (int i = 0; i < inputlist.count(); i++){
                povratnicaT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;

                outputList << (const T&) tempItem;
            }

        }else if (typeid(T) == typeid(nalogT)) {

            for (int i = 0; i < inputlist.count(); i++){
                nalogT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;

                outputList << (const T&) tempItem;
            }

        }else if (typeid(T) == typeid(narackaT)) {

            for (int i = 0; i < inputlist.count(); i++){
                narackaT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.td = inputlist.at(i).td;
                tempItem.tds = inputlist.at(i).tds;
                tempItem.komintent_id= inputlist.at(i).komintent_id;
                tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
                tempItem.valuta= inputlist.at(i).valuta;

                tempItem.kurs= inputlist.at(i).kurs;
                tempItem.iznos_val= inputlist.at(i).iznos_val;
                tempItem.ddv_val= inputlist.at(i).ddv_val;
                tempItem.rabat_val= inputlist.at(i).rabat_val;
                tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
                tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
                tempItem.rabat_den= inputlist.at(i).rabat_den;
                tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
                tempItem.transport_den= inputlist.at(i).transport_den;

                tempItem.carina_den= inputlist.at(i).carina_den;
                tempItem.ddv_den= inputlist.at(i).ddv_den;
                tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
                tempItem.dok_status= inputlist.at(i).dok_status;
                tempItem.user_id= inputlist.at(i).user_id;
                tempItem.komentar= inputlist.at(i).komentar;
                tempItem.mag_id= inputlist.at(i).mag_id;
                tempItem.object_id= inputlist.at(i).object_id;

                outputList << (const T&) tempItem;
            }

        }
     }
     void ConvertDokumentDetail(QList<dokumentDetailT>& inputlist, QList<T>& outputList){
        if (typeid(T) == typeid(fakturiDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                fakturiDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.izl_prod_iznos_so_ddv = inputlist.at(i).izl_prod_iznos_so_ddv;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;
            }

        } else if (typeid(T) == typeid(profakturiDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                profakturiDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;

            }

        } else if (typeid(T) == typeid(ispratnicaDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                ispratnicaDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;
            }

        } else if (typeid(T) == typeid(priemnicaDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                priemnicaDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;
            }

        } else if (typeid(T) == typeid(povratnicaDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                povratnicaDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;
            }

        }else if (typeid(T) == typeid(nalogDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                nalogDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;
            }

        }else if (typeid(T) == typeid(narackaDetailT)) {

            for (int i = 0; i < inputlist.count(); i++){
                narackaDetailT tempItem;
                tempItem.tid = inputlist.at(i).tid;
                tempItem.dokument_id = inputlist.at(i).dokument_id;
                tempItem.dokument_tip = inputlist.at(i).dokument_tip;
                tempItem.komintent_id = inputlist.at(i).komintent_id;
                tempItem.artikal_id = inputlist.at(i).artikal_id;
                tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
                tempItem.tip_artikal = inputlist.at(i).tip_artikal;
                tempItem.link_artikal = inputlist.at(i).link_artikal;
                tempItem.edm = inputlist.at(i).edm;
                tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
                tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
                tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
                tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
                tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
                tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
                tempItem.vlez_marza = inputlist.at(i).vlez_marza;
                tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
                tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
                tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
                tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
                tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
                tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
                tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
                tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
                tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
                tempItem.kol = inputlist.at(i).kol;
                tempItem.mag_id = inputlist.at(i).mag_id;
                tempItem.status = inputlist.at(i).status;
                outputList << (const T&) tempItem;
            }
        }
     }

     void AddItem( QList<T>& list, T& item ){
         list.push_back(item);
     }
     void RemoveItem( QList<T>& list, int i ){
         list.removeAt(i);
     }

     T getCurrentData(QList<T> &list, int m)
     {
         T resItem;
         resItem = list.at(m);
         return resItem;
     }

     T getCurrentArtikalKomintentData(QList<T> &list, QString id)
     {
         T resItem;
         for (int i = 0; i < list.count(); i++){
             if (list.at(i).id == id){
                 resItem = list.at(i);
                 break;
             }
         }
         return resItem;
     }


//     QStringList GetHeaderNames(/*QList<T>& tlist*/){
//         QStringList headerNames;
//         if (typeid(T) == typeid(artikalT)) {
//             GetHeaderArtikal(headerNames);
//         }else if (typeid(T) == typeid(komintentT)) {
//             GetHeaderKomintent(headerNames);
//         }else if (typeid(T) == typeid(dokumentT)) {
//             GetHeaderDokument(headerNames);
//         }else if (typeid(T) == typeid(dokumentDetailT)) {
//             GetHeaderDokumentDetail(headerNames);
//         }else if (typeid(T) == typeid(fakturiT)) {
//             GetHeaderFaktura(headerNames);
//         }else if (typeid(T) == typeid(fakturiDetailT)) {
//             GetHeaderFakturaDetail(headerNames);
//         }else if (typeid(T) == typeid(profakturiT)) {
//             GetHeaderProFaktura(headerNames);
//         }else if (typeid(T) == typeid(profakturiDetailT)) {
//             GetHeaderProFakturaDetail(headerNames);
//         }else if (typeid(T) == typeid(ispratnicaT)) {
//             GetHeaderIspratnica(headerNames);
//         }else if (typeid(T) == typeid(ispratnicaDetailT)) {
//             GetHeaderIspratnicaDetail(headerNames);
//         }else if (typeid(T) == typeid(priemnicaT)) {
//             GetHeaderPriemnica(headerNames);
//         }else if (typeid(T) == typeid(priemnicaDetailT)) {
//             GetHeaderPriemnicaDetail(headerNames);
//         }else if (typeid(T) == typeid(povratnicaT)) {
//             GetHeaderPovratnica(headerNames);
//         }else if (typeid(T) == typeid(povratnicaDetailT)) {
//             GetHeaderPovratnicaDetail(headerNames);
//         }else if (typeid(T) == typeid(nalogT)) {
//             GetHeaderNalog(headerNames);
//         }else if (typeid(T) == typeid(nalogDetailT)) {
//             GetHeaderNalogDetail(headerNames);
//         }else if (typeid(T) == typeid(narackaT)) {
//             GetHeaderNaracka(headerNames);
//         }else if (typeid(T) == typeid(narackaDetailT)) {
//             GetHeaderNarackaDetail(headerNames);
//         }
//         return headerNames;
//     }

     QList<showDataItem> GetItemRecord(T tempItem){
         QList<showDataItem> itemRecord;
         if (typeid(T) == typeid(artikalT)) {
               GetArtikalData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(komintentT)) {
               GetKomintentData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(dokumentT)) {
//                  GetDokumentData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(dokumentDetailT)) {
//                GetDokumentDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(fakturiT)) {
             GetFakturaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(fakturiDetailT)) {
             GetFakturaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(profakturiT)) {
//                GetProFakturaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(profakturiDetailT)) {
//                GetProFakturaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(ispratnicaT)) {
//                GetIspratnicaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(ispratnicaDetailT)) {
//                GetIspratnicaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(priemnicaT)) {
//                GetPriemnicaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(priemnicaDetailT)) {
//                GetPriemnicaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(povratnicaT)) {
//                GetPovratnicaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(povratnicaDetailT)) {
//                GetPovratnicaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(nalogT)) {
//                GetNalogData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(nalogDetailT)) {
//                GetNalogDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(narackaT)) {
//                GetNarackaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(narackaDetailT)) {
//                GetNarackaDetailData( itemRecord, tempItem);
         }
         return itemRecord;
     }


    void ShowData(QList<T>& tlist, QStandardItemModel* model, QHeaderView* header, QTableView *table, QList<int> colWidth)
    {
        QList<showDataItem> headerNames;
        if (tlist.count() != 0){
            headerNames = GetItemRecord(tlist.at(0));
        }

        int r = tlist.count();
        int c = headerNames.count();
        if (!model){
            return;
        }
        model->clear();
        model->setRowCount(r);
        int cc = 0;
        for (int m = 0; m < c; m++){
            if (headerNames.at(m).showColumn == true){
            model->setHeaderData( m, Qt::Horizontal, headerNames.at(cc).headerColumnName);
            cc++;
            }
        }
        model->setColumnCount(cc);
        table->setModel(model);
        table->setHorizontalHeader(header);
        header->show();

        int row = 0;
        for(int ii = 0; ii < tlist.count();ii++)
        {
            QList<showDataItem> itemRecord;
            T tempItem = ((QList<T>)tlist).at(ii);
            itemRecord = GetItemRecord( tempItem);
            int m_col = 0;
            for (int i = 0; i < c; i++)
            {
                if (itemRecord.at(i).showColumn != true){
                    continue;
                }
                QStandardItem *item = new QStandardItem(itemRecord.at(m_col).dataItem);
                item->setTextAlignment(itemRecord.at(m_col).flag);
                QBrush b;

                if (itemRecord.at(i).isColor == 1){
                    b.setColor(itemRecord.at(m_col).colorName);
                    item->setForeground(b);
                }

                item->setEditable(false);
                //ui->tableView->setRowHeight(row, 20);
                table->setColumnWidth(m_col, colWidth.at(m_col));
                item->setEditable(false);
                model->setItem(row, m_col, item);
                m_col++;
            }
            itemRecord.clear();
            row++;
        }

        tlist.clear();
        table->show();
    }

    //------------- artikli -------------------------------------------


    void GetArtikalData( QList<showDataItem>& itemRecord, T &tItemT){
        artikalT& tItem = (artikalT&)tItemT;

        itemRecord << showDataItem{tItem.id, Qt::AlignLeft,false ,Qt::color0, false, QObject::trUtf8("Id.") }
                       << showDataItem{tItem.sifra, Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("Шифра")}
                       << showDataItem{tItem.artikal, Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Артикал")}
                       << showDataItem{tItem.edm, Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Едм")}
                       << showDataItem{tItem.ref, Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Реф")}
                       << showDataItem{tItem.kataloski_broj, Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Кат.број")}
                       << showDataItem{tItem.ddv, Qt::AlignRight,false ,Qt::color0, true, QObject::trUtf8("Ддв")}
                       << showDataItem{tItem.proizvoditel, Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Производител")}
                       << showDataItem{tItem.kategorija, Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Категорија")};
    }

    //------------- komintenti -------------------------------------------

    void GetKomintentData( QList<showDataItem>& itemRecord, T &tItemT){
        komintentT& tItem = (komintentT&)tItemT;
        itemRecord
                   << showDataItem{tItem.id,Qt::AlignLeft,false ,Qt::color0, false, QObject::trUtf8("Id.")}
                   << showDataItem{tItem.sifra,Qt::AlignRight,false ,Qt::color0, true, QObject::trUtf8("Шифра")}
                   << showDataItem{tItem.naziv,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Назив")}
                   << showDataItem{tItem.adresa,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Адреса")}
                   << showDataItem{tItem.tel,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Тел")}
                   << showDataItem{tItem.mobil,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Мобил")}
                   << showDataItem{tItem.zirosmetka,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Жиро сметка")}
                   << showDataItem{tItem.edb,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Едб")}
                   << showDataItem{tItem.deponent,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Депонент")}
                   << showDataItem{tItem.sifra_dejnost,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Шиф.Дејност")}
                   << showDataItem{tItem.mb,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("МБ")}
                   << showDataItem{tItem.zabeleska1,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Забелешка")}
                   << showDataItem{tItem.zabeleska2,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Забелешка")}
                   << showDataItem{tItem.rabat,Qt::AlignRight,false ,Qt::color0, true, QObject::trUtf8("Рабат")}
                   << showDataItem{tItem.grad,Qt::AlignLeft,false ,Qt::color0, true, QObject::trUtf8("Град")}
                   ;
    }

//------------- dokumenti -------------------------------------------

//    void GetHeaderDokument( QStringList& headerNames){
//        headerNames << QObject::trUtf8("tid.")
//                    << QObject::trUtf8("dokument_id")
//                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
//                    << QObject::trUtf8("komintent_id")
//                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
//                    << QObject::trUtf8("valuta")
//                    << QObject::trUtf8("kurs")
//                    << QObject::trUtf8("t_iznos_val")
//                    << QObject::trUtf8("t_ddv_val")
//                    << QObject::trUtf8("t_rabat_val")
//                    << QObject::trUtf8("t_iznos_plakanje_val")
//                    << QObject::trUtf8("t_iznos_ddv_den")
//                    << QObject::trUtf8("t_rabat_den")
//                    << QObject::trUtf8("t_iznos_plakanje_den")
//                    << QObject::trUtf8("t_transport_den")
//                    << QObject::trUtf8("t_carina_den")
//                    << QObject::trUtf8("t_ddv_den")
//                    << QObject::trUtf8("t_drugi_trosoci_den")
//                    << QObject::trUtf8("t_dok_status")
//                    << QObject::trUtf8("t_user_id")
//                    << QObject::trUtf8("t_komentar")
//                    << QObject::trUtf8("t_mag_id")
//                    << QObject::trUtf8("t_object_id")
//                   ;
//    }

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

//    void GetHeaderDokumentDetail( QStringList& headerNames){
//        headerNames << QObject::trUtf8("tid.")
//                    << QObject::trUtf8("dokument_id")
//                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("t_komintent_id")
//                    << QObject::trUtf8("t_artikal_id")
//                    << QObject::trUtf8("t_artikal_naziv")
//                    << QObject::trUtf8("t_tip_artikal")
//                    << QObject::trUtf8("t_link_artikal")
//                    << QObject::trUtf8("t_edm")
//                    << QObject::trUtf8("t_vlez_nab_cena_bez_ddv")
//                    << QObject::trUtf8("t_vlez_nab_cena_so_ddv")
//                    << QObject::trUtf8("t_vlez_prenesen_ddv")
//                    << QObject::trUtf8("t_vlez_prenesen_ddv_denari")
//                    << QObject::trUtf8("t_vlez_rabat")
//                    << QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")
//                    << QObject::trUtf8("t_vlez_marza")
//                    << QObject::trUtf8("t_vlez_marza_den")
//                    << QObject::trUtf8("t_vlez_prod_cena_bez_ddv")
//                    << QObject::trUtf8("t_vlez_presmetan_ddv")
//                    << QObject::trUtf8("t_vlez_prod_cena_so_ddv")
//                    << QObject::trUtf8("t_vlez_prod_iznos_so_ddv")
//                    << QObject::trUtf8("t_izl_cena_bez_ddv_calc")
//                    << QObject::trUtf8("t_izl_cena_so_ddv_calc")
//                    << QObject::trUtf8("t_izl_cena_so_ddv_prod")
//                    << QObject::trUtf8("t_izl_ddv_prod")
//                    << QObject::trUtf8("t_kol")
//                    << QObject::trUtf8("t_mag_id")
//                    << QObject::trUtf8("t_status")
//                   ;
//    }

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

    //------------- fakturi -------------------------------------------

//    void GetHeaderFaktura( QStringList& headerNames){
//        headerNames << QObject::trUtf8("tid.")
//                    << QObject::trUtf8("dokument_id")
//                    << QObject::trUtf8("document_tip")
////                    << QObject::trUtf8("td")
////                    << QObject::trUtf8("tds")
//                    << QObject::trUtf8("komintent_id")
//                    << QObject::trUtf8("komintent_naziv")
////                    << QObject::trUtf8("prevoznik_id")
////                    << QObject::trUtf8("prevoznik_naziv")
//                    << QObject::trUtf8("valuta")
//                    << QObject::trUtf8("kurs")
//                    << QObject::trUtf8("t_iznos_val")
//                    << QObject::trUtf8("t_ddv_val")
//                    << QObject::trUtf8("t_rabat_val")
//                    << QObject::trUtf8("t_iznos_plakanje_val")
//                    << QObject::trUtf8("t_iznos_ddv_den")
//                    << QObject::trUtf8("t_rabat_den")
//                    << QObject::trUtf8("t_iznos_plakanje_den")
//                    << QObject::trUtf8("t_transport_den")
//                    << QObject::trUtf8("t_carina_den")
//                    << QObject::trUtf8("t_ddv_den")
//                    << QObject::trUtf8("t_drugi_trosoci_den")
//                    << QObject::trUtf8("t_dok_status")
//                    << QObject::trUtf8("t_user_id")
//                    << QObject::trUtf8("t_komentar")
//                    << QObject::trUtf8("t_mag_id")
//                    << QObject::trUtf8("t_object_id")
//                   ;
//    }

    void GetFakturaData( QList<showDataItem>& itemRecord, T &tItemT){
        fakturiT& tItem = (fakturiT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                ;
    }

//    void GetHeaderFakturaDetail( QStringList& headerNames){
//        headerNames
//                    << QObject::trUtf8("tid.")
////                    << QObject::trUtf8("dokument_id")
////                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("Шифра Коминтент")
//                    << QObject::trUtf8("Артикал Ид")
//                    << QObject::trUtf8("Артикал Назив")
////                    << QObject::trUtf8("Тип Артикал")
////                    << QObject::trUtf8("Линк Артикал")
////                    << QObject::trUtf8("t_edm")
////                    << QObject::trUtf8("t_vlez_nab_cena_bez_ddv")
////                    << QObject::trUtf8("t_vlez_nab_cena_so_ddv")
////                    << QObject::trUtf8("t_vlez_prenesen_ddv")
////                    << QObject::trUtf8("t_vlez_prenesen_ddv_denari")
////                    << QObject::trUtf8("t_vlez_rabat")
////                    << QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")
////                    << QObject::trUtf8("t_vlez_marza")
////                    << QObject::trUtf8("t_vlez_marza_den")
////                    << QObject::trUtf8("t_vlez_prod_cena_bez_ddv")
////                    << QObject::trUtf8("t_vlez_presmetan_ddv")
////                    << QObject::trUtf8("t_vlez_prod_cena_so_ddv")
////                    << QObject::trUtf8("t_vlez_prod_iznos_so_ddv")
////                    << QObject::trUtf8("t_izl_cena_bez_ddv_calc")
////                    << QObject::trUtf8("t_izl_cena_so_ddv_calc")
//                    << QObject::trUtf8("t_izl_cena_so_ddv_prod")
////                    << QObject::trUtf8("t_izl_ddv_prod")
//                    << QObject::trUtf8("t_kol")
//                    << QObject::trUtf8("izl_prod_iznos_so_ddv")
////                    << QObject::trUtf8("t_mag_id")
////                    << QObject::trUtf8("t_status")
//                   ;
//    }

    void GetFakturaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        fakturiDetailT& tItem = (fakturiDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("tid")}
                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tid")}
                 ;
    }

    //------------- profakturi -------------------------------------------


    void GetHeaderProFaktura( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
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

    void GetProFakturaData( QStringList& itemRecord, T &tItemT){
        profakturiT& tItem = (profakturiT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
//                << tItem.td
//                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
//                << tItem.prevoznik_id
//                << tItem.prevoznik_naziv
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

    void GetHeaderProFakturaDetail( QStringList& headerNames){
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

    void GetProFakturaDetailData( QStringList& itemRecord, T &tItemT){
        profakturiDetailT& tItem = (profakturiDetailT&)tItemT;
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

    //------------- priemnica -------------------------------------------


    void GetHeaderPriemnica( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
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

    void GetPriemnicaData( QStringList& itemRecord, T &tItemT){
        priemnicaT& tItem = (priemnicaT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
//                << tItem.td
//                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
//                << tItem.prevoznik_id
//                << tItem.prevoznik_naziv
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

    void GetHeaderPriemnicaDetail( QStringList& headerNames){
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

    void GetPriemnicaDetailData( QStringList& itemRecord, T &tItemT){
        priemnicaDetailT& tItem = (priemnicaDetailT&)tItemT;
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

    //------------- ispratnica -------------------------------------------

    void GetHeaderIspratnica( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
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

    void GetIspratnicaData( QStringList& itemRecord, T &tItemT){
        ispratnicaT& tItem = (ispratnicaT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
//                << tItem.td
//                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
//                << tItem.prevoznik_id
//                << tItem.prevoznik_naziv
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

    void GetHeaderIspratnicaDetail( QStringList& headerNames){
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

    void GetIspratnicaDetailData( QStringList& itemRecord, T &tItemT){
        ispratnicaDetailT& tItem = (ispratnicaDetailT&)tItemT;
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


    //------------- povratnica -------------------------------------------


    void GetHeaderPovratnica( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
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

    void GetPovratnicaData( QStringList& itemRecord, T &tItemT){
        povratnicaT& tItem = (povratnicaT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
//                << tItem.td
//                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
//                << tItem.prevoznik_id
//                << tItem.prevoznik_naziv
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

    void GetHeaderPovratnicaDetail( QStringList& headerNames){
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

    void GetPovratnicaDetailData( QStringList& itemRecord, T &tItemT){
        povratnicaDetailT& tItem = (povratnicaDetailT&)tItemT;
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

    //------------- naracka -------------------------------------------

    void GetHeaderNaracka( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
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

    void GetNarackaData( QStringList& itemRecord, T &tItemT){
        narackaT& tItem = (narackaT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
//                << tItem.td
//                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
//                << tItem.prevoznik_id
//                << tItem.prevoznik_naziv
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

    void GetHeaderNarackaDetail( QStringList& headerNames){
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

    void GetNarackaDetailData( QStringList& itemRecord, T &tItemT){
        narackaDetailT& tItem = (narackaDetailT&)tItemT;
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

    //------------- nalog -------------------------------------------

    void GetHeaderNalog( QStringList& headerNames){
        headerNames << QObject::trUtf8("tid.")
                    << QObject::trUtf8("dokument_id")
                    << QObject::trUtf8("document_tip")
//                    << QObject::trUtf8("td")
//                    << QObject::trUtf8("tds")
                    << QObject::trUtf8("komintent_id")
                    << QObject::trUtf8("komintent_naziv")
//                    << QObject::trUtf8("prevoznik_id")
//                    << QObject::trUtf8("prevoznik_naziv")
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

    void GetNalogData( QStringList& itemRecord, T &tItemT){
        nalogT& tItem = (nalogT&)tItemT;
        itemRecord << tItem.tid
                << tItem.dokument_id
                << tItem.dokument_tip
//                << tItem.td
//                << tItem.tds
                << tItem.komintent_id
                << tItem.komintent_naziv
//                << tItem.prevoznik_id
//                << tItem.prevoznik_naziv
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

    void GetHeaderNalogDetail( QStringList& headerNames){
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

    void GetNalogDetailData( QStringList& itemRecord, T &tItemT){
        nalogDetailT& tItem = (nalogDetailT&)tItemT;
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


    void ConvertAnyToDokument(QList<T>& inputlist, QList<dokumentT>& outputList){
       if (typeid(T) == typeid(fakturiT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;

               outputList << tempItem;
           }

       } else if (typeid(T) == typeid(profakturiT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;
               outputList << tempItem;

           }

       } else if (typeid(T) == typeid(ispratnicaT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;

               outputList <<  tempItem;
           }

       } else if (typeid(T) == typeid(priemnicaT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;

               outputList << tempItem;
           }

       } else if (typeid(T) == typeid(povratnicaT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;

               outputList << tempItem;
           }

       }else if (typeid(T) == typeid(nalogT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;

               outputList << tempItem;
           }

       }else if (typeid(T) == typeid(narackaT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
//                tempItem.td = inputlist.at(i).td;
//                tempItem.tds = inputlist.at(i).tds;
               tempItem.komintent_id= inputlist.at(i).komintent_id;
               tempItem.komintent_naziv= inputlist.at(i).komintent_naziv;
//                tempItem.prevoznik_id= inputlist.at(i).prevoznik_id;
//                tempItem.prevoznik_naziv= inputlist.at(i).prevoznik_naziv;
               tempItem.valuta= inputlist.at(i).valuta;

               tempItem.kurs= inputlist.at(i).kurs;
               tempItem.iznos_val= inputlist.at(i).iznos_val;
               tempItem.ddv_val= inputlist.at(i).ddv_val;
               tempItem.rabat_val= inputlist.at(i).rabat_val;
               tempItem.iznos_plakanje_val= inputlist.at(i).iznos_plakanje_val;
               tempItem.iznos_ddv_den= inputlist.at(i).iznos_ddv_den;
               tempItem.rabat_den= inputlist.at(i).rabat_den;
               tempItem.iznos_plakanje_den= inputlist.at(i).iznos_plakanje_den;
               tempItem.transport_den= inputlist.at(i).transport_den;

               tempItem.carina_den= inputlist.at(i).carina_den;
               tempItem.ddv_den= inputlist.at(i).ddv_den;
               tempItem.drugi_trosoci_den= inputlist.at(i).drugi_trosoci_den;
               tempItem.dok_status= inputlist.at(i).dok_status;
               tempItem.user_id= inputlist.at(i).user_id;
               tempItem.komentar= inputlist.at(i).komentar;
               tempItem.mag_id= inputlist.at(i).mag_id;
               tempItem.object_id= inputlist.at(i).object_id;

               outputList <<  tempItem;
           }

       }
    }
    void ConvertAnyToDokumentDetail(QList<T>& inputlist, QList<dokumentDetailT>& outputList){
       if (typeid(T) == typeid(fakturiDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.izl_prod_iznos_so_ddv = inputlist.at(i).izl_prod_iznos_so_ddv;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;
           }

       } else if (typeid(T) == typeid(profakturiDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;

           }

       } else if (typeid(T) == typeid(ispratnicaDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;
           }

       } else if (typeid(T) == typeid(priemnicaDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;
           }

       } else if (typeid(T) == typeid(povratnicaDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;
           }

       }else if (typeid(T) == typeid(nalogDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;
           }

       }else if (typeid(T) == typeid(narackaDetailT)) {

           for (int i = 0; i < inputlist.count(); i++){
               dokumentDetailT tempItem;
               tempItem.tid = inputlist.at(i).tid;
               tempItem.dokument_id = inputlist.at(i).dokument_id;
               tempItem.dokument_tip = inputlist.at(i).dokument_tip;
               tempItem.komintent_id = inputlist.at(i).komintent_id;
               tempItem.artikal_id = inputlist.at(i).artikal_id;
               tempItem.artikal_naziv = inputlist.at(i).artikal_naziv;
               tempItem.tip_artikal = inputlist.at(i).tip_artikal;
               tempItem.link_artikal = inputlist.at(i).link_artikal;
               tempItem.edm = inputlist.at(i).edm;
               tempItem.vlez_nab_cena_bez_ddv = inputlist.at(i).vlez_nab_cena_bez_ddv;
               tempItem.vlez_nab_cena_so_ddv = inputlist.at(i).vlez_nab_cena_so_ddv;
               tempItem.vlez_prenesen_ddv = inputlist.at(i).vlez_prenesen_ddv;
               tempItem.vlez_prenesen_ddv_denari = inputlist.at(i).vlez_prenesen_ddv_denari;
               tempItem.vlez_rabat = inputlist.at(i).vlez_rabat;
               tempItem.vlez_nabaven_iznos_so_ddv = inputlist.at(i).vlez_nabaven_iznos_so_ddv;
               tempItem.vlez_marza = inputlist.at(i).vlez_marza;
               tempItem.vlez_marza_den = inputlist.at(i).vlez_marza_den;
               tempItem.vlez_prod_cena_bez_ddv = inputlist.at(i).vlez_prod_cena_bez_ddv;
               tempItem.vlez_presmetan_ddv = inputlist.at(i).vlez_presmetan_ddv;
               tempItem.vlez_prod_cena_so_ddv = inputlist.at(i).vlez_prod_cena_so_ddv;
               tempItem.vlez_prod_iznos_so_ddv = inputlist.at(i).vlez_prod_iznos_so_ddv;
               tempItem.izl_cena_bez_ddv_calc = inputlist.at(i).izl_cena_bez_ddv_calc;
               tempItem.izl_cena_so_ddv_calc = inputlist.at(i).izl_cena_so_ddv_calc;
               tempItem.izl_cena_so_ddv_prod = inputlist.at(i).izl_cena_so_ddv_prod;
               tempItem.izl_ddv_prod = inputlist.at(i).izl_ddv_prod;
               tempItem.kol = inputlist.at(i).kol;
               tempItem.mag_id = inputlist.at(i).mag_id;
               tempItem.status = inputlist.at(i).status;
               outputList <<  tempItem;
           }
       }
    }



};

#endif // QBTEMPLATE_H
