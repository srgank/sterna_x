#ifndef ARTIKLIKOREKCIJA_H
#define ARTIKLIKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class ArtikliKorekcija;
}


class ArtikliKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit ArtikliKorekcija(BaseForm *parent = 0);
    ~ArtikliKorekcija();
    virtual void pressEscape();
    virtual void updateFont();
    virtual void pressReturn();
    virtual void pressEnter();
    virtual void Refresh();

    void initProc(QString m_searchID);

private:
    void on_SifraArtikalEdit_EditingFinished();
    Ui::ArtikliKorekcija *ui;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
    QString str_yellow;
    QString str_none;
    artikalT art_temp;
    QString artikal_id;
protected:
    bool eventFilter(QObject *object, QEvent *event);
signals:
    void signalpressEscape();
    void signalPrePressEscape();
private slots:
    void on_pushButton_released();
};

#endif // ARTIKLIKOREKCIJA_H
