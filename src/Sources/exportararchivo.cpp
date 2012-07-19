#include "src/Headers/exportararchivo.h"
#include <QFile>
#include <QTextStream>

ExportarArchivo::ExportarArchivo()
{
}

void ExportarArchivo::exportarHtml(QString secuencia1, QString secuencia2,QString nombreArchivo)
{
    QFile archivo(nombreArchivo);
    archivo.open (QIODevice::WriteOnly);
    QTextStream out(&archivo);
    QString html="<html>\n"
            "<head>\n"
            "<title>Alineacion de secuancias , generacion QtSecuen by C4M170RTT3</title>\n"
            "</head>\n"
            "<body>\n"
            "<p>>secuencia 1 </p>\n";
    html+=secuencia1;
    html+="<p>>Secuencia 2 </p>\n";
    html+=secuencia2;
    html+="<p>#||Codigo generado por QtSecuen V2.5 #||By C4M170RTT3</p>\n";
    html+="</body>\n";
    html+="</html>";
    out << html;
    archivo.close ();
}
