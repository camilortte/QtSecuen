#ifndef VENTANAMATRIZ_H
#define VENTANAMATRIZ_H

#include <QMainWindow>
#include "src/Headers/puntaje.h"
#include "src/Headers/getmatrizthread.h"
#include <QProgressBar>

namespace Ui {
class VentanaMatriz;
}

class VentanaMatriz : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VentanaMatriz(QWidget *parent = 0);
    VentanaMatriz(QString matriz,QWidget *parent = 0);
    VentanaMatriz(Puntaje *puntaje, QWidget *parent=0);
    ~VentanaMatriz();

protected:
     void changeEvent(QEvent *e);
    
private slots:
     void on_actionGuardar_matriz_triggered();

     void on_actionCopiar_triggered();

     void on_actionCortar_triggered();

     void on_actionPegar_triggered();

     void on_actionSeleccionar_Todo_triggered();

     void on_pushButton_cerrarMatriz_clicked();

     void slot_estadGetMatriz(int,int);

     void slot_threadFinish();

     void on_actionSalir_triggered();

private:
    Ui::VentanaMatriz *ui;
    QString matriz;
    Puntaje *puntaje;
    getMatrizThread *getMatrizThread1;
    QProgressBar *barraProgreso;

};

#endif // VENTANAMATRIZ_H


