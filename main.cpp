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
    bool busy;
};

int main() {
    std::srand(time(nullptr));
    Field field[9] = {0};

    int fieldFish = std::rand() % 9;
    field[fieldFish].busy = true;

    field[fieldFish].fish = new Fish();

    for (int i = 0; i < 3; ++i)
    {
        while (true)
        {
            int fieldBoot = std::rand() % 9;
            if (field[fieldBoot].busy) continue;
            else
            {
                field[fieldBoot].boot = new Boot();
                field[fieldBoot].busy = true;
                break;
            }
        }
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
