#ifndef FLUXSTREAM_H
#define FLUXSTREAM_H

#include "includes.h"

class FluxStream
{
public:
  virtual ~FluxStream(){}
  virtual bool close() = 0;
  virtual bool open(string&) = 0;
  virtual string& read() = 0;
  virtual int write(string&) = 0;
};

#endif