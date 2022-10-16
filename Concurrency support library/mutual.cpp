#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>



std::mutex mtx;
std::atomic<bool> lock = false;
auto s = std::chrono::system_clock::now();
auto f = std::chrono::system_clock::now();

void print_lock(int a, char c)
{
    /*t1
    mtx.lock();

    for(int i =0; i < a ; i++) { std::cout << c << std::endl;}
    std::cout << " first " << std::endl;
    mtx.unlock();
    */

    /*t2
    while(lock) { std::cout << " locked!" << std::endl; };

    for(int i =0; i < a ; i++) { std::cout << c << i << std::endl;}
    std::cout << " first " << std::endl;

  //  lock = false;
    */

    /*
    for(int i =0; i < a ; i++)
    {
        if(mtx.try_lock())
        {
            std::cout << c << i << std::endl;
            mtx.unlock();
        }
    }
    */

}
void basic()
{

    /*
    std::thread t(print_lock, 50, 'a');
    std::thread tx(print_lock, 50, 'b');
    std::thread txc(print_lock, 50, 'c');
    std::thread txv(print_lock, 50, 'd');

//    lock = false;

    t.join();
    tx.join();
    txc.join();
    txv.join();
    */

}

void CLockStart()
{
    s = std::chrono::system_clock::now();
}
void CLockEnd()
{
    f = std::chrono::system_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(f-s).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(f-s).count() << std::endl;
}


std::mutex mtx2;
std::timed_mutex timexmtx;

void time_mutex_lock_for(int a)
{
    for(int i = 0; i < 3 ; i++)
    {
        std::cout << a << " :id loop " << std::endl;
        if(timexmtx.try_lock_for(std::chrono::seconds(2)))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            timexmtx.unlock();
        }
        else
        {
            std::cout << " failed!" << std::endl;
        }

    }

    std::cout << a << " :id finish " << std::endl;
}

void time_mutex_until(int a)
{

    auto now = std::chrono::steady_clock::now();

    if(timexmtx.try_lock_until(now + std::chrono::seconds(2)))
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        timexmtx.unlock();
    }
    else
    {
        std::cout << a << " failed! " << std::endl;
    }
    std::cout << a << " :ss id finish " << std::endl;
}
void timedmutex()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(time_mutex_until, i);
    }

    for (auto& i: threads) {
        i.join();
    }
}

std::recursive_mutex m;
int buf;

void recursive(int id, int countLoop)
{
    std::cout << "before locked! " << id << std::endl;

    if(countLoop < 0)
        return;

    m.lock() ;
    std::cout << "locked! " << id << std::endl;

    std::cout << id << " id, " << buf++ << std::endl;
    recursive(id, --countLoop);

    m.unlock();
    std::cout << "unlocked! " << id << std::endl;

}
void recursice()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(recursive, i,5);
    }

    for (auto& i: threads) {
        i.join();
    }

}

int main()
{
    CLockStart();

    recursice();

    CLockEnd();

}


