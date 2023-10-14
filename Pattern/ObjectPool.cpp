#include <iostream>
#include <list>

class Resource
{
    int data;
public:

    Resource() : data(0) {}

    void reset() { data = 0;}

    int getData() { return data; }

    void setData(int assign) { data = assign; }

};

class Pool
{

public:
    Pool() {}

    static Pool* getIns() { if(instance == 0) { instance = new Pool;} return instance;}

    Resource* getResource()
    {
        if(resources.empty()) { std::cout << " Created! " << std::endl; return new Resource; }
        else
        {
            std::cout << "Already Exited! "<< std::endl;
            Resource* resource = resources.front();
            resources.pop_front();
            return resource;
        }
    }
    void returnResource(Resource* obj)
    {
        obj->reset();
        resources.push_back(obj);
    }

private:
    std::list<Resource*> resources;
    static Pool* instance;
};
Pool* Pool::instance = 0;
int main()
{
    Pool* pool = Pool::getIns();

    Resource* one;
    Resource* two;

    one = pool->getResource();

    one->setData(31);
    std::cout << one << " " << one->getData()<<std::endl;

    two = pool->getResource();
    one->setData(32);
    std::cout << two << " " << two->getData()<<std::endl;

    pool->returnResource(one);
    pool->returnResource(two);


    one = pool->getResource();
    std::cout << one << " " << one->getData()<<std::endl;

    two = pool->getResource();
    std::cout << two << " " << two->getData()<<std::endl;

}