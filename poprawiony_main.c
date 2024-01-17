#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include<string.h>
#include "simulation.h"

/*
interpretacja tablicy:
0 - białe pole
1 - czarne pole
2-┌
3- ┐
4-└
5- ┘
6- -
8-sciana+\n
9 - sciana
10 - mrowka skierowana w góre na blialym polu
20 - mrowka skierowana w prawo na blialym polu
30 - mrowka skierowana w dol na blialym polu
40 - mrowka skierowana w lewo na blialym polu
11 - mrowka skierowana w góre na czarnym polu
21 - mrowka skierowana w prawo na czarnym polu
31 - mrowka skierowana w dol na czarnym polu
41 - mrowka skierowana w lewo na czarnym polu

interpretacja rotacji:
1 - góra
2 - prawo
3 - dol
4 - lewo
*/

//wiersze/kolumny
int main(){
	//zmienne wejsciowe:
	int width=50;
	int height=50;
	int iterations=800;
	char rotation=1;
	
	//generowanie pustej mapy(trzeba przeniesc do funkcji):
	int map[width][height];
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			//┌
			if(i==0 && j==0){
				map[i][j]=2;
			}
			//┐
			else if(i==0 && j==height-1){
                                map[i][j]=3;
                        }
			//└
			else if(i==width-1 && j==0){
                                map[i][j]=4;
			}
			//┘
			else if(i==width-1 && j==height-1){
                                map[i][j]=5;
                        }
			// ─
			else if(i==0 && j<(height-1) && j>0){
                                map[i][j]=6;
                        }
			// ─
                        else if(i==width-1 && j<height-1 && j>0){

                                map[i][j]=6;
                        }
			// |
			else if(i>0 && i<width-1 && j==0 ){
                                map[i][j]=9;
			}
			// |
			else if(i>0 && i<width-1 && j==height-1){
                                map[i][j]=8;
                        }
			// białe pole
			else if(i>0 && i<(width-1) && j>0 && j<(height-1)){
                                map[i][j]=0;}
                        }
		}
	
	
	//pozycja poczatkowa mrowki:
	int pos_x=width/2;
	int pos_y=height/2;
	map[pos_x][pos_y]=10;
	
FILE *file;
char *filename = "pusta_mapa.txt";
file = fopen(filename, "w");

for(int i=0;i<width;i++) {
        for(int j=0;j<height;j++) {
                switch(map[i][j]){

                        case 0:
                        fprintf(file,"█");
                        break;

                        case 1:
                        fprintf(file," ");
                        break;

                        case 2:
                        fprintf(file,"┌");
                        break;

                        case 3:
                        fprintf(file,"┐\n");
                        break;

                        case 4:
                        fprintf(file,"└");
                        break;

                        case 5:
                        fprintf(file,"┘");
                        break;

                        case 6:
                        fprintf(file,"─");
                        break;

                        case 8:
                        fprintf(file,"│\n");
                        break;

                        case 9:
                        fprintf(file,"│");
                        break;
			
			case 10:
                        fprintf(file,"▲");
                        break;

                        case 11:
                        fprintf(file,"△");
                        break;

                        case 20:
                        fprintf(file,"▶");
                        break;

                        case 21:
                        fprintf(file,"▷");
                        break;

                        case 30:
                        fprintf(file,"▼");
                        break;

                        case 31:
                        fprintf(file,"▽");
                        break;

                        case 40:
                        fprintf(file,"◀");
                        break;

                        case 41:
                        fprintf(file,"◁");
                        break;
                }
        }
}
fclose(file);

	
	//test dzialania w terminalu:
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			printf("%d", map[i][j]);
		}
	}
return 0;
}
