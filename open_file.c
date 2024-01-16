#include <stdio.h>
#include<stdlib.h>
int main() {
FILE *file;
char filename[100];
char text[] = "To jest przykładowy tekst do zapisania w pliku.";
for (int i = 1; i <= 10; i++) {
      sprintf(filename, "mapy/file_%d.txt", i);
      file = fopen(filename, "w");
   
      if (file == NULL) {
         printf("Nie można otworzyć pliku %s.", filename);
         return 1;
      }

      fprintf(file, "%s", text);
      fclose(file);

      printf("Plik %s został pomyślnie utworzony i zapisany.\n", filename);
   }

return 0;
}
