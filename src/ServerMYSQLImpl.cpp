#include "../headers/ServerMYSQLImpl.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////
int ServerMYSQLImpl::value = 1;

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
ServerMYSQLImpl::~ServerMYSQLImpl() 
{

}

// METHODS
//////////////////////////////////////////////////////////
//Execute la requete envoyée
void ServerMYSQLImpl::execute(Request* req) 
{
  cout << "La requêtre est executée par le serveur MYSQL." << endl;
  if (req->getMethod() == ""){}

    if (req->parameters.IsObject()) {
      assert(req->parameters.IsObject());

      if (req->parameters.HasMember("hello")) {
        assert(req->parameters.HasMember("hello"));
        if (req->parameters["hello"].IsString()){
          assert(req->parameters["hello"].IsString());
          printf("hello = %s\n", req->parameters["hello"].GetString());
        }
        else {
          cout << "hello n'est pas une string" << endl;
        }
      }
      else {
        cout << "Pas de membre hello" << endl;
      }
    }

    else {
      cout << "Le paramètre n'est pas un objet" << endl;
    }
  
}