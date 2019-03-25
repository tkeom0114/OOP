#include <iostream>
#include <list>
#include <algorithm>
#include "movie.h"
#include "category.h"
//Movie의 constructor
Movie::Movie (string _name, string _genre, string _source,double _production,double _gross,double _rating)
{
    this->name = _name;
    this->category[GENRE] = _genre;
    this->category[SOURCE] = _source;
    this->values[0] = _production;
    this->values[1] = _gross;
    this->values[2] = _rating;
}

string Movie::getName (void)
{
    return this->name;
}
//입력값에 따라 genre나 source를 return한다.
string Movie::getCategory (int category)
{
    return this->category[category];
}
//입력값에 따라 production,gross,rating중 하나를 return한다.
double Movie::getValue (int figure)
{
    return this->values[figure];
}