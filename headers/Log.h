//
//  log.h
//  myWebServer
//
//  Created by Sébastien Bernard on 28/01/2015.
//
//

#ifndef __myWebServer__log__
#define __myWebServer__log__

#include "includes.h"
#include "../include/rapidjson/document.h"

class Log {
    
public:
    Log();
    void write(string text);
    void pasteDate(int moment, const rapidjson::Document & d);
    
private:
    void output(const rapidjson::Document & d);
    string getDate();
    void ecriture(string& PATH, string text);
    
};

#endif /* defined(__myWebServer__log__) */
