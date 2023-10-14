#include <iostream>
#include <bitset>
using namespace std;
#define GetSize(ar) (sizeof(ar) / sizeof((ar)[0]))
#define Print(arr) for(auto & i : (arr)){ std::cout << i  << endl;}


int hamming(int a, int b) {
    return __builtin_popcount(a^b);
}

int main()
{
    int a = 0b001011;
    int b = 0b001000;

    cout << hamming(a,b)<< endl;

}
