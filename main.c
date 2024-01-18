#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "simulation.h"
#include "map_generation.h"
#include "map_saving.h"

/*
interpretacja tablicy:
0 - białe pole
1 - czarne pole
2- ┌ 
3- ┐
4- └
5- ┘
6- |
9 - ─
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
	int width=100;
	int height=100;
	int iterations=11500;
	char rotation=1;
	
	//generowanie pustej mapy(trzeba przeniesc do funkcji):
	int map[width+2][height+2];
	generate_empty_map(width, height, map);
	
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
		//interpretacja tablicy na plik
		map_saving(width, height, map);
	}
	
	//test dzialania w terminalu:
	printf("\n\n");
	for(int i=0;i<width+2;i++){
		for(int j=0;j<height+2;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
}

