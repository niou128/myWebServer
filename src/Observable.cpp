#include "../headers/Observable.h"

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
Observable::~Observable()
{
  iterator itb = this->m_list.begin();
  const_iterator ite = this->m_list.end();

  for(; itb!=ite; ++itb)
  {
    this->remove((*itb));
  }
}

// METHODS
//////////////////////////////////////////////////////////
//Ajoute un observeur
void Observable::add(Observer* observer)
{
  this->m_list.push_back(observer);
}

//Notifie tous les observeurs
void Observable::notify(Request* req)
{
  cout << "Tous les observeurs sont en train d'être notifiés." << endl;

  iterator itb = this->m_list.begin();
  const_iterator ite = this->m_list.end();

  for(; itb!=ite; ++itb)
  {
    (*itb)->execute(req);
  }
}

//Supprime un observeur
void Observable::remove(Observer* observer)
{
  iterator it= find(m_list.begin(), m_list.end(), observer);

  if(it != m_list.end()){
    m_list.erase(it);
  }
}