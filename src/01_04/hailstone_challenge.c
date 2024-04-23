#include <stdio.h>

int main()
{
  int a;
  int count;
  printf("Enter the beginning number of hailstone sequence:\n");
  scanf("%d", &a);

  if (a < 1)
  {
    printf("Number must be a whole number greater than 1.\n");
    return 0;
  }
  if (a == 1)
  {
    printf("Hailstone sequence terminated after 1 element.\n");
    return 0;
  }
  count = 1;
  while (a > 1)
  {
    if (a % 2 == 1)
    {
      a = 3 * a + 1;
    }
    else
    {
      a = a / 2;
    }
    count++;
    printf("%d\n", a);
  }
  printf("Hailstone sequence terminates after %d elements.\n", count);
  return 0;
}