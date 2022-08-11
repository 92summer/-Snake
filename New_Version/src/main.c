#include "../inc/food.h"
#include "../inc/map.h"
#include "../inc/rules.h"
#include "../inc/snake.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>

int main()
{
    // system("Command");命令行调用Command命令
    system("title 贪吃蛇");
    system("mode con cols=53 lines=23");
    int Esc_flag = 0;
    do
    {
        int difficulty = select_difficulty(); //难度
        system("cls");
        MapInit();

        Snake S = SnakeInit();
        direQ D = directionInit();
        int direction = right;
        int endGame_flag = 0;
        Point FoodPosition = build_food();

        do
        {
            ifEatFood(S, &FoodPosition);

            endGame_flag = if_inWallOrinBody(S);

            if (!_kbhit())//没按键盘
            {
                direction = Done_direction(D, direction);
                SnakeMove(direction, S, &FoodPosition);
                Delay_ms(difficulty);//数值越高蛇动越慢
                continue;
            }
            else
            {
                //direction = detect_move(direction);
                Add_direction(D, direction, detect_move());
            }

        } while (!endGame_flag);

        system("cls");//清屏
        printf("游戏结束！Game Over!\n");
        showCursor();
        printf("Esc--退出游戏\n");
        printf("任意键继续游戏");
        if (_getch() == 27)
        {
            Esc_flag = 1;
        }
    }
    while (!Esc_flag);
    return 0;
}
