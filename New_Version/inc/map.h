#define Map_Width_X 50
#define Map_Width_Y 20



void gotoxy(short int x, short int y);//�ƶ������(x,y)λ����ʾ
void MapInit();
void HideCursor();//���ع��
void showCursor();
int ifnot_in_map(int x, int y);
void Delay_ms(unsigned long ms);
