#define Map_Width_X 50
#define Map_Width_Y 20



void gotoxy(short int x, short int y);//移动光标至(x,y)位置显示
void MapInit();
void HideCursor();//隐藏光标
void showCursor();
int ifnot_in_map(int x, int y);
void Delay_ms(unsigned long ms);