#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define print(m) std::cout << m << std::endl;
#define SumArr(arr,n) int size = sizeof(arr) / sizeof(arr[0]); \
    for(int i = 0; i<= size; i++){      \
        n += arr[i]; }
#define sum(i,j) i+j
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
typedef vector<pair<int, int>>  vpii;
typedef vector<int>  vi;
typedef set<int>  si;
typedef multiset<int>  mtsi;
typedef map<string,int>  mpsi;

int main()
{




    return 0;

}




void DataStructer()
{
    {
        {
            bitset<2> s2(string("00"));
            bitset<2> s3(string("11"));
            print((s2&s3));
            print((s2|s3));
            print((s2^s3));
        }
        {

            bitset<2> s(string("00"));

            print(s.count());
            s[1] = true;
            s[0] = true;
            print(s.count());
        }
    }

    {
        mpsi m;
        m["a"] = 34;
        m["b"] = 33;
        m["c"] = 32;
        m["d"] = 31;
        m["d"] = 32;
        print(m["d"]);
        print(m.count("d"));
    }
    {
        mtsi ms;
        ms.insert(1);
        ms.insert(1);
        ms.insert(1);
        print(ms.count(1));
        ms.erase(ms.find(1));
        print(ms.count(1));
        ms.erase(1);
        print(ms.count(1));
    }
    {
        si s;
        s.insert(3);
        s.insert(3);
        s.insert(3);
        cout << s.count(3) << endl;
        for (auto i : s) {
            cout << s.count(i) << endl;
        }
    }
    {
        vi v;
        v.pb(2);
        v.pb(5);
        v.pb(2);
        v.pop_back();
        cout << v[0] << " " << v[1] << " " << v[2] << '\n';
        for (auto i : v ) {
            cout << i << endl;
        }
    }
}
void ShorteningCode()
{
    {
        [[maybe_unused]]  ll a, b;

        int arr[] = {3, 7, 11, 15, 19};
        int n = 0;
        SumArr(arr, n);
        std::cout << n << std::endl;
    }
    {
        cout << "-------" << "\n";
        vpii v;
        v.pb(mp(1, 2));
        v.pb(mp(1, 2));
        v.pb(mp(1, 2));

        for (auto & i : v) {
            cout << sum(i.f,i.s) << "\n";
        }

    }
    {
        [[maybe_unused]] int n = 6;
        rep(i, 1, 6)cout << i << "\n";
        cout << "-------" << "\n";
    }


}
void InputOutPut()
{
    /// standart ios, get line and write it
    freopen("/home/xamblot/CLionProjects/CppExamplePractices/out.txt","r" , stdin);
    freopen("/home/xamblot/CLionProjects/CppExamplePractices/in.txt","w" , stdout);

    string x;

    while(!cin.eof() && cin >> x)
    {
        cout << x << endl; // writes to output.txt
    }
    /// get line
    string s;
    getline(cin, s);
    printf(" %s \n ", s.c_str());
    /// while line
    while(cin >> s)
    {
        printf(" %s \n ", s.c_str());
    }
}

