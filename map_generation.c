#include "map_generation.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

/*
tu maja byc funckje:
- generowanie pustej mapy
- generowanie losowej mapy
- wczytywanie mapy z pliku
*/

void generate_empty_map(int width, int height, int (*map)[width+2]){
	for(int i=0;i<width+2;i++){
		for(int j=0;j<height+2;j++){
				//┌
				if(i==0 && j==0){
					map[i][j]=2;
				}
				//└
				else if(i==0 && j==height+1){
		           	            map[i][j]=3;
		      	         }
				//┐
				else if(i==width+1 && j==0){
		                        map[i][j]=4;
				}
				//┘
				else if(i==width+1 && j==height+1){
		                        map[i][j]=5;
		                }
				// ─
				else if(i>0 && i<width+1 && j==0){
		                        map[i][j]=6;
		                }
				// ─
		                else if(i>0 && i<width+1 && j==height+1){
		                        map[i][j]=6;
		                }
				// |
				else if(i==0 && j>0 && j<height+1){
		                        map[i][j]=9;
				}
				// |
				else if(i==width+1 && j>0 && j<height+1){
		                        map[i][j]=9;
		                }
				// białe pole
				else if(i>0 && i<width+1 && j>0 && j<height+1){
		                        map[i][j]=0;
		           	}
		}
	}
}


int read_map(int width, int height, int (*map)[width+2]){
int i=0;
int j=0;
char filename[100];
char znak[3];
printf("Podaj nazwę pliku: ");
scanf("%s", filename);
FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

while ((znak = fgetc(file)) != EOF) {
   if(i>=0 && i<=width+1){
	if(j>=0 && j<=height+1){
 				//┌
                                if(znak=="┌"){
                                        map[i][j]=2;
					if(j+1>height+1){
					j=0;
					i++;}
					else
					j++;
				 }
                                //└
                                else if(znak=="└"){
                                        map[i][j]=3;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                 }
                                //┐
                                else if(znak=="┐"){
                                        map[i][j]=4;
                               		if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

				 }
                                //┘
                                else if(znak=="┘"){
                                        map[i][j]=5;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                // ─
                                else if(znak=="─"){
                                        map[i][j]=6;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;
                               	 }
                                // |
                                else if(znak=="|"){
                                        map[i][j]=9;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                // białe pole
                                else if(znak=="█"){
                                        map[i][j]=0;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak==" "){
                                        map[i][j]=1;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="▲"){
                                        map[i][j]=10;
					   if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="△"){
                                        map[i][j]=11;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="▶"){
                                        map[i][j]=20;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="▷"){
                                        map[i][j]=21;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                 }
                                else if(znak=="▼"){
        	   			map[i][j]=30;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="▽"){
                                        map[i][j]=31;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="◁"){
                                        map[i][j]=41;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;

                                }
                                else if(znak=="◀"){
					map[i][j]=40;
					if(j+1>height+1){
                                        j=0;
                                        i++;}
                                        else
                                        j++;
				}



}}}
return 0;}



void generate_random_map(int width, int height, int (*map)[width+2]){
        printf("Podaj procent czarnych pól na mapie: ");
	int r=0;
	scanf("%d",r);
	
		
	 for(int i=0;i<width+2;i++){
                for(int j=0;j<height+2;j++){
                                //┌
                                if(i==0 && j==0){
                                        map[i][j]=2;
                                }
                                //└
                                else if(i==0 && j==height+1){
                                            map[i][j]=3;
                                 }
                                //┐
                                else if(i==width+1 && j==0){
                                        map[i][j]=4;
                                }
                                //┘
                                else if(i==width+1 && j==height+1){
                                        map[i][j]=5;
                                }
                                // ─
                                else if(i>0 && i<width+1 && j==0){
                                        map[i][j]=6;
                                }
                                // ─
                                else if(i>0 && i<width+1 && j==height+1){
                                        map[i][j]=6;
                                }
                                // |
                                else if(i==0 && j>0 && j<height+1){
                                        map[i][j]=9;
                                }
                                // |
                                else if(i==width+1 && j>0 && j<height+1){
                                        map[i][j]=9;
                                }
                                // białe pole
                                else if(i>0 && i<width+1 && j>0 && j<height+1){
                                        srand(time(0));
					int random_number = rand() % 101;
					if(r>=random_number)
					map[i][j]=0;
					else
					map[i][j]=1;
                                }
                }
        }

}

