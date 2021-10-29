#include <iostream>
#include <windows.h>

#include"Combat.h"

using namespace std;
bool game_running = true;

int x = 19;
int y = 1;

char map[35][55] = {
"*  -  -  .  - -- .-@@@@@@@@@@@@@- ' [Planetname].*",
" -' ''  ' '- .  @@@             @@@ '. .. '.  - -.",
".  '   -  . -@@@                    @@.  '  '     ",
" -' .' .' -@@                          @@ -' '.   ",
"- '  .  @@                               @- '  .  ",
" .- '' @                                   @ '. --",
".  -  @                                     @  -  ",
" -' .@                                1      @- -.",
"'  '@                                         @.  ",
" ''@                                           @'-",
". @'                                            @ ",
" -@                                             @'",
"- @                                              @",
" @                                               @",
"-@                                               @",
" @       2                                       @",
"-@                                               @",
" @                                               @",
"'@                                               @",
" @                                               @",
"-@                                               @",
" @                                               @",
".@                                               @",
" .@                                         3    @",
"' @                                             @ ",
" -.@'                                          @-.",
"   .@                                         @-  ",
"-''..@                                       @. .-",
"--.'--@                                     @-  '.",
"'  ' -0@                                  @'' .- .",
" .' '' -@-                              @'  .- .. ",
"'  '  . . @`                          @@  -  .    ",
"  .  -  .  .@@                     @@ -- -. .-''  ",
".  - .   . '  -@@@             `@@`  .  -         ",
" .' '- .. -- ' -  - @@@@@@@@@!- .- -. '' '- '- .' ",
};

int charVerification(char value, int currLevel) {
    if (value == '1' && currLevel == 1)
        return 1;
    else if (value == '2' && currLevel == 2)
        return 2;
    else if (value == '3' && currLevel == 3)
        return 3;
    else
        return -1;
}

int movement(int currLevel)
{
    while (game_running == true)
    {
        system("cls");
        for (int display = 0; display < 35; display++) {
            cout << map[display] << endl;
        }
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN)) {
            int y2 = y + 1;
            if (map[y2][x] == ' ') {
                map[y][x] = ' ';
                y++;
                map[y][x] = '=';
            }
            else {
                int level = charVerification(map[y2][x], currLevel);
                if (level != -1)
                    return level;
            }
        }
        if (GetAsyncKeyState(VK_UP)) {
            int y2 = y - 1;
            if (map[y2][x] == ' ') {
                map[y][x] = ' ';
                y--;
                map[y][x] = '=';
            }
            else {
                int level = charVerification(map[y2][x], currLevel);
                if (level != -1)
                    return level;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            int x2 = x + 1;
            if (map[y][x2] == ' ') {
                map[y][x] = ' ';
                x++;
                map[y][x] = '=';
            }
            else {
                int level = charVerification(map[y][x2], currLevel);
                if (level != -1)
                    return level;
            }
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            int x2 = x - 1;
            if (map[y][x2] == ' ') {
                map[y][x] = ' ';
                x--;
                map[y][x] = '=';
            }
            else {
                int level = charVerification(map[y][x2], currLevel);
                if (level != -1)
                    return level;
            }
        }
    }
    return 0;
}