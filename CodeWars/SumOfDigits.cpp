#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")

int digital_attemp_1(int no,int sum = 0)
{

    while(no > 0)
    {
        sum += (no % 10);
        no /= 10;
    }

    return sum > 9 ? digital_attemp_1(sum) : sum;
}
int digital_attemp_2(int no,int sum = 0)
{
    return no > 0 ? digital_attemp_2(no/10,sum + (no % 10)) : (sum > 9 ? digital_attemp_2(sum) : sum);
}

int main()
{
    cout << digital_attemp_2(16) << endl;
    cout << digital_attemp_2(0) << endl;
    cout << digital_attemp_2(9) << endl;
    cout << digital_attemp_2(195) << endl;
    cout << digital_attemp_2(132189) << endl;
    cout << digital_attemp_2(493193) << endl;

}