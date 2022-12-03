#include <algorithm>
#include <array>
#include <cstdio>
#include <numeric>
#include <span>
#include <vector>
#include <bitset>
#include <iostream>
#include <typeinfo>
#include <unordered_set>


template<class T>
class Observer
{
public:
        Observer() { std::cout << " Observer " << std::endl;}
        virtual void notify() = 0;
};

class Obs : public Observer<int>
{
public:
    Obs() { std::cout << " Obs " << std::endl;}
    virtual void notify() override { std::cout << " Observer Con " << std::endl; }
};



class subject
{
public:
        inline subject(int id) : subID(id){ std::cout << " Subject " << std::endl;  }

        inline void Job()
        {
            for(int i = 0; i < 10000 ; i++)
                for(int j = 0; i < 10000 ; i++);
            std::cout << " Job is done! " << std::endl;
            notify_observers();
        }

        inline void register_Ob(Observer<int>& o)
        {
            n.insert(&o);
        }
        inline void notify_observers()
        {
            for(auto& o : n)
            {
                o->notify();
            }
        };
private:
    std::unordered_multiset<Observer<int>*> n;
    int subID;
};

int main()
{
    Obs obs;

    subject sub(1);
    sub.register_Ob(obs);
    sub.register_Ob(obs);
    sub.register_Ob(obs);
    sub.Job();
}

