#include <iostream>
///////// will updated
struct dict
{
    char c;
    struct dict *dict;
    const char *MAX[29]; // letters in alphabet
};

struct dict* insert(struct dict* node,std::string word)
{
    if(node == nullptr)
    {
        struct dict *root = (struct dict*) malloc(sizeof(struct dict*));
        root->c = word[0];

        word.erase(0);
        return root;
    }

    if(node->c != word[0])
    {

    }

    return node;
}

void print(struct dict *t)
{
    if(t == nullptr)
        return;
    if(t->parent == nullptr)
        std::cout <<t->c<< std::endl;
    else
        std::cout <<t->c << t->parent->c<< std::endl;

    print(t->child);

}
// childlar araso gezmeyi yapacaz
int main()
{

    struct dict *d = nullptr;

    std::string word = "hello";
    std::string word2 = "hell";


    d = insert(d,"/");
    d = insert(d,"word");

    print(d);

}

