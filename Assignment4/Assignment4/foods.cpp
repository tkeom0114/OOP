#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include "foods.h"

using namespace std;

int Food::count = 0;
int Food::minCount = 0;
int Food::correct = 0;

Food::Food (void)
{
    for(int i=0;i<7;i++)
        needIngredients[i]=-1;
}
void Food::putIngredient (int ingredient)
{
    string message[7]={
        "base [Pizza Dough]","ingredient [Pepperoni]","ingredient [Potato]",
        "ingredient [Shrimp]","base [Espresso]","ingredient [Water]","ingredient [Milk Foam]"
    };
    if (ingredient == DOUGH || ingredient == ESPRESSO)
    {
        if(needIngredients[DOUGH] == 0)
            cout << "[Wrong] You already added " << message[0] << endl;        
        else if(needIngredients[ESPRESSO] == 0)
            cout << "[Wrong] You already added " << message[4] << endl;  
        else if(needIngredients[ingredient] == -1)
            cout << "[Wrong] Wrong Base" << endl;
        else
        {
            cout << "You added "<< message[ingredient] << endl;
            needIngredients[ingredient]--;
        }     
    }
    else
    {
        if(needIngredients[DOUGH] == 1 || needIngredients[ESPRESSO] == 1)
            cout << "[Wrong] Select Base First" << endl;
        else if(needIngredients[ingredient] == -1)
            cout << "[Wrong] You should not add " << message[ingredient] << endl;
        else if(needIngredients[ingredient] == 0)
            cout << "[Wrong] You already added " << message[ingredient] << endl;
        else
        {
            cout << "You added "<< message[ingredient] << endl;
            needIngredients[ingredient]--;
        } 
    }
    count++;
}

int Food::getCorrect (void)
{
    return correct;
}

int Food::getCount (void)
{
    return count;
}

int Food::getMinCount (void)
{
    return minCount;
}

void Food::increaseMinCount (void)
{
    minCount++;
}

Food::~Food (void)
{
    bool success = true;
    for(int i=0;i<7;i++)
        if(needIngredients[i] == 1)
            success = false;
    if(success)
        correct++;   
}

Pizza::~Pizza (void)
{
    increaseMinCount();
}

Coffee::~Coffee (void)
{
    increaseMinCount();
}

void Pepperoni::printName (void)
{
    cout << "PepperoniPizza\t";
}

Pepperoni::~Pepperoni (void)
{
    increaseMinCount();
}

void Potato::printName (void)
{
    cout << "PotatoPizza\t";
}

Potato::~Potato (void)
{
    increaseMinCount();
}

void Shrimp::printName (void)
{
    cout << "ShrimpPizza\t";
}

Shrimp::~Shrimp (void)
{
    increaseMinCount();
}

void Americano::printName (void)
{
    cout << "Americano\t";
}

Americano::~Americano (void)
{
    increaseMinCount();
}

void Macchiato::printName (void)
{
    cout << "Macchiato\t";
}

Macchiato::~Macchiato (void)
{
    increaseMinCount();
}