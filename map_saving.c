#include "map_saving.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
//funkcja zapisujaca tablice do pliku

int map_saving(char *filename, int iterations, int width, int height, int (*map)[width+2]){
char fileName[50];
snprintf(fileName, sizeof(fileName), "mapy/%s_%d", filename,iterations );

FILE *file;
char *name=(filename);
file = fopen(fileName, "w");

for(int i=0;i<width+2;i++) {
	for(int j=0;j<height+2;j++) {
		switch(map[i][j]){
			
			case 0:
			fprintf(file," ");
			break;

			case 1:
			fprintf(file,"█");
			break;

			case 2:
			fprintf(file,"┌");
			break;

			case 3:
			fprintf(file,"┐");
			break;

			case 4:
			fprintf(file,"└");
			break;

			case 5:
			fprintf(file,"┘");
			break;

			case 6:
			fprintf(file,"│");
			break;

			case 9:
			fprintf(file,"─");
			break;

			case 10:
			fprintf(file,"△");
			break;

			case 11:
			fprintf(file,"▲");
			break;

			case 20:
			fprintf(file,"▷");
			break;

			case 21:
			fprintf(file,"▶");
			break;

			case 30:
			fprintf(file,"▽");
			break;

			case 31:
			fprintf(file,"▼");
			break;

			case 40:
			fprintf(file,"◁");
			break;

			case 41:
			fprintf(file,"◀");
			break;
		}
	}
	fprintf(file,"\n");
}
fclose(file);
return 0;
}
