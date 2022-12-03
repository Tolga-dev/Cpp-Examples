#include <iostream>
#include <cstring>
#include <cstdlib>
#include <inttypes.h>

class subClass
{
public:
    int id;
    int get_id()
    {
        return id;
    }
    void set_id(int nid)
    {
        id = nid;
    }
};


class class_name : subClass {
private:
    char *c_size;
    //nothing
public:

    class_name(int size);
    ~class_name();

    void f(unsigned long a, char* ptr);
    unsigned long get_f();
    void set_f(int a);
    friend void assign_id(class_name c);
    // nothing again :D
    long pri;
};
void class_name::f(unsigned long a, char* ptr)
{
    pri = id;
    c_size = ptr;
    pri = a;
}
void class_name::set_f(int a)
{
    pri = a;
}
unsigned long class_name::get_f()
{ return pri; }
void SquareClassVar(class_name *cn)
{
    std::cout << " Multiplied! " << std::endl;
//    cn.set_f(cn.get_f() * cn.get_f());
    cn->set_f(cn->get_f() * cn->get_f());
    std::cout << cn->get_f() << std::endl;

}
class_name::class_name(int size)
{
   // c_size = (char*)malloc(10);
    std::cout << " Created " << size << std::endl;
}
class_name::~class_name()
{
  //  std::cout << c_size << std::endl;
    std::cout << " Destroyed " << std::endl;
}


void assign_id(class_name c)
{
    c.pri += 1;
    std::cout << c.pri << std::endl;
}

int main()
{
    auto createClass = [=]()
    {
        long G = 9.14;
        int size = 2;
        class_name className(size);
        className.f(G, " hello world ");
        return className;
    };

    class_name c = createClass();
    class_name *p = &c;
    class_name v = createClass();
    SquareClassVar(p);
    assign_id(v);

    std::cout << c.get_f() << std::endl;
    std::cout << v.get_f() << std::endl;
    std::cout << p->get_f() << std::endl;

}