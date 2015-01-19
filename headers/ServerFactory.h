#ifndef SERVERFACTORY_H
#define SERVERFACTORY_H

#include "ServerDataBase.h"
#include "main.h"

class ServerFactory {
private:
	ServerFactory();
	static ServerDataBase* serverMYSQLInstance;
	static ServerDataBase* serverPostgreInstance;

public: 
	static ServerDataBase* getServerInstance(int sgbd);
	static void resetAll();
};

#endif