#ifndef ARTIKLIVNES_H
#define ARTIKLIVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class ArtikliVnes;
}

class ArtikliVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit ArtikliVnes(BaseForm *parent = 0);
    ~ArtikliVnes();
    virtual void pressEscape();
    virtual void pressEnter();
    virtual void pressReturn();
    virtual void updateFont();
    virtual void Refresh();

private:
    Ui::ArtikliVnes *ui;
    QHelperC *hlp;
    void on_SifraArtikalEdit_EditingFinished();
    QString str_yellow;
    QString str_none;
protected:
    bool eventFilter(QObject *object, QEvent *event);
signals:
    void signalpressEscape();

private slots:
    void on_pushButton_clicked();

};

#endif // ARTIKLIVNES_H
