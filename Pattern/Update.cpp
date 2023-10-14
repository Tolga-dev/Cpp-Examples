#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>
#define MAX_ENTITIES 10;

class Entity
{
public:
    Entity() : x_(0), y_(0) {}

    virtual ~Entity(){}
    virtual void Update()=0;

    double x() const { return x_;}
    double y() const { return y_;}

    void set_x(double x){ x_ = x; }
    void set_y(double y){ y_ = y; }

private:
    double x_;
    double y_;
};

class Enemy : Entity
{
public:
    Enemy(){};
    void Update()=0;

    int id = 0;
};

class World
{
public:
    World(int num) : numEntities_(num){}

    void WorldLoop();
    void CreateEntities(Enemy* entity);

private:
    int numEntities_;
    Enemy* entities_[1];
};

void World::WorldLoop()
{
    for(int i = 0; i < numEntities_; i++)
    {
        std::cout << entities_[i]->id << std::endl;
        entities_[i]->Update();
    }
}

void World::CreateEntities(Enemy* enemy)
{
    for(int i = 0; i < numEntities_; i++)
    {
        entities_[i] = enemy;

    }
}

int main()
{
    World startWorld(1);
    Enemy* entity;
    startWorld.CreateEntities(entity);
    startWorld.WorldLoop();

}
