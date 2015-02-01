#ifndef REQUEST_H
#define REQUEST_H

//Transforme la requête HTTP en objet Request

#include "includes.h"
#include "Server.h"

class Request{

public:                                        
  Request();
  string getMethod();
  string getUrl();
  bool update(string header);
  static string TYPE_JSON;
  Document  parameters;

private:
  string    method;
  string    url;
  string    header;
  bool updateMethod();
  bool updateUrl();
  bool updateParameters();
  bool updateParametersWithJsonString(string json); 
}; 

#endif