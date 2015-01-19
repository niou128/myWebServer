#ifndef SERVER_H
#define SERVER_H

#include "includes.h"
#include "Socket.h"

//Tuto utilisté : http://sdz.tdct.org/sdz/les-sockets.html

class Server{
private:
  /* Socket et contexte d'adressage du serveur */
  t_sockaddr_in sin;
  SOCKET        sock;
  socklen_t     recsize;
  /* Socket et contexte d'adressage du client */
  t_sockaddr_in csin;
  SOCKET        csock;
  socklen_t     crecsize;

  int           port;
public:                                        
  Server(int p);
  void      start();
  void      stop();
  bool      sAccept();
  string    sReceive();
  void      sendMessage(string line);
}; 

#endif