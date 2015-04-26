#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int e, l;
int test_num = 1;

_Bool match_path(int from, int to) {
  return true;
}

_Bool read_graph(int p[][e]) {
  // To access the element of array: *(p + (line*2) + col)
  int i, j;

  for (i=0; i<e; i++) {
    for (j=0; j<e; j++) {
      if (!match_path(i, j))
        return false;
    }
  }

  return true;
}

_Bool transmission_state() {
  int i, j, x, y, pair[e][e];

  memset(pair, 0, sizeof(pair[0][0]) * e * e);
  // reading the input
  for (i=0; i<l; i++) {
    scanf("%d %d\n", &x, &y);
    printf("Att %d:%d - ", x, y);
    pair[x-1][y-1] = 1;
    printf("%d:%d with %d\n", x-1, y-1, pair[x-1][y-1]);
  }

  if (!read_graph(pair))
    return false;
  return true;
}

int main() {
  while (true) {
    scanf("%d %d\n", &e, &l);
    if (((e == 0)&&(l == 0)) ||
       ((e < 3)||(e > 100)) ||
       ((l < e-1)||(l > e*(e-1)/2)))
      exit(1);

    if (transmission_state())
      printf("Teste %d\nnormal\n\n", test_num);
    else
      printf("Teste %d\nfalha\n\n", test_num);
    test_num++;
  }
}
