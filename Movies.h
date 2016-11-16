//-------------------------------------------------
// Hannah Hopkins
// CS255
// 15 April 2015
// Movies 
// The program displays a list of movies. It also asks 
// the user for a movie or year of a movie to search for, 
// and the program tells the user if it is in the list or
// not. 
//--------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using std::ifstream;
using std::cerr;
using std::endl;
using std::string;
using std::cout;
using std::stringstream;

class Movie{
    public:
    	Movie(string inTitle, int inYear);
    	int getYear() const { return year; }
    	string getTitle() const { return title; }
    	void setTitle(string inTitle) { title=inTitle; }
    	void setYear(int inYear) { year=inYear; }
    	void setNext(Movie* pointer) { pointer=next; }
    	void append(string inTitle, int theYear);
    	Movie* search(string target);
    	Movie* search(int target);
    	void displayList();
        Movie* getNext() const { return next; }
        ~Movie();

    private:
    	string title;
    	int year;
        string data;
        Movie* next;
};

#endif 
