#include <stdlib.h>
#include <stdio.h>
#include "simulation.h"

/*
interpretacja tablicy:
0 - białe pole
1 - czarne pole
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


int main(){
	//zmienne wejsciowe:
	int width=50;
	int height=50;
	int iterations=800;
	char rotation=1;
	
	//generowanie pustej mapy(trzeba przeniesc do funkcji):
	int map[width+2][height+2];
	for(int i=0;i<width+2;i++){
		for(int j=0;j<height+2;j++){
			if(i==0){
				map[i][j]=9;
			}
			else if(j==0){
				map[i][j]=9;
			}
			else if(i==width+1){
				map[i][j]=9;
			}
			else if(j==height+1){
				map[i][j]=9;
			}
			else{
				map[i][j]=0;
			}
		}
	}
	
	//pozycja poczatkowa mrowki:
	int pos_x=width/2;
	int pos_y=height/2;
	map[pos_x][pos_y]=10;
	
	//zmienne pomocnicze:
	int state;
	int new_state;
	
	//symulacja:
	for(int i=0;i<iterations;i++){
		//zmiana rotacji:
		state=map[pos_x][pos_y];
		rotation=change_rotation(rotation, state);
		//zmiana koloru:
		state=change_color(state);
		map[pos_x][pos_y]=state;
		//zmiana pozycji:
		change_posision(rotation, &pos_x, &pos_y);
		//zmiana stanu mrowki:
		state=map[pos_x][pos_y];
		new_state=change_ant_placing(state, rotation);
		//sprawdzenie czy walnela w sciane:
		if(new_state==0){
			printf("mrówka walnela w sciane");
			return 0;
		}
		//postawienie mrowki na mapie:
		else{
			map[pos_x][pos_y]=new_state;
		}
	}
	
	//test dzialania w terminalu:
	for(int i=0;i<width+2;i++){
		for(int j=0;j<height+2;j++){
			printf("%d", map[i][j]);
		}
	}
}
