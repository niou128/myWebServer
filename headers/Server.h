#ifndef SERVER_H
#define SERVER_H

class Server {
public: 
	virtual ~Server() {}
	static int value;
	virtual int getNb() = 0;
};

#endif