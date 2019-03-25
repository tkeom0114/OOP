#ifndef CATEGORY_H
#define CATEGORY_H

#include <list>
#include <iostream>
#include "movie.h"

using namespace std;
//genre,source 모두 Category class로 저장한다.
class Category{
    private:
        list<Category*> listOfSecondCategory;
        list<Movie*> listOfMovie;
        string category;
        int numOfMovies;
        double valuesOfCategory[3][4];
    public:
        Category (Movie,int,const bool);
        void addInCategory (Movie,int,const bool);
        void deleteInCategory (Movie,int,const bool);
        string getCategory (void);
        double getValue (int,int);
        int getNumOfMovies (void);
        list<Category*> &getList(void);
};

enum categories{
	GENRE = 0,
	SOURCE
};

//이 함수들은 Category method와 main program에서 모두 사용되기 때문에 category.cpp에 정의하고, 헤더에 올린다.
void addMovieInList (list<Category*> *listOfCategory,Movie movie,int selectCategory,const bool doingRecursive);
void deleteMovieInList (list<Category*> *listOfCategory,Movie movie,int selectCategory,const bool doingRecursive);

#endif