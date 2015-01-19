#include "../headers/Server.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////


// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
Server::Server(int p) 
{
  recsize   = sizeof(sin);
  
  csock     = 0;
  crecsize  = sizeof(csin);

  port      = p;
}

// METHODS
//////////////////////////////////////////////////////////
void Server::start()
{
//Créer une socket
  sock      = socket(AF_INET, SOCK_STREAM, 0);

  //Si la socket est valide
  if (sock != INVALID_SOCKET) {
    cout << "La socket " << sock << " est maintenant ouverte en mode TCP/IP" << endl;

    sin.sin_addr.s_addr = htonl(INADDR_ANY);  
    sin.sin_family = AF_INET;                
    sin.sin_port = htons(port);  

    //Si la socket fonctionne
    if (bind(sock, (SOCKADDR*)&sin, recsize) != SOCKET_ERROR) {
      if (listen(sock, 5) != SOCKET_ERROR) {
        cout << "Patientez pendant que le client se connecte sur le port " << port ;
        //csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
        cout << "Un client se connecte avec la socket " << csock << " de :" << htons(csin.sin_port) << endl;
    
        crecsize = sizeof csin;
      }
      else 
      {
        cout << "error 2" << endl;
      }
    }
    else 
    {
      cout << "error 1" << endl;
    }
  }
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
  return true;
}

string Server::sReceive()
{
  char buffer[30] = "";
  recv(csock, buffer, 30, 0);

  return buffer;
}

void Server::sendMessage(string line)
{
  //On convertit line en char*
  send(csock, (char*) line.c_str(), 32, 0);
}
