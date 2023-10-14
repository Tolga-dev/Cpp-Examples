#include <bits/c++io.h>
#include <stdio.h>
#include <iostream>



using namespace std;

class Int
{
    int x;

public:
    Int(int k = 0) : x{k} { cout << " Constructor " << endl; }
    operator string()    { cout << " Conversion " << endl;  return to_string(x); }


};


int main()
{
    Int obj(97);

    string s = obj;

    string s2 = static_cast<string>(obj);
    obj  = static_cast<Int>(96);

    std::cout << s << std::endl;

}