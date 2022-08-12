#include "../inc/rules.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int select_difficulty()
{
    printf("WSAD���ߡ��������������˶�\n");
    printf("�밴��Ӧ����ѡ���Ѷȣ�\nج��--1\n����--2\n����--3\n��--4\n��ͯ--5\nEsc��ʱ�˳���Ϸ");
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
            printf("�밴��Ӧ����ѡ���Ѷȣ�\nج��--1\n����--2\n����--3\n��--4\n��ͯ--5\nEsc��ʱ�˳���Ϸ");
            flag = 1;
        }
    }

    return -1;//����ִ��
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
    //ײ�����ж�
    while (PtrS != S->rear)
    {
        if (S->rear->position.x == PtrS->position.x && S->rear->position.y == PtrS->position.y)
        {
            return 1;
        }
        PtrS = PtrS->next;
    }

    if (ifnot_in_map(S->rear->position.x,S->rear->position.y))//��ͷ�Ƿ�ײǽ������
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}
