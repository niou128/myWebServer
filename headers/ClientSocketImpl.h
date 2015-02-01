#ifndef CLIENTSOCKETIMPL_H
#define CLIENTSOCKETIMPL_H

#include "Runnable.h"
#include "Observable.h"
#include "Observer.h"
#include "Server.h"
#include "ServerFactory.h"
#include "ServerMYSQLImpl.h"
#include "ServerPostgreImpl.h"

class ClientSocketImpl : public Observable, public Runnable {
private:
  bool stop;

public: 
  ClientSocketImpl(Observer* observer); 
  ~ClientSocketImpl();
  void run();
  void setStop();
};

#endif