#ifndef ALINEARTHREAD_H
#define ALINEARTHREAD_H

#include <QThread>
#include <QProgressBar>
#include "src/Headers/puntaje.h"

class AlinearThread : public QThread
{
    Q_OBJECT
public:
    AlinearThread();
    AlinearThread(QString secuencias[],QProgressBar *barraProgreso);
    void run();
    Puntaje* getPuntaje();
    QString* getResultados();
signals:
    void estadoAlineacionThread(int,int);
private slots:
    void slot_estadoAlineacionThread(int,int);
private:
    QProgressBar *barraProgreso;
    Puntaje *puntaje;
    QString resultados[2];
    QString secuencias[2];//esta sera de dos
};

#endif // ALINEARTHREAD_H
