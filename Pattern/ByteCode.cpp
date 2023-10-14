#include <iostream>
#include <stack>
#include <vector>

enum Instructions
{
    SET_POWER = 0,
    SET_AGE = 1,
    LEN = 2
};

Instructions getInstruction(int val)
{

    for(int i = 0; i <LEN ; i++)
    {
        if((Instructions)i == val)
            return (Instructions)i;
    }
}

class Man
{
public:
    Man(int power, int age) : power_(power), age_(age){}

     int power_;
     int age_;
};

class VM
{
public:

    VM() { Man man1(10,20); Man man2(100,200); men[0] = &man1; men[1] = &man2; }

    VM(Man man, Man man2) { men[0] = &man; men[1] = &man2; }

    inline void Execute(int byteCode[], int size)
    {
        for(int i = 0; i < size ; i++)
        {
            Instructions ix = getInstruction(byteCode[0]);

            switch (ix) {
                int power,age,man;
                case SET_POWER:

                    power = PopStack();
                    man = PopStack();
                    std::cout << man << power << std::endl;
                    SetPower(power, man);
                    break;
                case SET_AGE:
                    age = PopStack();
                    man = PopStack();
                    std::cout << man << power << std::endl;
                    SetAge(age, man);
                    break;
                default:
                    std::cout << " no " << std::endl;
                    break;


            }

        }
    }

    void SetPower(int index, int power)
    {
        men[index]->power_ = power ;
        std::cout << men[index] << " get " << power << std::endl;
    }
    void SetAge(int index, int age)
    {
        men[index]->age_ = age ;
        std::cout << men[index] << " get " << age << std::endl;
    }

    int PopStack()
    {
        int a = Stack.top();
        Stack.pop();
        return a;

    }

    std::stack<int> Stack;
    Man* men[2];

};


int main()
{

    Man m(10,10), n(20,20);
    auto vm = new VM(m,n);

    int arr[2] = {0,1};

    vm->Execute(arr,2);


}