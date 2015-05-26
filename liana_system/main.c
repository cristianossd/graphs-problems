#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INFINITY 9999

int n, m, min_cost, test = 1;

void mst_prim(int graph[][n], int parent[]) {
  int boss[n], i, v, v0, w0, x, y, cost;

  for (v=0; v<n; v++)
    boss[v] = v;

  while(1) {
    cost = INFINITY;
    for (v=0; v<n; v++)
      for (i=0; i<n; i++)
        if (graph[v][i] > 0 || graph[i][v] > 0)
          if (boss[v] != boss[i] && cost > graph[i][v]) {
            cost = graph[i][v];
            v0 = v;
            w0 = i;
          }
    if (cost == INFINITY)
      break;
    min_cost = min_cost + graph[v0][w0];
    x = boss[v0];
    y = boss[w0];
    for (v=0; v<n; v++)
      if (boss[v] == y)
        boss[v] = x;
  }

  printf("%d\n", min_cost);
}

int main() {
  int i, j, x, y, z;

  if (scanf("%d %d", &n, &m) == EOF)
    return 0;

  int graph[n][n],
      parent[n];
  memset(graph, 0, sizeof(graph[0][0]) * n * n);

  for (i=0; i<m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    graph[x-1][y-1] = z;
    graph[y-1][x-1] = z;
  }

  printf("Instancia %d\n", test++);
  min_cost = 0;
  mst_prim(graph, parent);
  printf("\n");
  main();
}
