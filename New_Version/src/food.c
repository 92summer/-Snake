#include"../inc/food.h"
#include"../inc/map.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>



Point build_food()
{
    srand(time(NULL));//��ʱ��������ɲ�ͬ��srand������ʹ��rand���
    int x, y;

    do
    {
        x = rand();
        y = rand();

    } while ( ifnot_in_map(x,y) );//�޶��ڷ�����
    gotoxy(x, y);
    printf("*");//ʳ��
    HideCursor();

    Point p;
    p.x = x;
    p.y = y;
    return p;
}
