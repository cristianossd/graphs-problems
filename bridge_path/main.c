#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INFINITY 9999

int n, m;

int min_distance(int dist[], bool control[]) {
  int v, min = INFINITY, min_index;

  for (v=0; v<n; v++) {
    if (control[v] == false && dist[v] <= min) {
      min = dist[v];
      min_index = v;
    }
  }

  return min_index;
}

void dijkstra(int graph[][n], int root) {
  int i, v, dist[n];
  bool control[n];

  for (i=0; i<n; i++) {
    dist[i] = INFINITY;
    control[i] = false;
  }

  dist[root] = 0;

  for (i=0; i<n; i++) {
    int u = min_distance(dist, control);

    control[u] = true;
    for (v=0; v<n; v++) {
      if (!control[v] && graph[u][v] && dist[u] != INFINITY
          && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
    }
  }

  for (i=0; i<n; i++)
    printf("%d\n", dist[i]);
}

int main() {
  int i, j, s, t, b;

  scanf("%d %d", &n, &m);

  int graph[n][n];
  memset(graph, 0, sizeof(graph[0][0]) * n * n);

  for (i=0; i<m; i++) {
    scanf("%d %d %d", &s, &t, &b);
    graph[s-1][t-1] = b;
    graph[t-1][s-1] = b;
  }

  dijkstra(graph, 0);
  printf("\n");
}
