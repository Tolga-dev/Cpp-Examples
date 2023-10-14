#include <iostream>

using namespace std;
int coins[] = {1,2,5,10,20,50,100,200};

void find(int input,int j,int c)
{
    if(input == 0)
    {
        cout << c << endl;
        return;
    }
    if(input >= coins[j])
    {
        input -= coins[j];
        find(input,j,c+1);
    }
else
        find(input,j-1,c);
}

int main()
{
    find(16,(sizeof(coins) / sizeof(coins[0]))-1,0);


}