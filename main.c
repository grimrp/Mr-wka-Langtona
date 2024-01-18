#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "simulation.h"
#include "map_generation.h"
#include "map_saving.h"
#include <getopt.h>

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


/*
getopt:
h - help
m - długość tablicy
n - szerokość tablicy
i - liczba iteracji
f - nazwa pliku wynikowego
r - początkowa rotacja
l - opcja generowania losowej mapy
u - opcja wczytania mapy z pliku
*/
int main(int argc, char **argv){  
	
	//zmienne wejsciowe:
	int width=0;
	int height=0;
	int iterations=0;
	char rotation=1;
	char *end_file_name = "default";
	int random=0;
	char *upload_file_name ="";
	
	int option_value=0, loop=1;
	
	while((option_value=getopt(argc, argv, "h:m:n:i:f:r:l:u"))){
		switch(option_value){
			case 'h':
				printf();
				break;
			case 'm':
				width=atoi(optarg);
				break;
			case 'n':
				height=atoi(optarg);
				break;
			case 'i':
				iterations=atoi(optarg);
				break;
			case 'f':
				end_file_name=optarg;
				break;
			case 'r':
				rotation=atoi(optarg);
				if(rotation==1 || rotation==2 || rotation==3 || rotation==4){
				}
				else{
					rotation=1;
				}
				break;
			case 'l':
				random=atoi(optarg);
				break;
			case 'u':
				upload_file_name=optarg;
				break;
			default:
				loop=0;
				break;
		}
		if(loop==0){
			break;
		}
	}
	
	if(width==0){
		printf("Źle podany lub brak argumentu -m\n");
		return 0;
	}
	if(height==0){
		printf("Źle podany lub brak argumentu -n\n");
		return 0;
	}
	if(iterations==0){
		printf("Źle podany lub brak argumentu -i\n");
		return 0;
	}
	if(random<0 || random>100){
		printf("Źle podany lub brak argumentu -l\n");
		return 0;		
	}
	if(upload_file_name!="" && random!=0){
		printf("Nie można wczytać mapy z pliku i jednocześnie wygenerować losowej mapy!\n");
		return 0;
	}
	//generowanie mapy:
	int map[width+2][height+2];
	if(random != 0){
		generate_random_map(width, height, map, random);
	}
	else if(upload_file_name!=""){
		printf("lolololololo");
		read_map("tes", width, height, map);
	}
	else{
		generate_empty_map(width, height, map);
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

