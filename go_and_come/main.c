#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int e, l, label[101];

int reach(int g[][e], int from, int to) {
  int node;

  if (from == to)
    return true;
  label[from] = 1;
  for (node=0; node<e; node++)
    if (g[from][node] == 1 && label[node] == 0)
      if (reach(g, node, to))
        return 1;
  return 0;
}

int match_path(int g[][e], int from, int to) {
  int node;

  for (node=0; node<e; node++)
    label[node] = 0;
  return reach(g, from, to);
}

int build_graph() {
  int i, j, v, w, p;
  bool result;

  scanf("%d", &e);
  if (e != 0)
    scanf(" %d", &l);
  if (((e == 0)||(l == 0)) ||
      ((e < 2)||(e > 2000)) ||
      ((l < 2)||(l > e*(e-1)/2)))
    return 0;

  int graph[e][e];

  memset(graph, 0, sizeof(graph[0][0]) * e * e);
  // reading the input
  for (i=0; i<l; i++) {
    scanf("%d %d %d\n", &v, &w, &p);
    if (p == 1)
      graph[v-1][w-1] = 1;
    else {
      graph[v-1][w-1] = 1;
      graph[w-1][v-1] = 1;
    }
  }

  for (i=0; i<e; i++) {
    for (j=0; j<e; j++) {
      if (!match_path(graph, i, j))
        result = false;
    }
  }

  if (result)
    printf("1\n");
  else
    printf("0\n");

  build_graph();
}

int main() {
  build_graph();

  return 0;
}
