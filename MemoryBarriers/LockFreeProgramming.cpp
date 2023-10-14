/// Why lock Free code

/// concurrency and scalability
    /// Eliminate or reduce blocking waiting in algorithms and data structures
/// two tool -> think  +  atomic<T>

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>
#include <mutex>
#include <shared_mutex>

using namespace std;

/// C++11 Mutex
class Mutex_user
{
public:
    constexpr Mutex_user() noexcept;
    ~Mutex_user();

    Mutex_user(const Mutex_user&) = delete;
    Mutex_user& operator=(const Mutex_user&) = delete;

    void lock(std::mutex th);
    bool try_lock(std::mutex th);
    void unlock(std::mutex th);

};
namespace Mutex
{
    namespace E1_lock_unlock
    {
        int g_cash = 0;
        std::mutex g_mutex;

        void BankIncrement(int id)
        {
            for (int i = 0; i < 10; ++i) {
                g_mutex.lock();  // protect data
                /// job
                g_cash++;
                cout << id << " " << g_cash << endl;
                /// job finish
                g_mutex.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
        }
        void Runner()
        {
            std::thread t1{Mutex::E1_lock_unlock::BankIncrement,0};
            std::thread t2{Mutex::E1_lock_unlock::BankIncrement,1};

            t1.join();
            t2.join();
        }

    }
    namespace E2_tryLock
    {
        std::mutex mutex;
        template<typename T = std::chrono::milliseconds> constexpr auto prd = T(100);

        void J1()
        {
            std::this_thread::sleep_for(prd<>);

            while(true) // job
            {
                if(mutex.try_lock())
                {
                    cout  << " job shared! " << endl;
                    return;
                }
                else
                {
                    cout  << " job not shared! " << endl;
                    std::this_thread::sleep_for(prd<>);
                }
            }

        }
        void J2()
        {
            mutex.lock();
            std::this_thread::sleep_for(4*prd<>);
            mutex.unlock();

        }
        void Runner()
        {
            std::thread th1(Mutex::E2_tryLock::J1);
            std::thread th2(Mutex::E2_tryLock::J2);

            th1.join();
            th2.join();
        }


    }

}

/// C++11 Recursive Mutex
class Recursive_Mutex_user
{
public:
    constexpr Recursive_Mutex_user() noexcept;
    ~Recursive_Mutex_user();

    Recursive_Mutex_user(const Recursive_Mutex_user&) = delete;
    Recursive_Mutex_user& operator=(const Recursive_Mutex_user&) = delete;

    void lock(std::recursive_mutex th);
    bool try_lock(std::recursive_mutex th);
    void unlock(std::recursive_mutex th);

};
namespace Recursive
{
    class Recursive_Mutex
    {
        std::mutex M; // change as g_mutex and see diff
        std::recursive_mutex g_mutex;
        int g_cash = 0;
    public:

        void Bank(int id)
        {
            g_mutex.lock();  // protect data

            for (int i = 0; i < 10; ++i) {
                /// job
                g_cash++;
                cout << "bank1 " << id << " " << g_cash << endl;
                /// job finish

            }

            g_mutex.unlock();
        }
        void Bank2(int id)
        {
            g_mutex.lock();  // protect data

            for (int i = 0; i < 10; ++i) {
                /// job
                g_cash++;
                cout << "bank2 " << id << " " << g_cash << endl;
                /// job finish
            }
            Bank(id);

            g_mutex.unlock();

        }


    };

}

/// C++11 Timed Mutex
namespace Timed
{
    namespace E1
    {
        class Timed_Mutex
        {
        public:
            std::timed_mutex g_mutex;
            int g_cash=0;

            void Increment(int id)
            {
                g_mutex.lock();
                for (int i = 0; i < 10; ++i)
                    g_cash++;
                cout << g_cash << endl;
                g_mutex.unlock();
            }

            void Runner()
            {
                Timed::E1::Timed_Mutex timedMutex;
                std::jthread th1(&Timed::E1::Timed_Mutex::Increment, &timedMutex,0);
                std::jthread th2(&Timed::E1::Timed_Mutex::Increment, &timedMutex,1);


            }

        };
    }
}

/// lock guard
//An object of type lock_guard controls the ownership of a lockable object within a scope.
//A lock_guard object maintains ownership of a lockable object throughout the lock_guard
//object's lifetime.
template<class Mutex>
class lock_guard_user {
public:
    using mutex_type = Mutex;

    explicit lock_guard_user(mutex_type& m) : pm(m) { pm.lock(); }
    lock_guard_user(mutex_type& m, adopt_lock_t) noexcept: pm(m) {}
    ~lock_guard_user(){ pm.unlock(); }

private:
    mutex_type& pm;             // exposition only
};
namespace LockGuard
{
    namespace E1
    {
        class LockGuard
        {
        public:
            int g_data= 0;
            std::mutex g_i_mutex;

            void Safe_Increment()
            {
                std::lock_guard<std::mutex> lockGuard(g_i_mutex);
                g_data++;

                cout<< g_data << endl;

            }
        };

        void Runner()
        {
            LockGuard lockGuard;

            std::jthread th(&LockGuard::Safe_Increment,&lockGuard);
            std::jthread th2(&LockGuard::Safe_Increment,&lockGuard);


        }
    }

    namespace E2
    {
        class UserDefineLockGuard
        {
        public:
            int g_data= 0;
            std::mutex g_i_mutex;

            void Safe_Increment()
            {
                lock_guard_user<std::mutex> lockGuard(g_i_mutex);
                g_data++;

                cout<< g_data << endl;

            }
        };

        void Runner()
        {
            UserDefineLockGuard usd;

            std::jthread jt(&LockGuard::E2::UserDefineLockGuard::Safe_Increment,&usd);
            std::jthread jt2(&LockGuard::E2::UserDefineLockGuard::Safe_Increment,&usd);

        }
    }

}


/// C++17  std::shared_mutex
class shared_mutex {
public:
    shared_mutex();
    ~shared_mutex();

    shared_mutex(const shared_mutex&) = delete;
    shared_mutex& operator=(const shared_mutex&) = delete;

    // exclusive ownership
    void lock();                // blocking
    bool try_lock();
    void unlock();

    // shared ownership
    void lock_shared();         // blocking
    bool try_lock_shared();
    void unlock_shared();

};
namespace Shared
{
    namespace E1
    {
        class Shared
        {
        public:
            Shared() = default;
            int get() const
            {
                std::shared_lock lock(mutex);
                return val;
            }
            void inc()
            {
                std::unique_lock lock1(mutex);
                val++;
            }
            void reset()
            {
                std::unique_lock lock1(mutex);
                val = 0;
            }

        private:
            mutable std::shared_mutex mutex;
            int val  = 0;
        };
        void Runner()
        {
            Shared shared;
            auto i_p = [&shared]()
            {
                for (int i = 0; i < 10; ++i) {
                    shared.inc();
                    cout<< std::this_thread::get_id() << " " << shared.get() << endl;
                }
            };

            std::jthread th1(i_p);
            std::jthread th2(i_p);
            std::jthread th3(i_p);
            std::jthread th4(i_p);

        }

    }

    namespace E2
    {

        std::shared_mutex mutex;
        int val  = 0;
        void Job()
        {
            val++;
        }
        void Runner()
        {
            auto i_p = []()
            {
                mutex.lock_shared();
                for (int i = 0; i < 10; ++i) {
                    Job();
                }
                cout<< std::this_thread::get_id() << " " << val << endl;
                mutex.unlock_shared();

            };
            for (int i = 0; i < 10 ; ++i) {
                std::jthread th1(i_p);
                std::jthread th2(i_p);
                std::jthread th3(i_p);
                std::jthread th4(i_p);
            }

        }
    }

    namespace E3
    {

        std::mutex cout_mutex;//Not really part of the example...
        void log(const std::string& msg){
            std::lock_guard guard(cout_mutex);
            std::cout << msg << std::endl;
        }

        class ThreadSafeCounter {
        public:
            ThreadSafeCounter() = default;

            // Multiple threads/readers can read the counter's value at the same time.
            unsigned int get() const {
                std::shared_lock lock(mutex_);//NB: std::shared_lock will shared_lock() the mutex.
                log("get()-begin");
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                auto result=value_;
                log("get()-end");
                return result;
            }

            // Only one thread/writer can increment/write the counter's value.
            void increment() {
                std::unique_lock lock(mutex_);
                value_++;
            }

            // Only one thread/writer can reset/write the counter's value.
            void reset() {
                std::unique_lock lock(mutex_);
                value_ = 0;
            }

        private:
            mutable std::shared_mutex mutex_;
            unsigned int value_ = 0;
        };

        void Runner() {
            ThreadSafeCounter counter;

            auto increment_and_print = [&counter]() {
                for (int i = 0; i < 3; i++) {
                    counter.increment();
                    auto ctr=counter.get();
                    {
                        std::lock_guard guard(cout_mutex);
                        std::cout << std::this_thread::get_id() << ' ' << ctr << '\n';
                    }
                }
            };

            std::thread thread1(increment_and_print);
            std::thread thread2(increment_and_print);
            std::thread thread3(increment_and_print);

            thread1.join();
            thread2.join();
            thread3.join();
        }
    }
}
/// C++17  std::SCOPED_LOCK
namespace Scoped
{
    namespace E1
    {
        class Worker
        {
        public:
            Worker(int i) : id(i) {}
            int id;
            std::mutex m;
        };
        class Scoped_Lock
        {
        public:
            void Job(Worker &worker,Worker &worker1)
            {
                static std::mutex mutex;
                {
                    std::lock_guard<std::mutex> l(mutex);
                    cout << " working! "<< worker.id << " " << worker1.id << endl;
                }
                {
                    std::scoped_lock lock(worker1.m, worker.m);
                    {
                        std::lock_guard<std::mutex> l(mutex);
                        cout << " finish! "<< worker.id << " " << worker1.id << endl;
                    }
                }
                this_thread::sleep_for(std::chrono::milliseconds(1000));
            }

        };
        void Runner()
        {
            Worker w(1),w1(2),w3(3);
            Scoped_Lock lock1;
            std::jthread th1(&Scoped_Lock::Job,&lock1,std::ref(w1),std::ref(w3));
            std::jthread th3(&Scoped_Lock::Job,&lock1,std::ref(w1),std::ref(w));
            std::jthread th2(&Scoped_Lock::Job,&lock1,std::ref(w),std::ref(w3));
        }
    }
}


/// C++14  std::SHARED_LOCK BASED ON LOCK_SHARED
namespace Shared_lock
{
    namespace E1
    {
        int cash = 0;
        std::mutex m;
        std::shared_mutex sm;
        void Bank1(int id)
        {
            int c;
            {
                std::shared_lock lock1(sm, std::defer_lock);
                lock1.lock();
                c = cash;
            }
            std::lock_guard lockGuard(m);
            cout << " current cash -> " << id << " : " << cash << endl;
        }
        void AddCash(int money)
        {
            cout << "moneys adding!" << endl;
            {
                std::lock_guard lockGuard(sm);
                cash += money;
                cout << "moneys added!" << endl;
            }
        }
        void GetCash(int money)
        {
            cout << "withdraw money!" << endl;
            {
                std::lock_guard lockGuard(sm);
                cash -= money;
                cout << "withdrawed money!" << endl;
            }
        }
        void Runner()
        {
            std::thread r1(Bank1,1);
            std::thread r2(Bank1,2);
            std::thread w2(AddCash,5);
            std::thread g2(GetCash,5);

            r1.join();
            r2.join();
            w2.join();
            g2.join();

            cout << " operation " << endl;

            r1 = std::thread{Bank1, 3};
            r1.join();
        }
    }
    namespace E2
    {

        template<typename T = std::chrono::milliseconds> constexpr auto prd = T(100);

        int cash = 0;
        std::shared_mutex sm;
        void Bank1(int id)
        {
            int c;
            {
                cout << " came " << id << endl;
                std::shared_lock lock1(sm, std::defer_lock);
                lock1.lock();

                c = cash;



                cout << " waiting " << id << endl;
                std::this_thread::sleep_for(10*prd<>);
                cout << " going home " << id <<endl;
            }
            std::lock_guard lockGuard(sm);
            cout << " current cash -> " << id << " : " << cash << endl;
        }

        void Runner()
        {
            std::thread r1(Bank1,1);
            std::thread r2(Bank1,2);

            r1.join();
            r2.join();

            cout << " operation " << endl;

            r1 = std::thread{Bank1, 3};
            r1.join();
        }
    }

}


///Double Check Locking -> pretty easy -> have to do right
/// with memory_order -> acquire and release
namespace DoubleCheck
{
    namespace E1
    {
        class Singleton
        {
        public:
            static Singleton* GetInstance();

            Singleton(Singleton const&) = delete; /// not implemented
            void operator=(Singleton const&) = delete; /// not implemented

            void Set_Val ( int i ) { this->id = i; }
            void Print_Val ( ) { cout << this->id << " " << this <<endl;}
        private:
            int id;
            Singleton() = default;
        };

        std::atomic<Singleton*> s_instance;
        std::mutex s_mutex;

        Singleton* Singleton::GetInstance() { /// Using C++11 Low-Level Ordering Constraints
            Singleton* p = s_instance.load(std::memory_order_acquire);
            if (p == nullptr) { // 1st check

                std::lock_guard<std::mutex> lock(s_mutex);
                p = s_instance.load(std::memory_order_relaxed);
                if (p == nullptr) { // 2nd (double) check
                    p = new Singleton();
                    s_instance.store(p, std::memory_order_release);
                }
            }
            return p;
        }


        void Runner()
        {
            Singleton* singleton = Singleton::GetInstance();
            singleton->Set_Val(2);
            singleton->Print_Val();

            Singleton* singleton2 = Singleton::GetInstance();
            singleton->Set_Val(5);
            singleton->Print_Val();

        }
    }
}

/// singly linked list -> find, push_front, and pop
namespace Link
{
    namespace E1
    {
        template<typename T>
        class linkedlist
        {
        public:
            linkedlist();
            ~linkedlist();

            T* find(T t) const;
            void print( ) const;
            void push_front(T t);
            void pop();
        private:
            struct Node{ T t; Node* next;};
            atomic<Node*> head{ nullptr };
            std::mutex m;
            linkedlist(linkedlist& l) = delete;
            void operator=(linkedlist& l)= delete;
        };

        /// constructor
        template<typename T>
        linkedlist<T>::linkedlist() { } // default
        /// destructor
        template<typename T>
        linkedlist<T>::~linkedlist() {
            auto first = head.load(); // good habit: access head once
            while( first ) { // (not needed here, but good habit...)
                auto unlinked = first;
                first = first->next;
                delete unlinked;
            }
        }
        /// no problem with find
        template<typename T>
        T* linkedlist<T>::find( T t ) const {
            auto p = head.load();
            while( p && p->t != t )
                p = p->next;
            return p ? &p->t : nullptr;
        }
        /// no problem with print
        template<typename T>
        void linkedlist<T>::print() const {
            auto p = head.load();
            while( p )
            {
                cout << p->t << " ";
                p = p->next;
            }
            cout << endl;
            delete p;
        }
        /// here is a problem -> in writer, what if two threads try to insert
        /// at the same time ?
        /// -> terminate called without an active exception
        /// in this case u can use compare_exchange_weak
        /// for basic building blocks of lockfree data structures
        template<typename T>
        void linkedlist<T>::push_front( T t ) {


            auto p = new Node; // create the new node
            p->t = t; // set its element value
            p->next = head; // set its place in the list

            /// -> make comment
//            head = p; // publish it at the head
            ///possible out put ->  2 3 1 || 3 2 1 || 1 3 2

            /// -> make uncomment // SOLUTION 1
            while( !head.compare_exchange_weak(p->next, p) ) { }

            /// -> make uncomment // SOLUTION 2
//            while( !atomic_compare_exchange_weak_explicit(
//                    &head,
//                    &p->next,
//                    p,
//                    std::memory_order_release,
//                    std::memory_order_relaxed)
//                    )
//            { }
        }

        /// double free or corruption (fasttop)
        /// i dont have a sol for this problem to be honest, it is ur task
        template<typename T>
        void linkedlist<T>::pop() {

            auto p = head.load(); // remember current first node
            /// to see error make it uncomment
//            this_thread::sleep_for(std::chrono::milliseconds(1000));

            if (p) head = p->next; // set head to the second node

            delete p;

        }


        void Runner()
        {
            linkedlist<int> s;

            thread t1(&linkedlist<int>::push_front,&s,1);
            thread t2(&linkedlist<int>::push_front,&s,2);
            thread t3(&linkedlist<int>::push_front,&s,3);


            t1.join();
            t2.join();
            t3.join();

            s.print();

            thread t4(&linkedlist<int>::pop,&s);
            thread t5(&linkedlist<int>::pop,&s);
            t4.join();
            t5.join();

            s.print();

        }

    }
}

namespace Atomic
{
    namespace E1
    {
        std::atomic<int> p;

        void foo()
        {
            auto mo = std::memory_order_relaxed;
            /// write value 3 into pos
            p.store(3);

            /// read current value from pos
            int ct = p.load(mo);
            cout << ct <<endl;

            /// write value 42 into pos and retrieve previous value
            int pt = p.exchange(42,mo);
            cout << pt <<endl;

            /// if pos == expected, sets pos to desired and returns true.
            /// otherwise does nothing and returns false.
            if(p.compare_exchange_strong(ct,31))
                cout << p.load(mo) << " - " << endl;

            cout << p.load(mo) << " " << ct << " " << pt << endl;
            ct = 42;

            /// if pos == expected, sets pos to desired and returns true.
            /// otherwise does nothing and returns false. (use in loops)
            while(p.compare_exchange_weak(ct,32))
                cout << p.load(mo) << " - " << endl;

            cout << "Result: " <<p.load(mo) << " " << ct << " " << pt << endl;

        }
        void Runner()
        {
                std::vector<std::jthread> pool;
                for(int n = 0; n < 5; ++n)
                    pool.emplace_back(foo);

        }
    }
    namespace E2
    {
        atomic_int s;
        int s2;
        void foo()
        {
            for(int n = 0; n < 1000; ++n) {
                ++s;
                ++s2;
            }
        }

        void Runner()
        {
            {
                std::vector<std::jthread> pool;
                for (int n = 0; n < 5; ++n)
                    pool.emplace_back(foo);
            }

            cout << s << " " << s2 << endl;
        }
    }
    namespace E3
    {
        std::atomic<int> s;
        int s2;
        void foo()
        {
            s2 = s.fetch_add(1);
            cout << s.load() << " " << s2 << endl;

        }

        void Runner()
        {
            {
                std::vector<std::jthread> pool;
                for (int n = 0; n < 5; ++n)
                    pool.emplace_back(foo);
            }

        }
    }

}

/// TEMPLATE
/* TEMPLATE
/// C++17  std::SCOPED_LOCK
namespace Scoped
{
    namespace E1
    {
        class Scoped_Lock
        {

        };
        void Runner()
        {

        }
    }
}
*/


int main()
{
//    Atomic::E1::Runner();
//    Atomic::E2::Runner();
//    Atomic::E3::Runner();

//    DoubleCheck::E1::Runner();
//    Link::E1::Runner();




//    Shared_lock::E2::Runner();
//    Shared_lock::E1::Runner();
//
//    Scoped::E1::Runner();
//
//    Shared::E1::Runner();
//    Shared::E2::Runner();
//    Shared::E3::Runner();
//
//
//    LockGuard::E1::Runner();
//
//    Timed::E1::Timed_Mutex timedMutex;
//    timedMutex.Runner();
//
//
//    Recursive::Recursive_Mutex d;
//    std::jthread th1(&Recursive::Recursive_Mutex::Bank,&d,0);
//    std::jthread th2(&Recursive::Recursive_Mutex::Bank2,&d,1);



    return 0;
}