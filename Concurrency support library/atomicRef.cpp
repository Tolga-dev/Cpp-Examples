#include <iostream>
#include <atomic>
#include <thread>
#include <vector>


void doit(int& a, int& b)
{
    std::atomic<int> ref(a);
    uint16_t ref1 = 0;
    std::atomic_ref<int> ref2(b);

    auto work = [&]()
    {
        static_assert(decltype(ref)::is_always_lock_free, "atomic int is not lock free!");
        for(int i = 0; i < 1000; i++ )
        {
            ref++;
            ref1++;
            ref2++;
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    };

    std::thread t(work);
    std::thread t2(work);
    std::thread t3(work);
    std::thread t4(work);

    t.join();
    t4.join();
    t2.join();
    t3.join();

    std::cout << ref << std::endl;
    std::cout << ref1 << std::endl;
    std::cout << ref2 << std::endl;
    std::cout << std::endl;

}
void AtomicRefExample()
{
    int a = 0;
    int b = 0;
    for(int i = 0; i < 100 ; i++)
        doit(a,b);
}

void operatorEqualMemberF(int& n)
{
    std::atomic_ref<int> a(n);
    std::atomic_ref<int> b(a);
}


void atomic_is_lock()
{
    struct A { int x[10]; };
    struct B { int x; };

    std::atomic<A> a;
 //   std::cout << std::atomic_is_lock_free(&a) << std::endl; use clang

}

int main()
{
    AtomicRefExample();
     return 0;
}
