#include <iostream>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a, int b)
{
    return (a > b)? a : b;
}
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

struct Node* Insert(struct Node* node, int key)
{
    if(node == nullptr)
    {
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->right = nullptr;
        node->left = nullptr;
        node->key = key;
        node->height = 1;
        return node;
    }

    if(key < node->key)
    {
        node->left = Insert(node->left, key);
    }
    else if(key >= node->key)
    {
        node->right = Insert(node->right, key);
    }
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);


    return node;
}

void PreOrder(struct Node* root, int d)
{
    if(root != nullptr )
    {
        std::cout << root->key << " " << d << std::endl;
        PreOrder(root->left,-1);
        PreOrder(root->right,1);
    }

}

int main()
{
    struct Node* root = nullptr;

    root = Insert(root,30);
    root = Insert(root,20);
    root = Insert(root,10);

    PreOrder(root,0);

}