#include <iostream>

//static member functions
/*

struct StaticDataStruct
{
    inline static int n = 1;
};
class StaticDataClass
{
    static int n;
};
int StaticDataClass::n = 1; // not allowed!
void StaticDataF()
{
    StaticDataStruct::n = 1;
    StaticDataStruct sds;
    sds.n = 31;
}
struct StaticIncompleteType;
struct GetIncompleteType
{
    static int a[];
    static StaticIncompleteType staticIncompleteType; // declaration incomplete
    static GetIncompleteType getIncompleteType; // declaration incomplete
};
int GetIncompleteType::a[10];
GetIncompleteType GetIncompleteType::getIncompleteType;

//To refer to a static member of class T::m T.m T->m
struct staticStruct
{
    static void returnStaticStruct();
    static int n;
};
staticStruct f(){ return staticStruct();} //returning staticStruct
*/
/*
void g()
{
    staticStruct::returnStaticStruct();
    f().returnStaticStruct(); // legal
    f().returnStaticStruct();
    f().n = 5;
}
*//*

// static ok with public private protected

struct PublicPrivateClass //public private
{
public:
    void add(int x)
    {
        n += x;
    }
    PublicPrivateClass returnParent()
    {
        return PublicPrivateClass();
    }
private:
    int n = 0;
};
PublicPrivateClass GetClass() { return PublicPrivateClass();}
void GetClass2(){ GetClass().returnParent();}


class TypenameCLass
{
    class Bclass{}; // private
public:
    typedef Bclass bclass; // public to grant access
};
TypenameCLass getTypeName(){ return TypenameCLass();}
void getTypeNameFunction(){ TypenameCLass::bclass babici;}

//virtual functions
struct baseClass
{
    virtual void foo(){ std::cout << "base";}
};
struct DerivedClass : baseClass
{
    void foo() override {std::cout << "derived";}
};

void CallVirtualClass()
{
    baseClass b;
    DerivedClass d;

    baseClass& bc = b;
    baseClass& dc = d;
    bc.foo();
    dc.foo();
}

class Base
{
    virtual void do_f(){ std::cout << " base " ;}; // private member
    virtual void do_int(){ int a = 10; }; // private member
public:
    void f() { do_f(); } // public interface
    void d() { do_int(); } // public interface
};

struct DerivedClassS : public Base
{
    void do_int() override { int a = 5; };
    void do_f() override { std::cout << " overrided " ;};; // overrides B::do_f
};
void getCallVirtualClass()
{
    DerivedClassS  derivedClassS;
    Base* bp = &derivedClassS;
    bp->f();
    bp->d();
}

struct first
{
    virtual void f() { std::cout << " 1" ;};
    virtual void d(int) const { std::cout << " d1" ;}; // dont write final keyword :(
    virtual void c(int) final { std::cout << " d1" ;}; // dont write final keyword :(

};
struct first2
{
    virtual void f() { std::cout << " 11" ;};
};
struct second : first,first2
{
    void f() { std::cout << " f2"; };
    void d(int) const override { std::cout << " d2"; };
};
struct third :virtual second
{
    void f() { std::cout << " 3"; };
    void d(int)const override { std::cout << " d3"; };
};
struct forth : virtual third{};
void getCallVIrtualFUnnc()
{
    forth f;
    f.f();
//    f.d(long);
}

class Destroctor
{
public:
    virtual ~Destroctor(){ std::cout << "1" ; }
};
class DerivedClassDestroctor : public Destroctor
{
    ~DerivedClassDestroctor(){ std::cout << "2" ; }
};
void getDestroctor()
{
    Destroctor* destroctor = new DerivedClassDestroctor;

    delete destroctor;
}
//contuenie public private
struct Baccess{ virtual void f(){std::cout<<"1";}};
class Daccess : public Baccess
{
private: void f(){ std::cout << "2";} // will not be overried due to private
};
void virutaleffecaccsess()
{
    Daccess daccess;
    Baccess& baccess = daccess;

    baccess.f();
}
//contunie static data memer

//non static memeber
class nonStaticMembers
{
    int m1;
    void mf2() volatile;
    void m3() &&;
    int m4() const { return data;}
    virtual void m5() final;
    nonStaticMembers() : data(12){}
    int data;
};
//abstract
struct baseAbstract
{
    virtual int g();
    virtual ~baseAbstract() {};
};
struct derivedAbstract : baseClass
{
    virtual int f() = 0, h();
};
//example
class Shape {
public:
    // pure virtual function providing interface framework.
    virtual int getArea() = 0;
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }
protected:
    int width;
    int height;
};
// Derived classes
class Rectangle: public Shape {
public:
    int getArea() {
        return (width * height);
    }
};
void getRect()
{
    using namespace std;
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    cout << "Total Rectangle area: " << Rect.getArea() << endl;
}
//contunie non memeber func
struct structk
{
    static int a;
    int n;
    void f();
};
*/
/*
void structk::f()
{
    n = 1;
    a = 2;
}
*//*

*/
/*
void getMemberFu()
{
    structk s1;
    s1.f();
}*//*


// the this pointer
class outer
{
    int s = sizeof(*this);

    void anan()
    {
        int a[sizeof(*this)];
        struct inner
        {
            void anan()
            {
               int c[sizeof(*this)];
            }
        };

    }

};

//exam
struct ThisKeywordStruct
{
    int var;
};

struct OuterStructKeyword : ThisKeywordStruct
{

    OuterStructKeyword() { this->ThisKeywordStruct::var = 1;}

};

//example
class ClassThis
{


public:
    ClassThis(int x) : x(x), y(this->x) { std::cout << x << y;}

private:
    int x  = 1;
    int y = 2;

};

//  nested classes
int x,y;
class outerClass
{
    int x;
    static int s;
public:
    struct nonanonmyous{
        void f(outerClass* pm ,int i)
        {
            ::x = i;
             pm->x = i;

        }
    };
};

//override, final
struct VirtualStruct
{
    virtual void foo();
};
struct OverrideVirtualFInal : VirtualStruct
{
    void foo() final;
};
struct OverrideOnFinal : OverrideVirtualFInal
{
//    void foo() override; // error
};

//std::basic ostream, friend
class x
{
public:
    char* foo(int);

};
class Y
{
    int data;
    friend std::ostream& operator<<(std::ostream& out, const Y& y);
    friend char* x::foo(int);


};
std::ostream& operator<<(std::ostream& out, const Y& y)
{
    return out << y.data;
}
//elaborated type specifier

//Argument-dependent lookup
void ArgumanetOperator()
{
    std::cout << "a";
    std::operator<<(std::cout,"a");
    std::cout << std::endl;
    (std::endl)(std::cout<< "asdsa");
    endl(std::cout);

    using std::cout;
    cout<<"ASD";
}
//Argument-dependent lookup with friend
*/
/*
template<typename T>
struct number
{
    number(int);
    friend number gcd(number x, number y) { return 0; };
    friend void ab(number k , number l){};
};
void g()
{
    number<int> a(3), b(4);
    a = gcd(a, b);
    ab(a,b);
}
 *//*

//Argument-dependent lookup with namespace
namespace loopUp1
{
    struct S{};
    template<int T>
    void a(S);
}
namespace loopUp2
{
    struct S{};
    template<int T>
    void a(S);
}
*/
/*
void loopUp1Fonk(loopUp1::S s, loopUp2::S b)
{
   a<3>(s);
   loopUp2::a<3>(b);
}
 *//*

//qualified loop up
struct cout
{
    static int s;
};
*/
/*
void Qualified()
{
    struct std
    {
        static void cout();
    };
    std::cout();
    ::std::cout<< "Sasd";
    int cout;
    cout::s = 5;
    ::cout couts;

}

*//*

//class member look up
struct A{ A();};
struct B : A { B();};
A::A() {};
B::B() {};
B::A ba;
//namespace member look up
namespace NameSpacemember
{
    template<typename T>
    struct foo{};
    struct X{};
}
NameSpacemember::foo<NameSpacemember::X> membbers;
//non look up
void nolook()
{
    int n = 1;
    int x = n + 1;
}
//static data non look up
namespace ns{
    struct X
    {
        static const int x;
        static const int n = 1; // found 1st
    };
    const int n = 2;                  // found 2nd
    const int X::x = n;
}
//overloaded operator
struct overloadedStruct{};
void operator-(overloadedStruct, overloadedStruct);
struct overloadedStructB
{
    void operator-(overloadedStructB);
    void f();
};
overloadedStruct overloadedStructc;
overloadedStructB overloadedStructBc;
*/
/*
void overloadedStructB::f()
{
    overloadedStructB::operator-(overloadedStructBc);
    overloadedStructc - overloadedStructc;
}
 *//*

//continue elaborated
class elaboratedclas
{
public:
    class U;
private:
    int U;
};
void elaboratedclasFUnction()
{
    int elaboratedclas;
    class elaboratedclas ec;
    ::elaboratedclas esc;
}
//continue friend
*/
/*
class F{};
void functionsfriend();

void friends()
{
    class local
    {
        friend void ::functionsfriend();
        friend class F; // friends a local F (defined later)
        friend class ::F; // friends the global F
    };
    class F {}; // local F
}
 *//*

//template friends
template<class T>
class Aprimary{};

template<class T> // partial
class Aprimary<T*>{};

template<>
class Aprimary<int>{}; // full

class templateFriend // legal
{
    template<typename T>
    friend class Bs;

    template<typename T>
    friend void fsa(T){}


//    template<class T>
//    friend class Aprimary<T*> // not refer partial

    friend class Aprimary<int>;
};
//friend operator7
template<typename T>
class Foo; // forward declare to make function declaration possible

template<typename T> // declaration
std::ostream& operator<<(std::ostream&, const Foo<T>&);

template<typename T>
class Foo
{
public:
    Foo(const T& val) : data(val) {}
private:
    T data;

    // refers to a full specialization for this particular T
    friend std::ostream& operator<< <> (std::ostream&, const Foo&);

    // note: this relies on template argument deduction in declarations
    // can also specify the template argument with operator<< <T>"
};

// definition
template<typename T>
std::ostream& operator<<(std::ostream& os, const Foo<T>& obj)
{
    return os << obj.data;
}

void friendTemplate()
{
    Foo<double> obj(1.23);
    std::cout << obj << '\n';
}

//default constructors
struct As
{
        As();
        As(int = 0);
        As(int, int, int = 0);
};
class DefaultC
{
public:
    int a, b;
    DefaultC()
    {
        a = 10;
        b = 20;
    }
    DefaultC( int x, int y)
    {
        x = y;
    }

};
//destructors
struct destruct
{
    int i;
    destruct(int num) : i(num){ std::cout << "c" << i << std::endl; }
    ~destruct() { std::cout << "d" << i << std::endl; }
};
void cDestructer()
{
    destruct as(0);
    destruct* px;
    {
        px = new destruct(1);
    }
    delete px;
}

// copy constructer
struct copyConstructer
{
    int x;

    copyConstructer(int i, int j) : x(i) {};
    copyConstructer();
    copyConstructer(copyConstructer& cC){}

};

void copyConstructerFunction()
{
    copyConstructer cpO(1,2);
    copyConstructer cp1 = cpO;
    copyConstructer cp2(cpO);

}

// copy assignment
struct copyAssignment
{
    copyAssignment& operator= (copyAssignment cA)
    {
        copyAssignment* p = &cA;
        std::cout << p <<" cA is copied to " << this << std::endl;
        return *this;
    }
};
void copyAssignmentFUnc()
{
    copyAssignment cA;
    copyAssignment cAA;
    copyAssignment *p = &cAA;
    copyAssignment *pc = &cA;
    cA= cAA;

    std::cout << p << "  " <<pc << std::endl;
}
// move constructer

class MoveConstruct
{
public:
    int* dataP;

    MoveConstruct(int data)
    {
        int a;
        data = a;
        *dataP = data;
        std::cout << "constructer is called for " << data << std::endl;

    }
    MoveConstruct(const MoveConstruct& source) : MoveConstruct( *source.dataP )
    {
        std::cout << "Copy Constructor is called -"
                   << "Deep copy for "
                   << *source.dataP
                   << std::endl;
    }
    MoveConstruct(MoveConstruct&& source) : dataP{source.dataP}
    {

        std::cout << "Move Constructor for "
             << *source.dataP << std::endl;
        source.dataP = nullptr;
    }

};
void moveCOntrocturFonkstion()
{
    int dataP = 5;
    MoveConstruct moveConstruct(dataP);

    moveConstruct.dataP = &dataP;
    MoveConstruct moveConstructCopy = std::move(moveConstruct);


}
*/

//move assignment operator
//move constructor is used to efficiently transfer ownership of resources( dynamic memory allocated using new)
// it used to reduce copying data and improving performance
namespace MoveAssignmentOperatorExamples
{
    namespace E1
    {
        class MoveOperator // general example for move operator
        {
        public:
            size_t size{};
            int* data{};
            std::string name;

            MoveOperator(size_t size, std::string& name) :name(name),size(size),data(new int[size]) {
                for (size_t i = 0; i < size; i++) {
                    data[i] = i * 2;
                }
                std::cout << "Constructor called." << std::endl;
            }

            MoveOperator(const MoveOperator& bar) : name(bar.name), size(bar.size), data(new int[bar.size])
            {
                for (size_t i = 0; i < size; ++i) {
                    data[i] = bar.data[i];
                }
                std::cout << "Copy constructor is called" << std::endl;
            };

            MoveOperator(MoveOperator&& bar) noexcept : name(std::move(bar.name)), size(bar.size), data(new int[bar.size])
            {
                bar.size = 0;
                bar.name = "";
                bar.data = nullptr;
                std::cout << "Move Constructor is called !" << '\n';
            }

            MoveOperator& operator=(MoveOperator&& select) noexcept
            {
                if(this != &select)
                {
                    data = select.data;
                    size = select.size;
                    name = select.name;

                    select.size = 0;
                    select.name = "";
                    select.data = nullptr;
                }
                std::cout << "Move Assignment is called !" << '\n';
                return *this;
            }

            MoveOperator& operator=(const MoveOperator& select)
            {
                if(this == &select) {
                    return *this;
                }

                    data = select.data;
                    size = select.size;
                    name = select.name;

                std::cout << "Copy Assignment is called !" << '\n';
                return *this;
            }
        };

        void Runner()
        {
            std::string name = "test";
            MoveOperator foo(10, name);
//            MoveOperator bar(foo);
            MoveOperator bar = foo;

            MoveOperator dum = std::move(foo);
            MoveOperator mud(std::move(bar));

            std::cout << foo.name << " " << foo.size << "  " << bar.name << " " << bar.size << std::endl;

        }

    }
    namespace E2
    {
        class foo // Implicitly-Defined Move Constructor
        {
        public:
            foo(){ };
            std::string temp;
            int* dummy;
        };

        void Runner()
        {
            int dum = 5;
            foo fo;
            fo.temp = "foo";
            fo.dummy = &dum;

            foo bar(std::move(fo));
            bar.temp = "bar";

            std::cout << fo.temp << " " << bar.temp << std::endl; // empty " " bar
            std::cout << fo.dummy << " " << bar.dummy << std::endl; // same address


        }
    }
    namespace E3
    {
        // deleted move constructor
        class NoMove // it can't generate move constructor by compiler
        {
        public:
            NoMove()= default;
            NoMove(const NoMove&) = default;

            NoMove& operator=(const NoMove&) {return *this;}

            NoMove(NoMove&&) = delete; // delete move constructor

        };
        void Runner()
        {
            NoMove x;
          //  NoMove y = std::move(x); // error : Attempting moving x to y;
        }
    }
    namespace E4
    {
        class Trivial // move constructor are automatically generated when no custom constructors are defined
        {
        public:
            Trivial() : data(new int[5]) { data[0] = 10;}

            int *data;

        };
        void Runner()
        {
            Trivial a;
            Trivial b = std::move(a);

            std::cout  << b.data[0] << std::endl;
        }
    }
    namespace E5
    {
        class Eligible
        {
        public:
            Eligible() : data(new int[5]) { data[0] = 10;}
            Eligible(Eligible&& local)  noexcept : data{local.data}
            {
                local.data = nullptr;
            }
            ~Eligible(){ delete[] data;}
            int *data;

        };
        void Runner()
        {
            Eligible a;
            Eligible b = std::move(a);

            std::cout  << b.data[0] << " " << (a.data == nullptr) << std::endl;
        }
    }
}

int main() {
    MoveAssignmentOperatorExamples::E1::Runner();
//    copyAssignmentFUnc();
//    copyConstructerFunction();

 //   int a= 5;
 //   ClassThis classThis(a);


   // getCallVIrtualFUnnc();
   // getCallVirtualClass();

//    CallVirtualClass();

    return 0;
}
