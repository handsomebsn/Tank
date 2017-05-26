#ifndef THREAD_H
#define THREAD_H
#include"tank.h"
#include"main.h"
#include<QThread>
class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);
protected:
    void run();
private:

};

#endif // THREAD_H
