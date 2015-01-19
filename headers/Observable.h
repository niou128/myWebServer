#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "includes.h"
#include "Observer.h"

class Observable {
private:
  list<Observer*> m_list;
  typedef list<Observer*>::iterator iterator; 
  typedef list<Observer*>::const_iterator const_iterator;
public: 
  ~Observable();
  void add(Observer* observer);
  void notify(string& data);
  void remove(Observer* observer);
};

#endif