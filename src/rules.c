#include "rules.h"



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