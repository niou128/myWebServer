#ifndef OBSERVER_H
#define OBSERVER_H

#include "includes.h"
#include "Request.h"

class Observer {
public:
  //~Observer();
  virtual void execute(Request* req) = 0;
};

#endif