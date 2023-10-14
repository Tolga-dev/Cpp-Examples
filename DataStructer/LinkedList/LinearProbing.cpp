#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Hash
{
public:
    Hash(int size)
    {
        this->size = size;
        for(int i = 0; i < size; i++)
                arr[i] = -1;
    }

    void insertItem(int key)
    {
        int index = hashFunction(key);

        while(true)
        {
            if(arr[index] == -1)
            {
                arr[index] = key;
                break;
            }
            else
            {
                index++;
                if(index >= size)
                    index = 0;
            }
        }

    }
    void displayHash();

    int hashFunction(int x) const {
        return (x % size);
    }

private:
    int size;
    int arr[];
};

void Hash::displayHash() {
    for (int i = 0; i < size; i++) {

        cout << i << " : "<< arr[i] << endl;
    }
}


int main()
{

    Hash h(10);
    h.insertItem(15);
    h.insertItem(11);
    h.insertItem(15);
    h.insertItem(15);
    h.insertItem(15);
    h.insertItem(15);
    h.insertItem(15);
    h.insertItem(15);
    h.insertItem(15);

    h.displayHash();

    /*
    h.deleteItem(12);

    h.displayHash();
*/


    return 0;
}