#ifndef WEBSERVERSOCKETIMPL_H
#define WEBSERVERSOCKETIMPL_H

#include "Thread.h"
#include "Runnable.h"
#include "Observable.h"
#include "Observer.h"
#include "ServerFactory.h"
#include "ServerMYSQLImpl.h"
#include "ServerPostgreImpl.h"

class WebServerSocketImpl : public Observable, public Runnable {
private:
  bool stopThread;
  Thread* th;

public: 
  WebServerSocketImpl(Observer* observer); 
  ~WebServerSocketImpl();
  void run();
  void setStopThread();
};

#endif