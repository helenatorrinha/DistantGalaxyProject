#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "CharacterConstructor.h"
#include "Map.h"
using namespace std;



bool Combat(CharacterConstructor player, CharacterConstructor monster)
{
    int choice;

    cout << "You can start!\n";

    while (player.hp > 0 && monster.hp > 0)
    {
        do
        {

            cout << "\nThe monster has " << monster.hp << " health points left\n\n";
            cout << "What do you want to do?\n You have " << player.hp << " health points.\n You have " << player.stm << " stamina points. \n 1 -> Heavy Attack (This attack has " << player.hatk << " damage. You will lose 6 stamina.) \n 2 -> Light Attack(This attack has" << player.latk << " damage. You will lose 2 stamina.) \n 3 -> Defensive mode(This will not give damage but you will receive 10 stamina.) \n";
            cin >> choice;
        }         while (choice < 1 && choice > 3);
        bool isChoiceGood = false;
        while (isChoiceGood == false)
        {
            switch (choice)
            {
            case 1: //heavy Attack
                if (player.stm >= 6)
                {
                    isChoiceGood = true;
                    player.damage = ((rand() % 5 - 5) +player. hatk) + ((rand() % 5));
                    monster.hp = monster.hp - player.damage;
                    player.stm = player.stm - 6;
                    cout << "\nYou did " << player.damage << " damage to the monster!\n";
                    break;
                }
                else
                {
                    cout << "You don't have enough stamina, choose another attack\n";
                    cin >> choice;
                }
            case 2: // Light Attack
                if (player.stm >= 2)
                {
                    isChoiceGood = true;
                    player.damage = ((rand() % 2 - 2) + player.latk) + ((rand() % 2));
                    monster.hp = monster.hp - player.damage;
                    player.stm = player.stm - 2;
                    cout << "\nYou did " << player.damage << " damage to the monster!\n";
                    break;
                }
                else
                {
                    cout << "You don't have enough stamina, choose another attack\n";
                    cin >> choice;
                }
            case 3: //Defensive mode
                isChoiceGood = true;
                player.stm = player.stm + 10;
                player.hp = player.hp + 5;
                cout << "\nYou did no damage to the monster but regenerated 10 stamina\n You also regenerate 5 health points\n";
                break;
            default:
                cout << "Invalid attack, choose another move\n";
                cin >> choice;
                break;
            }

            if (isChoiceGood == true && monster.hp>=1) {
                if (monster.stm >= 6)
                {
                    monster.damage = ((rand() % 5 - 5) + monster.hatk) + ((rand() % 5));
                    player.hp = player.hp - monster.damage;
                    monster.stm = monster.stm - 6;
                    cout << "\nYou took " << monster.damage << " damage from the monster\n";
                    break;
                }
                else if (monster.stm <= 5 && monster.stm >= 2)
                {
                    monster.damage = ((rand() % 2 - 2) + monster.latk) + ((rand() % 2));
                    player.hp = player.hp - monster.damage;
                    monster.stm = monster.stm - 2;
                    cout << "\nYou took " << monster.damage << " damage from the monster\n";
                    break;
                }
                else
                {
                    monster.stm = monster.stm + 10;
                    monster.hp = monster.hp + 5;
                    cout << "\nThe monster entered defense mode and regenerated 10 stamina\nThe monster also regenerated 5 health points\n ";
                    break;
                }
            }
        }


        if (monster.hp < 1)
        {
            return true;
        }
        else if (player.hp < 1)
        {
            cout << "\nYou died! The Monster still has " << monster.hp << " HP left. Better luck next time!\nReturning to map\n";
            Sleep(5000);
            return false;            
        }
    }
    return false;
}

