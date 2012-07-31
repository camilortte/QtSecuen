#include "src/Headers/puntaje.h"
#include <QDebug>
#include <QVector2D>
#include <stdarg.h>
#include "src/Headers/convercion.h"
#include <QMessageBox>
#include <QDebug>

Puntaje::Puntaje(){
    matrizBase[1][1]=10;
    matrizBase[1][2]=-1;
    matrizBase[1][3]=-3;
    matrizBase[1][4]=-4;

    matrizBase[2][1]=-1;
    matrizBase[2][2]=7;
    matrizBase[2][3]=-5;
    matrizBase[2][4]=-3;

    matrizBase[3][1]=-3;
    matrizBase[3][2]=-5;
    matrizBase[3][3]=9;
    matrizBase[3][4]=0;

    matrizBase[4][1]= -4;
    matrizBase[4][2]= -3;
    matrizBase[4][3]= 0;
    matrizBase[4][4]= 8;
    int tope=5;
    int tope2=8;
    array2D.resize(tope);
    for (int i = 0; i < tope; ++i)
        array2D[i].resize(tope2);

}

Puntaje::Puntaje(QString entrada1, QString entrada2)
{
    this->vecta=comprobarEntrada (entrada1);
    this->vectb=comprobarEntrada (entrada2);
    inicializar();
}


//si es falso se tendrqa que llamar el metodo para porder iniciar el algoritmo
Puntaje::Puntaje(QString entrada1, QString entrada2, bool iniciarAutomaticamente)
{
    this->vecta=comprobarEntrada (entrada1);
    this->vectb=comprobarEntrada (entrada2);
    if(iniciarAutomaticamente==true)
        inicializar();
}

Puntaje::Puntaje(QFile *archivo, bool iniciaarAutomaticamente)
{
    QString nombreSecuencia1,nombreSecuencia2;
    this->archivo=archivo;
    if (!archivo->open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(NULL,"Error al abrir el archivo","Error de lectura , no se puede abrir el archivo");
    }else{
        QTextStream stream(archivo);
        QString linea;
        short contador=1;
        while(!stream.atEnd()){
            linea = stream.readLine();
            if(linea[0]=='>'){
                if(contador==1){
                    nombreSecuencia1=linea.mid(1, linea.length());
                }else{
                    nombreSecuencia2=linea.mid(1, linea.length());
                }

                linea=stream.readLine();
                if(linea[0]!='#'){
                    if(contador==1){
                        //secuencia1=linea;
                        this->vecta=comprobarEntrada (linea);
                        contador++;
                    }else if(contador==2){
                        //secuencia2=linea;
                        this->vectb=comprobarEntrada (linea);
                        contador++;
                    }
                }
                if(contador>=2){
                    ////-----------Aca se modificara para un futuro leer mas de dos secuencias
                }
            }else{
                linea=stream.readLine();
            }

        }
        if(iniciaarAutomaticamente==true){
            inicializar();
        }
    }
}

Puntaje::~Puntaje()
{
//    if(archivo!=NULL)
//        delete archivo;
//
}




void Puntaje::inicializar()
{
    Maximo=0;
    matrizBase[1][1]=10;
    matrizBase[1][2]=-1;
    matrizBase[1][3]=-3;
    matrizBase[1][4]=-4;

    matrizBase[2][1]=-1;
    matrizBase[2][2]=7;
    matrizBase[2][3]=-5;
    matrizBase[2][4]=-3;

    matrizBase[3][1]=-3;
    matrizBase[3][2]=-5;
    matrizBase[3][3]=9;
    matrizBase[3][4]=0;

    matrizBase[4][1]= -4;
    matrizBase[4][2]= -3;
    matrizBase[4][3]= 0;
    matrizBase[4][4]= 8;

    resultado1="";
    resultado2="";

    //creacion de la matriz
    array2D.resize(vecta.size ());
    for (int i = 0; i < vecta.size (); i++)
        array2D[i].resize(vectb.size ());

    //rellenando la matriz con los -5
    array2D[0][0]=0;
    for(int i=1;i<array2D[0].size();i++){
        array2D[0][i]=i*-5;
    }
    for(int i=1;i<array2D.size ();i++){
        array2D[i][0]=i*-5;
    }
    generarPuntage ();
    backTracking ();
}


void Puntaje::iniciarTodo()
{
    inicializar();
}


QString Puntaje::getMatrizResultante()
{
    QString auxiliar1="",auxiliar2="";
    int mayor=0;
    int tipo,temporal = 0;
    int estado=0;
    this->maximoMatriz=vecta.size ()*vectb.size()*2;

    mayor=array2D[0][0];
    for(int i=0;i<vecta.size ();i++){
        for(int j=0;j<vectb.size ();j++){
            if(array2D[i][j]>mayor){
                mayor=array2D[i][j];
            }
            estado++;
            emit estadoGenerarMatriz(estado,maximoMatriz);
        }
        estado++;
        emit estadoGenerarMatriz(estado,maximoMatriz);
    }
    auxiliar1+=mayor;
    tipo=auxiliar1.length()+3;
    auxiliar1="";
    for(int i=0;i<vecta.size ();i++){
        for(int j=0;j<vectb.size ();j++){            
            auxiliar1=Convercion::qint32ToQString (array2D[i][j]);
            temporal=tipo-auxiliar1.length();
            for(int j1=0;j1<temporal;j1++){
                auxiliar1+=" ";
            }
            estado++;
//            emit estadoGenerarMatriz(estado,maximoMatriz);
            auxiliar2+=auxiliar1+" ";
        }
        auxiliar2+="\n";
        estado++;
        emit estadoGenerarMatriz(estado,maximoMatriz);
    }
    return auxiliar2;


}

QString Puntaje::getResultado1()
{
    return resultado1;
}

QString Puntaje::getResultado2()
{
    return resultado2;
}


vector <qint32> Puntaje::comprobarEntrada(QString resultado)
{
    QString auxiliar="_";
    for(int i=0;i<resultado.size ();i++){
        if(resultado[i]=='A'){
            auxiliar+="1";
            //aux.assign (1);
        }else if(resultado[i]=='G'){
             auxiliar+="2";
          // aux.assign (2);
        }else if(resultado[i]=='C'){
             auxiliar+="3";
          // aux.assign (3);
        }else if(resultado[i]=='T'){
             auxiliar+="4";
          // aux.assign (4);
        }
    }
    vector <qint32> salida;
    salida.resize (auxiliar.length ());
    for(int i=1;i<auxiliar.length ();i++){
        salida[i]=Convercion::QStringToInt32 ((QString)auxiliar[i]);
    }
    return salida;
}

void Puntaje::generarPuntage()
{
    Maximo=vecta.size();
    int mayor=0;
    int estado=1;
    //generamos la matriz del alineamiento
    for(int i=1;i<vecta.size ();i++){
        estado++;//Control de finalizacion
    //    this->barraProgreso->setValue(estado);
        emit estadoAlineacionPuntaje(estado,Maximo);
        for(int j=1;j<vectb.size ();j++){
            mayor=comprobarMatriz (vecta[i], vectb[j])+array2D[i-1][j-1];
            if(array2D[i][j-1]-5>mayor)
                mayor=array2D[i][j-1]-5;
            if(array2D[i-1][j]-5>mayor)
                mayor=array2D[i-1][j]-5;
            array2D[i][j]=mayor;
        }
    }
}

int Puntaje::comprobarMatriz(int a, int b)
{
       return matrizBase[a][b];
}

void Puntaje::backTracking()
{
    int puntoFila=vecta.size ()-1;
    int puntoColu=vectb.size ()-1;
    int i=vecta.size ()-1;
    int j=vectb.size ()-1;
    bool diagonal=false;
    bool izquierda=false;
    bool arriba=false;
    int mayor=0;
    int contadorVectora=vecta.size ()-1;
    int contadorVectorb=vectb.size ()-1;

    while(i>0 || j>0){
        diagonal=false;
        izquierda=false;
        arriba=false;

        if(j>0 && i>0){
            mayor=comprobarMatriz (vecta[puntoFila],vectb[puntoColu])+array2D[i-1][j-1];
            diagonal=true;
        }
        if(j>0 ){
            if(array2D[i][j-1]-5>mayor){
                diagonal=false;
                izquierda=true;
                arriba=false;
                mayor=array2D[i][j-1]-5;
            }
        }
        if(i>0){
            if(array2D[i-1][j]-5>mayor){
                diagonal=false;
                izquierda=false;
                arriba=true;
                mayor=array2D[i-1][j]-5;
            }
        }
        if(i==0){
            diagonal=false;
            izquierda=true;
            arriba=false;
        }

        if(j==0){
            diagonal=false;
            izquierda=false;
            arriba=true;
        }
        if(diagonal==true){
            j=j-1;
            i=i-1;
            resultado1+=Convercion::qint32ToQString (vecta[contadorVectora]);
            resultado2+=Convercion::qint32ToQString (vectb[contadorVectorb]);
            contadorVectora--;
            contadorVectorb--;

        }else if(izquierda==true){
            j=j-1;
            resultado1+="_";//vecta[contadorVectora];
            resultado2+=Convercion::qint32ToQString (vectb[contadorVectorb]);
            //contadorVectora--;
            contadorVectorb--;
        }else if(arriba==true){
            i=i-1;
            resultado1+=Convercion::qint32ToQString (vecta[contadorVectora]);
            resultado2+="_";
            contadorVectora--;
        }
        puntoFila=i;
        puntoColu=j;
    }
    organizarAlineamiento ();
}

void Puntaje::organizarAlineamiento()
{
    QString auxiliar="";
    for(int s=resultado1.length()-1;s>=0;s--){
        if(resultado1[s]=='1'){
            auxiliar+=" A ";
        }else if(resultado1[s]=='2'){
            auxiliar+=" G ";
        }else if(resultado1[s]=='3'){
            auxiliar+=" C ";
        }else if(resultado1[s]=='4'){
            auxiliar+=" T ";
        }else if(resultado1[s]=='_'){
            auxiliar+=" _ ";
        }
    }
    resultado1=auxiliar;
    auxiliar="";
    for(int i=resultado2.length()-1;i>=0;i--){
        if(resultado2[i]=='1'){
            auxiliar+=" A ";
        }else if(resultado2[i]=='2'){
            auxiliar+=" G ";
        }else if(resultado2[i]=='3'){
            auxiliar+=" C ";
        }else if(resultado2[i]=='4'){
            auxiliar+=" T ";
        }else if(resultado2[i]=='_'){
            auxiliar+=" _ ";
        }
    }
    resultado2=auxiliar;
}



