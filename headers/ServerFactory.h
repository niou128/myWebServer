#ifndef SERVERFACTORY_H
#define SERVERFACTORY_H

#include "Server.h"
#include "ServerMYSQLImpl.h"
#include "ServerPostgreImpl.h"
#include "main.h"

class ServerFactory {
private:
	ServerFactory();
	static Server* serverMYSQLInstance;
	static Server* serverPostgreInstance;

public: 
	static Server* getServerInstance(int sgbd);
	static void resetAll();
};

#endif