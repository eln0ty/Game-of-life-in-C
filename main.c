                                                                   /**Conway's Game of Life**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char map[100][100] , prev_map[100][100];    //Space to simulate
int rows,columns;                           //Size of map
int x,y,i,j,counter;                        //Counters

void Setup(int row,int column){

    int random;
    rows = row; columns = column;

    for(x=0;x<rows;x++){
        for(y=0;y<columns;y++){
           for(int i=0;i<10;i++) random = rand()%2;
           if(random){
            map[x][y]='*';
           }
           else{
            map[x][y]=' ';
           }
        }
    }
}

void operation(){
  counter=0;

  for(x=0;x<rows;x++){
    for(y=0;y<columns;y++){
        prev_map[x][y]=map[x][y];
    }
  }

  for(x=0;x<rows;x++){
    for(y=0;y<columns;y++){
        if(x && y){
            for(i=(x-1);i<=(x+1);i++){
                for(j=(y-1);j<=(y+1);j++){
                   if(i == x && j==y)               continue;
                   if(prev_map[i][j] == '*')        counter++;
                }
            }
        }else if(!x && y){
            for(i=x;i<=x+1;i++){
                for(j=y-1;j<=y+1;j++){
                   if(i == x && j==y)                 continue;;
                   if(prev_map[i][j] == '*')           counter++;
                }
            }
        }else if(!y && x){
            for(i=x-1;i<=x+1;i++){
                for(j=y;j<=y+1;j++){
                    if(i == x && j==y)           continue;
                    if(prev_map[i][j] == '*')    counter++;
                }
            }
        }else{
            for(i=x;i<=x+1;i++){
                for(j=y;j<=y+1;j++){
                    if(i == x && j==y)            continue;
                    if(prev_map[i][j] == '*')     counter++;
                }
            }
        }

        if( prev_map[x][y]=='*' && (counter == 2 || counter == 3)){
            map[x][y] ='*';
            counter=0;
        }
        else if(prev_map[x][y]=='*') {
            map[x][y] =' ';
            counter=0;
        }
        else if(prev_map[x][y]==' ' && counter == 3){
            map[x][y] ='*';
            counter=0;
        }
        else{
            map[x][y] =' ';
            counter=0;
        }
    }
  }
}

void Display(){
    system("cls");                      //Reprint the consul screen

printf("Previous state : \n");
for(x=0;x<rows;x++){
        for(y=0;y<columns;y++){
           putchar(prev_map[x][y]);
        }
        printf("\n");
 }

 printf("\nCurrent State : \n");
for(x=0;x<rows;x++){
    for(y=0;y<columns;y++){
        putchar(map[x][y]);
    }
    printf("\n");
 }
}

int main ()
{
    Setup(13,130);

    while(1){
        operation();
        Display();
        Sleep(500);
    };

return 0;
}
