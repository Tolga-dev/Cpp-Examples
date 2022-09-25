#include <iostream>
#include <thread>
#include <chrono>
#include <stop_token>


void start_thread_b()
{
    for(int i ; i < 1000 ; i++)
        std::cout << i << " : thread" << std::endl;
}
void Practice()
{
    int x = 0;
    //  std::thread thr1(start_thread_b);
    std::thread a;
    std::thread anan = std::thread([&](){
        std::cout<< " anan " << std::endl;
        a = std::thread([](){ std::cout << " wait " << std::endl; });
        a.join();
    } );

//    thr1.join();
    anan.join();
}


void t1(std::string s)
{
    s.append("s");
}
void t2(std::string s)
{
    std::cout << s << std::endl;
}
void dataRacing()
{
    std::string s = "s";

    std::thread a = std::thread(t1,s);
    std::thread b = std::thread(t2,s);

    a.join();
    b.join();

    std::cout << s << std::endl;
}


void stop_me(std::stop_token stopMe, int timeSlap)
{

    std::cout << "start thread" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    while(!stopMe.stop_requested())
    {
        std::cout << stopMe.stop_requested() << std::endl;
        std::cout << " operating!" << std::endl;
    }

    std::cout << " finished!" << std::endl;
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elap = end - start;
    std::cout << elap.count() << std::endl;
    std::cout << stopMe.stop_requested() << std::endl;

}

int main()
{

    std::jthread tr(stop_me, 5);
    std::jthread trx(std::move(tr));

    std::this_thread::sleep_for(std::chrono::seconds(4));

}
