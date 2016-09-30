#ifndef PRINTERLISTA_H
#define PRINTERLISTA_H
#include "Base/baseform.h"
#include <QWidget>
#include <QPrinter>
#include "Print/printerlista.h"
#include <QtWebEngineWidgets>
#include <QTextEdit>
#include <iostream>
#include <fstream>
#include <string>



using namespace std;



namespace Ui {
class PrinterLista;
}

class PrinterLista : public BaseForm
{
    Q_OBJECT

public:
    explicit PrinterLista(BaseForm *parent = 0);
    ~PrinterLista();
    void printPDF();
    virtual void pressEscape();
    void PrintDocumentText();

private:
    Ui::PrinterLista *ui;
    QWebEngineView *webview;
    QWebEnginePage *page;
    QString readFile();
    float faktor;

signals:
    void signalpressEscape();
    void finishedPrinting_();
private slots:
    void showLoad(bool a);
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_4_clicked();
};

#endif // PRINTERLISTA_H




