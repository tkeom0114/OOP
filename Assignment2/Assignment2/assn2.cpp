#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include "movie.h"
#include "category.h"

using namespace std;

int printMenu (void);
void printList (void);
void addMovie (void);
void deleteMovie(void);
void pivotTable(void);
void pivotChart(void);

list <Movie*> listOfMovie;
list <Category*> listOfCategory[2];


int main(void)
{	
    while(1)
	{	
		int selectmenu = printMenu();
		if (selectmenu == 1)
			addMovie();
		else if (selectmenu == 2)
			printList();
		else if (selectmenu == 3)
			pivotTable();
		else if (selectmenu == 4)
			pivotChart();
		else if (selectmenu == 5)
			deleteMovie();
		else
			break;
	}
	listOfMovie.clear();
	for(int i=0;i<2;i++)
	{
		list <Category*>::iterator iterEnd = listOfCategory[i].end();
		for (list<Category*>::iterator iterPos = listOfCategory[i].begin();iterPos != iterEnd;++iterPos)
			delete (*iterPos);
		listOfCategory[i].clear();
	}
    return 0;
}
//메뉴를 출력하고 항목을 선택한다.
int printMenu (void)
{
	int select_menu;
	cout << "----------MENU----------" << endl;
	cout << "1. Add Movie" << endl;
    cout << "2. Print List" << endl;
    cout << "3. Pivot Table" << endl;
    cout << "4. Pivot Chart" << endl;
	cout << "5. Delete Movie" << endl;
    cout << "6. Exit" << endl;
    cout << "------------------------" << endl;
	do{
		cout << "Selection: ";
		cin >> select_menu;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		if (select_menu < 1 || select_menu > 6)
			cout << "Try Again!" << endl;
	} while (select_menu < 1 || select_menu > 6);
	return select_menu;
}
//영화를 리스트에 추가하고, pivot table구성에 필요한 값을 수정한다.
void addMovie(void)
{
	string nameOfMovie;
	string genreOfMovie;
	string sourceOfMovie;
	double productionOfMovie;
	double grossOfMovie;
	double ratingOfMovie;
	cout << "Name: ";
	cin >> nameOfMovie;
	string name = nameOfMovie;
	transform (name.begin(),name.end(),name.begin(),::tolower);
	if(!listOfMovie.empty())
	{
		list <Movie*>::iterator iterEnd = listOfMovie.end();
		for (list<Movie*>::iterator iterPos = listOfMovie.begin();iterPos != iterEnd;++iterPos)
		{
			string cur = (*iterPos)->getName();
       		transform(cur.begin(),cur.end(),cur.begin(),::tolower);
       		if(cur.compare(name) == 0)
        	{
            	cout << "Error: Movie name already exists." <<endl;
        	    return;
        	}
		}
	}
	cout << "Genre: ";
	cin >> genreOfMovie;
	cout << "Source: ";
	cin >> sourceOfMovie;
	do{
		cout << "Production: ";
		cin >> productionOfMovie;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		break;
	}while(true);
	do{
		cout << "Gross: ";
		cin >> grossOfMovie;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		break;
	}while(true);	
	do{
		cout << "Rating: ";
		cin >> ratingOfMovie;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		if (ratingOfMovie < (double)0 || ratingOfMovie > (double)10)
			cout << "Try Again!" << endl;
	}while(ratingOfMovie < (double)0 || ratingOfMovie > (double)10);
	Movie *movie = new Movie(nameOfMovie,genreOfMovie,sourceOfMovie,productionOfMovie,grossOfMovie,ratingOfMovie);
	listOfMovie.push_back(movie);
	for(int i =0;i<2;i++)
		addMovieInList (listOfCategory+i,*movie,i,true);
}
//영화를 리스트에서 제거하고, pivot table구성에 필요한 값을 수정한다.
void deleteMovie(void)
{
	if(listOfMovie.empty())
	{
		cout << "There are no movies in the list!" << endl;
		return;
	}
	string nameOfMovie;
	cout << "Name: ";
	cin >> nameOfMovie;
	transform(nameOfMovie.begin(),nameOfMovie.end(),nameOfMovie.begin(),::tolower);
	list <Movie*>::iterator iterEnd = listOfMovie.end();
	for (list<Movie*>::iterator iterPos = listOfMovie.begin();iterPos != iterEnd;++iterPos)
	{
		string curName = (*iterPos)->getName();
    	transform(curName.begin(),curName.end(),curName.begin(),::tolower);
   		if(curName.compare(nameOfMovie) == 0)
        {
			Movie cur = Movie((*iterPos)->getName(),(*iterPos)->getCategory(GENRE),(*iterPos)->getCategory(SOURCE),0,0,0);
			delete (*iterPos);
			listOfMovie.erase(iterPos);
			for(int i =0;i<2;i++)
				deleteMovieInList (listOfCategory+i,cur,i,true);
			return;
        }
	}
	cout << "This movie does not exist!" << endl;
	
}
void printList(void)
{
	cout << "Name\tGenre\tSource\tProduction\tGross\tRating" <<endl;
	if(!listOfMovie.empty())
	{
		list <Movie*>::iterator iterEnd = listOfMovie.end();
		for (list<Movie*>::iterator iterPos = listOfMovie.begin();iterPos != iterEnd;++iterPos)
			cout << (*iterPos)->getName() << "\t" << (*iterPos)->getCategory(GENRE) << "\t" << (*iterPos)->getCategory(SOURCE)
			<< "\t" << (*iterPos)->getValue(Production) << "\t" << (*iterPos)->getValue(Gross)
			<< "\t" << (*iterPos)->getValue(Rating) << endl;
	}
}
int printCategory ()
{
	int select_category;
	cout << "----------Category----------" << endl;
	cout << "1. Genre" << endl;
	cout << "2. Source" << endl;
	cout << "3. Genre and Source" << endl;
	cout << "4. Source and Genre" << endl;
	cout << "----------------------------" << endl;
	do{
		cout << "Selection: " ;
		cin >> select_category;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		if(select_category < 1 || select_category > 4)
			cout << "Try again!" << endl;
	}while (select_category < 1 || select_category > 4);
	return --select_category;
}

int printFigure ()
{
	int select_figure;
	cout << "----------Figure----------" << endl;
	cout << "1. Production" << endl;
	cout << "2. Gross" << endl;
	cout << "3. Rating" << endl;
	cout << "--------------------------" << endl;
	do{
		cout <<("Selection: ");
		cin >> select_figure;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		if(select_figure < 1 || select_figure > 3)
			cout << "Try again!" << endl;
	}while (select_figure < 1 || select_figure > 3);
	return --select_figure;
}

int printFunction ()
{
	int select_funtion;
	cout << "----------Function----------" << endl;
	cout << "1. Average" << endl;
	cout << "2. Sum" << endl;
	cout << "3. Max" << endl;
	cout << "4. Min" << endl;
	cout << "----------------------------" << endl;
	do{
		cout <<("Selection: ");
		cin >> select_funtion;
		if(cin.fail())
		{
			cout << "Try Again!" << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		if(select_funtion < 1 || select_funtion > 4)
			cout << "Try again!" << endl;
	}while (select_funtion < 1 || select_funtion > 4);
	return --select_funtion;
}
//pivot table 출력할 때 쓰인다.
void printList (list<Category*> listOfCategory,int figure,int function,const bool doingRecursive)
{
    cout.setf(ios::fixed);
    cout.precision(2);
    list<Category*>::iterator iterEnd = listOfCategory.end();
    for(list<Category*>::iterator iterPos = listOfCategory.begin();iterPos != iterEnd;++iterPos)
    {
        if(doingRecursive == false)
            cout << (*iterPos)->getCategory() << "\t" << (*iterPos)->getValue(figure,function) << endl;
        else
        {
            list<Category*>::iterator iterEnd1 = (*iterPos)->getList().end();
            for(list<Category*>::iterator iterPos1 = (*iterPos)->getList().begin();iterPos1 != iterEnd1;++iterPos1)
                cout << (*iterPos)->getCategory() << "\t" << (*iterPos1)->getCategory() << "\t" << (*iterPos)->getValue(figure,function) << endl;
        }

    }
	cout.unsetf(ios::fixed);	
}
//pivot table을 출력한다.
void pivotTable(void)
{
	int selectCategory = printCategory ();
	int selectFigure = printFigure ();
	int selectFuntion = printFunction ();
	string figures[3] = {"Production","Gross","Rating"};
	int category = selectCategory % 2;
	bool doingRecursive = (bool) (selectCategory / 2);
	if (selectCategory == 0)
		cout << "Genre\t" << figures[selectFigure] <<endl;
	else if(selectCategory == 1)
		cout << "Source\t" << figures[selectFigure] <<endl;
	else if(selectCategory == 2)
		cout << "Genre\t" << "Source\t" << figures[selectFigure] <<endl;
	else
		cout << "Source\t" << "Genre\t" << figures[selectFigure] <<endl;
	printList(listOfCategory[category],selectFigure,selectFuntion,doingRecursive);
}
//pivot chart를 출력한다.
void pivotChart(void)
{
	int selectCategory = printCategory ();
	int selectFigure = printFigure ();
	int selectFuntion = printFunction ();
	int numOfGenre = listOfCategory[GENRE].size();
	int numOfSource = listOfCategory[SOURCE].size();
	string figures[3] = {"Production","Gross","Rating"};
	string indexOfGenre[numOfGenre];
	string indexOfSource[numOfSource];
	int category = selectCategory % 2;
	bool doingRecursive = (bool) (selectCategory / 2);
	int i = 0;
	int bar;
	double min = 9876543210;
	double max = 0;	
	cout.setf(ios::fixed);
	cout.precision(2);
	if (!doingRecursive)//한 카테고리에 대해서만 분류할 때
	{
		list<Category*>::iterator iterEnd = listOfCategory[category].end();
		list<Category*>::iterator iterPos;
   		for(iterPos = listOfCategory[category].begin();iterPos != iterEnd;++iterPos)
		{
			if (min > (*iterPos)->getValue(selectFigure,selectFuntion))
				min = (*iterPos)->getValue(selectFigure,selectFuntion);
			if (max < (*iterPos)->getValue(selectFigure,selectFuntion))
				max = (*iterPos)->getValue(selectFigure,selectFuntion);
		}
		for(iterPos = listOfCategory[category].begin();iterPos != iterEnd;++iterPos)
		{
			if(category == GENRE)
				cout << (char)(65+(i++)) << "|";
			else
				cout << ++i << "|";
			if(max == min || (*iterPos)->getValue(selectFigure,selectFuntion) == max)
				bar = 20;
			else if ((*iterPos)->getValue(selectFigure,selectFuntion) == min)
				bar = 0;
			else
				bar = (int)ceil((double)20 * ((*iterPos)->getValue(selectFigure,selectFuntion) - min)/(max - min) );
			for(int j = 0;j < bar;j++)
				cout << "=";
			cout << (*iterPos)->getValue(selectFigure,selectFuntion) << endl;
		}
		cout << "----------------------------" << endl;
		i = 0;
		if(category == GENRE)
			for(iterPos = listOfCategory[category].begin();iterPos != iterEnd;++iterPos)
				cout << (char)(65+(i++)) << "| " << (*iterPos)->getCategory() << endl;
		else
			for(iterPos = listOfCategory[category].begin();iterPos != iterEnd;++iterPos)
				cout << ++i << "| " << (*iterPos)->getCategory() << endl;
	}
	else//두 카테고리 모두에 대해서 분류할 때
	{	
		list<Category*>::iterator iterPos;
		if(category == GENRE)//source의 index만듦
		{
			i = 0;
			list<Category*>::iterator iterEnd = listOfCategory[SOURCE].end();
			for(iterPos = listOfCategory[SOURCE].begin();iterPos != iterEnd;++iterPos)
				indexOfSource[i++] = (*iterPos)->getCategory();
		}	
		else//genre의 index만듦
		{
			i = 0;
			list<Category*>::iterator iterEnd = listOfCategory[GENRE].end();
			for(iterPos = listOfCategory[GENRE].begin();iterPos != iterEnd;++iterPos)
				indexOfGenre[i++] = (*iterPos)->getCategory();
		}		
		list<Category*>::iterator iterEnd = listOfCategory[category].end();
    	for(iterPos = listOfCategory[category].begin();iterPos != iterEnd;++iterPos)
		{
			list<Category*>::iterator iterEnd1 = (*iterPos)->getList().end();
            for(list<Category*>::iterator iterPos1 = (*iterPos)->getList().begin();iterPos1 != iterEnd1;++iterPos1)
			{
				if (min > (*iterPos1)->getValue(selectFigure,selectFuntion))
					min = (*iterPos1)->getValue(selectFigure,selectFuntion);
				if (max < (*iterPos1)->getValue(selectFigure,selectFuntion))
					max = (*iterPos1)->getValue(selectFigure,selectFuntion);
			}
		}
		i = 0;
		iterPos = listOfCategory[category].begin();
		while(iterPos != iterEnd)
		{
			list<Category*>::iterator iterEnd1 = (*iterPos)->getList().end();
            for(list<Category*>::iterator iterPos1 =  (*iterPos)->getList().begin();iterPos1 != iterEnd1;++iterPos1)
			{
				int j;
				if(category == GENRE)
				{
					for(j = 0; j < numOfSource; j++)
						if(indexOfSource[j] == (*iterPos1)->getCategory())
						{
							j++;
							break;
						}
					cout << (char)(i+65) << j << "|";
				}
				else
				{
					for(j = 0; j < numOfGenre; j++)
						if(indexOfGenre[j] == (*iterPos1)->getCategory())
							break;
					cout << i+1 << (char)(j+65) << "|";
				}
				if(max == min || (*iterPos1)->getValue(selectFigure,selectFuntion) == max)
					bar = 20;
				else if ((*iterPos1)->getValue(selectFigure,selectFuntion) == min)
					bar = 0;
				else
					bar = (int)ceil((double)20 * ((*iterPos1)->getValue(selectFigure,selectFuntion) - min)/(max - min) );
				for(int j = 0;j < bar;j++)
					cout << "=";
				cout << (*iterPos1)->getValue(selectFigure,selectFuntion) << endl;
			}
			i++;
			if(++iterPos == iterEnd)
				cout << "----------------------------" << endl;
			else
				cout << "  |" <<endl;
		}
		i = 0;
		if(category == GENRE)
		{
			list<Category*>::iterator iterEnd = listOfCategory[GENRE].end();
			for(iterPos = listOfCategory[GENRE].begin();iterPos != iterEnd;++iterPos)
				cout << (char)(65+(i++)) << "| " << (*iterPos)->getCategory() << endl;
			i = 0;
			iterEnd = listOfCategory[SOURCE].end();
			for(iterPos = listOfCategory[SOURCE].begin();iterPos != iterEnd;++iterPos)
				cout << ++i << "| " << (*iterPos)->getCategory() << endl;
		}
		else
		{
			list<Category*>::iterator iterEnd = listOfCategory[SOURCE].end();
			for(iterPos = listOfCategory[SOURCE].begin();iterPos != iterEnd;++iterPos)
				cout << ++i << "| " << (*iterPos)->getCategory() << endl;
			i = 0;
			iterEnd = listOfCategory[GENRE].end();
			for(iterPos = listOfCategory[GENRE].begin();iterPos != iterEnd;++iterPos)
				cout << (char)(65+(i++)) << "| " << (*iterPos)->getCategory() << endl;
		}
	}
	cout.unsetf(ios::fixed);
}
