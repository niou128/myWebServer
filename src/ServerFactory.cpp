#include "../headers/ServerFactory.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////
ServerDataBase* ServerFactory::serverMYSQLInstance = new ServerMYSQLImpl();
ServerDataBase* ServerFactory::serverPostgreInstance = new ServerPostgreImpl();

// METHODS
//////////////////////////////////////////////////////////
ServerDataBase* ServerFactory::getServerInstance(int sgbd) {

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