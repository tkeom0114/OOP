#include <iostream>
#include <list>
#include <algorithm>
#include "movie.h"
#include "category.h"

using namespace std;

void addMovieInList (list<Category*> *listOfCategory,Movie movie,int selectCategory,const bool doingRecursive);
void deleteMovieInList (list<Category*> *listOfCategory,Movie movie,int selectCategory,const bool doingRecursive);

//Category 의 constructor
Category::Category (Movie movie,int selectCategory,const bool doingRecursive)
{
    int oppositeCategory = (selectCategory+1)%2;
    this->category = movie.getCategory(selectCategory);
    this->numOfMovies = 1;
    Movie *newMovie = new Movie(movie.getName(),movie.getCategory(0),movie.getCategory(1),movie.getValue(0),movie.getValue(1),movie.getValue(2));
    this->listOfMovie.push_back(newMovie);
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 4;j++)
            this->valuesOfCategory[i][j] = movie.getValue(i);
    if(doingRecursive == true)
        addMovieInList (&this->listOfSecondCategory,movie,oppositeCategory,false);
}
//Category에 movie를 추가하고 통계치들을 전부 수정한다.
void Category::addInCategory (Movie movie,int selectCategory,const bool doingRecursive)
{
    int oppositeCategory = (selectCategory+1)%2;
    this->numOfMovies++;
    Movie *newMovie = new Movie(movie.getName(),movie.getCategory(0),movie.getCategory(1),movie.getValue(0),movie.getValue(1),movie.getValue(2));
    this->listOfMovie.push_back(newMovie);
    for(int i = 0;i < 3;i++)
    {
        this->valuesOfCategory[i][Sum] += movie.getValue(i);
        this->valuesOfCategory[i][Average] = this->valuesOfCategory[i][Sum]/this->numOfMovies;
        if(this->valuesOfCategory[i][Max] < movie.getValue(i))
            this->valuesOfCategory[i][Max] = movie.getValue(i);
        if(this->valuesOfCategory[i][Min] > movie.getValue(i))
            this->valuesOfCategory[i][Min] = movie.getValue(i);
    }
    if(doingRecursive == true)
        addMovieInList (&this->listOfSecondCategory,movie,oppositeCategory,false);
}
//Category에 movie를 제거하고 통계치들을 전부 수정한다.
void Category::deleteInCategory (Movie movie,int selectCategory,const bool doingRecursive)
{
    string nameOfMovie = movie.getName();
    int oppositeCategory = (selectCategory+1)%2;
    transform(nameOfMovie.begin(),nameOfMovie.end(),nameOfMovie.begin(),::tolower);
    this->numOfMovies--;
    list<Movie*>::iterator iterEnd = this->listOfMovie.end();
    for (list<Movie*>::iterator iterPos = this->listOfMovie.begin();iterPos != iterEnd;++iterPos)
    {
        string curName = (*iterPos)->getName();
        transform(curName.begin(),curName.end(),curName.begin(),::tolower);
        string curCategory = (*iterPos)->getCategory(oppositeCategory);
        transform(curCategory.begin(),curCategory.end(),curCategory.begin(),::tolower);
        if(curName.compare(nameOfMovie) == 0)
        {
            delete(*iterPos);
            this->listOfMovie.erase(iterPos);
            break;
        }
    }
    iterEnd = this->listOfMovie.end();
    for(int i = 0;i < 3;i++)
    {
        this->valuesOfCategory[i][Sum] -= movie.getValue(i);
        this->valuesOfCategory[i][Average] = this->valuesOfCategory[i][Sum]/this->numOfMovies;
        this->valuesOfCategory[i][Max] = this->listOfMovie.front()->getValue(i);
        this->valuesOfCategory[i][Min] = this->listOfMovie.front()->getValue(i);
        for (list<Movie*>::iterator iterPos = this->listOfMovie.begin();iterPos != iterEnd;++iterPos)
        {
            if(this->valuesOfCategory[i][Max] < (*iterPos)->getValue(i))
                this->valuesOfCategory[i][Max] = (*iterPos)->getValue(i);
            if(this->valuesOfCategory[i][Min] > (*iterPos)->getValue(i))
                this->valuesOfCategory[i][Min] = (*iterPos)->getValue(i);
        }
    }
    if(doingRecursive == true)
        deleteMovieInList (&this->listOfSecondCategory,movie,oppositeCategory,false);
}

string Category::getCategory (void)
{
    return this->category;
}
//항목과 통계의 종류를 입력받아 그 카테고리의 통계 값을 return한다.
double Category::getValue (int figure,int function)
{
    return this->valuesOfCategory[figure][function];
}

int Category::getNumOfMovies (void)
{
    return this->numOfMovies;
}

list<Category*> &Category::getList (void)
{
    return this->listOfSecondCategory;
}


//listOfCategory에 movie를 추가한다.
void addMovieInList (list<Category*> *listOfCategory,Movie movie,int selectCategory,const bool doingRecursive)
{
    string nameOfCategory = movie.getCategory(selectCategory);
    transform (nameOfCategory.begin(),nameOfCategory.end(),nameOfCategory.begin(),::tolower);
    if (listOfCategory->empty())
    {
        listOfCategory->push_back(new Category(movie,selectCategory,doingRecursive));
        return;
    }
    list<Category*>::iterator iterEnd = listOfCategory->end();
    for(list<Category*>::iterator iterPos = listOfCategory->begin();iterPos != iterEnd;++iterPos)
    {
        string cur = (*iterPos)->getCategory();
        transform(cur.begin(),cur.end(),cur.begin(),::tolower);
        if(cur.compare(nameOfCategory) == 0)
        {
            (*iterPos)->addInCategory (movie,selectCategory,doingRecursive);
            return;
        }   
        else if(cur.compare(nameOfCategory) > 0)
        {
            listOfCategory->insert(iterPos,new Category(movie,selectCategory,doingRecursive));
            return;
        } 
    }
    listOfCategory->push_back(new Category(movie,selectCategory,doingRecursive));
}
//listOfCategory에서 movie를 제거한다.
void deleteMovieInList (list<Category*> *listOfCategory,Movie movie,int selectCategory,const bool doingRecursive)
{
    string nameOfCategory = movie.getCategory(selectCategory);
    transform (nameOfCategory.begin(),nameOfCategory.end(),nameOfCategory.begin(),::tolower);
    if (listOfCategory->empty())
        return;
    list<Category*>::iterator iterEnd = listOfCategory->end();
    for(list<Category*>::iterator iterPos = listOfCategory->begin();iterPos != iterEnd;++iterPos)
    {
        string cur = (*iterPos)->getCategory();
        transform(cur.begin(),cur.end(),cur.begin(),::tolower);
        if(cur.compare(nameOfCategory) == 0)
        {
            if((*iterPos)->getNumOfMovies() == 1)
            {
                delete(*iterPos);
                listOfCategory->erase(iterPos);
                return;
            }
            (*iterPos)->deleteInCategory (movie,selectCategory,doingRecursive);
            return;
        }   
    }
    return;
}