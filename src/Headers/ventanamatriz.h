#ifndef VENTANAMATRIZ_H
#define VENTANAMATRIZ_H

#include <QtGui/QWidget>

namespace Ui {
class VentanaMatriz;
}

class VentanaMatriz : public QWidget
{
    Q_OBJECT
    
public:
    explicit VentanaMatriz(QWidget *parent = 0);
    ~VentanaMatriz();
   VentanaMatriz(QString matriz,QWidget *parent = 0);
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::VentanaMatriz *ui;
};

#endif // VENTANAMATRIZ_H
