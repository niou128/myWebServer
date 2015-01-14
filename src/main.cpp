#include            "../headers/main.h"

int             main()
{
    Server* object = ServerFactory::getServerInstance(ServerMYSQLImpl::value);

    if (object == 0){
      cout << "Le serveur n'existe pas dans l'application" << endl;
      return 0;
    }

    //Notre code
    cout << object->getNb() << endl;
    cout << ServerFactory::getServerInstance(ServerPostgreImpl::value)->getNb() << endl;

    ServerFactory::resetAll();

  return (0);
}