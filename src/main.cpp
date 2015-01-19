#include            "../headers/main.h"

int             main()
{
  //Selon la config, on charge le serveur. Ici MYSQL
  WebServerSocketImpl* ws =  new WebServerSocketImpl(new ServerMYSQLImpl());

  //On lance l'observable
  ws->run();

  delete ws;

    /*ServerDataBase* object = ServerFactory::getServerInstance(ServerMYSQLImpl::value);

    if (object == 0){
      cout << "Le serveur n'existe pas dans l'application" << endl;
      return 0;
    }

    //Notre code
    cout << object->getNb() << endl;
    cout << ServerFactory::getServerInstance(ServerPostgreImpl::value)->getNb() << endl;

    ServerFactory::resetAll();*/

  return (EXIT_SUCCESS);
}