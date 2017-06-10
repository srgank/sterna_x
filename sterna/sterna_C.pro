#-------------------------------------------------
#
# Project created by QtCreator 2015-11-28T19:17:48
#
#-------------------------------------------------

QT       += core gui network printsupport webenginewidgets webengine
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = sterna_C
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Base/baseform.cpp \
    Artikli/artikli.cpp \
    Artikli/artiklivnes.cpp \
    Artikli/artiklilista.cpp \
    Artikli/artiklikorekcija.cpp \
    Left/left.cpp \
    xx.cpp \
    Helper/qhelperc.cpp \
    Komintenti/komintenti.cpp \
    Komintenti/komintentikorekcija.cpp \
    Komintenti/komintentilista.cpp \
    Komintenti/komintentivnes.cpp \
    Fakturi/fakturi.cpp \
    Fakturi/fakturikorekcija.cpp \
    Fakturi/fakturilista.cpp \
    Fakturi/fakturivnes.cpp \
    Ispratnici/ispratnici.cpp \
    Ispratnici/ispratnicikorekcija.cpp \
    Ispratnici/ispratnicilista.cpp \
    Ispratnici/ispratnicivnes.cpp \
    Smetki/smetki.cpp \
    Smetki/smetkikorekcija.cpp \
    Smetki/smetkilista.cpp \
    Smetki/smetkivnes.cpp \
    ProFakturi/ProFakturi.cpp \
    ProFakturi/ProFakturikorekcija.cpp \
    ProFakturi/ProFakturilista.cpp \
    ProFakturi/ProFakturivnes.cpp \
    Naracki/naracki.cpp \
    Naracki/narackikorekcija.cpp \
    Naracki/narackilista.cpp \
    Naracki/narackivnes.cpp \
    Helper/qworker_artikli.cpp \
    Helper/qworker_komintent.cpp \
    Helper/qworker_dokumenti.cpp \
    Helper/qworker_magacin.cpp \
    Delegate/qcbitemdelegate.cpp \
    Delegate/qleitemdelegate.cpp \
    Print/formprint.cpp \
    Print/printerlista.cpp \
    Template/qfakturatemplate.cpp \
    dialog.cpp \
    Helper/qworkerlogin.cpp \
    LagerLista/lager.cpp \
    LagerLista/lagerkorekcija.cpp \
    LagerLista/lagerlista.cpp \
    LagerLista/lagervnes.cpp \
    Priemnici/priemnici.cpp \
    Priemnici/priemnicikorekcija.cpp \
    Priemnici/priemnicilista.cpp \
    Priemnici/priemnicivnes.cpp \
    Povratnica/povratnici.cpp \
    Povratnica/povratnicikorekcija.cpp \
    Povratnica/povratnicilista.cpp \
    Povratnica/povratnicivnes.cpp \
    Nalog/nalog.cpp \
    Nalog/nalogkorekcija.cpp \
    Nalog/naloglista.cpp \
    Nalog/nalogvnes.cpp \
    InternaIspratnica/int_ispratnica.cpp \
    InternaIspratnica/int_ispratnicakorekcija.cpp \
    InternaIspratnica/int_ispratnicalista.cpp \
    InternaIspratnica/int_ispratnicavnes.cpp \
    InternaPriemnica/int_priemnica.cpp \
    InternaPriemnica/int_priemnicakorekcija.cpp \
    InternaPriemnica/int_priemnicalista.cpp \
    InternaPriemnica/int_priemnicavnes.cpp \
    AnalitikaKomintenti/analitikakomintenti.cpp \
    AnalitikaKomintenti/analitikakomintentikorekcija.cpp \
    AnalitikaKomintenti/analitikakomintentilista.cpp \
    AnalitikaKomintenti/analitikakomintentivnes.cpp \
    AnalitikaArtikli/analitikaartikli.cpp \
    AnalitikaArtikli/analitikaartiklikorekcija.cpp \
    AnalitikaArtikli/analitikaartiklilista.cpp \
    AnalitikaArtikli/analitikaartiklivnes.cpp



HEADERS  += mainwindow.h \
    Base/baseform.h \
    Artikli/artikli.h \
    Artikli/artiklivnes.h \
    Artikli/artiklilista.h \
    Artikli/artiklikorekcija.h \
    Left/left.h \
    xx.h \
    Helper/qhelperc.h \
    Komintenti/komintenti.h \
    Komintenti/komintentikorekcija.h \
    Komintenti/komintentilista.h \
    Komintenti/komintentivnes.h \
    Fakturi/fakturi.h \
    Fakturi/fakturikorekcija.h \
    Fakturi/fakturilista.h \
    Fakturi/fakturivnes.h \
    Ispratnici/ispratnici.h \
    Ispratnici/ispratnicikorekcija.h \
    Ispratnici/ispratnicilista.h \
    Ispratnici/ispratnicivnes.h \
    Smetki/smetki.h \
    Smetki/smetkikorekcija.h \
    Smetki/smetkilista.h \
    Smetki/smetkivnes.h \
    ProFakturi/ProFakturi.h \
    ProFakturi/ProFakturikorekcija.h \
    ProFakturi/ProFakturilista.h \
    ProFakturi/ProFakturivnes.h \
    Naracki/naracki.h \
    Naracki/narackikorekcija.h \
    Naracki/narackilista.h \
    Naracki/narackivnes.h \
    Helper/qworker_artikli.h \
    Helper/qworker_komintent.h \
    Helper/qworker_dokumenti.h \
    Helper/qworker_magacin.h \
    Struct/struct.h \
    qbtemplate.h \
    Delegate/qcbitemdelegate.h \
    Delegate/qleitemdelegate.h \
    Print/formprint.h \
    Print/printerlista.h \
    Template/qfakturatemplate.h \
    dialog.h \
    Helper/qworkerlogin.h \
    LagerLista/lager.h \
    LagerLista/lagerkorekcija.h \
    LagerLista/lagerlista.h \
    LagerLista/lagervnes.h \
    Priemnici/priemnici.h \
    Priemnici/priemnicikorekcija.h \
    Priemnici/priemnicilista.h \
    Priemnici/priemnicivnes.h \
    Povratnica/povratnici.h \
    Povratnica/povratnicikorekcija.h \
    Povratnica/povratnicilista.h \
    Povratnica/povratnicivnes.h \
    Nalog/nalog.h \
    Nalog/nalogkorekcija.h \
    Nalog/naloglista.h \
    Nalog/nalogvnes.h \
    InternaIspratnica/int_ispratnica.h \
    InternaIspratnica/int_ispratnicakorekcija.h \
    InternaIspratnica/int_ispratnicalista.h \
    InternaIspratnica/int_ispratnicavnes.h \
    InternaPriemnica/int_priemnica.h \
    InternaPriemnica/int_priemnicakorekcija.h \
    InternaPriemnica/int_priemnicalista.h \
    InternaPriemnica/int_priemnicavnes.h \
    AnalitikaKomintenti/analitikakomintenti.h \
    AnalitikaKomintenti/analitikakomintentikorekcija.h \
    AnalitikaKomintenti/analitikakomintentilista.h \
    AnalitikaKomintenti/analitikakomintentivnes.h \
    AnalitikaArtikli/analitikaartikli.h \
    AnalitikaArtikli/analitikaartiklikorekcija.h \
    AnalitikaArtikli/analitikaartiklilista.h \
    AnalitikaArtikli/analitikaartiklivnes.h





FORMS    += mainwindow.ui \
    Base/baseform.ui \
    Artikli/artikli.ui \
    Artikli/artiklivnes.ui \
    Artikli/artiklilista.ui \
    Artikli/artiklikorekcija.ui \
    Left/left.ui \
    Komintenti/komintenti.ui \
    Komintenti/komintentikorekcija.ui \
    Komintenti/komintentilista.ui \
    Komintenti/komintentivnes.ui \
    Fakturi/fakturi.ui \
    Fakturi/fakturikorekcija.ui \
    Fakturi/fakturilista.ui \
    Fakturi/fakturivnes.ui \
    Ispratnici/ispratnici.ui \
    Ispratnici/ispratnicikorekcija.ui \
    Ispratnici/ispratnicilista.ui \
    Ispratnici/ispratnicivnes.ui \
    Smetki/smetki.ui \
    Smetki/smetkikorekcija.ui \
    Smetki/smetkilista.ui \
    Smetki/smetkivnes.ui \
    ProFakturi/ProFakturi.ui \
    ProFakturi/ProFakturikorekcija.ui \
    ProFakturi/ProFakturilista.ui \
    ProFakturi/ProFakturivnes.ui \
    Naracki/naracki.ui \
    Naracki/narackikorekcija.ui \
    Naracki/narackilista.ui \
    Naracki/narackivnes.ui \
    Print/formprint.ui \
    Print/printerlista.ui \
    dialog.ui \
    LagerLista/lager.ui \
    LagerLista/lagerkorekcija.ui \
    LagerLista/lagerlista.ui \
    LagerLista/lagervnes.ui \
    Priemnici/priemnici.ui \
    Priemnici/priemnicikorekcija.ui \
    Priemnici/priemnicilista.ui \
    Priemnici/priemnicivnes.ui \
    Povratnica/povratnici.ui \
    Povratnica/povratnicikorekcija.ui \
    Povratnica/povratnicilista.ui \
    Povratnica/povratnicivnes.ui \
    Nalog/nalog.ui \
    Nalog/nalogkorekcija.ui \
    Nalog/naloglista.ui \
    Nalog/nalogvnes.ui \
    InternaIspratnica/int_ispratnica.ui \
    InternaIspratnica/int_ispratnicakorekcija.ui \
    InternaIspratnica/int_ispratnicalista.ui \
    InternaIspratnica/int_ispratnicavnes.ui \
    InternaPriemnica/int_priemnica.ui \
    InternaPriemnica/int_priemnicakorekcija.ui \
    InternaPriemnica/int_priemnicalista.ui \
    InternaPriemnica/int_priemnicavnes.ui \
    AnalitikaKomintenti/analitikakomintenti.ui \
    AnalitikaKomintenti/analitikakomintentikorekcija.ui \
    AnalitikaKomintenti/analitikakomintentilista.ui \
    AnalitikaKomintenti/analitikakomintentivnes.ui \
    AnalitikaArtikli/analitikaartikli.ui \
    AnalitikaArtikli/analitikaartiklikorekcija.ui \
    AnalitikaArtikli/analitikaartiklilista.ui \
    AnalitikaArtikli/analitikaartiklivnes.ui


DISTFILES += \
    info.txt


