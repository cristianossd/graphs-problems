#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int e, l, i;

void read_input() {
  int x, y;

  for (i=0; i<l; i++) {
    scanf("%d %d\n", &x, &y);
    printf("%d-line of %d\n", i, l);
  }
}

int main() {
  while (true) {
    scanf("%d %d\n", &e, &l);
    if (((e == 0)&&(l == 0)) ||
       ((e < 3)||(e > 100)) ||
       ((l < e-1)||(l > e*(e-1)/2)))
      exit(1);
    read_input();
  }
}
