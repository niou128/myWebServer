#ifndef FLUXSTREAMIMPL_H
#define FLUXSTREAMIMPL_H

#include <fstream>
#include "includes.h"
#include "FluxStream.h"

class FileStreamImpl : public FluxStream
{
// ATTRIBUTES
private:
  string currentLineContent;
  ifstream fileInput;
  ofstream fileOutput;
// CONSTRUCTOR / DESTRUCTOR

public:
  FileStreamImpl();
  ~FileStreamImpl();
  
// PUBLIC METHODS
public:
  bool close();
  bool open(string&);
  string& read();
  int write(string&);
};

#endif