#pragma once    //只编译一次
#include "map.h"

typedef struct p Point;
struct p
{
    int x;
    int y;
};

typedef struct Node *SnakeNode;
struct Node
{
    Point position;
    struct Node *next;
};
//队列表示蛇
typedef struct snake *Snake;
struct snake
{
    SnakeNode front;
    SnakeNode rear;
};

#define SnakeInit_Length 8
#define up 1
#define down 2
#define left 3
#define right 4

void SnakeLonger(Snake PtrS, Point posit);
Point SnakeShorter(Snake S);
Snake SnakeInit();
void ShowSnake(Snake S);
void SnakeMove(int direction, Snake S, Point *FoodPosition);
int detect_move(int direction);