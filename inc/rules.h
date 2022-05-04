#include "map.h"
#include "food.h"
#include "snake.h"

//检测是否吃了食物，是则重新生成
int ifEatFood(Snake S, Point *FoodPosition);

int if_inWallOrinBody(Snake S);