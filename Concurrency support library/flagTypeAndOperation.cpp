#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
#include <assert.h>
#include <csignal>

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void flagTypeOp(int ix )
{

    while(!ready) { std::this_thread::yield();}

    for(int i = 0; i < 10 ; i++)
    {
        while (std::atomic_flag_test_and_set_explicit(&winner, std::memory_order_acquire));
        std::cout << ix << std::endl;
        std::atomic_flag_clear_explicit(&winner, std::memory_order_release);
    }

    if(!winner.test_and_set()) { std::cout << ix << " is won!" << std::endl ;
        winner.clear();
        std::cout << winner.test_and_set()<< ix << std::endl;
    }


}
void atomic_flag()
{
    std::vector<std::thread> t;
    for(int i = 0 ; i <=10 ; i++) { t.push_back(std::thread(flagTypeOp, i)); }
    ready = true;
    for(auto& a : t) { a.join() ;}
}



std::atomic<int> a=1;
std::atomic<int> b;
int r;
int y;
void relax()
{
    r= a.load(std::memory_order_relaxed);
    std::cout << r << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if(r == 1)
    {
        std::cout << "yeas" << std::endl;
        b.store(r, std::memory_order_relaxed);
        std::cout << b << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    y= b.load(std::memory_order_relaxed);
    if(y == 1) {
        std::cout << "yeas2" << std::endl;
        a.store(y, std::memory_order_relaxed);
        std::cout << y << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

std::atomic<int> nt = {0};
std::atomic<int> mt = {0};
void relax2()
{
    for(int i = 0; i < 1000 ; i++)
        nt.fetch_add(1, std::memory_order_relaxed);
    mt = 31;
    mt.store(nt, std::memory_order_release);
    std::cout << std::this_thread::get_id() << std::endl;
}
void realse()
{
    mt = 32;
    mt.store(nt, std::memory_order_release);
    std::cout << std::this_thread::get_id() << std::endl;
}
void acquoire_realse()
{
    while(!(mt = nt.load(std::memory_order_acquire))) { std::cout << "acquire" << std::this_thread::get_id() << std::endl; };
    std::cout << mt << std::endl;
    std::cout << nt << std::endl;

}
void acRe()
{
    std::thread am(acquoire_realse);
    std::thread an(relax2);
    std::thread ak(realse);
    std::thread ab(relax2);
    std::thread ac(relax2);
    std::thread av(relax2);
    an.join();
    ac.join();
    ak.join();
    ab.join();
    av.join();
    am.join();
}

std::atomic<int> k = 0;
void release()
{
    int a = 5;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    k.store(a, std::memory_order_release);
}
void consumer()
{
    int m=0 ;
    std::cout << k.load(std::memory_order_consume) << std::endl;
    while(m == k.load(std::memory_order_consume))
    { std::cout << k.load(std::memory_order_consume) << std::endl; };
    std::cout << m << std::endl;
    std::cout << k.load(std::memory_order_consume) << std::endl;

}
void release_consume()
{
    std::thread y(release);
    std::thread x(consumer);

    x.join();
    y.join();

}

std::atomic<int> fence = 0;
std::atomic<int> fenceB = 0;
void hand(int signal)
{
    std::cout << " Signal has come: " << signal << std::endl;
    if(1 == a.load(std::memory_order_relaxed))
    {
        std::atomic_signal_fence(std::memory_order_acquire);
        assert(1 == fenceB.load(std::memory_order_relaxed));
    }
    exit(signal);
}

int main()
{
    std::signal(SIGINT, hand);

    fenceB.store(1, std::memory_order_relaxed);
    std::atomic_signal_fence(std::memory_order_release);
    fence.store(1, std::memory_order_relaxed);


    return 0;
}