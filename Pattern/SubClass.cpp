#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>

enum Sound { S1, S2};
enum Particles{ P1, P2};
class Powers
{
public:
    virtual ~Powers(){}
protected:
    virtual void active() = 0;

    inline void move(double x, double y) { std::cout << "move" << std::endl;}
    inline void Sound(Sound sound, double volume) {std::cout << "Sound"<< std::endl;}
    inline void SpawnParticles(Particles type, int time){std::cout << "Particles"<< std::endl;};

};
class SkyJump : public Powers
{
public:
    inline void active() override
    {
        Sound(S1, 1.0f);
        SpawnParticles(P1, 10);
        move(0,20);
    }
};

int main()
{
    SkyJump sk;
    sk.active();

}
