#include <bits/stdc++.h>
/// Smart Pointers
///  g++ main.cpp -std=c++20 -o main -fsanitize=address -Wall



template<class T>
class smart_ptr{
    T* p;

public:
    explicit smart_ptr(T* ptr = nullptr) : p(ptr) {}

    ~smart_ptr(){ delete p; }

/*    smart_ptr(smart_ptr& a)
    {
        p = a.p;
        a.p = nullptr;
    }
    smart_ptr& operator=(smart_ptr& a)
    {
        if(&a == this) return *this;
        delete p;
        p = a.p;
        a.p = nullptr;
        return *this;
    }*/

    T& operator*() const { return *p; }
    T* operator->() const { return p; }

};

class Resource
{
public:
    Resource() { std::cout << this << " : Foo ctor\n"; }
    Resource(const Resource&) { std::cout << "Foo copy ctor\n"; }
    Resource(Resource&&) { std::cout << "Foo move ctor\n"; }
    ~Resource() { std::cout << this <<" : ~Foo dtor\n"; }
};

void f()
{
    smart_ptr<Resource> ptr(new Resource);

    int x;

    std::cin >> x;

    if(x == 0) throw; // if x == 0, r cannot be deleted!

    std::cout << x << std::endl;

}

void pass(std::unique_ptr<Resource> a)
{
    std::cout << a.get() << std::endl;
}

int main()
{
    {
        std::unique_ptr<Resource> p (new Resource);
        std::unique_ptr<Resource> p2 = std::move(p);
        std::cout << p2.get() << " " << p.get() << std::endl;
    }

    //g++ main.cpp -std=c++11 -o main -fsanitize=address -Wall -Wextra
/*#if (__cplusplus < 201703L)
        {
        std::cout << " D " << std::endl;
        std::auto_ptr<Resource> u(new Resource);
        std::unique_ptr<Resource> p(std::move(u));
//        std::unique_ptr<Resource> y(new Resource);
    }
#endif*/

    {
       /* auto x = std::make_unique<Resource>();
        pass(std::move(x));
        std::cout << &x << " ";*/
    }

    {
/*
        std::unique_ptr<Resource> o = std::make_unique<Resource>();
        auto i = *o;
        std::cout << &i << " " << &o  << " " << o.get() << std::endl;
*/

    }

    {

/*
        Resource *rs = nullptr;
        std::unique_ptr<Resource> ni2(rs);
        std::unique_ptr<Resource> ni3(rs);
        std::cout << &ni2 << " " << &ni3 <<std::endl;
*/
    }

    {
//        std::unique_ptr<int> ni(new int);
    }
    {
    smart_ptr<Resource> res(new Resource);
    smart_ptr<Resource> res2(res);
    }
    {
//    f();
    }




}


