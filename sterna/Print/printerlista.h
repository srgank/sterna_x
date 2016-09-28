#ifndef PRINTERLISTA_H
#define PRINTERLISTA_H
#include "Base/baseform.h"
#include <QWidget>
#include <QPrinter>
#include "Print/printerlista.h"
#include <QWebEngineView>
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

private:
    Ui::PrinterLista *ui;
    QWebEngineView *webview;
    QString readFile();

signals:
    void signalpressEscape();
private slots:
    void showLoad(bool a);
    void on_toolButton_clicked();
};

#endif // PRINTERLISTA_H

