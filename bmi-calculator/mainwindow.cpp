#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double calcul=0.0;
    int poids=0;
    double taille=0.0;
    int calcul_entier=0;


    poids = ui->spinBoxPoids->value();
    taille = ui->doubleSpinBoxTaille->value();
    calcul = poids/(taille*taille);
    calcul_entier= (int)calcul;
    ui->progressBar->setValue(calcul_entier);
    //ui->labelResultat->setText(QString::number(calcul_entier));



    if (calcul_entier<16)
        ui->labelResultat->setText("Famine");
    else if (calcul_entier>16 && calcul_entier<19)
        ui->labelResultat->setText("Sous-poids");
    else if (calcul_entier>19 && calcul_entier<25)
        ui->labelResultat->setText("Corpulence normale");
    else if (calcul_entier>25 && calcul_entier<30)
        ui->labelResultat->setText("Surpoids");
    else if (calcul_entier>30 && calcul_entier<35)
        ui->labelResultat->setText("Obésité modérée");
    else if (calcul_entier>35 && calcul_entier<40)
        ui->labelResultat->setText("Obésité sévère");
    else
        ui->labelResultat->setText("Obésité morbide ou massive");
}
