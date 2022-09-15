#include <iostream>
#include <unordered_set>
#include <set>

std::ostream& operator<< (std::ostream& os, std::unordered_set<int> const& s)
{
    for(int i : s)
        os << i << ' ';
    return os << std::endl;
}

template<class T>
T cmerge(T a, T b)
{
    T t(a);
    t.insert(b.begin(),b.end());
    return t;
}
void memberF()
{
    std::unordered_set<std::string> f = {"a","b","c"};
    std::unordered_set<std::string> thrd = {"k","l","m"};
    std::unordered_set<std::string> fourth(f);
    std::unordered_set<std::string> fifth(cmerge(thrd, fourth));

    for(const std::string& x : fifth)
        std::cout << " " << x;
}


void iterators()
{
    std::unordered_set<int> f
            {
                    1,
                    2,
                    5,
                    3
            };

    std::cout << " " << *f.cbegin() << std::endl;
    for(auto it = f.cbegin(); it != f.cend() ; it++)
        std::cout << " " << *it << std::endl;
}

void modifiers()
{
    std::unordered_set<int> us{1, 2, 3};

    auto print = [](const int& n) { std::cout << " " << n; };

    std::for_each(us.begin(), us.end(), print);
    us.clear();
    std::for_each(us.cbegin(), us.cend(), print);

    std::unordered_set<int> num = { 1, 2, 3};
    std::unordered_set<int> n = { 14, 23, 23};

    std::cout << num ;

    auto p = num.insert(1);
    num.insert(p.first, 0);
    num.insert(n.begin(), n.end());

    std::cout << num ;

    std::unordered_set<int> othern = {9,8};
    auto node = othern.extract(othern.find(9));
    num.insert(std::move(node));
    num.emplace_hint(p.first);
    num.emplace(node.value());
    num.erase(p.first);
    auto a = num.equal_range(14);

    auto nb = num.max_bucket_count();
    std::cout << nb << std::endl ;
}
void hashPolicy()
{
    std::unordered_set<int> s;
    s.rehash(31);
    s.reserve(1);
    std::cout << s.size() << std::endl;
    std::cout << s.bucket_count() << std::endl;
    std::cout << s.load_factor() << std::endl;
    std::cout << s.max_load_factor() << std::endl;

    std::unordered_set<std::string> myset;

    std::unordered_set<std::string>::hasher fn = myset.hash_function();

    std::cout << "that: " << fn ("that") << std::endl;
    std::cout << "than: " << fn ("than") << std::endl;
}

int main ()
{


    return 0;
}