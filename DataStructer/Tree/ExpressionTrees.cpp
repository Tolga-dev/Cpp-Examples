#include <iostream>

struct tree
{
    struct tree* left;
    struct tree* right;
    int data;
    char operation;
};

struct tree* insert(struct tree* node, int data, char operation)
{
    if(node == nullptr)
    {
        struct tree* root = (struct tree*) malloc(sizeof(struct tree*));
        root->data = data;
        root->operation = operation;
        root->left = nullptr;
        root->right = nullptr;

        return root;
    }
    if(data < node->data)
    {
        node->left = insert(node->left, data, operation);
        return node;
    }

    node->right = insert(node->right, data, operation);

    return node;
}

void PreOrder(struct tree* tree)
{
    if(tree == nullptr)
        return;

    std::cout <<tree->data <<" "<< tree->operation << ",";

    PreOrder(tree->left);
    PreOrder(tree->right);
}
void PostOrder(struct tree* tree)
{
    if(tree == nullptr)
        return;

    PostOrder(tree->left);
    PostOrder(tree->right);
    std::cout <<tree->data <<" "<< tree->operation << ",";
}
void InOrder(struct tree* tree)
{
    if(tree == nullptr)
        return;

    InOrder(tree->left);
    std::cout <<tree->data <<" "<< tree->operation << ",";
    InOrder(tree->right);
}

int main()
{
    struct tree* t = nullptr;

    int arr[] = {25,15,50,22,35,70,12,18,24,31,44,29,32};

    t = insert(t, arr[0],'+');
    t = insert(t, arr[1],'+');
    t = insert(t, arr[2],'*');
    t = insert(t, arr[3],'*');
    t = insert(t, arr[4],'+');
    t = insert(t, arr[5],'g');
    t = insert(t, arr[6],'a');
    t = insert(t, arr[7],'b');
    t = insert(t, arr[8],'c');
    t = insert(t, arr[9],'*');
    t = insert(t, arr[10],'f');
    t = insert(t, arr[11],'d');
    t = insert(t, arr[12],'e');

    InOrder(t);

    return 0;
}