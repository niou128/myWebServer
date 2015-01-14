#include "../headers/ServerFactory.h"

Server* ServerFactory::serverMYSQLInstance = new ServerMYSQLImpl();
Server* ServerFactory::serverPostgreInstance = new ServerPostgreImpl();

Server* ServerFactory::getServerInstance(int sgbd) {

  if (sgbd == ServerMYSQLImpl::value) {
    return ServerFactory::serverMYSQLInstance;
  }

  else if (sgbd == ServerPostgreImpl::value) {
    return ServerFactory::serverPostgreInstance;
  }

  return 0;
}

void ServerFactory::resetAll() {
	delete ServerFactory::serverMYSQLInstance;
	delete ServerFactory::serverPostgreInstance;
}