#include <QtGui/QApplication>
#include "src/Headers/puntaje.h"
#include "src/Headers/ventanaprincipal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaPrincipal ventana;
    ventana.setVisible (true);

    
    return a.exec();
}
