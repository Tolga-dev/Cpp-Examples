#include <iostream>
#include <map>

void memberF()
{
    std::multimap<int, int> x
            {
                    {1,1},
                    {2,2}
            },y,z;
    const auto w = { std::pair<const int , int> {4,4}};
    z = w;
    y = std::move(z);
}
void iterators()
{
    auto showNode = [](const auto& node)
    {
        std::cout << node.first << " " << node.second << '\n';
    };
    std::multimap<std::size_t , std::string> nmap;
    nmap.insert({sizeof(int), "int"});
    nmap.insert({sizeof(int), "int"});
    nmap.insert({sizeof(int), "int"});
    showNode(*nmap.begin());
    std::for_each(nmap.begin(),nmap.end(), [&](const auto& n){ showNode(n);});
    std::for_each(nmap.rbegin(),nmap.rend(), [&](const auto& n){ showNode(n);});
    std::for_each(nmap.crbegin(),nmap.crend(), [&](const auto& n){ showNode(n);});

}
void modifitiar()
{
    std::multimap<int, char> cnt
            {
                    {1,'a'},
                    {1,'a'},
                    {1,'a'}
            };
    auto print = [](const auto& n)
    {
        std::cout << n.first << " " << n.second << std::endl;
    };
    std::for_each(cnt.begin(), cnt.end(), print);
    std::cout << cnt.size() << std::endl;
    cnt.clear();
    std::cout << cnt.size() << std::endl;
    std::for_each(cnt.begin(), cnt.end(), print);

    cnt.insert(decltype(cnt)::value_type(5, 'n'));
    cnt.insert(std::pair{6,'d'});
    cnt.insert({7,'b'});
    cnt.insert({{7,'b'},{77,'sb'}});
    std::for_each(cnt.begin(), cnt.end(), print);
    cnt.clear();

    cnt.emplace(std::make_pair(5,'x'));
    cnt.emplace(5,'x');
    std::for_each(cnt.begin(), cnt.end(), print);
    cnt.clear();

    auto it = cnt.end();
    it = cnt.emplace_hint(it, 5,'s');
    it = cnt.emplace_hint(it, 5,'s');
    it = cnt.emplace_hint(it, 5,'s');
    cnt.emplace_hint(it, 55,'b');
    cnt.erase(it);
    std::cout << cnt.count(5) << std::endl;
    auto f = cnt.find(55);
    cnt.erase(f);

    std::for_each(cnt.begin(), cnt.end(), print);
    cnt.clear();
}
int main()
{











    return 0;
}