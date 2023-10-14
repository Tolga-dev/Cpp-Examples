#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{


    std::string line;
    int st;
    int q;
    getline(std::cin,line);

    q = line[0]-48;
    int m[q][2];

    for (int i = 0; i < q; ++i) {
        m[i][0] = 0;
        m[i][1] = 0;
    }

    int mx = line[2] - 48;

    while (mx > 0)
    {
        getline(std::cin,line);

        st=line[0]-48;
        q = line[2]-49;

        if(st == 2)
            m[q][0] = 2;
        if(st == 1)
            m[q][1] += 1;

        if(st == 3)
        {
            if(m[q][0] == 2 || m[q][1] == 2)
            {
                cout << "Yes"<< endl;
            }
            else
            {
                cout << "No"<< endl;
            }

        }

        mx--;
    }


    return 0;
}
