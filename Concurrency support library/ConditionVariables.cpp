#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <mutex>


std::mutex m;
std::condition_variable cv;
std::string id;
int balance;
int queue = 0;

void transfer();

void sendSignal()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << " signal is sending!" << std::endl;
    cv.notify_all();
    queue = 0;
}
void waitTraffic(int id)
{
    std::unique_lock<std::mutex> lk(m);
    std::cout << "waiting traffic \n";
    cv.wait(lk);
    std::cout << "finished traffic \n";
    std::cout << "waiting signal \n";
    lk.unlock();

    std::unique_lock<std::mutex> lc(m);

    std::chrono::seconds(1 * id);
    std::cout << "working!" << std::endl;

    if(cv.wait_for(lc,std::chrono::seconds(1 * id),[]{ std::cout << queue << std::endl; return queue == 0; }))
        std::cout << "got signal \n";
    else
        std::cout << " timed out! | queue: " << queue<< std::endl;

    lc.unlock();
}
void transfer()
{
    std::lock_guard ul(m);
    balance += 100;
    std::cout << id << " will go" << std::endl;
    cv.notify_one();
}
void worker()
{
    id = "first";
    std::unique_lock uk(m);
    cv.wait(uk);
    std::cout << id << " get reaction, thread is processing" << std::endl;
    id = "second";
    std::cout << id << " worked completed" << std::endl;

    uk.unlock();

}

int main()
{
    std::thread th(worker);
    std::thread th4(worker);
    std::thread th2(transfer);
    std::thread th3(transfer);

    std::thread th5(waitTraffic,1);
    std::thread th6(waitTraffic,2);
    std::thread th7 (waitTraffic,3);
    std::thread th8 (sendSignal);

    th2.join();
    th3.join();
    th4.join();
    th.join();

    queue = 4;
    cv.notify_all();

    th5.join();
    th6.join();
    th7.join();
    th8.join();


    std::cout << balance << " money added" << std::endl;


    return 0;
}