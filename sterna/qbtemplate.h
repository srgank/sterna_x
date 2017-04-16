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
                GetProFakturaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(profakturiDetailT)) {
                GetProFakturaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(ispratnicaT)) {
                GetIspratnicaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(ispratnicaDetailT)) {
                GetIspratnicaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(priemnicaT)) {
                GetPriemnicaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(priemnicaDetailT)) {
                GetPriemnicaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(povratnicaT)) {
                GetPovratnicaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(povratnicaDetailT)) {
                GetPovratnicaDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(nalogT)) {
                GetNalogData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(nalogDetailT)) {
                GetNalogDetailData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(narackaT)) {
                GetNarackaData( itemRecord, tempItem);
         }else if (typeid(T) == typeid(narackaDetailT)) {
                GetNarackaDetailData( itemRecord, tempItem);
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
        model->setColumnCount(c);

        for (int m = 0; m < c; m++){
            if (headerNames.at(m).showColumn == true){
            model->setHeaderData(m, Qt::Horizontal, headerNames.at(m).headerColumnName);
            }
        }
        table->setModel(model);
        table->setHorizontalHeader(header);
        header->show();
        int row = 0;
        for(int ii = 0; ii < tlist.count();ii++)
        {
            QList<showDataItem> itemRecord;
            T tempItem = ((QList<T>)tlist).at(ii);
            itemRecord = GetItemRecord( tempItem);
            for (int i = 0; i < c; i++)
            {
                QStandardItem *item = new QStandardItem(itemRecord.at(i).dataItem);
                item->setTextAlignment(itemRecord.at(i).flag);
                QBrush b;

                if (itemRecord.at(i).isColor == 1){
                    b.setColor(itemRecord.at(i).colorName);
                    item->setForeground(b);
                }

                item->setEditable(false);
                //ui->tableView->setRowHeight(row, 20);
                if (itemRecord.at(i).showColumn == true){
                    table->setColumnWidth(i, colWidth.at(i));
                }else{
                    table->setColumnWidth(i, 0);
                }

                item->setEditable(false);
                model->setItem(row, i, item);
            }
            itemRecord.clear();
            row++;
        }
        header->show();
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

    //------------- fakturi -------------------------------------------

    void GetFakturaData( QList<showDataItem>& itemRecord, T &tItemT){
        fakturiT& tItem = (fakturiT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Документ\nИД")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Документ\nТип")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Коминтент\nИд")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Komintent\nНазив")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
//                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
//                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
//                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
//                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
//                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
//                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
//                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
//                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
//                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
//                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
//                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
//                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
//                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
//                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
//                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
//                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
//                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
//                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetFakturaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        fakturiDetailT& tItem = (fakturiDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Прод. Цена\nсо ДДВ")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Кол.")}
                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("Износ\nсо ДДВ")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- profakturi -------------------------------------------

    void GetProFakturaData( QList<showDataItem>& itemRecord, T &tItemT){
        profakturiT& tItem = (profakturiT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("document_tip")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("komintent_id")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("komintent_naziv")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetProFakturaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        profakturiDetailT& tItem = (profakturiDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_prod")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kol")}
//                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("izl_prod_iznos_so_ddv")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- priemnica -------------------------------------------


    void GetPriemnicaData( QList<showDataItem>& itemRecord, T &tItemT){
        priemnicaT& tItem = (priemnicaT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("document_tip")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("komintent_id")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("komintent_naziv")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetPriemnicaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        priemnicaDetailT& tItem = (priemnicaDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_prod")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kol")}
//`                 << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("izl_prod_iznos_so_ddv")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- ispratnica -------------------------------------------

    void GetIspratnicaData( QList<showDataItem>& itemRecord, T &tItemT){
        ispratnicaT& tItem = (ispratnicaT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("document_tip")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("komintent_id")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("komintent_naziv")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetIspratnicaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        ispratnicaDetailT& tItem = (ispratnicaDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_prod")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kol")}
//                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("izl_prod_iznos_so_ddv")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- povratnica -------------------------------------------

    void GetPovratnicaData( QList<showDataItem>& itemRecord, T &tItemT){
        povratnicaT& tItem = (povratnicaT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("document_tip")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("komintent_id")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("komintent_naziv")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetPovratnicaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        povratnicaDetailT& tItem = (povratnicaDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_prod")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kol")}
//                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("izl_prod_iznos_so_ddv")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- naracka -------------------------------------------

    void GetNarackaData( QList<showDataItem>& itemRecord, T &tItemT){
        narackaT& tItem = (narackaT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("document_tip")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("komintent_id")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("komintent_naziv")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetNarackaDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        narackaDetailT& tItem = (narackaDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_prod")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kol")}
//                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("izl_prod_iznos_so_ddv")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- nalog -------------------------------------------

    void GetNalogData( QList<showDataItem>& itemRecord, T &tItemT){
        nalogT& tItem = (nalogT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid") }
                << showDataItem{tItem.dokument_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
                << showDataItem{tItem.dokument_tip, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("document_tip")}
//                << showDataItem{tItem.td, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("td")}
//                << showDataItem{tItem.tds, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("tds")}
                << showDataItem{tItem.komintent_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("komintent_id")}
                << showDataItem{tItem.komintent_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("komintent_naziv")}
//                << showDataItem{tItem.prevoznik_id, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_id")}
//                << showDataItem{tItem.prevoznik_naziv, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("prevoznik_naziv")}
                << showDataItem{tItem.valuta, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("valuta")}
                << showDataItem{tItem.kurs, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kurs")}
                << showDataItem{tItem.iznos_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_val")}
                << showDataItem{tItem.ddv_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_val")}
                << showDataItem{tItem.rabat_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_val")}
                << showDataItem{tItem.iznos_plakanje_val, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_val")}
                << showDataItem{tItem.iznos_ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_ddv_den")}
                << showDataItem{tItem.rabat_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_rabat_den")}
                << showDataItem{tItem.iznos_plakanje_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_iznos_plakanje_den")}
                << showDataItem{tItem.transport_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_transport_den")}
                << showDataItem{tItem.carina_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_carina_den")}
                << showDataItem{tItem.ddv_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_ddv_den")}
                << showDataItem{tItem.drugi_trosoci_den, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_drugi_trosoci_den")}
                << showDataItem{tItem.dok_status, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_dok_status")}
                << showDataItem{tItem.user_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_user_id")}
                << showDataItem{tItem.komentar, Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_komentar")}
                << showDataItem{tItem.mag_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_mag_id")}
                << showDataItem{tItem.object_id, Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("t_object_id")}
                ;
    }

    void GetNalogDetailData( QList<showDataItem>& itemRecord, T &tItemT){
        nalogDetailT& tItem = (nalogDetailT&)tItemT;
        itemRecord
                << showDataItem{tItem.tid,Qt::AlignLeft, false, Qt::color0, false, QObject::trUtf8("tid")}
//                << showDataItem{tItem.dokument_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("dokument_id")}
//                << showDataItem{tItem.dokument_tip,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("document_tip")}
                << showDataItem{tItem.komintent_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Шифра\nКоминтент")}
                << showDataItem{tItem.artikal_id,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("Артикал\nИд")}
                << showDataItem{tItem.artikal_naziv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Артикал\nНазив")}
//                << showDataItem{tItem.tip_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Тип Артикал")}
//                << showDataItem{tItem.link_artikal,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("Линк Артикал")}
//                << showDataItem{tItem.edm,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_edm")}
//                << showDataItem{tItem.vlez_nab_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_nab_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_nab_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv")}
//                << showDataItem{tItem.vlez_prenesen_ddv_denari,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prenesen_ddv_denari")}
//                << showDataItem{tItem.vlez_rabat,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_rabat")}
//                << showDataItem{tItem.vlez_nabaven_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_nabaven_iznos_so_ddv")}
//                << showDataItem{tItem.vlez_marza,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza")}
//                << showDataItem{tItem.vlez_marza_den,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("t_vlez_marza_den")}
//                << showDataItem{tItem.vlez_prod_cena_bez_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_bez_ddv")}
//                << showDataItem{tItem.vlez_presmetan_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_presmetan_ddv")}
//                << showDataItem{tItem.vlez_prod_cena_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_cena_so_ddv")}
//                << showDataItem{tItem.vlez_prod_iznos_so_ddv,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("vlez_prod_iznos_so_ddv")}
//                << showDataItem{tItem.izl_cena_bez_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_bez_ddv_calc")}
//                << showDataItem{tItem.izl_cena_so_ddv_calc,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_calc")}
                << showDataItem{tItem.izl_cena_so_ddv_prod,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("izl_cena_so_ddv_prod")}
//                << showDataItem{tItem.izl_ddv_prod,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("izl_ddv_prod")}
                << showDataItem{tItem.kol,Qt::AlignRight, false, Qt::color0, true, QObject::trUtf8("kol")}
//                << showDataItem{tItem.izl_prod_iznos_so_ddv,Qt::AlignRight, true, Qt::blue, true, QObject::trUtf8("izl_prod_iznos_so_ddv")}
//                << showDataItem{tItem.mag_id,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("mag_id")}
//                << showDataItem{tItem.status,Qt::AlignLeft, false, Qt::color0, true, QObject::trUtf8("status")}
                 ;
    }

    //------------- func -------------------------------------------

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
