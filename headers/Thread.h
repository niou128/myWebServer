#ifndef THREAD_H
#define THREAD_H

#include "includes.h"
#include "Runnable.h"

class Thread {
private:
  Runnable* runa;
  pthread_t noThread;

public: 
  Thread(Runnable* runnable);
  ~Thread();
  void start();
  static void runThread(void*);
};

#endif