#include "map_generation.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include<time.h>
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

int read_map(char *filename,int width, int height, int (*map)[width+2]){
int i=0;
int j=0;
int znak;
FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }
int wys=height+2;
int szer=width+2;
int sum=wys*szer;
int temp[sum];
        for(int z=0;z<sum+1;z++){
        fscanf(file,"%d",&temp[z]);
        }
int z=0;
for(int i=0;i<height+2;i++){
        for(int j=0;j<height+2;j++){
        map[i][j]=temp[z];
        z++;
}
}
return 0;
}



void generate_random_map(int width, int height, int (*map)[width+2], int r){
	srand(time(0));
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
					int random_number = rand() % 101;
					if(r>=random_number){
						map[i][j]=1;
					}
					else{
						map[i][j]=0;
					}
                                }
                }
        }

}

