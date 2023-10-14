#include <iostream>

struct tree
{
    int data;

    struct tree *left;
    struct tree *right;
};

struct tree *insert(struct tree* node, int data)
{
    if(node == NULL)
    {
        struct tree* root = (struct tree*) malloc(sizeof(struct tree*));
        root->right = NULL;
        root->left = NULL;
        root->data = data;
        return root;
    }

    if(node->data < data)
    {
        node->right = insert(node->right,data);
        return node;
    }

    node->left = insert(node->left,data);
    return node;
}
void print(struct tree *t)
{
    if(t == NULL)
        return;
    print(t->left);
    std::cout << t->data << " ";
    print(t->right);

}
int find(struct tree* node, int t)
{
    if(node == nullptr)
        return -1;
    if (node->data == t)
        return 1;
    else if(node->data < t)
        find(node->right,t);
    else
        find(node->left,t);

}
int max(struct tree* node)
{
    while(node->right != nullptr)
        node = node->right;
    return node->data;
}
int min(struct tree* node)
{
    while(node->left != nullptr)
        node = node->left;
    return node->data;
}

int main()
{
    struct tree *t = nullptr;

    t = insert(t,12);
    t = insert(t,6);
    t = insert(t,28);
    t = insert(t,27);

    std::cout << find(t, 28) << std::endl;
    std::cout << find(t, 6) << std::endl;
    std::cout << find(t, 26) << std::endl;


    return 0;
}