#include <stdio.h>
#include <string.h>

void shuffle(char *, char *, char *);
void cut(char *, char *, char *, int);

#define DUMPVARS printf("%d\n%s\n%s\n%s\n%s\n", cuts, unshuffled, deck, tophalf, bottomhalf);
#define PRINTDECK printf("%s\n", deck);
#define DEBUGPRINT PRINTDECK
int cuts = 0;

int main()
{
  char unshuffled[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // subtract out the null terminator and diligently put it back in later
  int decksize = sizeof(unshuffled) / sizeof(unshuffled[0]) - 1;

  int halfsize = decksize / 2 + decksize % 2;
  char bottomhalf[halfsize + 1];
  char tophalf[halfsize + 1];
  char deck[decksize + 1];
  // DEBUGPRINT;
  strcpy(deck, unshuffled);
  do
  {
    cut(bottomhalf, tophalf, deck, halfsize);
    shuffle(deck, bottomhalf, tophalf);
    DEBUGPRINT;
  } while (strcmp(unshuffled, deck));
  printf("Program terminates after %d cuts\n", cuts);
}

void shuffle(char *deck, char *bottomhalf, char *tophalf)
{
  while (*bottomhalf && *tophalf)
  {
    *deck = *bottomhalf;
    bottomhalf++;
    deck++;
    *deck = *tophalf;
    deck++;
    tophalf++;
  }
  while (*bottomhalf)
  {
    *deck = *bottomhalf;
    bottomhalf++;
    deck++;
  }
  while (*tophalf)
  {
    *deck = *tophalf;
    deck++;
    tophalf++;
  }
  // both pointers exhausted
  *deck = '\0';
}

void cut(char *bottomhalf, char *tophalf, char *deck, int cutpoint)
{
  memcpy(bottomhalf, deck, cutpoint);
  bottomhalf[cutpoint + 1] = '\0';
  strcpy(tophalf, deck + cutpoint);
  cuts++;
}