#include <iostream>
#include <unordered_map>

void operators()
{
    std::unordered_map<std::string, std::string> smap; // empty
    std::unordered_map<std::string, std::string> ssmap({{"a","a"},{"b","b"}});
    std::unordered_map<std::string, std::string> sdssmap({{"fgda","sda"},{"b","b"}});
    std::unordered_map<std::string, std::string> fsmap(ssmap);
    ssmap.merge(sdssmap);
    std::unordered_map<std::string, std::string> ffsmap(ssmap);
    smap = ffsmap;
    for (auto& x: smap) std::cout << " " << x.first << ":" << x.second;

}

struct N{ double x, y; };
void moditifiears()
{
    N n[4] = { {1,2} , {3,4} , {5,6},{7,8} };

    std::unordered_map<N *, double> mag = {
            { n , 1},
            { n + 1 , 1 + 1},
            { n + 2 , 1 + 2},
            { n + 3 , 1 + 2},
    };
    mag.emplace(n,1);
    mag.insert(std::make_pair(n,3));
    mag.insert(std::make_pair(n,3));
    mag.insert_or_assign(n, 1);

    for(auto iter = mag.begin(); iter != mag.end(); ++iter)
    {
        auto cur = iter->first;
        cur->y = mag[cur];
    }

    mag.emplace( n + 3,3);
    mag.emplace( std::make_pair(n + 3,3));

    std::cout <<" is empty : " <<mag.empty() << std::endl;
    std::cout <<"is size : " <<  mag.size() << std::endl;
    //mag.clear();


    for(auto i : mag)
    {
        std::cout << i.first->x << std::endl;
        std::cout << i.first->y << std::endl;
        std::cout << i.second << std::endl;
        std::cout << "  " << std::endl;
    }


    std::unordered_map<std::string, std::string> amap;

    std::cout << (amap.try_emplace("a","b").second ? "yeas" : "no") <<std::endl;
    std::cout << (amap.try_emplace("a","b").second ? "yeas" : "no") <<std::endl;
    amap[amap.find("a")->second] = "1";
    std::cout << amap.at("a") << std::endl;
    std::cout << amap.count("a") << std::endl;
    std::cout << "bucket : " <<amap.bucket_count() << std::endl;
    std::cout << "size : " <<amap.size() << std::endl;
    amap.erase("a");

    amap.rehash(50);
    amap.reserve(1);
    std::cout << "bucket : " <<amap.bucket_count() << std::endl;


    for(const auto& i : amap)
        std::cout << i.first << " " << i.second <<std::endl;
    for (int i = 0; i < amap.bucket_count(); i++) {
        std::cout << amap.bucket_size(i) << " elements.\n";
    }

}
void observersa()
{
    std::unordered_map<std::string,std::string> mymap;
    std::unordered_map<std::string,std::string>::hasher fn = mymap.hash_function();

    std::cout << "this: " << fn ("this") << std::endl;
    std::cout << "thin: " << fn ("thin") << std::endl;

    std::unordered_map<int, int> imap = {
            {1,1},
            {1,1}
    };
    std::cout << imap.key_eq()(imap.begin()->first, imap.end()->first) << std::endl;
}

int main()
{

    return 0;
}