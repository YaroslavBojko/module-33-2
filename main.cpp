#include <iostream>
#include <stdlib.h>
#include <exception>

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

void play(Field* field)
{
    int sectorNumber;
    std::cout << "Enter the sector number (from 0 to 8): ";
    std::cin >> sectorNumber;

    if(field[sectorNumber].fish)
        throw std::exception();

}

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

    try
    {
        play(field);
    }
    catch (const std::exception& )
    {
        std::cout << "Caught a fish!!!" << std::endl;
    }


}
