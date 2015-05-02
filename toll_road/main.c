#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int c, e, l, p, label[50], test_num = 1;

int depth_search(int g[][c], int tax, int city) {
  int node;

  if (tax > p)
    return true;

  label[city] = 1;
  for (node=0; node<c; node++)
    if (g[city][node] == 1 && label[node] == 0)
      depth_search(g, tax + 1, node);
}

int build_graph() {
  int i, j, x, y, control;

  scanf("%d %d %d %d", &c, &e, &l, &p);
  if ((c == 0 && e == 0 && l == 0 && p == 0) ||
      (c < 0 || c > 50) ||
      (e < 0 || e > 2500) ||
      (l < 0 || l > c) ||
      (p < 0 || p > c))
    return 0;

  int graph[c][c];

  memset(graph, 0, sizeof(graph[0][0]) * c * c);
  memset(label, 0, sizeof(label[0]) * c);
  // reading the input
  for (i=0; i<e; i++) {
    scanf("%d %d", &x, &y);
    graph[x-1][y-1] = 1;
    graph[y-1][x-1] = 1;
  }

  control = 0;
  if (depth_search(graph, 0, l-1)) {
    printf("Teste %d\n", test_num);
    for (i=0; i<c; i++) {
      if (label[i] == 1 && i != l-1) {
        if (control == 0)
          printf("%d", i+1);
        else
          printf(" %d", i+1);
        control++;
      }
    }
    printf("\n\n");
  }

  test_num++;
  build_graph();
}

int main() {
  build_graph();

  return 0;
}
