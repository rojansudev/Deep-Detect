#include "mythread.h"

mythread::mythread(QObject* parent)
{

}

void mythread::run()
{
    QProcess proc;
    QString cmd="python directory_predict.py "+path;
    proc.start(cmd);
    proc.waitForFinished(-1);
    QString stdout=proc.readAllStandardOutput();
    emit output(stdout);
}
