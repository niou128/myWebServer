#include "../headers/Server.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////
Server* Server::instance = new Server(1985);

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
Server::Server(int p) 
{
  recsize   = sizeof(sin);
  
  csock     = 0;
  crecsize  = sizeof(csin);

  port      = p;
}

Server* Server::getInstance(){
  return Server::instance;
}

// METHODS
//////////////////////////////////////////////////////////
bool Server::start()
{
//Créer une socket
  sock      = socket(AF_INET, SOCK_STREAM, 0);

  //initialise les log
  doc       = Log();

  //Si la socket est valide
  if (sock != INVALID_SOCKET) {

    sin.sin_addr.s_addr = htonl(INADDR_ANY);  
    sin.sin_family = AF_INET;                
    sin.sin_port = htons(port);  

    //Si la socket fonctionne
    if (bind(sock, (SOCKADDR*)&sin, recsize) != SOCKET_ERROR) {
      if (listen(sock, 5) != SOCKET_ERROR) {
        doc.write("Les clients peuvent maintenant se connecter.");
        //cout << "Les clients peuvent maintenant se connecter." << endl ;
    
        crecsize = sizeof csin;
        this->is_start = true;
        return true;
      }
      else 
      {
        doc.write("Erreur lors du listen.");
        //cout << "Erreur lors du listen." << endl;
      }
    }
    else 
    {
      doc.write("Impossible de créer la socket. Essayez de changer de port.");
      //cout << "Impossible de créer la socket. Essayez de changer de port." << endl;
    }
  }

  return false;
}

bool Server::isStart()
{
  return this->is_start;
}

void Server::stop()
{
  shutdown(sock, 2);      //On ferme la transmission dans les deux sens
  closesocket(csock);
  cout << "Fermeture de la socket serveur" << endl;
  closesocket(sock);
}

bool Server::sAccept()
{
  csock = accept(sock, (SOCKADDR*)&csin, &crecsize);

  if (csock == -1){
    return false;
  }

  cout << "Un nouveau client vient d'arriver." << endl;
  return true;
}

string Server::sReceive()
{
  char buffer[100000] = "";
  recv(csock, buffer, 100000, 0);

  return buffer;
}

void Server::sendMessage(string line)
{
  //On convertit line en char*
  send(csock, (char*) line.c_str(), 32, 0);
}
