#ifndef SERVERMYSQLIMPL_H
#define SERVERMYSQLIMPL_H

#include "ServerDataBase.h"
#include "Observer.h"

class ServerMYSQLImpl : public ServerDataBase, public Observer{
public: 
	~ServerMYSQLImpl();
  static int value;
  void test() { cout << "ok" << endl; }
};

#endif