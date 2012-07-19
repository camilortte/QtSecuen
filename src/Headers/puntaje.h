#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QString>
#define MAX_FILAS 100
#define MAX_COLUMNAS 100
#include <vector>
#include <QProgressBar>
#include <QFile>

using namespace std;

class Puntaje:public QObject
{
    Q_OBJECT
private:
    vector < vector < int > > array2D;//Arreglo PRINCIPAL generado
    QString resultado1,resultado2;
    vector <qint32>  vecta,vectb;//arreglos
    int matrizBase[5][5];
    int A,G,C,T;
    void organizarAlineamiento();
    void generarPuntage();
    int comprobarMatriz(int a, int b);
    void backTracking();
    vector<qint32> comprobarEntrada(QString resultado);
    void inicializar();
public:
    Puntaje();
    Puntaje(QString entrada1,QString entrada2);
    Puntaje(QString entrada1,QString entrada2,bool iniciarAutomaticamente);
    Puntaje(QFile *archivo,bool iniciaarAutomaticamente);
    QString getMatrizResultante();
    QString getResultado1();
    QString getResultado2();
    QFile *archivo;
    //seguimiento de finalziacion
    int Maximo;
    void iniciarTodo();

signals:
    void estadoAlineacionPuntaje(int,int);

};

#endif // PUNTAJE_H

