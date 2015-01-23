#include "../headers/WebServerSocketImpl.h"

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
WebServerSocketImpl::WebServerSocketImpl(Observer* observer)
{
  this->stopThread = false;
  this->add(observer);
  this->th = new Thread(this);
  this->th->start();
}

WebServerSocketImpl::~WebServerSocketImpl() 
{

}

// METHODS
//////////////////////////////////////////////////////////
void WebServerSocketImpl::run() 
{
  //Server* ss = new Server(23);
  //ss->start();

  //ss->sAccept();

  string message = "";

  //while(!stopThread){
    //Si quelqu'un se connecte
    //if (ss->sAccept()){

      //On crée un nouveau Thread qui traite la demande de l'utilisateur


     //new Thread(this);
      //message = ss->sReceive();

      //this->notify(message);

      //TEST
      //Pour couper la connexion
      /*if (message.compare("stop\r\n") == 0){
        this->setStopThread();
      }
      cout << " Recu :" << message << endl;*/
    //} 
    //usleep(1000); //Libérer le processeur
  //}
  
  //ss->stop(); 
}



void WebServerSocketImpl::setStopThread() 
{
  this->stopThread = false;
}