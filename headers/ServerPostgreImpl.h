#ifndef SERVERPOSTGREIMPL_H
#define SERVERPOSTGREIMPL_H

#include "ServerDataBase.h"
#include "Observer.h"

class ServerPostgreImpl : public ServerDataBase, public Observer{
public: 
	virtual ~ServerPostgreImpl();
  static int value;
  void test() { cout << "ok" << endl; }
};

#endif