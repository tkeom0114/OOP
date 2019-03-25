#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

enum ingredients{
	DOUGH = 0,
    PEPPERONI,
    POTATO,
    SHRIMP,
    ESPRESSO,
    WATER,
    MILKFOAM
};

class Food{ //Abstract base class
    private:
static int minCount; //최소 선택 횟수를 나타낸다.
        static int count;  //플레이어가 한 선택 횟수를 나타낸다.
        static int correct;  //올바르게 조리한 요리의 개수를 나타낸다.
    protected:        
        int needIngredients[7]; //요리에 필요한 재료인지 나타낸다. 1이면 필요한 것이고, 0이면 이미 들어간 재료이고, -1이면 필요 없는 재료이다.
    public:
        Food (); //Food의 Constructor로 needIngredients를 모두 -1로 초기화 시킨다.
        virtual ~Food (void); //Food의 destructor로 모든 재료가 들어간 경우 correct를 1증가시키고, 해당 요리를 제거한다.
        virtual void printName (void) = 0; //pure virtual method
        void putIngredient (int); //번호에 해당하는 재료를 넣는다. 올바를 재료를 넣은 경우 needIngredients[int]를 0으로 만들고 그렇지 않으면 에러 메시지를 출력한다.
        static int getCorrect (void); //correct를 return한다.
        static int getCount (void); //count를 return한다.
        static int getMinCount (void); //mincount를 return한다.
        static void increaseMinCount (void); //mincount를 1증가시킨다.
};


class Pizza: public Food{
    public:
        Pizza () : Food (){needIngredients[DOUGH] = 1;} //Dough가 필요함
         ~Pizza (void);//Pizza의 distructor로 mincount를 1증가
        virtual void printName (void) = 0; //pure virtual method
};

class Coffee: public Food{
    public:
        Coffee () : Food (){needIngredients[ESPRESSO] = 1;} //Espresso가 필요함
        ~Coffee (void); //Coffee의 distructor로 mincount를 1증가
        virtual void printName (void) = 0; //pure virtual method
};

class Pepperoni: public Pizza{
    public:
        Pepperoni () : Pizza (){needIngredients[PEPPERONI] = 1;} //Pepperoni가 필요함
        ~Pepperoni (void); // Pepperoni 의 distructor로 mincount를 1증가
        virtual void printName (void); //Pepperoni의 이름 출력
};

class Potato: public  Pizza{
    public:
        Potato () :  Pizza (){needIngredients[POTATO] = 1;} //Potato가 필요함
        ~Potato (void); // Potato 의 distructor로 mincount를 1증가
        virtual void printName (void);  //Potato의 이름 출력
};

class Shrimp: public  Pepperoni{
    public:
        Shrimp () :  Pepperoni (){needIngredients[SHRIMP] = 1;} // Shrimp가 필요함
        ~Shrimp (void); // Shrimp의 distructor로 mincount를 1증가
        virtual void printName (void); // Shrimp의 이름 출력
};

class Americano: public  Coffee{
    public:
        Americano () :  Coffee (){needIngredients[WATER] = 1;;}  // Water가 필요함
        ~Americano (void); // Americano의 distructor로 mincount를 1증가
        virtual void printName (void); // Americano의 이름 출력
};

class Macchiato: public  Coffee{
    public:
        Macchiato () :  Coffee (){needIngredients[MILKFOAM] = 1;;} // Milk Foam이 필요함
        ~Macchiato (void); // Macchiato의 distructor로 mincount를 1증가
        virtual void printName (void); // Macchiato의 이름 출력
};