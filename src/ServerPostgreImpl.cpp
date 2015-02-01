#include "../headers/ServerPostgreImpl.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////
int ServerPostgreImpl::value = 2;

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
ServerPostgreImpl::~ServerPostgreImpl() 
{
  
}

// METHODS
//////////////////////////////////////////////////////////
//Execute la requete envoyée
void ServerPostgreImpl::execute(Request* req) 
{
  cout << "La requêtre est executée par le serveur Postgre." << endl;
  if (req->getMethod() == ""){}
}
