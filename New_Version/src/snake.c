#include "../inc/snake.h"
#include "../inc/map.h"
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

direQ directionInit()
{
    direQ D = (direQ)malloc(sizeof(struct directionSeries));
    D->front = NULL;
    D->rear = NULL;
    return D;
}

/*
void Add_direction(direQ D,int dire)//加方向操作
{
    if (dire == up || dire == down || dire == left || dire == right)
    //配合detect_move函数return 0结果,反方向不入队
    {
        if (D->rear == dire)
        {
            return;
        }


        if ((D->rear+1)%maxsize == D->front)//队列满
        {
            //printf("Queue full!\n");
            return;
        }
        else if (D->front == D->rear)//队列空
        {
            D->direction[D->rear] = dire;
            D->front = (D->front + maxsize - 1) % maxsize;
        }
        else
        {
            D->rear = (D->rear + 1) % maxsize;
            D->direction[D->rear] = dire;
        }

        }
    else
        return;
}
*/

void Add_direction(direQ D,int now_dire,int dire)//加方向操作
{
    if (dire == up || dire == down || dire == left || dire == right)
    {
    switch (dire)//禁止反方向移动
    {
    case up:
        if(D->front)
        {
            if(D->rear->direction == down)//上一个操作与接下来的操作相反
            return;
        }
        else
        {
            if (now_dire == down)
            {
                return;
            }
        }
        break;
    case down:
        if(D->front)
        {
            if(D->rear->direction == up)//上一个操作与接下来的操作相反
            return;
        }
        else
        {
            if (now_dire == up)
            {
                return;
            }
        }
        break;
    case left:
        if(D->front)
        {
            if(D->rear->direction == right)//上一个操作与接下来的操作相反
            return;
        }
        else
        {
            if (now_dire == right)
            {
                return;
            }
        }
        break;
    case right:
        if(D->front)
        {
            if(D->rear->direction == left)//上一个操作与接下来的操作相反
            return;
        }
        else
        {
            if (now_dire == left)
            {
                return;
            }
        }
        break;
    }
    if (!D->front)//空队
    {
        dQNode newD = (dQNode)malloc(sizeof(struct direQNode));
        newD->next = NULL;
        newD->direction = dire;
        D->front = D->rear = newD;
    }
    else if (D->rear->direction == dire)//同向操作不加入
    {
        return;
    }
    else
    {
        dQNode newD = (dQNode)malloc(sizeof(struct direQNode));
        newD->next = NULL;
        newD->direction = dire;
        D->rear->next = newD;
        D->rear = newD;
    }
    }
    else
        return;
}

/*
int Done_direction(direQ D,int last_diretion)//执行操作//出队
{
    if (D->rear==D->front)//队列空
    {
        //printf("Queue empty!\n");
        return last_diretion;
    }
    D->front = (D->front + 1) % maxsize;
    return D->direction[(D->front)];

}
*/

int Done_direction(direQ D,int last_diretion)//执行操作//出队
{
    if (!D->front)//空队
    {
        return last_diretion;
    }

    int direction = D->front->direction;
    dQNode preD = D->front;
    D->front = D->front->next;
    free(preD);
    return direction;
}

/*
int detect_move(direQ D,int dire)
{
    /*
    if (!_kbhit())
    //_kbhit()是判断是否有按键按下，返回值0代表无，非0代表有
    {
        return direction;
    }
    else
    //

    int last_direction = Done_direction(D, dire);
    int direction = last_direction;
    {
    int key;
    key = _getch();
    switch (key)
    {
    case 72://上up
        if (last_direction == down)
        {
            break;
        }

            direction = up;
        break;
    case 80://下down
        if (last_direction == up)
        {
            break;
        }

            direction = down;
        break;
    case 75://左left
        if (last_direction == right)
        {
            break;
        }

            direction = left;
        break;
    case 77://右right
        if (last_direction == left)
        {
            break;
        }

            direction = right;
        break;
    }
    return direction;
    }
}
*/

int detect_move()
{

    int key;
    key = _getch();
    int direction = 0;
    switch (key)
    {
        case 'w':
        case 72://上up
            direction = up;
            break;
        case 's':
        case 80://下down
            direction = down;
            break;
        case 'a':
        case 75://左left
            direction = left;
            break;
        case 'd':
        case 77://右right
            direction = right;
            break;

        case 27://Esc 退出游戏
            exit(0);

    }
    return direction;

}
