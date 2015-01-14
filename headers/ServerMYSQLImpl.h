#ifndef SERVERMYSQLIMPL_H
#define SERVERMYSQLIMPL_H

#include "Server.h"

class ServerMYSQLImpl : public Server{
public: 
	~ServerMYSQLImpl();
	static int value;
  int getNb();
};

#endif