#include<bits/stdc++.h>
using namespace std;


int binCoff_for(vector<vector<int>> vec,int n, int m)
{
    if(m > n) return 0;

    if (m == 0 || n == m ) return 1;

    return binCoff_for(vec, n-1,m-1) + binCoff_for(vec,n-1,m);
}

//https://www.codewars.com/kata/5174a4c0f2769dd8b1000003/train/cpp
std::vector<int> solution(std::vector<int> nums) {
    sort(nums.begin(),nums.end());
    return nums;
}


int main()
{





    //    cout << binCoff_for(5,2)<< endl;

}
