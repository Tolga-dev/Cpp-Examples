#include <iostream>
#include <string>
#include <cstring>
#include <utility>

class Student
{
public:
    Student() : _id(0), _name(nullptr){};

    Student(const char* name, int id) : _id(id), _name(new char[strlen(name) + 1])
    {
        std::strcpy(_name,name);
    };

    ~Student() { delete[] _name;}

    Student(const Student& student) : _id(student._id), _name(new char[strlen(student._name) + 1])
    {
        std::strcpy(_name,student._name);
    }

    Student& operator=(const Student& student)
    {
        _id = student._id;
        delete[] _name;

        _name = new char[strlen(student._name) + 1];
        std::strcpy(_name,student._name);

        return *this;
    }

private:
    int _id;
    char* _name;
};


int main()
{

    Student s1(static_cast<const char*>("name!"), 10);
    Student s2 = s1;

}