#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>
using namespace std;

//#################################
//// Relaxed Ordering
namespace RelaxedOrdering
{
    namespace E1
    {
        std::atomic<int> a  = 0;

        void t1()
        {
            a = 1;
            cout << a << " t1 " << endl;

        }
        void t2()
        {
            a = 2;
            cout << a << " t2 " << endl;
        }

        void Uf_RelaxedOrdering()
        {
            std::thread th(t1);
            std::thread th1(t2);
            th.join();
            th1.join();

        }

    }
    namespace E2
    {
        template<typename T> concept numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;

        template<typename T> requires numeric<T>
        std::atomic<T> a{0};

        template<typename T>
        class Relax_Class
        {
        public:
            static inline void th1_for()
            {
                for (int i = 0; i < 10; i+=2) {
                    a<T>.store(i,std::memory_order_relaxed);
                }
            }
            static inline void th2_for()
            {
                for (int i = 0; i < 10; i+=2) {
                    a<T>.store(i,std::memory_order_relaxed);
                }
            }
            static inline void th3_store_vector(vector<T> *v)
            {
                for (int i = 0; i < 10; ++i) {
                    v->push_back(a<T>.load(std::memory_order_relaxed));
                }
            }
            static inline void th4_store_vector(vector<T> *v)
            {
                for (int i = 0; i < 10; ++i) {
                    v->push_back(a<T>.load(std::memory_order_relaxed));
                }
            }

            static void Runner()
            {
                vector<T> v3,v4;
                std::thread th1(Relax_Class<T>::th1_for),
                        th2(Relax_Class<T>::th2_for),
                        th3(Relax_Class<T>::th3_store_vector,&v3),
                        th4(Relax_Class<T>::th4_store_vector,&v4);
                th1.join();
                th2.join();
                th3.join();
                th4.join();

                for (T i : v3) cout << i << " ";
                cout << endl;
                for (T i : v4) cout << i << " ";
                cout << endl;
            }
        };


    }
    namespace E3
    {
        template<typename T, typename U> concept is_memory_provider = std::same_as<T,U>;
        template<typename T> concept numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;

        template<typename T> requires numeric<T>
        std::atomic<T> x{0};
        template<typename T> requires numeric<T>
        std::atomic<T> y{0};

        template<memory_order T,typename U> requires is_memory_provider<decltype(T),memory_order>

        class Memory_Order{
        public:
            static inline void x_f()
            {
                int r = y<U>.load(T);
                x<U>.store(r,T);
                cout << "X "<< x<U>.load(T) << endl;
            }

            static inline void y_f()
            {
                int r = x<U>.load(std::memory_order_relaxed);
                y<U>.store(41,std::memory_order_relaxed);
                cout << "Y " << y<U>.load(std::memory_order_relaxed) << endl;
            }

            static inline void Runner()
            {
                cout << x<U>.load(std::memory_order_relaxed) << endl;
                cout << y<U>.load(std::memory_order_relaxed) << endl;
                cout << " ========== " << endl;

                std::jthread t2(y_f), t1(x_f);

                cout << " ========== " << endl;

            }
        };



    }
    namespace E4
    {
        std::atomic<int>x,y;

        void th1()
        {
            y.store (20, memory_order_relaxed);
            x.store (10, memory_order_relaxed);
        }
        void th2()
        {
            if (x.load (memory_order_relaxed) == 10)
            {
                assert (y.load(memory_order_relaxed) == 20); /* assert A */
                y.store (10, memory_order_relaxed);
            }
        }
        void th3()
        {
            if (y.load (memory_order_relaxed) == 10)
                assert (x.load(memory_order_relaxed) == 10); /* assert B */
        }

        void Runenr()
        {
            std::jthread t1(th1);
            std::jthread t2(th2);
            std::jthread t3(th3);

        }


    }
}
//#################################
////// Release Consume Ordering
namespace ReleaseConsumeOrdering
{
    namespace E1
    {
        std::atomic<int> val;
        int data;

        class ReleaseConsume
        {
        public:
            static inline void foo()
            {
                data = 4;

                for (int i = 0; i < 10000; ++i);

                val.store(data,std::memory_order_release);

            }

            static inline void bar()
            {

                while(data != val.load(std::memory_order_consume)){ cout << "wait!" << " "; };

                cout << data << endl;

            }
            static inline void Runner()
            {
                jthread t1(foo);
                jthread t2(bar);

            }

        };
    }
    namespace E2
    {
        std::atomic<int> val{0};
        int data;
        bool Breaker = true;
        class ReleaseConsume
        {
        public:
            static inline void foo()
            {
                data = 4;

                for (int i = 0; i < 100000; ++i);
                cout << "finish" << endl;
                val.store(data,std::memory_order_release);
                Breaker = false;

            }

            static inline void bar()
            {

                while(Breaker){ cout<<" 2 "; cout <<val.load(std::memory_order_consume) << endl; };

                cout <<val.load(std::memory_order_consume) << endl;

            }
            static inline void Runner()
            {
                jthread t1(foo);
                jthread t2(bar);

            }

        };
    }
    namespace E3
    {
        struct str
        {
            int i;
        };
        std::atomic<str*>p;
        std::atomic<int>a;

        class Consume
        {
        public:
            static inline void create()
            {
                str* x = new str;
                x->i = 32;
                int y = 31;
                for (int i = 0; i < 1000000; ++i);
                cout << "job finish! " << endl;

                a.store(y,std::memory_order_relaxed);
                cout << "WAITING2 START! " << endl;
                for (int i = 0; i < 1000000; ++i);
                p.store(x,std::memory_order_release);
                cout << "WAITING2 FINISH! " << endl;
            }
            static inline  void use_x()
            {
                str* x;
                cout << "WAITING! " << endl;
                while(!(x = p.load(std::memory_order_consume)));
                cout << "WAITING FINISH! " << endl;

                cout << x->i << endl;
                cout << a.load(std::memory_order_relaxed) << endl;

            }
            static inline void Runner()
            {
                jthread t1(use_x);
                jthread t2(create);

            }
        };
    }

}
//#################################
////// Release-Acquire
namespace ReleaseAcquire
{
    namespace E1
    {

        std::atomic<int> ptr;
        int data;

        void creator()
        {
            int p = 31;
            ptr.store(p, std::memory_order_release);
            data = 54;
        }
        void consumer()
        {
            int p2 ;
            while(!(p2 = ptr.load(std::memory_order_acquire)));

            cout << p2<< " " << data << endl;

        }
        void runner()
        {
            jthread jt(creator);
            jthread jt2(consumer);
        }

    }
    namespace E2
    {

        std::atomic<int> ptr;
        std::atomic<int> ptr1;
        std::atomic<int> ptr2;

        void creator()
        {
            ptr.store(1, std::memory_order_relaxed);
            ptr2.store(1, std::memory_order_relaxed);
            for (int i = 0; i < 40000 ; ++i); // some job
            ptr1.store(1, std::memory_order_release);
            cout << "released" << endl;
        }
        void consumer()
        {
            cout << "start!!" << endl;

            {
                // what if there is no (if or while?) [ make while commit and see]
                cout << ptr1.load(std::memory_order_acquire) << endl;
            }

            {
                while (true) {
                    cout << "wait!" << endl;

                    /// im so lazy to write one line, cp i did sorry :*
                    if (ptr.load(std::memory_order_relaxed))
                        if (ptr1.load(std::memory_order_acquire))
                            if (ptr2.load(std::memory_order_relaxed))
                                break;
                }
                cout << "finish!!" << endl;
            }

        }
        void runner()
        {
            jthread jt(creator);
            jthread jt2(consumer);
        }

    }

}
//#################################
////// Sequentially consistent
namespace SequentiallyConsistent
{
    namespace E1
    {
        std::atomic<int> x,y,z;

        void client1()
        {
            cout << " Wait cl x " << endl;
            x.store(1,std::memory_order_seq_cst);

        }
        void client2()
        {
            cout << " Wait cl y " << endl;
            y.store(1,std::memory_order_seq_cst);
        }
        void bank1()
        {
            cout << " Wait bank 1 x " << endl;
            while(!x.load(std::memory_order_seq_cst)){ cout << " 1 working!" << endl;};

            cout << " Wait y load bank 1 " << endl;
            if(y.load(std::memory_order_seq_cst)) ++z;
        }

        void bank2()
        {
            cout << " Wait bank 2 y " << endl;
            while(!y.load(std::memory_order_seq_cst)){ cout << " 2 working!" << endl;};

            cout << " Wait x load bank 2 " << endl;
            if(x.load(std::memory_order_seq_cst)) ++z;
        }

        void Runner()
        {
            using namespace SequentiallyConsistent::E1;

            std::jthread th1(client1);
            std::jthread th2(client2);
            std::jthread th3(bank1);
            std::jthread th4(bank2);

        }
    }
    namespace E2
    {
        std::atomic<int> x,y;

        void creator()
        {
            y.store(10);
            x.store(10);
        }
        void check1()
        {
            cout << "check1 1" << y.load() << " " << x.load() << endl;
            if(x.load() == 10)
            {
                cout << "check1 2" << y.load() << " " << x.load() << endl;
                assert(y.load() == 10);
                y.store(5);
            }
            cout << "check1 3" << y.load() << " " << x.load() << endl;
        }
        void check2()
        {

            cout << "check2 1" << y.load() << " " << x.load() << endl;
            if(y.load() == 5)
            {
                cout << "check2 2" << y.load() << " " << x.load() << endl;
                assert(x.load() == 10);
            }
            cout << "check2 3" << y.load() << " " << x.load() << endl;

        }
        void Runner()
        {
            std::jthread th1(creator);
            std::jthread th2(check2);
            std::jthread th3(check1);
        }

    }
}
//#################################

int main()
{


//    memory_order::relaxed
////////////////////////////////////////////
    /// JUST BASIC EXAMPLE
//    RelaxedOrdering::E1::Uf_RelaxedOrdering();
    /// Relax Example
//    RelaxedOrdering::E2::Relax_Class<int>::Runner();
    /// Relax ANOTHER Example
//      RelaxedOrdering::E3::Memory_Order<memory_order_relaxed,int>::Runner();
    ///another ex
//    void RelaxedOrdering::E4::th2():
//    Assertion `y.load(memory_order_relaxed) == 20' failed.
    /*
     for (int i = 0; i < 100; ++i) {
        cout << i << endl;
        RelaxedOrdering::E4::Runenr();
    }
     */



//    memory_order::consume
////////////////////////////////////////////
    /// basic example
//    ReleaseConsumeOrdering::E1::ReleaseConsume::Runner();
    /// thinkable example [for me eeheh]
//    ReleaseConsumeOrdering::E2::ReleaseConsume::Runner();
    /// himmmm
//    ReleaseConsumeOrdering::E3::Consume::Runner();

/////////////////////////////////////////////



//    memory_order::acquire
/////////////////////////////////////////////
//        ReleaseAcquire::E1::runner();
//        ReleaseAcquire::E2::runner();
/////////////////////////////////////////////



//    memory_order_seq_cst
/////////////////////////////////////////////

//    SequentiallyConsistent::E1::Runner();
//    SequentiallyConsistent::E2::Runner();

/////////////////////////////////////////////




    return 0;
}