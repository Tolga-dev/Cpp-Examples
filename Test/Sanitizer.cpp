#include <iostream>
#include <typeinfo>
#include <memory>
#include <map>

void f()
{
    std::map<char, int> map;
    map.emplace('a',6);
    map.insert(std::pair<char,int>('b',1));
    map.insert_or_assign('n',8);
    map.try_emplace('c');

    for(auto &a : map)
        std::cout << a.first << " " << a.second << std::endl;
}

template<typename bar>
bar Sum(bar a, bar b)
{
    return a + b;
}


class bar_rule_three{
    int *val;
    bar_rule_three() = default;
    ~bar_rule_three();

    bar_rule_three(const bar_rule_three &);
    bar_rule_three(bar_rule_three&&);
    bar_rule_three &operator==(const bar_rule_three &);
    bar_rule_three &operator=(bar_rule_three &&);
    
};

bar_rule_three::~bar_rule_three(){ val = nullptr; }

int main()
{


}

