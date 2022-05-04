1.printf建框  
2.框内随机生成食物  
3.链表（队列）或数组表示蛇身体  
4.接收键盘控制蛇运动 

```c
_kbhit();//键盘监视：判断是否有按键按下，返回值0代表无，非0代表有
_getch();//键盘接收
//例子
key=getch(); 
if(key==72) printf("按了 上 键    按 ESC退出!\n");
if(key==80) printf("按了 下 键    按 ESC退出!\n");
if(key==75) printf("按了 左 键    按 ESC退出!\n");
if(key==77) printf("按了 右 键    按 ESC退出!\n");
```

5.食物判断，撞墙判断  
