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

  ClientSocketImpl* clientsocket = new ClientSocketImpl(new ServerMYSQLImpl());
  clientsocket->run();

  return (EXIT_SUCCESS);
}