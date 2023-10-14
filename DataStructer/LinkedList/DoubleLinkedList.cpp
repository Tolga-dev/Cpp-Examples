#include <iostream>

struct node *head = nullptr;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void CreateBegin( int data)
{
    auto *ptr = (struct node*) malloc(sizeof(struct node*));
    if(head == nullptr)
    {
        ptr->next = nullptr;
        ptr->prev = nullptr;
        ptr->data = data;
        head = ptr;
    }
    else
    {
        ptr->data = data;
        ptr->prev = nullptr;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}
void CreateLast(int data)
{
    auto *ptr = (struct node*) malloc(sizeof(struct node*));
    auto *temp = (struct node*) malloc(sizeof(struct node*));
    ptr->data = data;

    if(head == nullptr)
    {
        ptr->next = nullptr;
        ptr->prev = nullptr;
        head = ptr;
    }
    else
    {
        temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = nullptr;
    }
}
void addUserDefinedPlace( int i, int data)
{
    struct node* ptr = (struct node *) malloc(sizeof(struct node)), *temp = head;

    for (int j = 0; j < i; ++j) {
        temp = temp->next;
    }

    ptr->data = data;
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next = ptr;
    temp->next->prev = ptr;

}
void deleteLastOne()
{
    struct node * ptr;
    if(head->next == NULL)
    {
        head = NULL;
        free(head);
    }
}
void deleteSpecified(int data)
{
    /*
    struct node *ptr = head, *temp;

    while(ptr->next->data != data)
        ptr = ptr->next;
    if(ptr -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
    }
    */

} /// sonra denenmeli!

void search(int item)
{
    struct node *ptr;
    int i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nitem found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\nItem not found\n");
        }
    }

}
void display()
{
    struct node *ptr = head;

    while(ptr != nullptr)
    {
       /* if(ptr->prev != nullptr)
            std::cout <<" next " << ptr->prev->data << std::endl;
        if(ptr->next != nullptr)
            std::cout <<" prev" << ptr->next->data << std::endl;*/
        std::cout << " middle " << ptr->data << std::endl;
        ptr = ptr->next;
      //  std::cout << " ---------------------- " << std::endl;
    }
}

int main()
{

    CreateBegin(1);
    CreateBegin(151);
    CreateBegin(13);
    CreateBegin(15);
    CreateBegin(14);

    search(13);
    display();

    return 0;
}