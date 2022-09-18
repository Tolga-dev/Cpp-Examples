#include <iostream>
#include <thread>
#include <chrono>


void jthread()
{
    std::cout << " en " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << " ex " << std::endl;
}
void jthread2(int n)
{

    n++;
    std::cout << n << std::endl;

    std::cout << " en " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << " ex " << std::endl;
}

void jtreadconstructers()
{
    int n;
    std::jthread a(jthread);
    std::jthread b(jthread);
    std::jthread c(jthread);
    std::jthread d(std::move(c));

    std::jthread k(jthread2, std::ref(n));
    std::jthread l(jthread2, std::ref(n));
}

void joinableJthread()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void jthreadJoinable()
{
    std::jthread t;
    std::cout << t.joinable() << std::endl;
    t = std::jthread(joinableJthread);
    std::cout << t.joinable() << std::endl;
    t.detach();
    std::cout << t.joinable() << std::endl;
}

class treadClass
{
public:
    void foo()
    {
        n++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << n << std::endl;
    }
    int n;
};

void operatoions()
{
    int n = 0;
    treadClass tc;
    std::jthread mytreadh(&treadClass::foo, &tc);
    std::jthread mytreadhs(&treadClass::foo, &tc);

    std::cout << mytreadh.get_id() << " " << mytreadhs.get_id() << std::jthread::hardware_concurrency();

    mytreadhs.swap(mytreadhs);
    std::swap(mytreadhs, mytreadh);
}

void stopRequest()
{

    std::jthread jt0([](std::stop_token tk) {
        for (int i = 0; i < 10; i++) {
            std::cout << "value: " << i << '\n';

            if (tk.stop_requested()) {
                return;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(5));

    jt0.request_stop();
    std::cout << "Stopped" << std::endl;
}


int main()
{
    return 0;
}
