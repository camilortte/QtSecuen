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
    //para secuencias ingresadas manualmente
    AlinearThread(QString secuencias[]);
    //para cuando las cargamos desde un archivo
    AlinearThread(QFile *archivo);
    ~AlinearThread();
    void run();
    Puntaje* getPuntaje();
    QString* getResultados();
signals:
    void estadoAlineacionThread(int,int);
private slots:
    void slot_estadoAlineacionThread(int,int);
private:
    Puntaje *puntaje;
    QFile *archivo;
    QString resultados[2];
    QString secuencias[2];//esta sera de dos
};

#endif // ALINEARTHREAD_H
