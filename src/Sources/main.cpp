#include <QtGui/QApplication>
#include "src/Headers/puntaje.h"
#include "src/Headers/ventanaprincipal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Puntaje as("CGTCTT","ACCGTCTT");
    //as.getMatrizResultante ();
    VentanaPrincipal ventana;
    ventana.setVisible (true);

    /*VentanaMatriz as("coso");
    as.show ();*/

    
    return a.exec();
}
