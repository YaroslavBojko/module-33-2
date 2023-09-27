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

class CaughtBoot : public std::exception
{
    const char* what() const noexcept override
    {
        return "Loss!!!";
    }
};


void play(Field* field)
{
    int sectorNumber;
    std::cout << "Enter the sector number (from 0 to 8): ";
    std::cin >> sectorNumber;

    if(field[sectorNumber].fish)
        throw field->fish;
    if (field[sectorNumber].boot)
        throw CaughtBoot();
}

int main() {
    std::srand(time(nullptr));
    Field field[9] = {0};

    int fieldFish = std::rand() % 9;
    field[fieldFish].busy = true;

    field[fieldFish].fish = new Fish();
    std::cout << "---------------CLUE---------------" << std::endl;
    std::cout << "Fish in " << fieldFish << " sector" << std::endl;

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
                std::cout << "Boot in " << fieldBoot << " sector" << std::endl;
                break;
            }
        }
    }
    std::cout << "--------------------------------------" << std::endl;

    int count = 0;
    while (true)
    {
        count++;
        try
        {
            play(field);
        }
        catch (const bool& x)
        {
            std::cout << "Victory!!!" << std::endl;
            std::cout << "You caught a fish  in " << count << " attempts!!!" << std::endl;
            break;
        }
        catch (const CaughtBoot& cb)
        {
            std::cout << "Loss!!!" << std::endl;
            std::cout << "You caught a boot  in " << count << " attempts!!!" << std::endl;
            break;
        }
        std::cout << "The sector is empty!!!" << std::endl;
    }



}
