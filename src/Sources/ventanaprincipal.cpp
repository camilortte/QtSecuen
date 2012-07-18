#include "src/Headers/ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    puntaje=NULL;
    ventana=NULL;
    barraProgreso=new QProgressBar();
    barraProgreso->setMinimum(1);
    barraProgreso->setMaximum(100);
    statusBar()->addWidget(barraProgreso,1);
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
    /*QString a=ui->secuencia1_lineEdit->text ();
    QString b=ui->secuencia2_lineEdit_2->text ();
    if(puntaje==NULL){
        puntaje=new Puntaje(a,b);
        ui->salida_textBrowser->append ("Aneacion=\n"+puntaje->getResultado1 ()+"\n");
        ui->salida_textBrowser->append (puntaje->getResultado2 ());
    }else{
        delete puntaje;
        puntaje=new Puntaje(a,b);
        ui->salida_textBrowser->append ("Aneacion=\n"+puntaje->getResultado1 ()+"\n");
        ui->salida_textBrowser->append (puntaje->getResultado2 ());
    }/
    https://www.google.com.co/search?q=status+bar+qt&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a
*/

    ui->statusbar->showMessage("Alineamndo epsere",5000);
    QString resultado1="<p> ";
    QString resultado2="<p>";
    ui->comboBox_secuencia1->currentText();
    QString a=ui->comboBox_secuencia1->currentText();
    QString b=ui->comboBox_secuencia2->currentText();
    if(puntaje==NULL){
        puntaje=new Puntaje(a,b);
        QString auxiliar=puntaje->getResultado1 ();
        QString auxiliar2=puntaje->getResultado2 ();

        for(int i=0;i<puntaje->getResultado1 ().length ();i++){
            if(auxiliar[i]=='_' || auxiliar2[i]=='_'){
                resultado1+="<FONT COLOR=red>"+auxiliar[i]+" </FONT>";
                resultado2+="<FONT COLOR=red>"+auxiliar2[i]+" </FONT>";
            }else{
                resultado1+="<FONT COLOR=green>"+auxiliar[i]+" </FONT>";
                resultado2+="<FONT COLOR=green>"+auxiliar2[i]+" </FONT>";
            }
        }
        resultado1+="</p>";
        resultado2+="</p>";

        ui->salida_textBrowser->append ("Aneacion=");
        ui->salida_textBrowser->append(resultado1);
        ui->salida_textBrowser->append (resultado2);
        ui->salida_textBrowser->append ("\n");
    }else{
        delete puntaje;
        puntaje=new Puntaje(a,b);
        QString auxiliar=puntaje->getResultado1 ();
        QString auxiliar2=puntaje->getResultado2 ();

        for(int i=0;i<puntaje->getResultado1 ().length ();i++){
            if(auxiliar[i]=='_' || auxiliar2[i]=='_'){
                resultado1+="<FONT COLOR=red>"+auxiliar[i]+" </FONT>";
                resultado2+="<FONT COLOR=red>"+auxiliar2[i]+" </FONT>";
            }else{
                resultado1+="<FONT COLOR=green>"+auxiliar[i]+" </FONT>";
                resultado2+="<FONT COLOR=green>"+auxiliar2[i]+" </FONT>";
            }
        }
        resultado1+="</p>";
        resultado2+="</p>";

        ui->salida_textBrowser->append ("Aneacion=");
        ui->salida_textBrowser->append(resultado1);
        ui->salida_textBrowser->append (resultado2);
        ui->salida_textBrowser->append ("\n");
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
        ui->salida_textBrowser->copy ();
        ui->salida_textBrowser->moveCursor (QTextCursor::End);
        ui->salida_textBrowser->moveCursor (QTextCursor::Left);
    }
}

void VentanaPrincipal::on_actionGuardar_triggered()
{
    QString nombreArchivo=QFileDialog::getSaveFileName(this,
                                                       tr("Save Address Book"), "",
                                                       tr("Archivo de texto (*.txt);;All Files (*)"));
    if( !nombreArchivo.isNull() )
    {
        if(puntaje!=NULL){
            QFile archivo(nombreArchivo);
            archivo.open (QIODevice::WriteOnly);
            QTextStream out(&archivo);
            out << ui->salida_textBrowser->toPlainText ()<< "\n";
            archivo.close ();
        }else{
            QMessageBox::warning(this,"No hay consulta","No se han realizado consultas, no se almacenará NADA");
        }
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
        /* if(puntaje!=NULL){
            QFile archivo(nombreArchivo);
            archivo.open (QIODevice::WriteOnly);
            QTextStream out(&archivo);
            out << ui->salida_textBrowser->toPlainText ()<< "\n";
            archivo.close ();
        }else{
            QMessageBox::warning(this,"No hay consulta","No se han realizado consultas, no se almacenará NADA");
        }*/
        qDebug()<<"jeje";
    }
}
