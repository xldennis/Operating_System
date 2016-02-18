/*                                          */
/* Author: Barrett                          */
/* Date  : 1/10/2013                        */
/*                                          */
/* Purpose: example of using argc and argv  */
/*          using -p, -f flags for no       */
/*          good reason.                    */
/*                                          */

// Include the C++ i/o library
#include <iostream>
// Include the C-string library
#include <string.h>
// Standard library
#include <stdlib.h>
// Shortcut for the std namespace
using namespace std;

// String length, plus one for \0
#define STRLEN 32

//
// main( )
//
//    Shows the use of argc and argv
//      and retrieving argv from getopt( )
//
int main( int argc, char** argv )
{
   // getopt( ) requires char* arguments
   char str1[STRLEN] = "", str2[STRLEN] = "";
   // For return value of getopt( )
   char c;

   // argc is the number of command-line arguments, always at least 1
   cout << "# command line arguments = " << argc << endl;

   // This depends on the specs - suppost that the command line
   // arguments -p and -f are required; if not present, quit
   if ( argc == 1 ) {
      cout << "Usage: getoptex -p arg1 -f arg2" << endl;
      exit(0);
   } // if

   // Use getopt( ) to loop through -p, -f flags
   while ( (c = getopt(argc, argv, "p:f:")) != -1 ) {
      switch (c) {
         case 'p': strncpy(str1, optarg, STRLEN-1);
                   break; 
         case 'f': strncpy(str2, optarg, STRLEN-1);
                   break; 
      }; // switch 
   } // while

   // Show the arguments
   if ( strlen(str1) > 0 ) {
      cout << "str1 = " << str1 << endl;
   }
   if ( strlen(str2) > 0 ) {
      cout << "str2 = " << str2 << endl;
   }

   // Requires an integer return value
   return 0;

} // main( )

