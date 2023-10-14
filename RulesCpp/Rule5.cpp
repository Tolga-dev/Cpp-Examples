#include <iostream>
#include <string>
#include <cstring>
#include <utility>

class Rule5
{
public:
    Rule5(const char* string = ""): _name(nullptr)
    {
        if(string)
        {
            std::size_t size= std::strlen(string) + 1;
            _name = new char[size];
            std::memcpy(_name,string,size);
        }
    }
    ~Rule5() { delete[] _name; }
    Rule5(Rule5 const& rule5) : Rule5(rule5._name)
    { std::cout << " Copy Constructor" << std::endl;};

    Rule5(Rule5&& rule5) : _name(std::exchange(rule5._name, nullptr))
    { std::cout << " Move Constructor" << std::endl;};

    Rule5& operator=(const Rule5& rule5)
    {
        return *this = Rule5(rule5);
        std::cout << " Copy Assignment " << std::endl;
    };
    Rule5& operator=(Rule5&& rule5)
    {
        std::swap(_name,rule5._name);
        return *this;
        std::cout << " Move Assignment " << std::endl;
    };
    void Print()
    {
        std::cout << _name << std::endl;

    }
private:
    char* _name;
};

class Person
{

public:
    Person(const Rule5& string) : _name(string) {}

    Person(Rule5&& string) : _name(std::move(string))
    { std::cout << " Move Constructor" << std::endl;}

    void Print()
    {
        _name.Print();
    }
private:
    Rule5 _name;
};
int main()
{
    Person person(Rule5("hi"));
    Person person2(person);
    person2.Print();

}
/*

#include <bits/stdc++.h>

class Rule0
{
    Rule0() = default;

    Rule0(Rule0 const& rule0) = default;
    Rule0(Rule0&& rule0) = default;

    Rule0& operator=(Rule0 const& rule0) = default;
    Rule0& operator=(Rule0&& rule0) = default;

    ~Rule0() = default;

};

template<class T>
class unique
{
    T* m_ptr = nullptr;

public:
    explicit unique(T* ptr) : m_ptr(ptr) { std::cout <<"Constructor: " << m_ptr << std::endl;}

    ~unique()
    {
        std::cout << "Destructor: " << m_ptr << std::endl;
        if(m_ptr) delete m_ptr;
        m_ptr = nullptr;
    }

    auto operator*() const -> T { return *m_ptr; }
};



int main(void)
{

}
*/
