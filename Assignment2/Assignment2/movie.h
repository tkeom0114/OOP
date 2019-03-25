#ifndef MOVIE_H
#define MOVIE_H

#include <list>
#include <iostream>

using namespace std;

class Movie{
    private:
        string name;
	    string category[2];
	    double values[3];
    public:
        Movie (string,string,string,double,double,double);
        string getName (void);
        string getCategory (int);
        double getValue (int);
};

enum figures{
	Production = 0,
	Gross,
	Rating
};

enum functions{
	Average = 0,
	Sum,
	Max,
	Min
};
#endif