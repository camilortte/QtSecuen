#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QString>
#define MAX_FILAS 100
#define MAX_COLUMNAS 100
#include <vector>

using namespace std;

class Puntaje
{
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
public:
    Puntaje();
    Puntaje(QString entrada1,QString entrada2);
    QString getMatrizResultante();
    QString getResultado1();
    QString getResultado2();




};

#endif // PUNTAJE_H

