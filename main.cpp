#include <iostream>
#include <stdlib.h>

class Fish
{

};

class Boot
{

};

class Field
{
public:
    bool fish;
    bool boot;
};

int main() {
    std::srand(time(nullptr));
    Field field[9] = {0};

    field[rand() % 9].fish = new Fish();

    for (int i = 0; i < 3; ++i)
    {
        if ((field[rand() % 9].boot) == (field[rand() % 9].fish)) std::cout << "Error";
        field[rand() % 9].boot = new Boot();
    }

    for (int i = 0; i < 9; ++i)
    {
        std::cout << field[i].fish << " " ;
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; ++i)
    {
        std::cout << field[i].boot << " " ;
    }
    std::cout << std::endl;



}
