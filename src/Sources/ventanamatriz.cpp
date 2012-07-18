#include "src/Headers/ventanamatriz.h"
#include "ui_ventanamatriz.h"
#include <QDebug>

VentanaMatriz::VentanaMatriz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaMatriz)
{
    ui->setupUi(this);
}

VentanaMatriz::~VentanaMatriz()
{
    delete ui;
}

VentanaMatriz::VentanaMatriz(QString matriz,QWidget *parent ) : QWidget(parent),ui(new Ui::VentanaMatriz)
{
    ui->setupUi(this);
    ui->salida_textBrowser->setText (matriz);
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
