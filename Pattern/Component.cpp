#include <iostream>


int main()
{

}


// example 1

class World;

enum Inputs
{
    LEFT,
    RIGHT
};

class InputComponent
{
public:
    InputComponent(World* world) : world_(world) {}

    void Update()
    {
        Inputs inputs;
        switch (inputs) {
            case LEFT:
              ///  world_.velocity -= world_.walk_acc;
                break;
            case RIGHT:
              ///  world_.velocity += world_.walk_acc;
                break;
            default:
                break;
        }
    }
private:
    World* world_;
};

class World
{
public:

    void update(){ inputComponent->Update(); }

    friend class InputComponent;

private:
    InputComponent* inputComponent;
    int walk_acc;
    int velocity;
};

