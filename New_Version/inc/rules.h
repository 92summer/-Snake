#include "map.h"
#include "food.h"
#include "snake.h"

//�Ѷȶ���
#define nightmare 50
#define hard 100
#define medium 200
#define easy 300
#define childish 500

//����Ƿ����ʳ�������������
int ifEatFood(Snake S, Point *FoodPosition);

int if_inWallOrinBody(Snake S);

int select_difficulty();
