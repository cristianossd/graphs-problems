#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int e, l, label[101], test_num = 1;

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
  int i, j, x, y;
  bool result;

  scanf("%d %d\n", &e, &l);
  if (((e == 0)&&(l == 0)) ||
      ((e < 3)||(e > 100)) ||
      ((l < e-1)||(l > e*(e-1)/2)))
    return 0;

  int graph[e][e];

  memset(graph, 0, sizeof(graph[0][0]) * e * e);
  // reading the input
  for (i=0; i<l; i++) {
    scanf("%d %d\n", &x, &y);
    graph[x-1][y-1] = 1;
    graph[y-1][x-1] = 1;
  }

  for (i=0; i<e; i++) {
    for (j=0; j<e; j++) {
      if (!match_path(graph, i, j))
        result = false;
    }
  }

  if (result)
    printf("Teste %d\nnormal\n\n", test_num);
  else
    printf("Teste %d\nfalha\n\n", test_num);

  test_num++;
  build_graph();
}

int main() {
  build_graph();

  return 0;
}
