#include <iostream>

int main()
{


}



// first example
class MonsterBase
{
public:
    MonsterBase(int Attack, int Health) : health_(Attack), attack_(Attack){}
    inline auto getHealth(){ return health_; }
private:
    int health_;
    int attack_;
};

class Monster
{
public:
    Monster(MonsterBase& base) : base_(base),health_(base.getHealth()){}
    inline auto getHealth(){ return health_; }

private:
    int health_;
    MonsterBase& base_;
};
[[maybe_unused]] void attempt()
{
    MonsterBase base(100,200);
    std::cout << base.getHealth() << std::endl;

    Monster monster(base);
    std::cout << base.getHealth() << std::endl;
}





// second example
class MonsterBase1
{
public:
    MonsterBase1(MonsterBase1* parent, int Attack, int Health) :
            health_(Health),
            attack_(Attack),
            parent_(parent)
    {
        if(health_ == 0 && parent_ != NULL )  health_ = parent_->health_;
        if(attack_ == 0 && parent_ != NULL )  attack_ = parent_->attack_;
    }

    inline auto getHealth()
    {
        return health_;
        // here can be defined inside of constructor, for now it is defined in there
        /*
        if(health_ != 0 || parent_ == NULL ) return health_;
        return parent_->health_;
        */
    }


private:
    int health_;
    int attack_;
    MonsterBase1* parent_;
};

class Monster1
{
public:
    MonsterBase1& getBase() { return base_; }
    Monster1(MonsterBase1& base) : base_(base),health_(base.getHealth()){}

    inline auto getHealth(){ return health_; }

private:
    int health_;
    MonsterBase1& base_;
};

