#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Word{//일반 단어
    private:
        int line;//단어가 위차한 행
        int position;//단어가 위치한 열
        string word;//단어
        bool isWord;//object가 derived인지 base인지 알려줌
        static int hp;//플레이어의 체력
        static int score;//플레이어의 점수
    protected:        
        static void setHP (int);
        static void setScore (int);
    public:
        Word (string a,int b,int c)
        {word = a;line = b;position = c;isWord = true;}
        virtual ~Word (void);//단어가 사라지면서 1점 획득
        virtual void printWord (void);//각 단어의 종류에 따라 단어 출력
        string getWord(void);
        int getLine(void);
        int getPosition(void);
        void setIsWord(bool);
        virtual bool getNext(void);
        virtual int getCount(void);
        static int getHP (void);
        static int getScore (void);
};

class RecoveryWord: public Word{//회복 단어
    private:
    public:
        RecoveryWord (string a,int b,int c) : Word (a,b,c){setIsWord(false);}
         ~RecoveryWord (void);//단어가 사라지면서 체력 10과 1점 획득
        virtual void printWord (void);
};

class BombWord: public Word{//폭탄 단어
    private:
    public:
        BombWord (string a,int b,int c) : Word (a,b,c){setIsWord(false);}
        ~BombWord (void);//단어가 사라지면서 체력 20감소, 2점 감소
        virtual void printWord (void);
};

class CompleteRecoveryWord: public Word{//완전 회복 단어
    private:    
        int count;//word의 남은 출력횟수
        bool sucide;//count가 다돼서 없어지는지 알려주는 flag
        bool isComRecover;//죽음의 폭탄과 완전회복을 구별하는 flag
    public:
        CompleteRecoveryWord (string a,int b,int c) : Word (a,b,c){setIsWord(false);count = 3;sucide = false;isComRecover = true;}
        ~CompleteRecoveryWord (void);//입력해서 사라진 경우 체력 100
        void minusCount (void);
        bool getSucide (void);
        void setIsComRecover (bool);
        virtual int getCount (void);
        virtual void printWord (void);
        virtual bool getNext(void);
};

class DeathlyBombWord: public  CompleteRecoveryWord{//죽음의 폭탄 단어
    public:
        DeathlyBombWord (string a,int b,int c) :  CompleteRecoveryWord (a,b,c){setIsWord(false);setIsComRecover(false);}
        ~DeathlyBombWord (void);//입력해서 사라진 경우 체력 0
        virtual void printWord (void);
};

