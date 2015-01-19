#include "../headers/Socket.h"

// ATTRIBUTE
//////////////////////////////////////////////////////////


// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
Socket::Socket(short s_family, unsigned short s_port, unsigned long s_addr, string s_zero) 
{
  this->sin_family  = s_family;
  this->sin_port    = s_port;
  this->sin_addr    = s_addr;
  this->sin_zero    = s_zero;
}

// METHODS
//////////////////////////////////////////////////////////
