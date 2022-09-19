#include <iostream>
#include <chrono>
#include <thread>

#define START_THREADS true
void wait(std::chrono::microseconds t)
{

    auto s = std::chrono::high_resolution_clock::now();
    auto e = s + t;

    do{
        std::this_thread::yield();
    }
    while(std::chrono::high_resolution_clock::now() < e);

}
void yield2()
{
    auto s = std::chrono::high_resolution_clock::now();
    wait(std::chrono::microseconds(100));


    auto elap = std::chrono::high_resolution_clock::now() - s;

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(elap).count()
              << std::endl;
}


void wait2(int id)
{
    while(!START_THREADS)
        std::this_thread::yield();
    for(auto i = 0; i < 1000000 ; i++){}
    std::cout << " th: " << id << std::endl;
}
void yield()
{
    std::thread th[10];
    std::cout << "set the threads" << std::endl;
    for(int i = 0 ; i < std::size(th) ; i++)
    {
        th[i] = std::thread(wait2, i);
    }
    for(auto& t : th) t.join();
}

void foo()
{
    std::thread::id this_id = std::this_thread::get_id();

    std::cout << this_id << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void getid()
{
    std::jthread t1(foo);
    std::jthread t2(foo);
    std::cout << t1.get_id() << std::endl;
    std::cout << t2.get_id() << std::endl;
}


void sleepfo()
{
    std::cout << "start thread" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elap = end - start;
    std::cout << elap.count() << std::endl;
}

void sleepUNTIL()
{
    using namespace std::literals;
    auto start_time = std::chrono::steady_clock::now();

    for (auto i = start_time; i <= start_time + 1s ; i += 50ms) {
        std::this_thread::sleep_until(i);
    }
}

int main()
{


    return 0;
}