//
// class mp3
//   Definition of the mp3 class
//
// Author: Barrett
// Date  : 1/10/2013
//

// The following lines help prevent multiple include's
//   Note this requires #endif at the end of the file
#ifndef MP3_H
#define MP3_H

// String class
#include <string>
using namespace std;

// Define the interface for class mp3
// Note: no code here, with one exception
class mp3 {

private:
   // Class constant - only one for all mp3 objects
   // Or: #define DOWNLOADTIME 3.0
   //   note the lack of = and ; above
   static const double DOWNLOADTIME = 3.0;
   string title;    // mp3 file name
   double filesize; // mp3 file size
   // private function to compute the download time
   double computeDownloadTime( );

public:
   // Default Constructor
   mp3();
   // Overloaded constructor
   mp3( string aTitle, double aFilesize );

   // Getter functions
   string getTitle( );
   double getFilesize( );

   // Setter functions
   void   setTitle( string aTitle );
   void   setFilesize( double aFilesize );

   // Convert data to a string
   string toString( );

}; // Note this semicolon

#endif
