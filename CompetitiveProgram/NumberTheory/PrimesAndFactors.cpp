#include <iostream>
using namespace std;


unsigned int factorial(unsigned int n)
{
    return  !n ? 1 : n * factorial(n - 1);
}


int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}
int gcd2(int a, int b)
{
    return (a%b == 0)? abs(b) : gcd(b,a%b);
}

int lcm(int a, int b)
{
    return a* b / gcd(a,b);
}
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    int f1 = 0, f2 = 1, f3 = 1;
    while (f3 <= n)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return f2;
}


void Diophantine(int a, int b ,int c)
{
    if(c % gcd(a,b) == 0)
    {
        cout << "POSSIBLE "<< a << " " << b << " " << c << endl;
    }
}

void SieveOfEratosthenes()
{
    int sieve[10] = {0};
    int n = 10;
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= n; u += x) {
            sieve[u] = x;
        }
    }

    for (int i = 2; i < n; ++i) {
        if(!sieve[i])
            cout << i << " ";
    }
};

bool WilsonTheorem(int is_prime)
{
    return factorial(is_prime-1)%(is_prime) == is_prime -1 ? 1 : 0;
};

void PythagoreanTriples(int lm)
{
    int a, b, c = 0,m = 2;

    while (c < lm) {
        for (int n = 1; n < m; ++n) {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if (c > lm)
                break;
            cout << a << " " << b << " " << c << endl;
        }
        m++;
    }

}

void Zeckendorf(int n)
{
    while (n > 0)
    {
        int f = fib(n);

        cout << f << " ";

        n = n - f;
    }
}

int main()
{


//    Zeckendorf(31);
//    PythagoreanTriples(20);
//    cout << WilsonTheorem(3) << " " <<WilsonTheorem(8) << endl;
//    Diophantine(47,30,1);

//    cout << gcd(3,6) << endl;
//    cout << lcm(3,8) << endl;

    return 0;
}