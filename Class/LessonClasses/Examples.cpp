#include <iostream>

class subCss {

public:
    int id;
    subCss(int a) : id(a) { std::cout << id << " contructer " << std::endl; };
    ~subCss() {
        std::cout << id << " deleted "<< std::endl;} //destructor

};

subCss mn(subCss *a)
{
    subCss m(3);
    return m;
}

void Example1()
{
    subCss a(1);
    subCss b(2);
    subCss c(4);

    b = mn(&a);
    c = mn(&a);
    std::cout << b.id << std::endl;
    std::cout << c.id << std::endl;

}

class anan
{

public:
    anan() { std::cout << " cons fx" << std::endl;}
    ~anan() { std::cout << " destroy me fx" << std::endl;}
    int len = 1;
};

class bClass //: public anan
{

private:
public:
    int id;
    bClass(int i) : id(i) { std::cout << " cons " << std::endl;}
    bClass( const bClass &b) {   id = b.id;  std::cout << " copy " << std::endl;}
    ~bClass() { std::cout << " destructer " << std::endl;}
    void get_len()
    {
        //std::cout << len << std::endl;
    }
};

int main (){

    bClass b(2);
    bClass c = b;

    std::cout << c.id << std::endl;
 //   c.get_len();

    return 0;
}
*/



