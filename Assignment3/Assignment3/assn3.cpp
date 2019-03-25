#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
#include "words.h"

using namespace std;

void createWord (list <string> &ableWordList,list <Word*> &wordList);
string printWords (list <string> &ableWordList,list <Word*> &wordList);



bool countIsZero(Word *word)//count 0인 단어들을 지우는데 사용
{
    return word->getNext();
}

bool compare(Word *a,Word *b)//list내에서 위치순대로 정렬하는 역할
{
    if(a->getLine() < b->getLine())
        return true;
    else if( ( a->getLine() == b->getLine() )&& ( a->getPosition() < b->getPosition() ) )
        return true;
    else 
        return false;
}

int main (void)
{
    string WordList[20] = {"Able","Baker","Charlie","Delta","Echo","Foxtrot","Golf","Hotel","India","Juliett","Kilo","Lima","Mike","November",
                        "Oscar","Papa","Quebec","Romeo","Sierra","Tango"};
    list <string> ableWordList;//생성할 수 있는 단어들의 list
    list <Word*> wordList;//출력되는 단어들의 list
    list <string> erasedWords;//바로 전에 지워져서 생성할 수 없는 단어들의 list
    for(int i=0;i<20;i++)
        ableWordList.push_back(WordList[i]);
    while(true)
    {
        while(wordList.size()<10)//출력되는 단어가 10개가 되도록 함
        {
            createWord(ableWordList,wordList);
        }
        while(erasedWords.size()>0)//이제는 erasedWords내의 단어들을 생성할 수 있어 모두 able로 옮김
        {
            list <string>::iterator iter = erasedWords.begin();
            ableWordList.push_back((*iter));
            erasedWords.erase(iter);
        }
        erasedWords.push_back(printWords(ableWordList,wordList));//단어들을 출력하고 입력받음
        list <Word*>::iterator iterEnd = wordList.end();
        for(list <Word*>::iterator iterPos = wordList.begin();iterPos != iterEnd;++iterPos)//count가 0인 모든 단어들을 erasedWord에 넣음
            if((*iterPos)->getCount() == 0)
                erasedWords.push_back((*iterPos)->getWord());
        wordList.remove_if(countIsZero);//count가 0인 모든 단어들을 제거
        if(Word::getHP() <= 0)//체력이 다되면 게임종료
            break;
    }
    cout << "GAME OVER! Score: " << Word::getScore()  << endl;
    return 0;
}

void createWord (list <string> &ableWordList,list <Word*> &wordList)//wordList에 단어 추가
{
    srand((unsigned int)time(0));
    int size = ableWordList.size();//able list에서 단어를 임의로 선택
    int k = rand()%size;
    int line,position;
    bool again = false;
    list <string>::iterator iter = ableWordList.begin();
    advance(iter,k);
    string word = *iter;
    ableWordList.erase(iter);
    list <Word*>::iterator iterEnd = wordList.end();
    do{//단어의 위치를 임의로 정해줌
        line = rand()%5;
        position = rand()%5;
        again = false;       
        for(list <Word*>::iterator iterPos = wordList.begin();iterPos != iterEnd;++iterPos)
            if((*iterPos)->getLine()==line && (*iterPos)->getPosition()==position)
                again = true;
    }while(again);
    int select = rand()%10;//단어의 종류를 정함
    Word *newWord;
    if(select<4)
        newWord = new Word(word,line,position);
    else if(select<6)
        newWord = new RecoveryWord(word,line,position);
    else if(select<8)
        newWord = new BombWord(word,line,position);
    else if(select<9)
        newWord = new CompleteRecoveryWord(word,line,position);
    else
        newWord = new DeathlyBombWord(word,line,position);
    wordList.push_back(newWord);//word list에 단어 추가
    wordList.sort(compare);//위치 순서대로 word list정렬
}

string printWords (list <string> &ableWordList,list <Word*> &wordList)//word list의 단어들을 보여주고 단어를 입력받음
{
    string word;
    list <Word*>::iterator iterPos = wordList.begin();
    list <Word*>::iterator iterEnd = wordList.end();
    bool again;
    do{//정해진 위치에 단어 출력
        
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(iterPos == iterEnd)
                    break;
                if((*iterPos)->getLine() == i && (*iterPos)->getPosition() == j)
                {
                    (*iterPos)->printWord();
                    cout << "\t";
                    iterPos++;
                }
                else
                    cout << "\t\t";
            }
            cout << endl;
        }
    }while(false);
    cout << "HP: " << Word::getHP() << "\t\t\t\t" << "Score: " << Word::getScore() << endl;//체력과 점수 출력
    do{//단어 입력받음
        again = true;
        cout << "Input: ";
        cin >> word;
        for(iterPos = wordList.begin();iterPos != iterEnd;++iterPos)
            if((*iterPos)->getWord() == word)
            {
                again = false;
                break;
            }
        if(again)
            cout << "Try again!" << endl;
    }while(again);
    delete (*iterPos);//입력받은 단어 제거
    wordList.erase(iterPos);
    return word;
}