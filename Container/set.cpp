#include <iostream>
#include <set>


void setConstructor()
{
    std::set<std::string> a{"donkey"};
    a.insert("pust");
    a.insert("tezek");

// iterator constructor
//    std::set<std::string> b(a.find("pust"), a.end());

    //copy constructor
//    std::set<std::string> c(a);
//    c.insert("horse");

    //move constructor
    std::set<std::string> c(std::move(a));

    for(auto& str : c)
        std::cout << str << std::endl;

    for(auto& str : a)
        std::cout << str << std::endl;

}


void print(auto const& container)
{
    auto size = std::size(container);
    for(auto const& element : container)
        std::cout << element << std::endl;
}
void operators()
{
    std::set<int> x {1,2,3},z;
    const auto w =  {1,2,3};
    print(w);
    print(x);
    z = w; // copy
    x = std::move(w);
    print(w);
    print(x);

}


void iterators()
{
    std::set<int> x {1,2,3};

    std::cout << *x.begin() << std::endl;
    std::cout << *x.cbegin() << std::endl;

    std::cout << *x.end() << std::endl;
    std::cout << *x.cend() << std::endl;

    std::cout << *x.rbegin() << std::endl;
    std::cout << *x.crend() << std::endl;

}


void capacity()
{
    std::set<std::string> cap = {"tol"};
    cap.insert("lol");

    std::cout << cap.empty() << std::endl;
    std::cout << cap.size() << std::endl;
    std::cout << cap.max_size() << std::endl;
}


void modifiers()
{
    std::set<int> a = {23,2,3,223};
    print(a);
    a.clear();
    print(a);
    {


    auto print = [&]()
    {
        for(int n : a)
            std::cout << n << std::endl;
    };
    print();
    std::cout << a.erase(23) << std::endl;
    print();

    std::set<int> b = {3,142,903};

    auto i1 = std::next(b.begin());
    auto i2 = std::next(a.begin());

    const int& ref1 = *(a.begin());
    const int& ref2 = *(b.begin());

    std::cout << *i2 << std::endl;
    std::cout << *i1 << std::endl;
    std::cout << ref2 << std::endl;
    std::cout << ref1 << std::endl;

    b.swap(a);

    }

    std::set<int> cont {0,1,2,3};
    auto nh = cont.extract(0);
    nh.value() = 31;
    cont.insert(std::move(nh));
    print(cont);

    cont.merge(a);
    print(cont);

}

void lookup()
{
    {
        std::set<int> a = {1,2,3,4};
        auto i = a.equal_range(0);
        auto j = a.equal_range(32132);
        auto k = a.lower_bound(1);
        auto l = a.upper_bound(1);
        std::cout << *i.second << std::endl;
        std::cout << *i.first << std::endl;
        std::cout << *j.second << std::endl;
        std::cout << *j.first << std::endl;
        std::cout << *k << std::endl;
        std::cout << *l << std::endl;
    }
    std::set<int> a  = {1,1,2,2,3,3,3};
    std::cout << a.count(1) << std::endl;
    std::cout << a.contains(1) << std::endl;
   // auto ng = a.find(2);

   auto comp = a.key_comp();
   auto vcomp = a.value_comp();
   std::cout << comp(1,5) << std::endl;
   std::cout << vcomp(1,5) << std::endl;


}

int main()
{




}
