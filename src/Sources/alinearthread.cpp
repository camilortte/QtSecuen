#include "src/Headers/alinearthread.h"
#include <QDebug>



AlinearThread::AlinearThread()
{
}

AlinearThread::AlinearThread(QString secuencias[])
{
    this->secuencias[0]=secuencias[0];//Esto me toca mejorarlos
    this->secuencias[1]=secuencias[1];
    puntaje=NULL;
    archivo=NULL;
}

AlinearThread::AlinearThread(QFile *archivo)
{
    this->archivo=archivo;
}

void AlinearThread::run()
{
    QString resultado1="<p> ";
    QString resultado2="<p>";

    if(this->archivo==NULL){
        puntaje=new Puntaje(secuencias[0],secuencias[1],false);
    }else{
        puntaje=new Puntaje(archivo,false);
    }

    connect(puntaje,SIGNAL(estadoAlineacionPuntaje(int,int)),this,SLOT(slot_estadoAlineacionThread(int,int)));
    puntaje->iniciarTodo();

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

    resultados[0]=resultado1;
    resultados[1]=resultado1;

}

Puntaje *AlinearThread::getPuntaje()
{
    return this->puntaje;
}

QString *AlinearThread::getResultados()
{
    return this->resultados;
}


void AlinearThread::slot_estadoAlineacionThread(int numero, int Maximo)
{
    emit estadoAlineacionThread(numero,Maximo);
}

