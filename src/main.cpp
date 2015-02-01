#include            "../headers/main.h"

int             main()
{

  ClientSocketImpl* clientsocket = new ClientSocketImpl(new ServerMYSQLImpl());
  clientsocket->run();

  return (EXIT_SUCCESS);
}