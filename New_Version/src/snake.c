#include "../inc/snake.h"
#include "../inc/map.h"
#include "../inc/rules.h"
#include <conio.h> //Ϊ���ü��̽��պ���_getch();
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void SnakeLonger(Snake PtrS,Point posit)//��ʳ�ﳤ//��β���
{
    SnakeNode NewSnakeNode = (SnakeNode)malloc(sizeof(struct Node));
    NewSnakeNode->next = NULL;
    NewSnakeNode->position = posit;
    if (!PtrS->front)//�ն�
    {
        PtrS->front = PtrS->rear = NewSnakeNode;
    }
    else            //�ӷǿ�
    {
        PtrS->rear->next = NewSnakeNode;
        PtrS->rear = NewSnakeNode;
    }

}

Point SnakeShorter(Snake S)//����
{
    if (!S->front)//���п�
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
    //ͼ���������
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
        if (PtrS == S->rear)//���ж�β����ͷ
        {
            putchar('$'); //��ͷ
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
    putchar(' ');//����ͷ
    gotoxy(S->rear->position.x, S->rear->position.y);
    putchar(' ');//����β

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
void Add_direction(direQ D,int dire)//�ӷ������
{
    if (dire == up || dire == down || dire == left || dire == right)
    //���detect_move����return 0���,���������
    {
        if (D->rear == dire)
        {
            return;
        }


        if ((D->rear+1)%maxsize == D->front)//������
        {
            //printf("Queue full!\n");
            return;
        }
        else if (D->front == D->rear)//���п�
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

void Add_direction(direQ D,int now_dire,int dire)//�ӷ������
{
    if (dire == up || dire == down || dire == left || dire == right)
    {
    switch (dire)//��ֹ�������ƶ�
    {
    case up:
        if(D->front)
        {
            if(D->rear->direction == down)//��һ��������������Ĳ����෴
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
            if(D->rear->direction == up)//��һ��������������Ĳ����෴
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
            if(D->rear->direction == right)//��һ��������������Ĳ����෴
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
            if(D->rear->direction == left)//��һ��������������Ĳ����෴
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
    if (!D->front)//�ն�
    {
        dQNode newD = (dQNode)malloc(sizeof(struct direQNode));
        newD->next = NULL;
        newD->direction = dire;
        D->front = D->rear = newD;
    }
    else if (D->rear->direction == dire)//ͬ�����������
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
int Done_direction(direQ D,int last_diretion)//ִ�в���//����
{
    if (D->rear==D->front)//���п�
    {
        //printf("Queue empty!\n");
        return last_diretion;
    }
    D->front = (D->front + 1) % maxsize;
    return D->direction[(D->front)];

}
*/

int Done_direction(direQ D,int last_diretion)//ִ�в���//����
{
    if (!D->front)//�ն�
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
    //_kbhit()���ж��Ƿ��а������£�����ֵ0�����ޣ���0������
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
    case 72://��up
        if (last_direction == down)
        {
            break;
        }

            direction = up;
        break;
    case 80://��down
        if (last_direction == up)
        {
            break;
        }

            direction = down;
        break;
    case 75://��left
        if (last_direction == right)
        {
            break;
        }

            direction = left;
        break;
    case 77://��right
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
        case 72://��up
            direction = up;
            break;
        case 's':
        case 80://��down
            direction = down;
            break;
        case 'a':
        case 75://��left
            direction = left;
            break;
        case 'd':
        case 77://��right
            direction = right;
            break;

        case 27://Esc �˳���Ϸ
            exit(0);

    }
    return direction;

}
