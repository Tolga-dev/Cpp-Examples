#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>

void atomic_is_lock()
{
    struct A { int x[10]; };
    struct B { int x; };

    std::atomic<A> a;
    //   std::cout << std::atomic_is_lock_free(&a) << std::endl; use clang

}


std::atomic<int> f(0);

void s(int i)
{
    f.store(i, std::memory_order_relaxed);
}
void p()
{
    int x;
    x = f.load(std::memory_order_relaxed);
    std::cout << x << std::endl;
}

void atomic_store()
{
    std::thread sx(s, 10);
    std::thread fx(p);
    fx.join();
    sx.join();
}


std::atomic<int> sum;
void Atomic_store()
{
    sum++;
}
void atomic_exchange()
{
    std::vector<std::thread> n;

    auto assign = [&](){
        for(int o = 0; o < 100; o++)
            n.emplace_back(Atomic_store);
    };
    auto assignJ = [&](){
        for(auto& o : n)
            o.join();
    };
    assign();
    assignJ();
    std::cout << sum << std::endl;
}


struct atomicObj { int a; };
std::atomic<atomicObj> fo;
std::atomic<atomicObj> ba;
void atomic_exchange_f()
{
    atomicObj atomics = fo.load();
    atomics.a = 5;
    fo.store(atomics);

    std::cout << &fo << std::endl;
    std::cout << &ba << std::endl;

    ba.exchange(fo);
  //  std::atomic_exchange_explicit(&fo,ba,std::memory_order_consume);
    std::atomic_exchange(&fo,ba);

    atomicObj atomicsObj = fo.load();
    std::cout << atomicsObj.a  << std::endl;
    std::cout << &ba << std::endl;
}

void NonMemoeryOrdering()
{
    /* ex2
    while(!wait) { std::this_thread::yield();}

    while(a.load() != b)
    {
        std::cout << " a != b " << std::endl;
    }
    a.store(b);
    c = a.load();
    while(c.load() == a)
    {
        std::cout << " c == a " << std::endl;
    }
     */


    /* ex1
    std::cout << std::this_thread::get_id() << " id " << std::endl;
    print();
    while(wait)
    {
        std::cout << " wait " << std::endl;
        std::this_thread::yield();
    }
   if(a.load() == 1) {
        std::cout << a.load() << " == a.load()" << std::endl;
    }

    a = 1;
    b.store(c);

    print();
    wait = false;
    */
}
void nonMemory()
{
/*
    std::thread k (NonMemoeryOrdering);
    std::thread l (NonMemoeryOrdering);
    std::cout << " thread is ok " << std::endl;
    wait = true;

    k.join();
    l.join();
    std::cout << " thread is joined " << std::endl;
*/
}
std::atomic<bool> kl= false;
std::atomic<int> balance = 0;

void deposit() {
    while(kl == false) std::this_thread::yield();
    balance = balance + 1;
}
void withdraw() {
    while(kl == false) std::this_thread::yield();
    balance = balance - 1;
}
void exampleThread()
{
    std::vector<std::thread> th;

    for (int i = 0; i < 5; ++i) {
        th.push_back(std::thread(deposit));
    }
    for (int i = 0; i < 5; ++i) {
        th.push_back(std::thread(deposit));
    }
    kl = true;

    for (int i = 0; i < 10; ++i) {
        th[i].join();
    }
    std::cout << balance << std::endl;
}


std::atomic<int> a = 0;
std::atomic<int> b = 10;
std::atomic<int> c = 20;
std::atomic<bool> wait = false;

auto print = []()
{
    std::cout << a.load() << std::endl;
    std::cout << b.load() << std::endl;
    std::cout << c.load() << std::endl;
    std::cout << " Printed " << std::endl;
};


std::atomic<int> th1;
std::atomic<int> th2;

void f1() { th1.store(1, std::memory_order_seq_cst); std::cout << " f1 " << std::endl;}
void f2() { th2.store(1, std::memory_order_seq_cst); std::cout << " f2 " << std::endl;}

void f3()
{
    while(!th1.load(std::memory_order_seq_cst));
    if(th2.load(std::memory_order_seq_cst)) std::cout << " X then Y" << std::endl;
}
void f4()
{
    while(!th2.load(std::memory_order_seq_cst));
    if(th1.load(std::memory_order_seq_cst)) std::cout << " y then x" << std::endl;

}
void memoryOrder()
{

      std::thread th(f1);
      std::thread th1(f2);
      std::thread th2(f3);
      std::thread th3(f4);

      th.join();
      th1.join();
      th2.join();
      th3.join();
}

std::atomic<bool> l(false);

void fm(int k)
{
    while(std::atomic_exchange(&l, true))
        ;
    std::cout << " Out from " << k << " " << std::endl;
    std::atomic_store(&l, false);
}
void fm_ex(int k)
{
    while(std::atomic_exchange_explicit(&l, true, std::memory_order_acquire))
        ;
    std::cout << " Out from " << k << " " << std::endl;
    std::atomic_store_explicit(&l, false,std::memory_order_release);
}
void atomic_exc()
{
    std::vector<std::thread> v ;

    for(int n =0; n < 10 ; n++)
        v.emplace_back(fm_ex, n);

    for(auto& t : v) { t.join(); }
}


std::atomic<int> com1A = 0;
std::atomic<int> com2 = 1;
std::atomic<int> com3 = 2;

void fetch()
{
    com1A = std::atomic_fetch_sub(&com1A,1);
    com1A = std::atomic_fetch_add(&com1A,1);
    com2 = std::atomic_fetch_sub(&com2,1);

}
void mainFetch()
{
    std::thread d (fetch);
    d.join();
    std::cout << com1A << std::endl;
    std::cout << com2 << std::endl;

}

std::atomic<int> and1ForAtomic = 13;
std::atomic<int> and2ForAtomic = 1;
std::atomic<int> and3ForAtomic = 1;
void orAndXor()
{
    std::cout << std::atomic_fetch_or(&and1ForAtomic, 0) << std::endl;
    std::cout << std::atomic_fetch_and(&and1ForAtomic, 0) << std::endl;
    std::cout << std::atomic_fetch_xor(&and1ForAtomic, 0) << std::endl;
    std::cout << and1ForAtomic << std::endl;
    std::cout << and2ForAtomic << std::endl;
    std::cout << and3ForAtomic << std::endl;
}

std::atomic<int> atomicWait = 21;


int main()
{




    return 0;
}