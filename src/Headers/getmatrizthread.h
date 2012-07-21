#ifndef GETMATRIZTHREAD_H
#define GETMATRIZTHREAD_H

#include <QThread>
#include "src/Headers/puntaje.h"

class getMatrizThread : public QThread
{
    Q_OBJECT
public:
    explicit getMatrizThread(QObject *parent = 0);
    getMatrizThread(Puntaje *puntaje);
    ~getMatrizThread();
    void run();
    QString getMatriz();
    
signals:
    void estadoGetMatriz(int,int);
    
public slots:
    void slot_estadoGetMatriz(int,int);

private:
    Puntaje *puntaje;
    QString matriz;
    
};

#endif // GETMATRIZTHREAD_H
