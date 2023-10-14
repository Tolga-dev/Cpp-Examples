#include <cstdio>
#include <iostream>
#include <cstdlib>
void Print();
struct List* list = (struct List*)malloc(sizeof(struct List*));

struct List
{
    int data;
    struct List* next;
};

void Create(int data)
{
    struct List* t = (struct List*) malloc(sizeof(struct List*));

    t->data = data;

    t->next = list;

    list = t;

}

void del(int key)
{
    struct List* ptr = list, *prev = nullptr;

    while(ptr)
    {
        if(key == ptr->data)
            break;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    Print();
}
void delLastElement()
{
    struct List* ptr = list, *t;

    while(ptr->next != nullptr)
    {
        t = ptr;
        ptr = ptr->next;
    }
    t->next = nullptr;
    free(ptr);
}
void delBegin()
{
    struct List* ptr = list, *t;

    list = ptr->next;
    free(ptr);

}
void Print()
{
    struct List* temp = list;

    while(temp->next != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;

}
int store()
{
    FILE *fp;
    struct List *p = list;

    if((fp = fopen("/home/xamblot/CLionProjects/CppExamplePractices/list.txt","w")) == nullptr)
        return  -1;

    while (p){
        fwrite(p, sizeof(struct List*)-2*sizeof(*p), 1, fp);

        p = p->next;

    }
    printf("List was stored\n");
    fclose(fp);

    return 0;

}

int main()
{
    Create(1);
    Create(2);
    Create(3);
    Create(4);
    Create(5);
    del(4);
    delLastElement();
    delBegin();

    Print();
    store();
    return 0;
}
