#include "map.h"
#include<stdio.h>
#include<windows.h>

void gotoxy(short int x, short int y)
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    /*
    typedef struct _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    WINBOOL bVisible;  //为0时光标不可见
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
    WINBOOL bVisible;  //为1时光标可见
    } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;
    */
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void MapInit()
{
    for (int i = 0; i < Map_Width_X + 2; i++)
    {
        printf("▇");
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
        printf("▇");
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