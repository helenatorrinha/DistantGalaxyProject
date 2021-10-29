#ifndef CharacterConstructor_h
#define CharacterConstructor_h
#include <iostream>

class CharacterConstructor
{
public:
    int hp; //Only decreases with damage from the the other player
    int latk; //light attack
    int hatk; //heavy attack
    int stm;
    int damage; 
    
    void giveValues(int _hp, int _latk, int _hatk, int _stm, int _damage)
    {
        hp = _hp;
        latk = _latk;
        hatk = _hatk;
        stm = _stm;
        damage = _damage;
    }
};

CharacterConstructor ReturnCharacterValues (int level, int character) 
{
    CharacterConstructor values;
    if (level == 1 && character == 1)
    {
       values.giveValues(50, 15, 20, 18, 0);
    }
    else if (level == 1 && character == 2)
    {
        values.giveValues(60, 10, 17, 25, 0);
    }
    else if (level == 1 && character == 3)
    {
        values.giveValues(55, 12, 17, 23, 0);
    }
    else if (level == 2 && character == 1)
    {
        values.giveValues(60, 20, 25, 21, 0);
    }
    else if (level == 2 && character == 2)
    {
        values.giveValues(70, 15, 22, 28, 0);
    }
    else if (level == 2 && character == 3)
    {
        values.giveValues(65, 17, 24, 26, 0);
    }
    else if (level == 3 && character == 1)
    {
        values.giveValues(75, 26, 30, 27, 0);
    }
    else if (level == 3 && character == 2)
    {
        values.giveValues(85, 21, 26, 34, 0);
    }
    else if (level == 3 && character == 3)
    {
       values.giveValues(80, 23, 28, 30, 0);
    }
    return values;
}

CharacterConstructor ReturnMonsterValues (int level)
{
    CharacterConstructor values;
    if (level == 1)
    {
       values.giveValues(75, 5, 10, 15, 0);
    }
    else if (level == 2)
    {
        values.giveValues(100, 10, 17, 20, 0);
    }
    else if (level == 3)
    {
        values.giveValues(120, 15, 20, 22, 0);
    }
    return values;
}

#endif

