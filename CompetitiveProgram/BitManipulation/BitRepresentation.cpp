#include <iostream>
#include <bitset>
using namespace std;
#define GetSize(ar) (sizeof(ar) / sizeof((ar)[0]))
#define Print(arr) for(auto & i : (arr)){ std::cout << i  << endl;}
void BitRepresentation();



int main()
{

 BitRepresentation();

}

void BitRepresentation()
{
    {

        int x = (1 << 1) | (1 << 3) | (1 << 8);
        int y = (1 << 12) | (1 << 3) | (1 << 9);
        int z = x | y;

        for (int i = 0; i < 31 ; ++i) {
            if(z & (1 << i)) cout << i << " ";
        }

    }
    {
        int x = 32;

        cout << __builtin_clz(x) << endl;
        cout << __builtin_ctz(x) << endl;
        cout << __builtin_popcount(x) << endl;
        cout << __builtin_parity(x) << endl;
    }
    {
        int x = 32;

        for (int i = 31; i >= 0; i--) {
            if(x & (1 << i))
                cout << "1";
            else
                cout << "0";
        }
    }
    {
        bitset<6> x = 0b101011, y = 0b000000;

        cout << (x & y) << endl;
        cout << (x | y) << endl;
        cout << (x | y).to_ulong() << endl;
        cout << (~x) << endl;
    }
    {
        bitset<6> x = 0b1110;
        x >>= 2;
        cout << x.to_ullong() << endl;
        x <<= 2;
        cout << x.to_ullong() << endl;
    }
    {
        bitset<6> x = 0b110001;
        x <<= 3;
        cout << x.to_ullong() << endl;
        x >>= 3;
        cout << x.to_ullong() << endl;

    }


}