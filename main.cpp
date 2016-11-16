//-------------------------------------------------
// Hannah Hopkins
// CS255
// 15 April 2015
// Movies
// This is the main part of the program. The program 
// displays a list of movies. It also asks the user
// for a movie or year of a movie to search for, and 
// the program tells the user if it is in the list or
// not. 
//--------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "Movies.h"
using std::ifstream;
using std::cerr;
using std::endl;
using std::string;
using std::cout;


int main() {
    ifstream films;
    string title;
    string rank;
    string yearStr;
    int yearInt;
    string restOfLine;
    int endOfTitle;

    films.open("afi.txt");

    if(films.fail()){
        cerr << "File not found." << endl;
    }

	Movie* head=new Movie(title, yearInt);	

	do{
        getline(films, rank, ' ');
        getline(films, restOfLine);
        endOfTitle=restOfLine.size() -5;
        title=restOfLine.substr(0, endOfTitle);
        yearStr=restOfLine.substr(endOfTitle);
        
		stringstream convert(yearStr);
		convert >> yearInt;
					
		head->append(title, yearInt); 
	}
	while(!films.eof());
	

	cout << "The list is: " << endl;
	head->displayList();
	cout << endl;
	
	head->search(1942);
	head->search("GOODFELLAS"); 
	cout << endl;
	head->search(2021); // should not find it
	head->search("HARRY POTTER"); // should not find it unfortunately-Harry Potter is great. 

    films.close();

	return 0;
}

