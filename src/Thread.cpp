#include "../headers/Thread.h"

void* maFonction(void* data);
void* maFonction(void* data)
{
  cout << "test" << endl;
    if (data == 0){}   
    return NULL;
}

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
Thread::Thread(Runnable* runnable) 
{
  this->runa = runnable;
}

Thread::~Thread() 
{

}

// METHODS
//////////////////////////////////////////////////////////
void Thread::start()
{
    // Permet d'exécuter le fonction maFonction en parallèle
  /*while (1){
    pthread_create(&noThread, NULL, maFonction, NULL);
  }
    
    // Attend la fin du thread créé
    thread_join(noThread, NULL);*/
}