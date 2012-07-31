#include "src/Headers/ventanamatriz.h"
#include "ui_ventanamatriz.h"
#include <QMessageBox>
#include "src/Headers/exportararchivo.h"
#include <QFileDialog>
#include "src/Headers/getmatrizthread.h"
#include <QDebug>

VentanaMatriz::VentanaMatriz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaMatriz)
{
    ui->setupUi(this);
}


VentanaMatriz::~VentanaMatriz()
{
    delete ui;
//    if(puntaje!=NULL)
//        delete puntaje;
//    if(getMatrizThread1!=NULL)
//        delete getMatrizThread1;
//    if(barraProgreso!=NULL)
//        delete barraProgreso;
}


VentanaMatriz::VentanaMatriz(QString matriz,QWidget *parent ) : QMainWindow(parent),ui(new Ui::VentanaMatriz)
{
    ui->setupUi(this);
    this->matriz=matriz;
    ui->salida_textBrowser->setText (matriz);
}

VentanaMatriz::VentanaMatriz(Puntaje *puntaje,QWidget *parent ) : QMainWindow(parent),ui(new Ui::VentanaMatriz)
{
    ui->setupUi(this);
    barraProgreso=new QProgressBar();
    barraProgreso->setMinimum(1);
    barraProgreso->setValue(1);
    ui->statusbar->showMessage("Generando Matriz...");
    ui->statusbar->addPermanentWidget(barraProgreso,0);
    this->puntaje=puntaje;
    getMatrizThread1=new getMatrizThread(puntaje);
    QObject::connect(getMatrizThread1,SIGNAL(estadoGetMatriz(int,int)),this,SLOT(slot_estadGetMatriz(int,int)));
    QObject::connect(getMatrizThread1,SIGNAL(finished()),this,SLOT(slot_threadFinish()));
    getMatrizThread1->start();
}

void VentanaMatriz::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void VentanaMatriz::on_actionGuardar_matriz_triggered()
{
    QString nombreArchivo=QFileDialog::getSaveFileName(this,
                                                       tr("Guardar Matriz Alineacion"), "miMatriz",
                                                       tr("Archivo de texto (*.txt);;All Files (*)"));
    if( !nombreArchivo.isNull() )
    {
        ExportarArchivo exportar;
        exportar.almacentarTextoPlano(matriz,nombreArchivo);
    }
}

void VentanaMatriz::on_actionCopiar_triggered()
{
    ui->salida_textBrowser->selectAll ();
    ui->salida_textBrowser->moveCursor (QTextCursor::End);
    ui->salida_textBrowser->moveCursor (QTextCursor::Left);
    ui->salida_textBrowser->copy ();
}

void VentanaMatriz::on_actionCortar_triggered()
{
    ui->salida_textBrowser->cut();
}



void VentanaMatriz::on_actionPegar_triggered()
{
    ui->salida_textBrowser->selectAll ();
    ui->salida_textBrowser->moveCursor (QTextCursor::End);
    ui->salida_textBrowser->moveCursor (QTextCursor::Left);
    ui->salida_textBrowser->paste();
}

void VentanaMatriz::on_actionSeleccionar_Todo_triggered()
{
    ui->salida_textBrowser->selectAll ();
}

void VentanaMatriz::on_pushButton_cerrarMatriz_clicked()
{
    this->close();
}

void VentanaMatriz::slot_estadGetMatriz(int numero, int maximo)
{
    //aca modificamos la barra de progreso
    this->barraProgreso->setMaximum(maximo);
    this->barraProgreso->setValue(numero);
}

void VentanaMatriz::slot_threadFinish()
{
    matriz=getMatrizThread1->getMatriz();
    ui->salida_textBrowser->setText(matriz);
    ui->statusbar->showMessage("Generado",3000);
    this->barraProgreso->setVisible(false);
}

void VentanaMatriz::on_actionSalir_triggered()
{
    this->close();
}
