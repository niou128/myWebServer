//
//  Log.cpp
//  myWebServer
//
//  Created by Sébastien Bernard on 28/01/2015.
//
//

#include "../headers/log.h"
#include "../headers/FileStreamImpl.h"
#include <time.h>

Log::Log(){}

void Log::write(string text){
    
    
    rapidjson::Document d;
    
    d.SetObject();
    
    rapidjson::Value s;
    
    rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

  s.SetString(StringRef(getDate().c_str()));
  d.AddMember("date", s, allocator);
  s.SetString(StringRef(text.c_str()));
  d.AddMember("message", s, allocator);

    

  
  string str = "/Users/sebastien/Documents/etna/rendusvn/m1/DCPP/myWebServer/bernar_s/mon_serveur_web/log.json";
    
  output(d);
  rapidjson::StringBuffer strbuf;
  rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
  d.Accept(writer);
  
  ecriture(str, strbuf.GetString());
}

void Log::output(const rapidjson::Document & d){
    cout << d["date"].GetString() << endl;
    if(d.HasMember("message"))
        cout << d["message"].GetString() << endl;
}

void Log::ecriture(string& PATH, string text)
{
  FileStreamImpl fs;
  fs.open(PATH);
  fs.write(text);
  fs.close();
}


/**
 *  Récupère la date courante
 */
string Log::getDate()
{
    time_t now = time(NULL);
    struct tm * tm = localtime(&now);
    char date[64];
    strftime(date, sizeof date, "%A, %B %d, %Y %H:%M:%S", tm);
    
    return date;
}



