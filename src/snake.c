#include "snake.h"
#include "map.h"
#include <conio.h> //为了用键盘接收函数_getch();
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rules.h"


void SnakeLonger(Snake PtrS,Point posit)//蛇食物长//蛇尾入队
{
    SnakeNode NewSnakeNode = (SnakeNode)malloc(sizeof(struct Node));
    NewSnakeNode->next = NULL;
    NewSnakeNode->position = posit;
    if (!PtrS->front)//空队
    {
        PtrS->front = PtrS->rear = NewSnakeNode;
    }
    else            //队非空
    {
        PtrS->rear->next = NewSnakeNode;
        PtrS->rear = NewSnakeNode;
    }
    
}

Point SnakeShorter(Snake S)//出队
{
    if (!S->front)//队列空
    {
        Point p;
        p.x = p.y = 0;
        return p;
    }
    Point p = S->front->position;
    SnakeNode preSf = S->front;
    S->front = S->front->next;
    free(preSf);
    return p;
}

Snake SnakeInit()
{
    srand(time(NULL));
    Snake S = (Snake)malloc(sizeof(struct snake));
    S->front = S->rear = NULL;
    //图中左出显蛇
    for (int i = 1; i <= SnakeInit_Length; i++)
    {
        Point p;
        p.x = i;
        p.y = Map_Width_Y/2;
        SnakeLonger(S, p);
    }
    ShowSnake(S);
    return S;
}

void ShowSnake(Snake S)
{
    SnakeNode PtrS = S->front;
    while (PtrS)
    {
        gotoxy(PtrS->position.x, PtrS->position.y);
        if (PtrS == S->rear)//队列队尾作蛇头
        {
            putchar('$'); //蛇头
        }
        else
            putchar('#');
        PtrS = PtrS->next;
    }
}


void SnakeMove(int direction,Snake S,Point *FoodPosition)
{
    
    //SnakeNode PtrSf = S->front;
    //SnakeNode PtrSr = S->rear;
    Point p = S->rear->position;


    gotoxy(S->front->position.x, S->front->position.y);
    putchar(' ');//清蛇头
    gotoxy(S->rear->position.x, S->rear->position.y);
    putchar(' ');//清蛇尾

    switch (direction)
    {
    case up:
        p.y -= 1;        
        SnakeLonger(S, p);
        if (ifEatFood(S, FoodPosition))
        {
            break;
        }       
        SnakeShorter(S);
        break;
    case down:
        p.y += 1;        
        SnakeLonger(S, p);
        if (ifEatFood(S, FoodPosition))
        {
            break;
        }
        SnakeShorter(S);
        break;
    case left:
        p.x -= 1;        
        SnakeLonger(S, p);
        if (ifEatFood(S, FoodPosition))
        {
            break;
        }
        SnakeShorter(S);
        break;
    case right:
        p.x += 1;        
        SnakeLonger(S, p);
        if (ifEatFood(S, FoodPosition))
        {
            break;
        }
        SnakeShorter(S);
        break;
   
    }

    ShowSnake(S);
}

int detect_move(int direction)
{
    /*
    if (!_kbhit())
    //_kbhit()是判断是否有按键按下，返回值0代表无，非0代表有
    {
        return direction;
    }
    else
    */
    {
    int key;
    key = _getch();
    switch (key)
    {
    case 72:
        if (direction == down)
        {
            break;
        }
        else
            direction = up;
        break;
    case 80:
        if (direction == up)
        {
            break;
        }
        else
            direction = down;
        break;
    case 75:
        if (direction == right)
        {
            break;
        }
        else
            direction = left;
        break;
    case 77:
        if (direction == left)
        {
            break;
        }
        else        
            direction = right;
        break;
    }
    return direction;
    }
}