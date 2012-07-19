#ifndef CONVERCION_H
#define CONVERCION_H
#include <QString>
#include <QtCore>

class Convercion
{
public:
    Convercion();
    static QString intToQString(int a);
    static QString qint8ToQString(qint8 a);
    static QString qint16ToQString(qint16 a);
    static QString qint32ToQString(qint32 a);
    static QString qint64ToQString(qint64 a);
    static QString floatToQString(float a);
    static QString doubleToQstring(double a);
    static QString qrealToQString(qreal a);
    static QString longToQString(long a);
    static QString qlonglongToQString(qlonglong a);

    static int QStringToInt(QString a);
    static qint8 QStringToInt8(QString a);
    static qint16  QStringToInt16(QString a);
    static qint32 QStringToInt32(QString a);
    static qint64 QStringToInt64(QString a);
    static float QStringToFloat(QString a);
    static double QStringToDouble(QString a);
    static qreal QStringToQreal(QString a);
    static long QStringToLong(QString a);
    static qlonglong QStringToQlonglong(QString a);
};

#endif // CONVERCION_H
