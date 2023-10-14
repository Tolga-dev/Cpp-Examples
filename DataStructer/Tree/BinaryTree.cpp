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

void InOrderprint(struct tree *t)
{
    if(t == NULL)
        return;
    InOrderprint(t->left);
    std::cout << t->data << " ";
    InOrderprint(t->right);
}
void PreOrder(struct tree * t)
{
    if(t == nullptr)
        return;

    std::cout << t->data << " ";
    PreOrder(t->left);
    PreOrder(t->right);
}
void PostOrder(struct tree * t)
{
    if(t == nullptr)
        return;

    PreOrder(t->left);
    PreOrder(t->right);
    std::cout << t->data << " ";
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

    return 0;
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
int PrintLevel(struct tree *node, int t, int level)
{
    if(node == nullptr)
    {
        std::cout << " not found! " << std::endl;
        return -1;
    }
    if (node->data == t)
        return level;
    else if(node->data < t)
        level = PrintLevel(node->right,t,level + 1);
    else
        level = PrintLevel(node->left,t,level + 1);

        return level;


}
/*
if (t == NULL)
    return 0;

if (t->data == number)
    return level;

int downlevel = PrintLevel(t->left, number, level + 1);

if (downlevel != 0)
    return downlevel;

 return PrintLevel(t->right, number, level + 1);
 */

int main()
{
    struct tree *t = nullptr;

    t = insert(t,6);
    t = insert(t,2);
    t = insert(t,8);
    t = insert(t,1);
    t = insert(t,4);
    t = insert(t,3);
    t = insert(t,5);

    std::cout << PrintLevel(t,4,0) << std::endl;

/*    PostOrder(t);
    InOrderprint(t);
    PreOrder(t);*/

/*    std::cout << find(t, 28) << std::endl;
    std::cout << find(t, 6) << std::endl;
    std::cout << find(t, 26) << std::endl;*/


    return 0;
}