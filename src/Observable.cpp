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
void Observable::add(Observer* observer)
{
  this->m_list.push_back(observer);
}

void Observable::notify(string& data)
{
  cout << "notify" << endl;
  if (data == "test") {
    //
  }
  iterator itb = this->m_list.begin();
  const_iterator ite = this->m_list.end();

  for(; itb!=ite; ++itb)
  {
    (*itb)->test();
  }
}

void Observable::remove(Observer* observer)
{
  iterator it= find(m_list.begin(), m_list.end(), observer);

  if(it != m_list.end()){
    m_list.erase(it);
  }
}