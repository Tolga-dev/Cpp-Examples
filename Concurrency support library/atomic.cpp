#include <iostream>       // std::cout
#include <atomic>         // std::thread
#include <memory>
#include <vector>
#include <thread>


template<class T>
struct atomic;

template<class T>
class atomic<T*>;

template<class T>
struct atomic<std::shared_ptr<T>>;

template<class T>
struct atomic<std::weak_ptr<T>>;

std::atomic<bool> r (false);
std::atomic_flag w = ATOMIC_FLAG_INIT;

void threadsF(int id)
{

    while (!r) { std::this_thread::yield(); }
    for(int i = 0; i < 100000 ; i++) {}
    if(!w.test_and_set()) { std::cout << id << std::endl; }

}
void threadFCall()
{
    std::vector<std::thread> ths;

    for(int i = 0; i < 10 ; i++) { ths.push_back(std::thread(threadsF,i)); }
    r = true;
    for(auto& t : ths) t.join();
}

std::atomic<int> f = 0;

void set_f(int x)
{
    std::cout << "coming x : " << x << std::endl;
    f = x;
}
void print_F()
{
    std::cout << "coming f : " << f << std::endl;
    while(!f) std::this_thread::yield();
    std::cout << "came f : " << f << std::endl;
    std::cout << std::endl;

}
void equalOperator()
{
    std::vector<std::thread> thread_vector;
    std::vector<std::thread> thread_vector_second;

    for(int o = 0; o < 10; o++)
        thread_vector.push_back(std::thread(set_f,10));
    for(int u = 0; u < 10; u++)
        thread_vector_second.push_back(std::thread(print_F));

    for(auto& t : thread_vector_second) t.join();
    for(auto& t : thread_vector) t.join();
}


std::atomic<int*> struct_atomic{nullptr};

void loadAtomic()
{
    std::cout << "load Atomic" << std::endl;
    std::cout << struct_atomic.load(std::memory_order_relaxed) << std::endl;
}
void storeAtomic()
{
    std::cout << "store Atomic" << std::endl;

    struct_atomic.store(new int(5),std::memory_order_relaxed);
}
void loadAndStore()
{
    std::thread f(loadAtomic);
    std::thread s(storeAtomic);

    s.join();
    f.join();
}
std::atomic<int_least16_t> foo = 0;
std::atomic<uint_least16_t> bar = 0;

void st_f(int f)
{
    foo = f;
}
void cp_f_to_b()
{
    while(!foo) std::this_thread::yield();
    bar = foo;
}
void print_f_b()
{
    while(!foo && !bar) std::this_thread::yield();
    std::cout << foo << " " << bar << std::endl;
}
void atomicOperator()
{
    std::thread f(print_f_b);
    std::thread s(st_f,1);
    std::thread rs(cp_f_to_b);
    f.join();
    s.join();
    rs.join();
}
void exchange()
{
    const int_least8_t threadNumber = 5;
    std::atomic<int> f{0};
    std::atomic<int> c{0};

    auto fn = [&](const int id)
    {
        for(int o = 0 ; o < threadNumber;)
        {
            const int curr = f.exchange(o);
            c++;
            std::cout << "  " << id << "  "<< std::this_thread::get_id() << "  "
                      << o << "   " << curr << std::endl;
            o = std::max(curr, o) + 1;
        }
    };
    std::vector<std::thread> t;
    for(int i = 0 ; i < threadNumber ; i++)
        t.emplace_back(fn,i);
    for(auto& tx : t)
        tx.join();
    std::cout <<  f << " " << c << std::endl;
}


struct N { N* next; };
std::atomic<N*> head (nullptr);
void app()
{
    std::cout<< "app! " << std::endl;

    N* old = head;
    N* newNode = new N{old};

    while(!head.compare_exchange_strong(old, newNode))
        newNode->next = old;

    std::cout<< "compared! " << std::endl;

}
void compareExchange()
{
    std::thread one(app);
    std::thread two(app);

    one.join();
    two.join();

}


std::atomic<int> ai = 3;
int t = 35;
int newt = 4;
bool exc = false;

void out()
{
    std::cout << ai << " " << t << " " << newt<< " " <<exc << std::endl;
}
void strongAndWeak()
{
    out();
    exc = ai.compare_exchange_weak(t,newt);
    out();
    exc = ai.compare_exchange_weak(t,newt);
    out();
    exc = ai.compare_exchange_strong(t,newt);
    out();
    exc = ai.compare_exchange_strong(t,newt);
    out();
}

std::atomic<int> a;
std::atomic<int> b;
std::atomic<int> c;
void nothing()
{
    std::cout << a.is_always_lock_free << std::endl;
    a.fetch_add(31, std::memory_order_relaxed);
    a.fetch_sub(31, std::memory_order_relaxed);

    std::cout << a << std::endl;
    std::cout << b.fetch_and(c) << std::endl;
    std::cout << b.fetch_or(c) << std::endl;
    std::cout << b.fetch_xor(c) << std::endl;
    std::cout << b++ << std::endl;
    std::cout << ++b << std::endl;
    b += b;

}
void atomicOP()
{
    std::thread x (nothing);
    x.join();

}


void typesInteger()
{
    {
        int8_t  a = 0b0;
        int16_t b = 0b111111111111111;
        int32_t c = 0b1111111111111111111111111111111;
        int64_t d = 0b111111111111111111111111111111111111111111111111111111111111111;

        std::cout << sizeof(a) << std::endl;
        std::cout << sizeof(b) << std::endl;
        std::cout << sizeof(c) << std::endl;
        std::cout << sizeof(d) << std::endl;

        std::cout << (a) << std::endl;
        std::cout << (b) << std::endl;
        std::cout << (c) << std::endl;
        std::cout << (d) << std::endl;
    }
    {
        int_fast8_t  aa = 0b0;
        int_fast16_t ba = 0b111111111111111;
        int_fast32_t ca = 0b1111111111111111111111111111111;
        int_fast64_t da = 0b111111111111111111111111111111111111111111111111111111111111111;

        std::cout << sizeof(aa) << std::endl;
        std::cout << sizeof(ba) << std::endl;
        std::cout << sizeof(ca) << std::endl;
        std::cout << sizeof(da) << std::endl;

        std::cout << (aa) << std::endl;
        std::cout << (ba) << std::endl;
        std::cout << (ca) << std::endl;
        std::cout << (da) << std::endl;
    }
    {
        int_least8_t a = 0b0;
        int_least16_t b = 0b111111111111111;
        int_least32_t c = 0b1111111111111111111111111111111;
        int_least64_t d = 0b111111111111111111111111111111111111111111111111111111111111111;

        int_fast8_t  aa = 0b0;
        int_fast16_t ba = 0b111111111111111;
        int_fast32_t ca = 0b1111111111111111111111111111111;
        int_fast64_t da = 0b111111111111111111111111111111111111111111111111111111111111111;

        std::cout << sizeof(a) << std::endl;
        std::cout << sizeof(b) << std::endl;
        std::cout << sizeof(c) << std::endl;
        std::cout << sizeof(d) << std::endl;

        std::cout << (a) << std::endl;
        std::cout << (b) << std::endl;
        std::cout << (c) << std::endl;
        std::cout << (d) << std::endl;

        std::cout << sizeof(aa) << std::endl;
        std::cout << sizeof(ba) << std::endl;
        std::cout << sizeof(ca) << std::endl;
        std::cout << sizeof(da) << std::endl;

        std::cout << (aa) << std::endl;
        std::cout << (ba) << std::endl;
        std::cout << (ca) << std::endl;
        std::cout << (da) << std::endl;
    }

}

int main()
{


}
