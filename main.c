#include "./inc/food.h"
#include "./inc/map.h"
#include "./inc/rules.h"
#include "./inc/snake.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>

int main()
{
    // system("Command");命令行调用Command命令
    system("title 贪吃蛇");
    system("mode con cols=53 lines=23");

    MapInit();

    Snake S = SnakeInit();
    int direction = right;
    int endGame_flag = 0;
    Point FoodPosition = build_food();
    do
    {
        ifEatFood(S, &FoodPosition);

        endGame_flag = if_inWallOrinBody(S);

        if (!_kbhit())
        {
            SnakeMove(direction, S, &FoodPosition);
            Delay_ms(200);//数值越高蛇动越慢
            continue;
        }
        else
            direction = detect_move(direction);

    } while (!endGame_flag);
    
    system("cls");//清屏
    printf("Game Over!\n");
    showCursor();
    system("pause");   
    return 0;
}
