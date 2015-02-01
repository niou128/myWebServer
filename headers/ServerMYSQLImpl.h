#ifndef SERVERMYSQLIMPL_H
#define SERVERMYSQLIMPL_H

#include "ServerDataBase.h"
#include "Observer.h"
#include "Request.h"

class ServerMYSQLImpl : public ServerDataBase, public Observer{
public: 
	~ServerMYSQLImpl();
  static int value;
  void execute(Request* req);
};

#endif