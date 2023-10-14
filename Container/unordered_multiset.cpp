#include <iostream>
#include <unordered_set>



template<class T>
T cmerge (T a, T b) { T t(a);  t.insert(b.begin(),b.end()); return t; }

void contrsuter()
{
    std::unordered_multiset<std::string> first;                                // empty
    std::unordered_multiset<std::string> second ( {"a","b","c"} );    // init list
    std::unordered_multiset<std::string> third ( {"a","f","c"} );    // init list
    std::unordered_multiset<std::string> fourth ( second );                    // copy
    std::unordered_multiset<std::string> fifth ( cmerge(third,fourth) );       // move
    std::unordered_multiset<std::string> sixth ( fifth.begin(), fifth.end() ); // range

    for (const std::string& x: sixth)
        std::cout << " " << x;
}
auto print = [](const auto& um)
{
    for(const auto& e : um)
        std::cout << e << std::endl;
    std::cout << um.size() << std::endl;
    std::cout << um.empty() << std::endl;
    std::cout << um.max_size() << std::endl;

    for(auto it = um.begin(); it != um.end() ; ++it)
        std::cout << *it << std::endl;

};

void lookmoditifiers()
{
    std::unordered_multiset<int> f = {1,2,3};
    std::unordered_multiset<int> fo = {11,22,33};
    f = fo;
    f.emplace(13);
    auto a = f.find(13);
    f.insert(a, 316);
    f.insert(a, 316312);
    f.erase(a);
    f.insert(1);
    f.emplace(1);
    std::cout <<"f" << f.count(1) << std::endl;
    std::cout <<"f" << f.contains(13) << std::endl;

    print(f);
    fo.clear();
    print(fo);

}
void bucket()
{
    std::unordered_multiset<int> arg = {1,2,3,4};
    for(const auto& a : arg)
        std::cout << a <<" "<<arg.bucket(a) << std::endl;
    for (unsigned a=0; a<arg.bucket_count(); ++a) {
        std::cout << a <<" "<<arg.bucket(a) << std::endl;
        std::cout << a <<" "<<arg.bucket_size(a) << std::endl;
    }

    std::cout << arg.bucket_count() << std::endl;
    std::cout << arg.max_bucket_count() << std::endl;
    std::cout << arg.bucket_size(1) << std::endl;

    std::cout << arg.load_factor() << std::endl;
    std::cout << arg.max_load_factor() << std::endl;

}

void policy()
{
    std::unordered_multiset<int> myums;

    std::cout << "size = " << myums.size() << std::endl;
    std::cout << "bucket_count = " << myums.bucket_count() << std::endl;
    std::cout << "load_factor = " << myums.load_factor() << std::endl;
    std::cout << "max_load_factor = " << myums.max_load_factor() << std::endl;

    std::unordered_multiset<int> arg;
    arg.rehash(2);
    for(int i = 0 ; i < 10 ; i++)
        arg.insert(i);

    std::cout << arg.bucket_count() << std::endl;

    for (unsigned a=0; a<arg.bucket_count(); ++a) {
        std::cout << a <<" "<<arg.bucket(a) << std::endl;
    }
}

int main ()
{

    return 0;
}