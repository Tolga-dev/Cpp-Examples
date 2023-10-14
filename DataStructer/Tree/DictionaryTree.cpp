#include <iostream>
///////// will updated
const char *MAX[50];
struct dict
{
    char c;
    struct dict *dict;
    struct words *word;
};

struct words
{
    std::string data;
    struct words *word;
};

struct dict* insert(struct dict* node, std::string data, char c)
{
    if(node == nullptr)
    {
        struct dict *root = (struct dict*) malloc(sizeof(struct dict*));
        struct words *word = (struct words*) malloc(sizeof(struct word*)+ sizeof(MAX));
        word->data = data;
        word->word = nullptr;

        root->word = word;
        root->dict = nullptr;
        root->c = c;
        return root;
    }

    node->dict = insert(node->dict, data,c);

    return node;

}

void print(struct dict *t)
{
    if(t == nullptr)
        return;

    print(t->dict);

    std::cout <<t->c << " "<< t->word->data<< std::endl;
}

int main()
{

    struct dict *d = nullptr;

    d = insert(d,"asd",'/');

    print(d);

}

