#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int e, l, label[101], test_num = 1;

void reach(int g[][e], int from) {
  int v;

  label[from] = 1;
  for (v=0; v<e; v++)
    if ((g[from][v] == 1 || g[v][from] == 1) && label[v] == 0)
      reach(g, v);
}

_Bool match_path(int g[][e], int from, int to) {
  int v;

  for (v=0; v<e; v++)
    label[v] = 0;
  reach(g, from);

  if (label[to] == 0)
    return false;
  return true;
}

_Bool transmission_state(int g[][e]) {
  int i, j;

  for (i=0; i<e; i++) {
    for (j=0; j<e; j++) {
      if (!match_path(g, i, j))
        return false;
    }
  }

  return true;
}

_Bool build_graph() {
  int i, j, x, y, graph[e][e];

  memset(graph, 0, sizeof(graph[0][0]) * e * e);
  // reading the input
  for (i=0; i<l; i++) {
    scanf("%d %d\n", &x, &y);
    graph[x-1][y-1] = 1;
  }

  if (!transmission_state(graph))
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

    if (build_graph())
      printf("Teste %d\nnormal\n\n", test_num);
    else
      printf("Teste %d\nfalha\n\n", test_num);
    test_num++;
  }
}
