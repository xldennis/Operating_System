// Include system header files before yours
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


// Shortcut for the regular namespace
using namespace std;

// Function prototype
void* child_function(char **argv);


int main(int argc, char **argv)
{
    /* Check for a valid value of argc before copying */
    if(argc != 3) { 
      cout << "You need to supply input file name and output file name to this program.";
      return -1;
    }
    
    int value = fork(); // start fork
    int status;                               // Termination status of child
    if (value == 0)
    {
        // child process
        child_function(argv);
    } else if (value > 0)
    {
        // parent process
        wait(&status);                        //wait for children to exit
        cout << endl << "Parent Display the Output File:" <<endl << endl;
        // std::string provides an overload of the + operator. as I have to concatentated 'cat' with 'argv[2]'
        std::string const command = std::string( "cat " ) + argv[2]; 
        system(command.c_str());          
    } else
    {
        // fork failed
        printf("fork failed!\n");
        exit(0);
    }

    return 0;
}


void* child_function(char **argv){
  int pid = getpid(); 
  int ppid = getppid();
  cout << "Child process ID: " << pid << endl;       //print child ID
  cout << "Parent process ID: " << ppid << endl;     //print parent 
  if( access("hw1", 0 ) != -1 ) {
    // hw1 exists
    // char *args[] = {"hw1", "infile1", "output_file", 0};
    execv("hw1", argv);                              //executing hw1
  } else {
    // hw1 doesn't exist
    cerr << "Error: make sure hw1 file exist";
    cin.get();
  }

  exit(0); 
}