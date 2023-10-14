#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Number
{
    static Number *instance;
    int data;

public:
    Number() { data = 0; }
    static Number *getInstance()
    {
        if(!instance) instance = new Number();
        return instance;
    }
    int getData() { return this->data; }
    void setData(int _data) { this->data = _data; }

};

Number *Number::instance = 0;

int main()
{
    Number *s = s->getInstance();
    std::cout << s->getData() << std::endl;
    s->setData(31);
    std::cout << s->getData() << std::endl;

}