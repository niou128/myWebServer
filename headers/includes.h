#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <regex>
#include <string>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

//Pour les Sockets
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close (s)

typedef int SOCKET;
typedef struct sockaddr SOCKADDR;

typedef           struct s_sockaddr_in
{
    short             sin_family;
    unsigned short    sin_port;
    struct   in_addr  sin_addr;
    char              sin_zero[8];
}                 t_sockaddr_in;

//Pour le Json
#include "../include/rapidjson/document.h"         // rapidjson's DOM-style API
#include "../include/rapidjson/prettywriter.h"     // for stringify JSON
#include "../include/rapidjson/filestream.h"  

using namespace rapidjson;

#endif