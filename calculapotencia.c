#include <stdio.h>

int potencia (int n, unsigned int x);

int main ()
{
  int, n, x;
  printf ("Ingrese la base:");
  scanf ("%d", &n);

  printf ("Ingrese el exponente:");
  scanf ("%d", &x);

  printf ("El resultado es %d", potencia(n, x));
}

int potencia (int n, unsigned int x)
{
  int pot = 1;
  while (x --> 0)
    pot *= n;
  return pot;
}
