#include "src/Headers/getmatrizthread.h"

getMatrizThread::getMatrizThread(QObject *parent) :
    QThread(parent)
{
}

getMatrizThread::getMatrizThread(Puntaje *puntaje)
{
    this->puntaje=puntaje;
    connect(puntaje,SIGNAL(estadoGenerarMatriz(int,int)),this,SLOT(slot_estadoGetMatriz(int,int)));
}

getMatrizThread::~getMatrizThread()
{
    if(puntaje!=NULL)
        delete puntaje;
}

void getMatrizThread::run()
{
    matriz=this->puntaje->getMatrizResultante();
}

QString getMatrizThread::getMatriz()
{
    return this->matriz;
}


void getMatrizThread::slot_estadoGetMatriz(int numero, int maximo)
{
    emit estadoGetMatriz(numero,maximo);
}
