#include <stdio.h>
#include<stdlib.h>
int main() {

int status = system("mkdir mapy");

// Sprawdzanie, czy utworzenie folderu było udane
if (status == 0) {
	printf("Folder 'mapy' został utworzony.\n");
} 
else {
	printf("Nie udało się utworzyć folderu 'mapy'.\n");
}

return 0;
}
