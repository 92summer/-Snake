#include "map.h"
#include "food.h"
#include "snake.h"

//难度定义
#define nightmare 50
#define hard 100
#define medium 200
#define easy 300
#define childish 500

//检测是否吃了食物，是则重新生成
int ifEatFood(Snake S, Point *FoodPosition);

int if_inWallOrinBody(Snake S);

int select_difficulty();
