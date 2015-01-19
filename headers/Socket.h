#ifndef SOCKET_H
#define SOCKET_H

#include "includes.h"

class Socket{

public:                                        
  Socket(short s_family, unsigned short s_port, unsigned long s_addr, string s_zero);
  short           getFamily() {return sin_family;}
  unsigned short  getPort() {return sin_port;}
  unsigned long   getAddr() {return sin_addr;}
  string          getZero() {return sin_zero;}
  short           sin_family;   //Protocole familial (IP)
  unsigned short  sin_port;     //Listage du port
  unsigned long   sin_addr;     //Adresse IP automatique
  string          sin_zero;
}; 

#endif