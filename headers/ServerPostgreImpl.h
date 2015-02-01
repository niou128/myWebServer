#ifndef SERVERPOSTGREIMPL_H
#define SERVERPOSTGREIMPL_H

#include "ServerDataBase.h"
#include "Observer.h"
#include "Request.h"

class ServerPostgreImpl : public ServerDataBase, public Observer{
public: 
	virtual ~ServerPostgreImpl();
  static int value;
  void execute(Request* req);
};

#endif