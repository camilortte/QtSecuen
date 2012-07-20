#ifndef EXPORTARARCHIVO_H
#define EXPORTARARCHIVO_H

#include <QString>

class ExportarArchivo
{
public:
    ExportarArchivo();
    void exportarHtml(QString secuencia1, QString secuencia2, QString nombreArchivo);
    void exportarFasta(QString secuencia1,QString secuencia2,QString nombreArchivo);
    void almacentarTextoPlano(QString texto,QString nombreArchivo);
};

#endif // EXPORTARARCHIVO_H
