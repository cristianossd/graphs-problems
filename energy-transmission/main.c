#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int e, l, i;

void print(int *p) {
  printf("%d %d\n", *(p + (i*2)), *(p + (i*2) + 1));
}

// To acess the the element: *(p + (line*2) + col)
void transmission_state() {
  int x, y, pair[l][2];

  // reading the input
  for (i=0; i<l; i++) {
    scanf("%d %d\n", &(pair[i][0]), &(pair[i][1]));
    print(&pair[0][0]);
  }
}

int main() {
  while (true) {
    scanf("%d %d\n", &e, &l);
    if (((e == 0)&&(l == 0)) ||
       ((e < 3)||(e > 100)) ||
       ((l < e-1)||(l > e*(e-1)/2)))
      exit(1);
    transmission_state();
  }
}
