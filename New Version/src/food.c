#include"food.h"
#include"map.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>



Point build_food()
{
    srand(time(NULL));//以时间参数生成不同的srand参数，使得rand随机
    int x, y;

    do
    {
        x = rand();
        y = rand();
        
    } while ( ifnot_in_map(x,y) );//限定在方框内
    gotoxy(x, y);
    printf("*");//食物
    HideCursor();

    Point p;
    p.x = x;
    p.y = y;
    return p;
}