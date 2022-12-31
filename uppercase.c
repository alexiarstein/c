#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  // Comprobamos si se ha proporcionado un argumento
  if (argc < 2) {
    printf("Por favor proporciona una cadena como argumento\n");
    return 1;
  }

  char *str = argv[1];  // Obtenemos el primer argumento

  for (int i = 0; i < strlen(str); i++) {
    str[i] = toupper(str[i]);
  }

  printf("%s\n", str);  // Imprime la cadena en mayúsculas
  return 0;
}
