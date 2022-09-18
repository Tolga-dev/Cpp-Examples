#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <chrono>

using namespace std::chrono;

void startwithId()
{
    std::thread t ( []{ std::this_thread::sleep_for(256ms);} );
    std::thread t2 ( []{ std::this_thread::sleep_for(512ms);} );

    std::clog << t.get_id() << std::endl;
    std::clog << t2.get_id() << std::endl;

    t.join();
    t2.join();

}

void footh1(int n)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        std::cout << " t1 ";
        n++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void gooth2(int& n)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        std::cout << " t2 ";
        n++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

class fooClassT3
{
public:
    void bar()
    {
        for(int i = 0; i < 5; i++)
        {
            std::cout << " t3 ";
            n++;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    int n = 0;
};

class gooClassT4
{
public:
    void operator()()
    {
        for (int i = 0; i < 5; ++i) {
            std::cout << " t4 ";
            ++n;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    int n = 0;
};
void constructer()
{
    int n = 0;
    std::thread t1;
//    t1.join();
    std::thread t2(footh1,n+1);
    std::thread t3(gooth2,std::ref(n));
    std::thread t4(std::move(t3));

    fooClassT3 f;
    gooClassT4 g;
    std::thread t5(&fooClassT3::bar,&f);
    std::thread t6(g);

    t2.join();
    t5.join();
    t4.join();
    t6.join();

    std::cout << "n : " << n << std::endl;
}

void mythread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));

}
void myoperator()
{
    std::thread th[100];

    for (int i=0; i< 100; ++i)
    {
        th[i] = std::thread(mythread,(i+1));
        std::cout << " th  : " << i <<std::endl;
    }

    for (int i=0; i< 100; ++i)
    {
        th[i].join();
        std::cout << " th join : " << i <<std::endl;
    }
}

void joinable()
{
    std::thread t;
    std::cout << t.joinable() << std::endl;
    t = std::thread(mythread, 1);
    std::cout << t.joinable() << std::endl;
    t.join();
    std::cout << t.joinable() << std::endl;

}
void id()
{

    std::thread t(mythread,1);
    std::thread::id tid =  t.get_id();

    std::thread t2(mythread,1);
    std::thread::id t2id =  t2.get_id();

    std::cout << tid << std::endl;
    std::cout << t2id << std::endl;

    tid = t2id;

    std::cout << tid << std::endl;
    std::cout << t2id << std::endl;

    t.join();
    t2.join();

    std::cout << std::thread::hardware_concurrency() << std::endl;
}

void f()
{
    double a;
    for(double n; n < 10000; n++)
        for(double j; j < 10000; j++)
            for(double k; k < 10000; k++)
                a++;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    std::cout << a << std::endl;

}
void g()
{
    double a;
    for(double n; n < 10000; n++)
        for(double j; j < 10000; j++)
            for(double k; k < 10000; k++)
                a++;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    std::cout << a << std::endl;

}
void join()
{
    std::thread a(f);
    std::thread b(g);

    a.join();
    b.join();
}


void independentTh()
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}

void thCall()
{
    std::cout << "Starting thread caller.\n";

    std::thread t(independentTh);
    std::thread t1(independentTh);
    std::thread t2(independentTh);

    //t.join();
    t.detach();

    std::cout << t.get_id() << std::endl;

    t1.join();
    t2.join();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Exiting thread caller.\n";
}

void swaspf()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void swasps()
{
    std::thread f(swaspf);
    std::thread d(swaspf);

    std::cout << f.get_id() << std::endl;
    std::cout << d.get_id() << std::endl;

    f.swap(d);
    std::swap(f,d);

    std::cout << f.get_id() << std::endl;
    std::cout << d.get_id() << std::endl;

    f.detach();
    d.detach();

}


int main()
{


    return 0;
}