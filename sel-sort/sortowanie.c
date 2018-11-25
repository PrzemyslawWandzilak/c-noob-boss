// Wymagane aby dzialala funkcjonalnosc math z glibc
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define MAX_ELEMENTS 1000

int main (int argc, char *argv[]) 
{
  // deklaracja tablicy o stalej wielkosci
  // TODO: dorobic zarzadzanie pamiecia zeby zniesc ograniczenie
  int elements[MAX_ELEMENTS];
  char string[108];
  int  liczbaelementow;
  int  high, low, min, minindex, buff;
  //int i;

  if (argc != 1)
  {
    printf("Program nie przyjmuje argumentow\n");
    return 0; 
  }

  // Odczytaj liczbe elementow do posortowania
  printf("Podaj liczbe elementow do posortowania:\n");
  gets(string);
  printf("Uzytkownik podal: %s\n", string);

  // Zamiana string to int
  liczbaelementow = atoi(string);
  printf("Po zamianie na liczbe: %d\n\n", liczbaelementow);


  // Zaplodnic generator liczb pseudolosowych czasem
  srand(0);

  // Wygenerowac podana liczbe liczb losowych
  high = 100;
  low = 0;
  for (int i=0; i < liczbaelementow; i++)
  {
    elements[i] = (rand() % (high - low)) + low;
    printf("Element[%d]: %d\n", i, elements[i]);
  }
  
  printf("Elements[%d]: ", liczbaelementow); for (int i=0; i < liczbaelementow; i++) { printf("%d ", elements[i]); } printf("\n\n");

  // Sortowanie 
  for (int krok = 0; krok < liczbaelementow - 1; krok++)
  {
    min = elements[krok];
    minindex = krok;
    for(int pilot = krok +1; pilot < liczbaelementow; pilot++)
    {
      if(elements[pilot] < min)
      {
        min = elements[pilot];
	minindex = pilot;
      }
    }
    if (minindex > krok)
    {
      buff = elements[krok];
      elements[krok] = elements[minindex];
      elements[minindex] = buff;
    }

  printf("Krok[%d]: ", krok); for (int i=0; i < liczbaelementow; i++) { printf("%02d ", elements[i]); } printf("\n");
  for (int i=0; i < 3*krok+10; i++) printf(" ");printf("^\n");
  }


  return (0);
}
