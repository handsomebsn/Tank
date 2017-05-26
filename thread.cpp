#include "thread.h"



Thread::Thread(QObject *parent):QThread(parent){



}
void Thread::run(){
    while(true){
     sleep(1);
        for(int i=0;i<glo.badtanks.count();i++){
        if(qrand()%5==0)
        glo.badtanks.at(i)->startmove();
       if(qrand()%10==0)
           glo.badtanks.at(i)->stopmove();
       if(qrand()%4==0)

             glo.badtanks.at(i)->setdir(UP);
        }
  qDebug("==============================================================");

    }
}
