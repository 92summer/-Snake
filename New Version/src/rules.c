#include "rules.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int select_difficulty()
{
    printf("WSAD或者↑↓←→控制蛇运动\n");
    printf("请按对应数字选择难度：\n噩梦--1\n困难--2\n正常--3\n简单--4\n儿童--5\nEsc随时退出游戏");
    int key;
    int flag = 1;
    while(flag)
    {
        key = _getch();
        switch (key)
        {
        case '1':
            return nightmare;
            break;
        case '2':
            return hard;
            break;
        case '3':
            return medium;
            break;
        case '4':
            return easy;
            break;
        case '5':
            return childish;
            break;

        case 27:
            exit(0);
        default:
            printf("请按对应数字选择难度：\n噩梦--1\n困难--2\n正常--3\n简单--4\n儿童--5\nEsc随时退出游戏");
            flag = 1;
        }
    }

    return -1;//错误执行
}

int ifEatFood(Snake S,Point *FoodPosition)
{
    if (S->rear->position.x == FoodPosition->x && S->rear->position.y == FoodPosition->y)
    {
        *FoodPosition = build_food();
        return 1;
    }
    else
        return 0;
}

int if_inWallOrinBody(Snake S)
{
    int flag = 0;
    SnakeNode PtrS = S->front;
    //撞身子判断
    while (PtrS != S->rear)
    {
        if (S->rear->position.x == PtrS->position.x && S->rear->position.y == PtrS->position.y)
        {
            return 1;
        }       
        PtrS = PtrS->next;
    }
    
    if (ifnot_in_map(S->rear->position.x,S->rear->position.y))//蛇头是否撞墙或身子
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}