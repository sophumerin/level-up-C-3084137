#include <stdio.h>

int main()
{
  char unshuffled[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  int decksize = sizeof(unshuffled) / sizeof(unshuffled[0]);
  // Desk work required, buffer size is too small for even lengths
  // int halfsize = decksize / 2 + (decksize % 2) ? 0 : 1
  char bottomhalf[halfsize];
  printf("Not yet implemented.\n");
}
