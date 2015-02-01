#include "../headers/Request.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////
string Request::TYPE_JSON = "application/x-www-form-urlencoded";

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
Request::Request() 
{
}
// METHODS
//////////////////////////////////////////////////////////
string Request::getMethod() 
{
  return method;
}

string Request::getUrl() 
{
  return url;
}

bool Request::update(string header) 
{
  cout << header << endl;

  this->header = header;
  if (!this->updateMethod()) {
    return false;
  }
  if (!this->updateUrl()){
    return false;
  }
  if (!this->updateParameters()){
    cout << "Aucun paramètre n'a été trouvé." << endl;
  } else {
    cout << "Les paramètres ont été trouvé." << endl;
  }
  return true;
}

//Met à jour la méthode en fonction de l'en-tête
bool Request::updateMethod() 
{
  std::smatch match;

  string regex = method + "(\\S+)";

  if (std::regex_search (this->header, match, std::regex(regex), std::regex_constants::match_continuous )) {
    method = match[1];
    if (method == "GET" || method == "POST" || method == "DELETE" || method == "UPDATE"){
      return true;
    }
    
  }
  return false;
}

bool Request::updateUrl() 
{
  std::smatch match;

  string regex = method + "\\s+" + "(\\S+)";

  if (std::regex_search (this->header, match, std::regex(regex), std::regex_constants::match_continuous )) {
    url = match[1];
    return true;
  }
  return false;
}

//Enregistre les paramètres en json
bool Request::updateParameters() 
{
  std::smatch match;
  string regex = "Content-Type: (\\S+)";

  if (std::regex_search (this->header, match, std::regex(regex) )) {
    //Si les paramètres envoyés sont en JSON
    if (match[1] == Request::TYPE_JSON){
      regex = "application\\/x-www-form-urlencoded[\\s]+([{].+[}])$";
      if (std::regex_search (this->header, match, std::regex(regex) )) {
        //On met à jour les paramètres avec le json
        return this->updateParametersWithJsonString(match[1]);
      }
    }
    else {
      cout << "Le serveur ne gère que le Json." << endl;
    }
  }

  return false;
}

//Parse le string json en Document
bool Request::updateParametersWithJsonString(string json_str) 
{

  char * writable = new char[json_str.size() + 1];
  std::copy(json_str.begin(), json_str.end(), writable);
  writable[json_str.size()] = '\0';
  cout << writable << "\n";
  if (parameters.Parse<0>(writable).HasParseError()){
    cout << "Impossible de parser le json" << endl;
    return false;
  }
      
  cout << "Le json a bien été parsé." << endl;
  return true;
}