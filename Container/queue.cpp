#include <iostream>
#include <queue>

void constructer()
{
    std::queue<int> c;
    c.push(31);
    c.push(31);
    c.push(31);
    std::cout << c.size() << std::endl;

    std::queue<int> d(c);
    std::cout << d.size() << std::endl;
    d = c;

    d = std::move(c);
}
int main()
{
    auto print = [](std::queue<int>& a){
        for(; !a.empty() ; a.pop())
            std::cout << a.back() << " ";
        std::cout << std::endl;
    };


    std::vector<int> a {1,23,132,1,3,2};
    std::queue<int> q;
    std::queue<int> qx;
    qx.push(23);

    for(auto i : a)
        q.push(i);

    std::cout<<q.front() << " " << q.back() << std::endl;
    std::cout << q.empty() << " " << q.size() << std::endl;
    q.pop();

    print(q);
    print(qx);

    
    q.swap(qx);
    print(q);
    print(qx);



    return 0;
}