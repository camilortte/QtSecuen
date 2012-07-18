#include "src/Headers/convercion.h"

Convercion::Convercion()
{
}

QString Convercion::intToQString(int a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

QString Convercion::qint8ToQString(qint8 a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

QString Convercion::qint16ToQString(qint16 a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

QString Convercion::qint32ToQString(qint32 a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

QString Convercion::qint64ToQString(qint64 a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

QString Convercion::floatToQString(float a){
    QString numero="";
    numero=numero.setNum(a);
    return numero;
}

QString Convercion::doubleToQstring(double a){
    QString numero="";
    numero=numero.setNum(a);
    return numero;
}

QString Convercion::qrealToQString(qreal a){
    QString numero="";
    numero=numero.setNum(a);
    return numero;
}

QString Convercion::longToQString(long a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

QString Convercion::qlonglongToQString(qlonglong a){
    QString numero="";
    numero=numero.setNum(a,10);
    return numero;
}

int Convercion::QStringToInt(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        int b=auxiliar.toInt();
        return b;
    }
}

qint8 Convercion::QStringToInt8(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        qint8 b=auxiliar.toInt();
        return b;
    }
}

qint16  Convercion::QStringToInt16(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        qint16 b=auxiliar.toInt();
        return b;
    }
}

qint32 Convercion::QStringToInt32(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        qint32 b=auxiliar.toInt();
        return b;
    }
}

qint64 Convercion::QStringToInt64(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        qint64 b=auxiliar.toInt();
        return b;
    }
}


float Convercion::QStringToFloat(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    bool real=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }else if(a[i]=='.' && real!=true){
            auxiliar+=a[i];
            real=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        float b=auxiliar.toFloat();
        return b;
    }
}


double Convercion::QStringToDouble(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    bool real=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }else if(a[i]=='.' && real!=true){
            auxiliar+=a[i];
            real=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        double b=auxiliar.toDouble();
        return b;
    }
}

qreal Convercion::QStringToQreal(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    bool real=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }else if(a[i]=='.' && real!=true){
            auxiliar+=a[i];
            real=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        qreal b=auxiliar.toDouble();
        return b;
    }
}

long Convercion::QStringToLong(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        long b=auxiliar.toLong();
        return b;
    }
}

qlonglong Convercion::QStringToQlonglong(QString a){
    bool negativo=false;
    bool digitoEntrada=false;
    QString auxiliar="";
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57){
                digitoEntrada=true;
                auxiliar +=a[i];
        }else if(a[i]=='-' && negativo!=true && digitoEntrada!=true){
            auxiliar+=a[i];
            negativo=true;
        }
    }
    if(auxiliar==""){
        return 0;
    }else{
        qlonglong b=auxiliar.toLongLong();
        return b;
    }
}

