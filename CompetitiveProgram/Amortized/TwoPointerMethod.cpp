#include <iostream>
using namespace std;

int arr[] = {1,3,2,5,1,1,2,3};

void SubArraySum(int i, int j, int target, int sum)
{

    if(sum == target)
    {
        cout << arr[i] << " " << arr[j] <<" " << sum <<  " if " << endl;
        cout << " yes " << endl;
        return;
    }
    else if(sum < target)
    {
        sum += arr[j];
        if(sum >= target)
            SubArraySum(i,j,target,sum);
        else
            SubArraySum(i,j+1,target,sum);
    }
    else
    {
        sum -= arr[i];
        if(sum < target)
            SubArraySum(i+1,j+1,target,sum);
        else if(sum == target)
            SubArraySum(i+1,j,target,sum);
        else
            SubArraySum(i+1,j,target,sum);

    }

}
void SumArray()
{
    for (int i = 1; i < 10; ++i) {
        SubArraySum(0,0, i,0);
    }
}

int ar[] = {1, 4, 5, 6, 7, 9, 9, 10};

void TwoSum(int i, int j, int sum, int target, int size)
{
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            sum=ar[i]+ar[j];
            if(sum==target)
            {
                printf("Output : [%d, %d]",i,j);
            }
        }
    }

}
void TwoSum()
{
    int size = sizeof(ar) / sizeof(ar[0]);
    std::sort(std::begin(ar), std::end(ar));

    int i,j,target=12,sum=0;
    TwoSum(i,j,0,target,size);
}
int main()
{




}

