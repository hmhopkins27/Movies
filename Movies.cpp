//-------------------------------------------------------------
// Hannah Hopkins
// CS255
// 15 April 2015
// Movies
// This is the implementation part of the program. The program 
// displays a list of movies. It also asks the user
// for a movie or year of a movie to search for, and 
// the program tells the user if it is in the list or
// not. 
//---------------------------------------------------------------

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
using std::stringstream;

// This is a constructor that initializes the private member variables. 
Movie::Movie(string inTitle, int inYear){
	next=NULL;
	title=inTitle;
	year=inYear;
}

// This is the destructor. 
Movie::~Movie(){
	delete [] next;
}

// This function adds another node to the linked list. 
void Movie::append(string inTitle, int theYear){
	
    Movie* pointer= this;
    Movie* newMovie=new Movie(inTitle, theYear);

    while(pointer->next != NULL){
        pointer=pointer->next;
    }

    pointer->next=newMovie;
    
}

// This function displays the list to the console. 
void Movie::displayList(){	

	Movie* pointer=this;
	pointer=pointer->next;
	
	do{
		cout << pointer->title << " " << pointer->year << endl;
		pointer=pointer->next;
	}
	
	while(pointer!=NULL);
	
}

// This function searches through the titles and 
// finds whether or not the title that the user
// is searching for is in the list. 
Movie* Movie::search(string target){
	
	Movie* pointer=this;
	
	while(pointer != NULL){
	
		if(pointer->title == target) {
			cout << "The movie " << target << " has been found in the list. " << endl;
			return pointer;
		}
		else{
			pointer=pointer->next;
		}
	}
	
	cout << "The movie " << target << " has NOT been found in the list. " << endl;
	
	return pointer;
	
}

// This function searches through the years and 
// finds whether or not the year that the user
// is searching for is in the list. 
Movie* Movie::search(int target){
	
	Movie* pointer=this;
	
	while(pointer != NULL){
	
		if(pointer->year == target) {
			cout << "The year " << target << " has been found in the list. " << endl;
			return pointer;
		}
	
		else{
			pointer=pointer->next;
		}
	}
	
	cout << "The year " << target << " has NOT been found in the list. " << endl;
	
	return pointer;
	
}
