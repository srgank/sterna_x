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
    QString izl_prod_iznos_so_ddv;
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
    QString izl_prod_iznos_so_ddv;
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
}  AnalitikaKomintentiT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  AnalitikaKomintentiDetailT ;

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
}  ProFakturiT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  ProFakturiDetailT ;

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
}  PriemniciT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  PriemniciDetailT ;

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
}  IspratniciT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  IspratniciDetailT ;

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
} PovratniciT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  PovratniciDetailT ;

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
}  NarackiT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  NarackiDetailT ;

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
}  NalogT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  NalogDetailT ;


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
}  LagerT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  LagerDetailT ;

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
}  SmetkiT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  SmetkiDetailT ;

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
}  IntIspratniciT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  IntIspratniciDetailT ;

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
}  IntPriemniciT ;

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
    QString izl_prod_iznos_so_ddv;
    QString kol;
    QString mag_id;
    QString status;
}  IntPriemniciDetailT ;




typedef struct {
    fakturiT data1;
    QList<fakturiDetailT> data2;
} faktura_trans;

typedef struct {
    LagerT data1;
    QList<LagerDetailT> data2;
} Lager_trans;


typedef struct {
    ProFakturiT data1;
    QList<ProFakturiDetailT> data2;
} ProFaktura_trans;

typedef struct {
    IspratniciT data1;
    QList<IspratniciDetailT> data2;
} Ispratnici_trans;

typedef struct {
    PriemniciT data1;
    QList<PriemniciDetailT> data2;
} Priemnici_trans;


typedef struct {
    SmetkiT data1;
    QList<SmetkiDetailT> data2;
} Smetki_trans;

typedef struct {
    PovratniciT data1;
    QList<PovratniciDetailT> data2;
} Povratnici_trans;

typedef struct {
    NarackiT data1;
    QList<NarackiDetailT> data2;
} Naracki_trans;

typedef struct {
    NalogT data1;
    QList<NalogDetailT> data2;
} Nalog_trans;


typedef struct {
    AnalitikaKomintentiT data1;
    QList<AnalitikaKomintentiDetailT> data2;
} AnalitikaKomintenti_trans;



typedef struct {
    IntIspratniciT data1;
    QList<IntIspratniciDetailT> data2;
} IntIspratnici_trans;

typedef struct {
    IntPriemniciT data1;
    QList<IntPriemniciDetailT> data2;
} IntPriemnici_trans;


typedef struct {
    QString dataItem;
    Qt::AlignmentFlag flag;
    bool isColor;
    Qt::GlobalColor colorName;
    bool showColumn;
    QString headerColumnName;
} showDataItem;


typedef struct {
    QString token;
    QString database_prefix;
    QString valid_to;
    QString company;
} loginDataT;



#endif // STRUCT_H
