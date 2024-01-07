#include<stdio.h>
char chess[8][8];
char next[8][8];
int check(short y,short x,short xt,short yt,char data){
    int c=0;
    int n=0;
    for (int i = x+xt,j=y+yt; i >-1 && j >-1 && j<8 && i<8; i+=xt,j+=yt){
        n++;
        if(chess[j][i]==data)  
            return 0;
        if(chess[j][i]!=data&&chess[j][i]!='0')    
            c=1;
        if(chess[j][i]=='0'){
            if(c==1){
                return n;
            }
            return 0;
        }
    }return 0;
}
void dnext(char data,short i,short j){
    if(data=='1'){
        if(next[j][i]!='b'){
            next[j][i]='w';
        }
        else{
            next[j][i]='a';
        }
        }
        else{
            if(next[j][i]!='w'){
                next[j][i]='b';
            }else{
                next[j][i]='a';
            }
    }
}
void output_data(char data){
    int d=0;
    if(data=='1')
        data='w';
    else
        data='b';
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(next[i][j]==data||next[i][j]=='a'){
                if(d==1){
                    printf(",");
                }else
                    d=1;
                printf("(%d,%d)",i,j);
            }
        }
    }
    printf("\n");
}
int main(){    
    int x,y;
    char target;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; ){
            scanf("%c",&chess[i][j]);
            next[i][j]=chess[i][j];
            if (chess[i][j]=='\n'||chess[i][j]==' '){
                continue;
            }
            j++;
        }
    }
    printf("enter ");
    scanf("%1d%c%1d",&x,&target,&y);
    char data=chess[x][y];
    if (data=='0'){
        return 0;
    }
    for (short i = -1; i < 2; i++){
        for (short j = -1; j < 2; j++){
            int temp=check(x,y,i,j,data);
            if(temp){
                dnext(data,x+temp*j,y+temp*i);
            }
        }
    }
    output_data(data);
    for (int k = 0; k < 8; k++){
        for (int l = 0; l < 8; l++){
            if(chess[k][l]=='0') 
                continue;
            for (short i = -1; i < 2; i++){
                for (short j = -1; j < 2; j++){                    
                    int temp=check(k,l,i,j,chess[k][l]);
                    if(temp){
                        dnext(chess[k][l],k+temp*j,l+temp*i);
                    }
                }
            }
        }
    }
    printf("black可下在:\n");
    output_data('1');
    printf("white可下在:\n");
    output_data('2');
}
