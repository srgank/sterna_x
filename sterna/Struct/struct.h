#ifndef STRUCT_H
#define STRUCT_H
#include <QList>

typedef struct {
    QString id;
    QString sifra;
    QString artikal;
    QString edm;
    QString ref;
    QString kataloski_broj;
    QString ddv;
    QString proizvoditel;
    QString kategorija;
} artikalT;


typedef struct {
    QString id;
    QString sifra;
    QString naziv;
    QString adresa;
    QString tel;
    QString mobil;
    QString zirosmetka;
    QString edb;
    QString deponent;
    QString sifra_dejnost;
    QString mb;
    QString zabeleska1;
    QString zabeleska2;
    QString rabat;
    QString grad;

}  komintentT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  dokumentT ;


typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  dokumentDetailT ;


typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  fakturiT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  fakturiDetailT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  profakturiT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  profakturiDetailT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  priemnicaT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  priemnicaDetailT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  ispratnicaT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  ispratnicaDetailT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  povratnicaT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  povratnicaDetailT ;


typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  nalogT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  nalogDetailT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString td;
    QString tds;
    QString komintent_id;
    QString komintent_naziv;
    QString prevoznik_id;
    QString prevoznik_naziv;
    QString valuta;

    QString kurs;
    QString iznos_val;
    QString ddv_val;
    QString rabat_val;
    QString iznos_plakanje_val;
    QString iznos_ddv_den;
    QString rabat_den;
    QString iznos_plakanje_den;
    QString transport_den;
    QString carina_den;
    QString ddv_den;
    QString drugi_trosoci_den;
    QString dok_status;
    QString user_id;
    QString komentar;
    QString mag_id;
    QString object_id;
}  narackaT ;

typedef struct {
    QString tid;
    QString dokument_id;
    QString dokument_tip;
    QString komintent_id;
    QString artikal_id;
    QString artikal_naziv;
    QString tip_artikal;
    QString link_artikal;
    QString edm;
    QString vlez_nab_cena_bez_ddv;
    QString vlez_nab_cena_so_ddv;
    QString vlez_prenesen_ddv;
    QString vlez_prenesen_ddv_denari;
    QString vlez_rabat;
    QString vlez_nabaven_iznos_so_ddv;
    QString vlez_marza;
    QString vlez_marza_den;
    QString vlez_prod_cena_bez_ddv;
    QString vlez_presmetan_ddv;
    QString vlez_prod_cena_so_ddv;
    QString vlez_prod_iznos_so_ddv;
    QString izl_cena_bez_ddv_calc;
    QString izl_cena_so_ddv_calc;
    QString izl_cena_so_ddv_prod;
    QString izl_ddv_prod;
    QString kol;
    QString mag_id;
    QString status;
}  narackaDetailT ;

typedef struct {
    fakturiT data1;
    QList<fakturiDetailT> data2;
} faktura_trans;



#endif // STRUCT_H
