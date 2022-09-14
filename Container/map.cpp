#include <iostream>
#include <map>

void mapMemberClass()
{
    std::map<char, int> m =
            {
                    {'a', 1},
                    {'b', 2},
                    {'c', 3},
            };
    auto i = m.begin();
    auto j = m.rbegin();
    std::cout << i->second << std::endl;
    std::cout << j->second << std::endl;

}

template<typename key, typename value>
std::ostream& operator<<(std::ostream& os, std::map<key,value> const& m)
{
    for(auto const& p : m)
        os<< '(' << p.first << ':' << p.second << ')';
    return os<< '\n';
}
struct P{ double x, y; };
struct Comp
{
    bool operator()(const P& l, const P& k) const { return  l.x < k.x; }
};
void memberFUnction()
{
    //default constructor
    std::map<std::string, int> mapf;
    mapf["f"] = 1;
    mapf["s"] = 2;
    mapf["g"] = 3;
    std::cout << mapf << std::endl;

    //range
    std::map<std::string, int> mapg(mapf.find("s"),mapf.end());
    std::cout << mapf << std::endl;

    //copy
    std::map<std::string, int> mapc(mapf);
    std::cout << mapc << std::endl;

    //move
    std::map<std::string, int> mapm(std::move(mapf));
    std::cout << mapm << std::endl;
    std::cout << mapf << std::endl;

    std::map<P, double, Comp> mapcp = {
            { {5, -12}, 13 },
            { {3, 4},   5 },
            { {-8, -15}, 17 }
    };
    for(auto p : mapcp)
        std::cout << p.first.x << ' ' << p.first.y << ' ' << p.second << '\n';

    auto compLambda = [&mapcp](const P &l,const P &k){
        return mapcp[l] < mapcp[k];
    };
    std::map<P , double , decltype(compLambda)> mapgy(compLambda);

    mapgy.insert(std::pair<P , double>({5,7},13));
    mapgy.insert({{654,4},5});
    mapgy.insert({P{-8,4},45});

    for(auto p : mapgy)
    {
        std::cout << p.first.x << ' ' << p.first.y << ' ' << p.second << '\n';
        std::cout << mapgy.at(p.first) << '\n';
        std::cout << mapgy[p.first] << '\n';
        auto it = mapgy.begin()->first.x;
        std::cout << it << '\n';

    }

    std::map<char, int> mapat = {{'a',1},{'b',2}};
    std::cout << mapat.at('a') << std::endl;
    auto it = mapat.begin();
    std::cout << it->first << '\n';
    std::cout << mapat.begin()->first << '\n';
    std::cout << mapat.end()->first << '\n';
    std::cout << mapat.cend()->first << '\n';
    std::cout << mapat.crend()->first << '\n';
    std::cout << mapat.crbegin()->first << '\n';
    std::cout << mapat.cbegin()->first << '\n';
    std::cout << mapat.empty() << std::endl;
    std::cout << mapat.size() << std::endl;
    std::cout << mapat.max_size() << std::endl;

}

template<typename T>
void printStat(T t, bool s)
{
    std::cout << t->first << (s ? " s " : " f ");
}

void moditifiers()
{
    std::map<int, char> mapc{
            {1, 'a'},
            {2, 'b'},
            {3, 'c'},
    };

    auto print = [](std::pair<const int , char>& n)
    {
        std::cout << ' ' << n.first << ' ' << n.second << '\n';
    };
    //   std::for_each(mapc.begin(), mapc.end(), print);
    // mapc.clear();

    const auto [it, suc] = mapc.insert({5, 'c'});
    printStat(it, suc);
    {
        // const auto [it2, suc2] = mapc.insert({5, 'c'});
        const auto [it2, suc2] = mapc.insert(*it);
        printStat(it2, suc2);
    }

    std::for_each(mapc.begin(), mapc.end(), print);


}

auto print_noe = [](const auto& node)
{
    std::cout << node.first << std::endl;
};
auto print_result = [](const auto& pair)
{
    std::cout << (pair.second ? "ins" : "assig");
    print_noe(*pair.first);
};
void moditifier()
{
    std::map<std::string, std::string> mymap;
    print_result(mymap.insert_or_assign("a", "ab"));
    print_result(mymap.insert_or_assign("b", "abc"));
    print_result(mymap.insert_or_assign("c", "abcd"));
    print_result(mymap.insert_or_assign("c", "abcdf"));
    print_result(mymap.try_emplace("c", "abcdf"));
    mymap.emplace(std::make_pair("cv", "sd"));
    mymap.erase(mymap.cbegin());


    for(const auto& node : mymap)
        print_noe(node);
}

void lookup()
{
    std::map<std::string,std::string> a;
    a.insert({"a","n"});
    a.insert({"sa","dn"});
    a.insert({"sba","sn"});
    a.insert({"ba","nb"});
    std::cout << a.count("a") << std::endl;
    auto cnt = a.find("a");
    cnt->second = "asdasd";
    a.insert(std::pair(cnt->first,cnt->second));
    std::cout << a.find("a")->second << std::endl;

}
int main()
{



    return 0;
}