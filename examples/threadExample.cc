//
// threadex.cc
// Author: Marty Barrett
// What  : Example of usage of pthread library.
//         Uses shared memory with mutex protection of
//         critical regions.

// Usual Unix system includes
#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// Pthread includes
#include <pthread.h>

using namespace std;

// Two thread records
pthread_t child1, child2;

// Mutex for stuff
pthread_mutex_t mu_stuff   = PTHREAD_MUTEX_INITIALIZER;
// Mutex for console output
pthread_mutex_t mu_console = PTHREAD_MUTEX_INITIALIZER;

// Global values
struct stuff {
   int count;
   int list[20];
};

stuff mystuff;

// Function prototypes
void* child1_fn(void*);
void* child2_fn(void*);

int main(int argc, char** argv)
{

   int i = 1, j = 2;

   mystuff.count = 0;

   pthread_create(&child1, NULL, child1_fn, (void*)&i);

   pthread_create(&child2, NULL, child2_fn, (void*)&j);

   pthread_mutex_lock(&mu_console);
      cout << "Created two threads" << endl;
   pthread_mutex_unlock(&mu_console);

   pthread_join(child1, NULL);
   pthread_join(child2, NULL);

   for (i=0; i<20; i++) {
      cout << "list[" << i << "] = " << mystuff.list[i] << endl;
   }

   return 0;

} // main( )

void* child1_fn(void* x)
{

int whoami;
int i = 1;
int value;

whoami = *((int*)x);
srand( (unsigned) time(NULL) );
pthread_mutex_lock(&mu_console);
   cout << "child# " << whoami << " started" << endl;
pthread_mutex_unlock(&mu_console);

while ( i < 20 )
{

   pthread_mutex_lock(&mu_stuff);
      mystuff.count++;
      value = mystuff.count;
      mystuff.list[i] = value;
   pthread_mutex_unlock(&mu_stuff);

   pthread_mutex_lock(&mu_console);
      cout << "child# " << whoami << " puts " << value << endl;
   pthread_mutex_unlock(&mu_console);

   // Soft kitty, warm kitty, little ball of fur
   usleep((long)(rand()%2));
   i++;

} // while

pthread_mutex_lock(&mu_console);
   cout << "child# " << whoami << " exiting" << endl;
pthread_mutex_unlock(&mu_console);

pthread_exit(0);

}

void* child2_fn(void* x)
{

int whoami;
int i = 1;
int value = 0;

whoami = *((int*)x);

pthread_mutex_lock(&mu_console);
   cout << "child# " << whoami << " started" << endl;
pthread_mutex_unlock(&mu_console);

while (i < 20)
{

   pthread_mutex_lock(&mu_stuff);
      mystuff.count--;
      value = mystuff.count;
      mystuff.list[i] = value;
   pthread_mutex_unlock(&mu_stuff);

   pthread_mutex_lock(&mu_console);
      cout << "child# " << whoami << " puts " << value << endl;
   pthread_mutex_unlock(&mu_console);

   // Happy kitty, sleepy kitty, purr purr purr
   usleep((long)(rand()%1000));
   i++;

} // while

pthread_mutex_lock(&mu_console);
   cout << "child# " << whoami << " exiting" << endl;
pthread_mutex_unlock(&mu_console);
pthread_exit(0);

}

