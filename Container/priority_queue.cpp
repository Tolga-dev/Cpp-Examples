#include <iostream>
#include <queue>

void memberf()
{
    std::priority_queue<int> pq;
    pq.push(1);
    std::cout << pq.size() << std::endl;

    std::priority_queue<int> pqz {pq};
    std::cout << pq.size() << std::endl;

    std::vector<int> v {1,23,2132,132,1};
    std::priority_queue<int> pqx {std::less<int>(), v};
    pqx = pq;

    std::cout << pqx.size() << std::endl;

    for (std::cout << "pq3 : "; !pqx.empty(); pqx.pop())
    {
        std::cout << pqx.top() << ' ';
    }
    std::cout << '\n';

}

struct S
{
    int id;

    S(int i) : id{i} {std::cout << id << std::endl; }

    friend bool operator < (S const& x, S const& y) { std::cout<< ">" << std::endl; return x.id < y.id; };
    friend bool operator > (S const& x, S const& y) { std::cout<< ">" << std::endl; return x.id > y.id; };
};
void memberobjecss()
{
    S a(1),b(2);
    std::cout << (a < b) << std::endl;

    std::priority_queue<S> pq;
    std::priority_queue<S> pqx;
    pq.emplace(11);
    pqx.emplace(156);

    pqx.swap(pq);
    std::cout << pq.top().id << std::endl;
    std::cout << pqx.top().id << std::endl;

}

int main()
{



    return 0;
}