#include "src/Headers/ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QRect>
#include <QDesktopWidget>
#include <QProcess>
#include <QMessageBox>
#include "src/Headers/exportararchivo.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    //para que la ventana este en la mitad de la pantalla
    QRect qRect(QApplication::desktop()->screenGeometry());
    int iXpos=qRect.width()/2-this->width()/2;
    int iYpos=qRect.height()/2-this->height()/2;
    this->move(iXpos,iYpos);

    //inicializacion de componentes
    puntaje=NULL;
    ventana=NULL;
    alinearThread=NULL;
    barraProgreso=new QProgressBar();
    barraProgreso->setMinimum(1);
    barraProgreso->setMaximum(100);
    conector=new QObject();
    ui->statusbar->addWidget(barraProgreso);


    //esto toca Borrarlo
    //QFile *archivo=new QFile("/home/c4m170rtt3/Desktop/Secuencias_20para_20alineamiento.FASTA");
    //Puntaje *p=new Puntaje(archivo,true);

}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void VentanaPrincipal::on_alinear_pushButton_clicked()
{    
    bool banderaPass=true;
    if(puntaje!=NULL)
        delete puntaje;
    if(alinearThread!=NULL)
        delete alinearThread;

    ui->alinear_pushButton->setEnabled(false);

    if(ui->tabInicio->currentWidget()==ui->tab){
        barraProgreso->setValue(1);
       // ui->statusbar->showMessage("Ejecutando alineacion... ");
        QString secuencias[2];
        secuencias[0]=ui->comboBox_secuencia1->currentText();
        secuencias[1]=ui->comboBox_secuencia2->currentText();
        alinearThread=new AlinearThread(secuencias);
    }else{
        QFile *archivo=new QFile(ui->lineEdit_examinar->text());
        if(archivo->exists()){
            alinearThread=new AlinearThread(archivo);
        }else{
            QMessageBox::critical(this,"Error al leer el archivo","No se pudo leer el archivo ,comprueba su existencia o el formato.");
            banderaPass=false;
            puntaje=NULL;
            alinearThread=NULL;
            ui->alinear_pushButton->setEnabled(true);
        }
    }
    if(banderaPass!=false){
        conector->connect(alinearThread,SIGNAL(estadoAlineacionThread(int,int)),this,SLOT(estaodAlineacionVentana(int,int)));
        conector->connect(alinearThread,SIGNAL(finished()),this,SLOT(hilo()));
        alinearThread->start();
    }
}

void VentanaPrincipal::on_limpiar_pushButton_clicked()
{
    if(puntaje==NULL){
        ui->salida_textBrowser->setText ("");
    }else{
        delete puntaje;
        ui->salida_textBrowser->setText ("");
        puntaje=NULL;
    }

    if(ventana!=NULL){
        delete ventana;
        ventana=NULL;
    }
}

void VentanaPrincipal::on_verMatriz_pushButton_2_clicked()
{
    if(puntaje==NULL){
        QMessageBox::critical(this,"No se ha generado ninguna secuencia","No se ha generado ninguna secuencia");
    }else{
        if(ventana==NULL){
            QString auxiliar=puntaje->getMatrizResultante ();
            ventana=new VentanaMatriz(auxiliar);
            ventana->show ();
        }else{
            delete ventana;
            QString auxiliar=puntaje->getMatrizResultante ();
            ventana=new VentanaMatriz(auxiliar);
            ventana->show ();
        }
    }
}



void VentanaPrincipal::on_actionSalir_triggered()
{

    this->close();
    if(ventana!=NULL){
        delete this->ventana;
        ventana=NULL;
    }
}

void VentanaPrincipal::on_actionAcerca_de_Qt_triggered()
{
    QMessageBox::aboutQt (this,"Acerca de Qt");
}

void VentanaPrincipal::on_actionAcerca_de_estePrograma_triggered()
{
    QMessageBox::about (this,"Creacion C4M170RTT3","Este programa ha sido diseñado y creado por \n"
                        "Camilo Antonio Ramirez Morales estudiante de \n"
                              "la Universidad distrital Francisco Jose de caldas\n"
                               "Para mayor informacion camilortte@hotmail.com");
}

void VentanaPrincipal::on_actionCopiar_triggered()
{
    if(puntaje==NULL){
        QMessageBox::warning(this,"No hay consulta","No se han realizado consultas");
    }else{
        ui->salida_textBrowser->selectAll ();
        ui->salida_textBrowser->moveCursor (QTextCursor::End);
        ui->salida_textBrowser->moveCursor (QTextCursor::Left);
        ui->salida_textBrowser->copy ();
    }
}

void VentanaPrincipal::on_actionGuardar_triggered()
{
     if(puntaje!=NULL){
        QString nombreArchivo=QFileDialog::getSaveFileName(this,
                                                           tr("Guardar resultados Alineacion"), "ResultadoAlineacion",
                                                           tr("Archivo de texto (*.txt);;All Files (*)"));
        if( !nombreArchivo.isNull() )
        {
            ExportarArchivo exportar;
            exportar.almacentarTextoPlano(ui->salida_textBrowser->toPlainText(),nombreArchivo);
        }
    }else{
        QMessageBox::warning(this,"No hay consulta","No se han realizado consultas, no se almacenará NADA");
    }

}

void VentanaPrincipal::on_actionAbrir_triggered()
{
    QMessageBox::information (this,"Funcion no implementada","Esta solicitud no ha sido implementada "
                              ",por favor comunicarse con camilortte@hotmail.com "
                              "para obtener mas informacion");
}

void VentanaPrincipal::on_pushButton_examinar_clicked()
{
    QString nombreArchivo=QFileDialog::getOpenFileName(this,"Abrir Secuencia",NULL,"Secuencia FASTA *.FASTA (*.FASTA)");
    if( !nombreArchivo.isNull() )
    {
       ui->lineEdit_examinar->setText(nombreArchivo);
    }
}



void VentanaPrincipal::hilo()
{
    this->puntaje=alinearThread->getPuntaje();
    ui->salida_textBrowser->append(alinearThread->getResultados()[0]);
    ui->salida_textBrowser->append (alinearThread->getResultados()[1]);
    ui->alinear_pushButton->setEnabled(true);
}



void VentanaPrincipal::estaodAlineacionVentana(int numero, int Maximo)
{
    barraProgreso->setMaximum(Maximo);
    barraProgreso->setValue(numero);
}

void VentanaPrincipal::on_actionHtml_triggered()
{
    if(puntaje!=NULL){
        QString nombreArchivo=QFileDialog::getSaveFileName(this,
                                                           tr("Exportar a HTML"), "AlineamientoDeSecuencias",
                                                           tr("HTML(*.HTML)"));
        if( !nombreArchivo.isNull() )
        {
            ExportarArchivo exportar;
            exportar.exportarHtml(alinearThread->getResultados()[0], alinearThread->getResultados()[1],nombreArchivo);
        }
    }else{
        QMessageBox::warning(this,"No hay consulta","No se han realizado consultas, no se almacenará NADA");
    }
}

void VentanaPrincipal::on_actionArchivo_FASTA_triggered()
{
    if(puntaje!=NULL){
        QString nombreArchivo=QFileDialog::getSaveFileName(this,
                                                           tr("Exportar a FASTA"), "AlineamientoDeSecuencias",
                                                           tr("FASTA(*.FASTA)"));
        if( !nombreArchivo.isNull() )
        {
            ExportarArchivo exportar;
            exportar.exportarFasta(puntaje->getResultado1(), puntaje->getResultado2(),nombreArchivo);
        }
    }else{
        QMessageBox::warning(this,"No hay consulta","No se han realizado consultas, no se almacenará NADA");
    }
}
