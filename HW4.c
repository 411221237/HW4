#include <stdio.h>
#define IN_CHESS(x,y) (x>=0&&x<=7&&y>=0&&y<=7)

int fun2(int chess[8][8], int x, int y, int dx, int dy,int color) {
     if (chess[x][y] == color^3 && IN_CHESS(x,y)){
         while (chess[x][y] == color^3 && IN_CHESS(x,y)){
              x += dx;
              y += dy;
         }
     if (chess[x][y] == color && IN_CHESS(x,y))
              return 1;
     return 0;    
}
}
void fun1(int chess[8][8], int next[8][8], int i, int j, int color) {
         for (int dx = -1; dx <= 1; dx++)
             for (int dy = -1; dy <= 1; dy++)
                  next[i][j] |= fun2(chess, i+dx,j+dy,dx,dy,color);
}


int main(){
    int chess[8][8], next[8][8];
    int color;
    int x,y;
    scanf("%d %d", &x, &y);
    scanf("%d", &color);
    for (int i = 0; i <= 7; i++){
        for (int j = 0; j <= 7; j++){
            if (chess[i][j] == 0)
                fun1(chess, next, i, j, color);
        }
    } 
    return 0;
}
    
