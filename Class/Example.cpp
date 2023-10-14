
/*Virtual base classes are used in virtual inheritance in a way of preventing multiple “instances”
of a given class when using multiple inheritances.*/

/*#include <iostream>
using namespace std;

class class1
{
public:
    int dim_a; double *A;

    class1( int a )
    {
        dim_a= a;
        A= new double[dim_a];
        A[0] = a;
    }
    ~class1()
    {
        delete [] A;
    }
    class1 &operator=( class1 &object_1 );
};
class1& class1::operator=(class1 &object_1 )
{
    for (int i = 0; i < object_1.dim_a; ++i) {
        A[i] = object_1.A[i];
    }
    for (int i = 0; i < dim_a; ++i) {
        std::cout << A[i] << std::endl;

    }
     return *this;
}

int main()
{
    class1 a(3); // assume same size
    class1 b(3);
    a = b;

}*/

/*
#include <iostream>
using namespace std;
class B1{
private:
    int a;
public:
    B1(int x)
    {
        a = x;
        cout << "“Base B1 a=”" << a << endl;
    }
    B1()
    {
        a = 100;
        cout << "“Base B1(no param) a=”" << a << endl;
    }
    ~B1()
    {
        cout << "“Destructing B1 a=”" << a << endl;
    }
    int geta()
    {
        return a;
    }
};

class B2
{
private:
    int b;
public:
    B2(int x)
    {
        b = x;
        cout << "“Base B2 b=”" << b << endl;
    }

    ~B2(){cout << "“Destructing B2 b=” "<< b << endl;}

    int getb()
    {
    return b;
    }
};

class D : public B2, public B1{
private:
    int c;
public:
    D(int x, int y) : B2(x), B1()
    {
        c = y;
        cout << "“Constructing D(no parameter) c=”" << c << endl;
    }
    D(int x, int y, int z) : B2(x), B1(y)
    {
        c = z;
        cout << "“Constructing D c=”" << c << endl;
    }
    ~D()
    {
        cout << "“Destructing D c=”" << c << endl;
    }
    void show()
    {
        cout << "“a= “" << geta() << "“, b=”" << getb() << "“, c=”" << c << endl;
    }
};
int main()
{
    int i;
    B2 bo2(15);
    cout << "“b of bo2=”" << bo2.getb() << endl;
    D ob(3, 5, 8);
    ob.show();
    B1 bo1(20);
    cout << "“a of bo1=”" << bo1.geta() << endl;
    return 0;
}
*/

/*
#include <iostream>
using namespace std;
class coord{
public:
    int i, j, x, y;
    coord(int i = 10, int j = 15)
    {
        x = i, y = j;
    }
    coord operator+(const coord &object)
    {
        coord temp;
        temp.x = x + 2 * object.x;
        temp.y = y + 2 * object.y;
        return temp;
    }
    coord operator*(const coord &object)
    {
        coord temp;
        temp.x = x * object.x;
        temp.y = y * object.y;
        return temp;
    }
    void show_xy()
    {
        cout << "“X=”" << x << "“ Y=”" << y << endl;
    }
};
int main(){
    coord o1(1,2),o2(3,5),o3,o4,o5;
    o3.show_xy();
    o3 = o1 + o3;
    o3.show_xy();
    o4.show_xy();
    o4 = o1 + o2 + o5;
    o4.show_xy();
    o1.show_xy();
    o1 = o1 * o2;
    o1.show_xy();
    o3=o1.operator+(o2);
    o3.show_xy();
    return 0;
}
*/
/*

#include <iostream>
using namespace std;
class myclass
{
public:
    double x, y;

    myclass(double a, double b)
    {
        x = a; y = b;
        cout << "“Constructing,x=”"  << x << "“ y=”" << y << endl;
    };

    myclass(const myclass &ob1)
    {
        x = ob1.x; y = ob1.y;
        cout << "“Copy Constructor,x=” "<< x << "“ y=”" << y << endl;
    };
    ~myclass()
    {
        cout << "“Destroying,x=”" << x << "“ y=”" << y << endl;
    };

    void show()
    {
        cout << "“x=” "<< x << "“ y=” "<< y << endl;}
    };
void fun1(myclass ob1)
{
    myclass ob(5, 20);
    ob.x = ob.x + ob1.x;
    ob.y = ob.y + ob1.y;
    cout << "“x= “" << ob.x << "“ y=”" << ob.y << endl;
}
int main()
{
    myclass ob1(50, 100);
    myclass ob2 = ob1;
    fun1(ob1);
    ob1.show();
    fun1(ob2);
    ob2.show();
    return 0;
}
*/


