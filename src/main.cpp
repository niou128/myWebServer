#include            "../headers/main.h"

void* tata(void* data);
void* tata(void* data)
{
  Server* ss = Server::getInstance();
  string message = "";

  while(1){
    message = ss->sReceive();
    ss->sendMessage(message);
  }

  if (data == 0){}   

  return NULL;
}

int             main()
{

  Server* ss = Server::getInstance();

  ss->start();

  while(1){
    //Si quelqu'un se connecte
    if (ss->sAccept()){

      pthread_t thread;
      pthread_create(&thread, NULL, tata, NULL);
      ss->sendMessage("llllll");
      pthread_join(thread, NULL);

    } 
    usleep(1000); //Libérer le processeur
  }
  
  ss->stop();

  return (EXIT_SUCCESS);
}