#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dllpincode.h"
#include "dllserialport.h"
#include "dllrestapi.h"

#include "paakayttoliittyma.h"
#include "creditordebit.h"
#include "nostarahaa.h"
#include "talletarahaa.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

public slots:
    void kortinNumeroSlot(QString);
    void pinkoodiSlot(QString);
    void loginSlot(QString);
    void asiakasTiedotSlot(QStringList);
    void tilitapahtumatSlot(QStringList);
    void tiliValittuSlot(QString);
    void nostaRahaaValittuSlot();
    void nostaRahaaSlot(QString);
    void talletaRahaaValittuSlot();
    void talletaRahaaSlot(QString);
    void tilitapahtumaValintaSlot(QString);
    void singleShotTilitapahtumaSlot();
    void kirjauduUlosSlot();
    void PaaTimerSlot();

private:
    Ui::MainWindow *ui;

    DLLPinCode *objectDLLPinCode;
    DLLSerialPort *objectDLLSerialPort;
    DLLRESTAPI *objectDLLRESTAPI;

    paakayttoliittyma *objectpaakayttoliittyma;
    creditOrDebit *objectCreditOrDebit;
    NostaRahaa *objectNostaRahaa;
    TalletaRahaa *objectTalletaRahaa;

    QString kortinnumero;
    QString id_Tili;
    QString id_Asiakas;
    QString nimi;
    QString debitTilinumero;
    QString creditTilinumero;
    QString debitSaldo;
    QString creditSaldo;
    QString valinta;
    QString luottoraja;
    QStringList tilitapahtumat;

    int kiinteaHakuMaara = 0;
    int tapahtumatListaPituus = 0;

    bool paikallinenBoolean = true;


};
#endif // MAINWINDOW_H
