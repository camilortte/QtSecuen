#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QtGui/QMainWindow>
#include "puntaje.h"
#include "ventanamatriz.h"
#include <QProgressBar>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();
    
protected:
    void changeEvent(QEvent *e);
    
private slots:
    void on_alinear_pushButton_clicked();

    void on_limpiar_pushButton_clicked();

    void on_verMatriz_pushButton_2_clicked();


    void on_actionSalir_triggered();

    void on_actionAcerca_de_Qt_triggered();

    void on_actionAcerca_de_estePrograma_triggered();

    void on_actionCopiar_triggered();

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();

    void on_pushButton_examinar_clicked();

private:
    Ui::VentanaPrincipal *ui;
    Puntaje *puntaje;
    VentanaMatriz *ventana;
    QProgressBar *barraProgreso;
};

#endif // VENTANAPRINCIPAL_H
