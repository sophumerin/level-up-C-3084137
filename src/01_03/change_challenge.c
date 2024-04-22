#include <stdio.h>

int main(int argc, char **argv)
{
  float amount[] = {0.49, 1.27, 0.75, 1.31, 0.83};

  int x, quarters, dimes, nickles, pennies;

  for (int i = 0; i < 5; i++)
  {
    printf("Making change for %.2f\n", amount[i]);
    x = (int)(amount[i] * 100);
    quarters = 0;
    dimes = 0;
    nickles = 0;
    pennies = 0;

    while (x >= 25)
    {
      quarters++;
      x -= 25;
    }

    while (x >= 10)
    {
      dimes++;
      x -= 10;
    }

    while (x >= 5)
    {
      nickles++;
      x -= 5;
    }
    pennies = x;
    if (quarters > 0)
    {
      printf("%d quarters (25¢)\n", quarters);
    }
    if (dimes > 0)
    {
      printf("%d dimes (10¢)\n", dimes);
    }
    if (nickles > 0)
    {
      printf("%d nickles (5¢)\n", nickles);
    }
    if (pennies > 0)
    {
      printf("%d pennies (1¢)\n", pennies);
    }
    printf("\n");
  }
  return 0;
}
