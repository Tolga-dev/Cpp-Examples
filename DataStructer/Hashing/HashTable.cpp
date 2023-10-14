#include <bits/stdc++.h>
using namespace std;

class SeperateHash
{

public:
    inline SeperateHash(int n)
    {
        this->n = n;
        this->table = new list<int>[]();
    }

    inline int getHashIndex(int x)
    {
        return x % this->n;
    }

    inline void add(int index)
    {
        this->table[this->getHashIndex(index)].push_back(index);
    }

    void del(int x);

    void displayHash();


private:
    int n;
    std::list<int, std::allocator<int> > * table;
};


void SeperateHash::displayHash()
{
    for(int i = 0; i < n; i++)
    {
        cout << i;
        for(auto &x : table[i])
        {
            std::cout << " -> " << x;
        }
        std::cout << std::endl;
    }

}
void SeperateHash::del(int key)
{
    int index = getHashIndex(key);
    list<int> :: iterator i;

    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash()
{
    int arr[4] = {12, 3, 3, 2};
    int size = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    SeperateHash obj = SeperateHash(size);
    for(int i = 0; i < size; i++) {
        obj.add(arr[i]);
    }

    std::operator<<(std::cout, "Initial Hash:\n");

    obj.displayHash();
    std::operator<<(std::cout, "\nRemoving 23 from Hash: ");

    obj.del(23);
    std::cout.operator<<(std::endl);
    obj.displayHash();
}

int main()
{
    Hash();
    return 0;
}
