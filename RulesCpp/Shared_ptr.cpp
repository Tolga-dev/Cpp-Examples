#include <bits/stdc++.h>

/// shared ptr
template<class T>
class Shared_ptr
{
    T *s_ptr;
public:
    Shared_ptr(T *ptr = nullptr) : s_ptr(ptr){}

    ~Shared_ptr(){delete s_ptr;}

    Shared_ptr(Shared_ptr& a)
    {
        s_ptr = a.s_ptr;
        a.s_ptr = nullptr;
    }

    Shared_ptr& operator=(Shared_ptr& sharedPtr)
    {
        if(&sharedPtr == nullptr) return *this;
        delete s_ptr;
        s_ptr = sharedPtr.s_ptr;
        sharedPtr.s_ptr = nullptr;
        return *this;
    }

    T& operator*() const { return *s_ptr; }
    T* operator->() const { return s_ptr; }

};

struct SharedStruct
{

    SharedStruct()= default;
    ~SharedStruct()=default;
};

int main()
{

    {
/*
        std::shared_ptr<int> m2(new int,[](int *p){ return p; },std::allocator<int>());
        std::shared_ptr<SharedStruct> m3(new SharedStruct,[](SharedStruct *p){ return p; },std::allocator<SharedStruct>());
*/
    }

    {
        /*std::shared_ptr<SharedStruct> s = std::make_shared<SharedStruct>();
        std::shared_ptr<SharedStruct> s2 = s;

        std::shared_ptr<SharedStruct> m = std::make_shared<SharedStruct>();
        std::cout << s.use_count() << " " << s2.use_count() << " " << m.use_count() << std::endl;
        std::cout << m.use_count() << std::endl;
        */
    }

    {
/*
        Shared_ptr<SharedStruct> st(new SharedStruct);
        Shared_ptr<SharedStruct> st2 = st;
        std::cout << &st2 << std::endl;
        std::cout << &st << std::endl;
*/
    }
    {
/*
        std::shared_ptr<SharedStruct> sp(new SharedStruct);
        std::shared_ptr<SharedStruct> sp2 = sp;
*/
    }


}


