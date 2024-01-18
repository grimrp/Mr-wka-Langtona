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
