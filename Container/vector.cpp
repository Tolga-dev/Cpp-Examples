#include <iostream>
#include <vector>
#include <chrono> // time

struct VectorMy
{

    static void f()
    {
        std::vector<int> v{ 1, 5 , 9, 7}, c{2,6,10,8};
        v.push_back(26);
        v.push_back(13);

        v.swap(c);

        for(int i : v)
            std::cout << i << std::endl;

        v.clear();

        for(int i : v)
            std::cout << i << std::endl;
        std::cout << v.size() << std::endl;

        v = c;

        for(int i : v)
            std::cout << i << std::endl;
        std::cout << v.size() << std::endl;

        v.assign(v.size(), 'b');

        for(int i : v)
            std::cout << i << std::endl;
    }
    static void VectorReverse()
    {
        using namespace std;
        vector<int> v2;
        ssize_t size;

        v2.reserve(25);

        for (int i = 0; i < 25; ++i) {
            v2.emplace_back(i);
            if (size != v2.capacity()) {
                size = v2.capacity();
                cout << "Expanding vector v2 to hold " << size
                     << " elements" << endl;
            }
        }
    }
    static void Shrink_to_fit()
    { //Requests the removal of unused capacity.
        std::vector<int> a;

        cap(a);
        a.resize(100);
        cap(a);
        a.resize(50);
        cap(a);
        a.shrink_to_fit();
        cap(a);
        for (int i = 1000; i < 1300; ++i)
            a.push_back(i);
        cap(a);
        a.clear();
        cap(a);
        a.shrink_to_fit();
        cap(a);

    }
    static void EraseVoid()
    {
        std::vector<int> erased {0,1,2,3};
        cap(erased);

        erased.erase(erased.begin());
        cap(erased);

        erased.erase(erased.begin(), erased.end());
        cap(erased);

    }
    static void insertF()
    {
        std::vector<int> b(3,100);
        cap(b);
        b.insert(b.begin(),3,200);
        b.emplace(b.begin(),5);
        cap(b);
        b.resize(9,5);
        cap(b);
        b.pop_back();
        b.pop_back();
        b.pop_back();
        cap(b);

    }
    static void elementAccessFunctions()
    {
        std::vector<long long> a = {1,5,6,54,65,654,654};
        std::vector<long long> b = {};
        std::cout << a.at(1) << std::endl;
        std::cout << a[0] << std::endl;
        std::cout << a.front() << std::endl;
        std::cout << a.back() << std::endl;
        std::cout << *a.begin() << *a.cbegin() << std::endl;
        std::cout << *a.end() << *a.cend() << std::endl;
        std::cout << *a.rbegin() << *a.crbegin() << std::endl;
        std::cout << *a.rend() << *a.crend() << std::endl;
        std::cout << a.empty() << std::endl;
        std::cout << a.size() << std::endl;
        std::cout << a.max_size() << std::endl;
        std::cout << a.capacity() << std::endl;
        b.swap(a);
        std::cout << a.capacity() << std::endl;

    }
    static void erases()
    {
        std::vector<int> a = {1,5,6,54,65,654,654};
        a.erase(a.begin(), a.end() - 5);
        cap(a);
    }


    static void cap(std::vector<int> b)
    {
        std::cout << b.capacity() << std::endl;
        for (const int x: b) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }


};

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& b)
{
    s.put('[');
    char comma[3] = {'\0',' ', '\0'};
    for(const auto& e : b)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

int main()
{
    std::vector<std::string> word {"a","asd","asdfb"};
    std::cout << "new : " << word << '\n';
    VectorMy::erases();


}