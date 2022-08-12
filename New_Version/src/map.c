#include "../inc/map.h"
#include<stdio.h>
#include<windows.h>

void gotoxy(short int x, short int y)
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    /*
    typedef struct _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    WINBOOL bVisible;  //Ϊ0ʱ��겻�ɼ�
    } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;
    */
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void showCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};
    /*
    typedef struct _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    WINBOOL bVisible;  //Ϊ1ʱ���ɼ�
    } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;
    */
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void MapInit()
{
    for (int i = 0; i < Map_Width_X + 2; i++)
    {
        printf("�~");
    }

    for (int i = 1; i <= Map_Width_Y; i++)
    {
        gotoxy(0, i);
        printf("|");
        gotoxy(Map_Width_X + 2, i);
        printf("|");
    }
    putchar('\n');
    for (int i = 0; i < Map_Width_X + 2; i++)
    {
        printf("�~");
    }
    putchar('\n');
}

int ifnot_in_map(int x,int y)
{
    int flag = 1;
    if (x > 0 && x < Map_Width_X+1)
            if (y > 0 && y < Map_Width_Y+1)
                flag = 0;
    return flag;
}

void Delay_ms(unsigned long ms)
{
    Sleep(ms);
}
