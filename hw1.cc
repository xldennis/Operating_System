// Include system header files before yours
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <string>

// Include once
#ifndef PROCUCT_RECORD
#include "product_record.h"
#endif


// Shortcut for the regular namespace
using namespace std;

// Function prototype
int readFile(fstream&, string, vector<product_record>&);
int writeToFile(fstream&, string, vector<product_record>&);

int main(int argc, char** argv)
{
/* Check for a valid value of argc before copying */
    if(argc != 3) { 
      cout << "You need to supply input file name and output file name to this program.";
      return -1;
    }

/* Copying input and output file names from command line */
    string input_name = argv[1]; string output_name = argv[2];
	  //string input = "out"; string output = "1";


    vector<product_record> records(0);  // Create an empty vector that will contain the structure
    fstream inFile;                    // Input file
    fstream outFile;                    // Output file


/* Read file and store information in the vector 
   Parameter: fstream, filename and vector of record */
    
    if ( readFile(inFile, input_name, records) == -1 ) {
      cout << "File read failed" << endl;
    }
    
/* Next display the result */
    for(int i=0; i<records.size(); i++)
    {
       cout.precision(2);              // Precision 2
       cout << "ID: " << records[i].idnumber << endl;
       cout << "Name: " << records[i].name << endl;
       cout << "Price: " << fixed << records[i].price << endl;
       cout << "Number: " << records[i].number << endl;
       cout << "Tax: "  << records[i].tax << endl;
       cout << "SandH: " << records[i].sANDh << endl;
       cout << "Total: " << records[i].total << endl;
       cout << "stations: ";
       for (int k = -MAXSTAGES; k < 0; k++){
       		cout << records[i].stations[k] << " ";
       }
       cout << endl;       
       cin.get();
    }

/* Write the product_record’s to the output file in the same 
   format, Parameter: fstream, filename and vector of record */
    
    if ( writeToFile(outFile, output_name, records) == -1 ) {
      cout << "File write failed" << endl;
    }

    return 0;

} //main()





int readFile( fstream& f, string name,  vector<product_record>& data_vector) {

   f.open(name.c_str(), fstream::in);

   // Always check that the file opened correctly
   if ( !f ) {
      // f.open( ) failed
      cerr << "Error, opening file. ";
      cin.get();
      return -1;
   } else {
      // keep reading record information from file
      string line;                        // Read line from data
      product_record data;                // Create an object to access each member in the structure.
      while(f >> data.idnumber>> data.name>> data.price >> data.number >> data.tax >> data.sANDh
      >> data.total >> * data.stations )
    {   
        data_vector.push_back(data);
        getline(f, line) ;
    }

      f.close( );
   }
   
   return 0;
}

int writeToFile( fstream& f, string name,  vector<product_record>& data_vector ) {

   f.open(name.c_str(), fstream::out);

   // Always check that the file opened correctly
   if ( !f ) {
      // f.open( ) failed
      cerr << "Error, opening file. ";
      cin.get();
      return -1;
   } else {
      // keep saving record information to the file
      for(int i=0; i<data_vector.size(); i++){
      f << data_vector[i].idnumber << "\n" << data_vector[i].name << "\n" << fixed << std::setprecision(2) 
      << data_vector[i].price << "\n" << data_vector[i].number << "\n" << data_vector[i].tax  
      << "\n" << data_vector[i].sANDh << "\n" << data_vector[i].total << "\n";
      for(int t = -MAXSTAGES; t < 0; t++){
        f << data_vector[i].stations[t] << " ";
      }
        f << endl;
    }

      f.close( );
   }
   
   return 0;
}


