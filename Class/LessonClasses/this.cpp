#include <iostream>
#include <inttypes.h>


class subClass
{
public:
    subClass(int num) : id(num) { std::cout << " C " << std::endl; };
    ~subClass(){ std::cout << " D " << std::endl; };
    int id;
    int get_id()
    {
        return id;
    }
    void set_id(int nid)
    {
        id = nid;
    }
};


int main()
{
    subClass *sb;
    sb = new subClass(1);
    sb->set_id(31);
    std::cout << sb->get_id() << std::endl;

    subClass subs[3] = {1,1,2};

    for(int i = 0; i < 3; i++)
        subs[i].set_id(5);

    for(auto x: subs)
        std::cout << "id "<< x.get_id() << std::endl;


}
