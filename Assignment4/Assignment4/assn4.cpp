#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include "foods.h"

using namespace std;

void printMenu (list <Food*> &listOfFoods);//모드를 선택하고 시뮬레이션을 진행한다.

int main(void)
{	
    srand((unsigned int)time(0));
    time_t begin,end;
    int selectMode;
    list <Food*> listOfFoods;//요리할 음식들의 list
    Food *newFood[5];
    cout << "<Food Truck Simulation>" << endl;
    cout << "Mode 1. Static Order List" << endl;
    cout << "Mode 2. Random Order List" << endl;
    do{//요리할 음식들을 만들어 newFood에 저장
		cout << "Choose your action: ";
    	cin >> selectMode;
    	if(cin.fail())
		{
    		cout << "[Wrong] Wrong Choose" << endl;
    		cin.clear();
		    cin.ignore(1000,'\n');
		    continue;
	    }
		if(selectMode < 1 || selectMode > 2)
    		cout << "[Wrong] Wrong Choose" << endl;
	} while(selectMode < 1 || selectMode > 2);
    if(selectMode == 1)
    {
        newFood[0] = new Pepperoni();
        newFood[1] = new Potato();
        newFood[2] = new Shrimp();
        newFood[3] = new Americano();
        newFood[4] = new Macchiato();
    }
    else
    {
        for(int i=0;i<5;i++)
        {         
            int j =rand()%5;
            if(j == 0)
                newFood[i] = new Pepperoni();
            else if(j == 1)
                newFood[i] = new Potato();
            else if(j == 2)
                newFood[i] = new Shrimp();
            else if(j == 3)
                newFood[i] = new Americano();
            else
                newFood[i] = new Macchiato();
        }
    }
    for(int i=0;i<5;i++)//음식들 list에 저장
        listOfFoods.push_back(newFood[i]);
    begin = time(NULL);//시뮬레이션 시작
    while(!listOfFoods.empty())//모든 음식들을 조리할 때 까지 시뮬레이션 진행
		printMenu(listOfFoods);
    end = time(NULL);//시뮬레이션 끝
    cout << "<Result>" << endl;//결과출력
    cout << "# of correctly provided food: " << Food::getCorrect() << endl;
    cout << "# of wrongly provided food: " << 5-Food::getCorrect() << endl;
    cout << "Minimum # of selection: " << Food::getMinCount() << endl;
    cout << "Your # of selection: " << Food::getCount() << endl;
    cout << "Time you spent: " << (int)(end-begin) << endl;
    return 0;
}

//메뉴를 출력하고 항목을 선택한다.
void printMenu (list <Food*> &listOfFoods)
{
	int selectMenu;
    cout << "<Order List>" << endl;
    cout << "[ ";
    list <Food*>::iterator iterEnd = listOfFoods.end();
	for (list<Food*>::iterator iterPos = listOfFoods.begin();iterPos != iterEnd;++iterPos)
        (*iterPos)->printName();
    cout << "]" << endl;
	cout << "<Action List>" << endl;
	cout << "1. Prepare Base [Pizza Dough]" << endl;
    cout << "2. Add ingredient [Pepperoni]" << endl;
    cout << "3. Add ingredient [Potato]" << endl;
    cout << "4. Add ingredient [Shrimp]" << endl;
	cout << "5. Prepare Base [Espresso]" << endl;
    cout << "6. Add ingredient [Water]" << endl;
    cout << "7. Add ingredient [Milk Foam]" << endl;
    cout << "8. [Provide Food]" << endl << endl;
    cout << "<User Command>" << endl;
    while(true)
    {
        do{
		    cout << "Choose your action: ";
    		cin >> selectMenu;
	    	if(cin.fail())
		    {
    			cout << "[Wrong] Wrong Choose" << endl;
	    		cin.clear();
		    	cin.ignore(1000,'\n');
			    continue;
		    }
    		if(selectMenu < 1 || selectMenu > 8)
	    		cout << "[Wrong] Wrong Choose" << endl;
	    } while(selectMenu < 1 || selectMenu > 8);
        if(selectMenu == 8)
            break;
        (*listOfFoods.begin())->putIngredient(selectMenu-1);
    }
	delete *listOfFoods.begin();//destructor호출
    listOfFoods.pop_front();//list에서 제거
}