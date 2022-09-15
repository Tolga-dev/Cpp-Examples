#include <iostream>
#include <unordered_map>

void constructers()
{
    std::unordered_multimap<std::string, int> a
            {
                    {"a" , 1},
                    {"b" , 2},
            };
    std::unordered_multimap<std::string, int> b
            {
                    {"a" , 11},
                    {"c" , 22},
            };

    std::unordered_multimap<std::string, int> c;
    c = b;
    c.insert(a.begin(), a.end());


    for(const auto& m : c)
        std::cout << m.first << std::endl;

}
void modiandLookup()
{
    auto print = [](const auto& map)
    {
        for(const auto& i : map)
        {
            std::cout << i.first << " " <<i.second << std::endl;
        }
        std::cout << map.empty() << std::endl;
        std::cout << map.size() << std::endl;
        std::cout << map.max_size() << std::endl;
        std::cout << map.count(1) << std::endl;
        std::cout << map.contains(11) << std::endl;
    };

    std::unordered_multimap<int , int> main;
    std::unordered_multimap<int , int> copy {{2,2},{1,1}};
    main.insert(copy.begin(), copy.end());
    main.emplace(std::make_pair(1,1));
    auto t = main.find(2)->first;
    auto ty = main.find(2)->second;
    main.emplace(t,ty);
    main.erase(t);

    print(main);

}

void bucket()
{
    std::unordered_multimap<int,int> m = {
            {1,2},
            {15,23},
            {541,234},
    };
    for(auto& s : m)
    {
        std::cout << m.bucket(s.first)<< " "<< s.first << std::endl;
    }
    std::cout << m.bucket_count() << std::endl;
    std::cout << m.max_bucket_count() << std::endl;

    for(int i = 0; i < m.bucket_count() ; i ++)
        std::cout << m.bucket_size(i) << std::endl;

}
void hash()
{
    std::unordered_multimap<int,int> mymap;

    std::cout << "size = " << mymap.size() << std::endl;
    std::cout << "bucket_count = " << mymap.bucket_count() << std::endl;
    std::cout << "load_factor = " << mymap.load_factor() << std::endl;
    std::cout << "max_load_factor = " << mymap.max_load_factor() << std::endl;

    std::unordered_multimap<int , int> a ;
    a.rehash(40);
    a.reserve(8);

    a.insert({1,2});
    a.insert({1,2});
    a.insert({1,2});

    for(int i = 0; i < a.bucket_count() ; i ++)
        std::cout << a.bucket_size(i) << std::endl;

    std::cout << a.bucket_count() << std::endl;

}
int main()
{
    
    return 0;
}

