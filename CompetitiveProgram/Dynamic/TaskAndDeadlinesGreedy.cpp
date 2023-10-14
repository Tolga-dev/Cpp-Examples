#include <bits/stdc++.h>


using namespace std;

void sort(int arr[4][2],int n)
{
    int m = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
            if(arr[i][m]>arr[j][m]){
                swap(arr[i], arr[j]);
            }
    }

}

int main()
{
    int arr[4][2] = {{4,2},{3,5},{2,7},{4,5}};
    sort(arr,4);

    for(auto & i : arr)
    {
        cout << i[0] << " " << i[1] << endl;
    }


    int p = 0,t=0,s=0;

    for (auto & i : arr) {

        t+=i[0];
        p = i[1] - t;
        s += p;
        cout << t << " " << p << endl;
    }

    cout << s << endl;


}

