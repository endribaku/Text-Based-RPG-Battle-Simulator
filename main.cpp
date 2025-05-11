#include <iostream> 
#include <string>
#include <vector>
using namespace std; 

class Ability;
class Inventory;
class Hero;
class Enemy;
class Item;

class Character {
    private:
        string name;
        int hp;
        int attack; 
        int defense;
    public:
        Character(string n, int h, int a, int d): name(n), hp(h), attack(a), defense(d) {};
        virtual void takeDamage(int damage) = 0;
        virtual void useAbility(Ability& ability) = 0;
        virtual void useAttack(Character& target) = 0;
        bool isAlive() {
            return hp > 0;
        }
};

class IUsable {
    virtual void use() = 0;
};

class Item: public IUsable {
    private:
        string name;
    public:
        virtual void use() = 0;
};

class Ability: public IUsable {
    private: 
        string name;
    public: 
        virtual void use() = 0;
};

class Inventory {
    private:
    vector<Item*> items;
    const int max_capacity = 10;

    public:
    void addItem(Item& item);
    void removeItem(int index);
    void useItem(int index);
};

class Hero: public Character {
    private:
        Inventory inv;
        int level;
        int xp;
    public:
        Hero(string n, int h, int a, int d): Character(n,h,a,d), inv(), level(1), xp(0) {};
};




int main()
{

}