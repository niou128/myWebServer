#ifndef SERVERPOSTGREIMPL_H
#define SERVERPOSTGREIMPL_H

#include "Server.h"

class ServerPostgreImpl : public Server{
public: 
	~ServerPostgreImpl();
	static int value;
  int getNb();
};

#endif