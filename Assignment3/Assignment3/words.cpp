#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include "words.h"

using namespace std;

int Word::hp = 100;
int Word::score = 0;

int Word::getHP (void)
{
    return hp;
}
int Word::getScore (void)
{
    return score;
}

void Word::setHP (int newHP)
{
    hp = newHP;
}
void Word::setScore (int newScore)
{
    score = newScore;
}

void Word::printWord (void)
{
    cout << word;
}

string Word::getWord (void)
{
    return word;
}

int Word::getLine (void)
{
    return line;
}

int Word::getPosition (void)
{
    return position;
}

bool Word::getNext (void)
{
    return false;
}

int Word::getCount (void)
{
    return 1;
}

void Word::setIsWord (bool newIsWord)
{
    isWord = newIsWord;
}

Word::~Word (void)
{
    if(isWord)
        score++;
}

void RecoveryWord::printWord (void)
{
    cout << "(" << getWord() << ")";
}

RecoveryWord::~RecoveryWord (void)
{
    setHP(min(getHP()+10,100));
    setScore(getScore()+1);
}

void BombWord::printWord (void)
{
    cout << "<" << getWord() << ">";
}

BombWord::~BombWord (void)
{
    setHP(getHP()-20);
    setScore(max(getScore()-2,0));
}

void CompleteRecoveryWord::minusCount (void)
{
    count--;
}

void CompleteRecoveryWord::printWord (void)
{
    cout << "((" << getWord() << "(" << count-- << ")))";
}

int CompleteRecoveryWord::getCount (void)
{
    return count;
}

bool CompleteRecoveryWord::getSucide (void)
{
    return sucide;
}

void CompleteRecoveryWord::setIsComRecover (bool setting)
{
    isComRecover = setting;
}

bool CompleteRecoveryWord::getNext (void)
{
    if(count == 0)
    {
        this->sucide = true;
        delete this;
        return true;
    }
    else
        return false;
}

CompleteRecoveryWord::~CompleteRecoveryWord (void)
{
    if(isComRecover && !sucide)
        setHP(100);
}

void DeathlyBombWord::printWord (void)
{
    cout << "<<" << getWord() << "(" << getCount() << ")>>";
    minusCount();
}

DeathlyBombWord::~DeathlyBombWord (void)
{
    if(!getSucide())
        setHP(0);
}