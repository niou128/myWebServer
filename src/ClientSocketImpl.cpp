#include "../headers/ClientSocketImpl.h"

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
ClientSocketImpl::ClientSocketImpl(Observer* observer)
{
  this->stop = false;
  this->add(observer);
}

ClientSocketImpl::~ClientSocketImpl() 
{

}

// METHODS
//////////////////////////////////////////////////////////
void ClientSocketImpl::run() 
{
  Server* ss = Server::getInstance();

  if (ss->start()) {
    string st;

    while(!this->stop){
      //Si quelqu'un se connecte
      if (ss->sAccept()){
        Request* req = new Request();
        string header = ss->sReceive();

        if (req->update(header)){
          //On envoie l'objet de l'en-tête de la requête à tous les observeurs
          //Ici, il n'y a qu'un observeur, MYSQL ou Postgre
          this->notify(req);


          ss->sendMessage("HTTP/1.1 200 OK\r\nContent-Length: 200\r\n\r\n\0");
          cout << "requete envoyee" << endl;
        }
        else {
          cout << "L'en-tête ne correspond pas au bon format. Impossible de traiter la demande." << endl;
        }
      } 
      usleep(1000); //Libérer le processeur
    }

    ss->stop();
  }
}



void ClientSocketImpl::setStop() 
{
  this->stop = true;
}