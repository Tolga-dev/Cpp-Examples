#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>

auto s = std::chrono::system_clock::now();
auto f = std::chrono::system_clock::now();

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

std::mutex mtx;
std::atomic<int> count;

void lock_guard_mutex()
{
    mtx.lock();
    for(int i ; i < 11000; i++){}
    mtx.unlock();

    std::lock_guard<std::mutex> l(mtx);
    for(int i =0 ; i < 11000; i++){ count++; }
    std::cout << " result: " << count << std::endl;

    std::cout << "g_i: " << std::this_thread::get_id() << '\n';

}
void lock_guard()
{
    std::thread t1(lock_guard_mutex);
    std::thread t2(lock_guard_mutex);

    t1.join();
    t2.join();
}


int key = 0;
std::mutex mt;
void unique_lock()
{

    std::unique_lock<std::mutex> lock(mt);

    for(int i =0; i < 10 ; i ++)
    {
        std::cout << i << std::endl;
    }

}
void unique()
{
    std::thread t1(unique_lock);
    std::thread t2(unique_lock);

    t1.join();
    t2.join();
}


class BankAccount
{
public:
    BankAccount(int balance) : balance(balance){}
    int getBalance(){return balance;}
    friend void transferAmountMoney(BankAccount* from, BankAccount* to, int amount);
private:
    int balance;
    std::mutex m;
};

void transferAmountMoney(BankAccount* from, BankAccount* to, int amount)
{
    std::unique_lock<std::mutex> lock1(from->m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(from->m, std::defer_lock);

    from->balance -= amount;
    to->balance += amount;

/*
    std::lock_guard<std::mutex> lock1(from->m, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(from->m, std::adopt_lock);

    from->balance -= amount;
    to->balance += amount;

 */
}
void bank()
{
    BankAccount p1(100);
    BankAccount p2(1000);

    std::cout << p1.getBalance() << std::endl;
    std::cout << p2.getBalance() << std::endl;

    std::thread t1(transferAmountMoney, &p1, &p2, 50);
    std::thread t2(transferAmountMoney, &p2, &p1, 100);
    std::thread t3(transferAmountMoney, &p2, &p1, 100);
    std::thread t4(transferAmountMoney, &p2, &p1, 100);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << p1.getBalance() << std::endl;
    std::cout << p2.getBalance() << std::endl;
}

int main()
{
    CLockStart();




    CLockEnd();



}