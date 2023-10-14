#include <bits/stdc++.h>

struct Class;

struct Object
{
    int _data;
    explicit Object(int data) : _data(data){};
};

struct Student
{
    std::weak_ptr<Class> aclass;
    ~Student(){
        aclass.reset();
        std::cout << " Student Destructed! " << std::endl;
    }
};

struct Class
{
    std::shared_ptr<Student> student;
    ~Class(){
        student.reset();
        std::cout << " Class Destructed! " << std::endl;
    }
};


int main()
{

    {/*
    std::shared_ptr<Class> c = std::make_shared<Class>();
    std::shared_ptr<Student> s = std::make_shared<Student>();

    c->student = s;
    s->aclass = c;
*/
    }


    {/*    std::weak_ptr<Object> child;
    std::shared_ptr<Object> Parent = std::make_shared<Object>(1);
    child = Parent;

    if(auto temp = child.lock())
        std::cout << temp->_data;
    else
        std::cout << " null ";
    Parent.reset(new Object(1));

    if(child.expired())
        std::cout<<" died ";*/}

}


