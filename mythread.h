#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QString>
#include <QProcess>
#include<QThread>
class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject* parent=0);
    void run();
    QString path;

signals:
    void output(QString);

};

#endif // MYTHREAD_H
