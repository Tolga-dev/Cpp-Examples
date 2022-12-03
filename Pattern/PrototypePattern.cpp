#include <iostream>
#include <memory>

namespace BadCode
{
    class Animal
    {
    public:
        Animal(std::string Type) : AnimalType(Type) {};

        std::string AnimalType;
    };
     class Mammals
    {
    public:
        std::string Name;
        Animal animal;

        Mammals(Animal animal1, std::string name) : animal(animal1), Name(name) { std::cout << name << " " << animal1.AnimalType << std::endl;};

    };

}
namespace Alternative
{
    class Animal
    {
    protected:
        std::string Type;
        int64_t Population;
    public:
        virtual Animal* Clone()=0;

        std::string GetType()
        {
            return Type;
        }
        int64_t GetPopulation()
        {
            return Population;
        }
    };
    class Type1 : public Animal
    {
    public:
        Type1(int64_t population, std::string type){ Type=type; Population = population; }
        Animal* Clone() { return new Type1(*this); }

    };

    class Spawner
    {
        static Animal* type1;
    public:

        static void Initialize(void)
        {
            type1 = new Type1(1000, "Mammals");
        }
        static Animal* GetType1Value()
        {
            return type1->Clone();
        }

    };
    Alternative::Animal* Alternative::Spawner::type1 = 0;

}

class Animal
{

};

int main()
{



    /*Alternative
    Alternative::Spawner::Initialize();
    Alternative::Animal* animal;

    animal = Alternative::Spawner::GetType1Value();
    std::cout << animal->GetType() << std::endl;
    */

     // BadCode::Mammals mammals(BadCode::Animal("Mammals"), "Human");



    return 0;
}
