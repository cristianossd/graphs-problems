#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INFINITY 9999

int n, m;

void dijkstra(int graph[][n], int root, int parent[], int dist[]) {
  int i, v0, w, head[n], cost, min_dist;

  for (w=0; w<n; w++) {
    parent[w] = -1;
    dist[w] = INFINITY;
  }
  parent[root] = root;
  dist[root] = 0;
  for (i=0; i<n; i++) {
    if (graph[root][i] > 0) {
      w = i;
      cost = graph[root][i];
      dist[w] = cost;
      head[w] = root;
    }
  }

  while (1) {
    min_dist = INFINITY;
    for (w=0; w < n; w++)
      if (parent[w] == -1 && min_dist > dist[w]) {
        min_dist = dist[w];
        v0 = w;
      }
    if (min_dist == INFINITY)
      break;
    parent[v0] = head[v0];
    for (i=0; i<n; i++) {
      if (graph[v0][i] > 0) {
        w = i;
        cost = graph[v0][i];
        if (parent[w] == -1 && dist[w] > dist[v0] + cost) {
          dist[w] = dist[v0] + cost;
          head[w] = v0;
        }
      }
    }
  }

  for (i=0; i<n; i++)
    printf("parent: %d | dist: %d\n", parent[i], dist[i]);
}

int main() {
  int i, j, s, t, b;

  scanf("%d %d", &n, &m);

  int graph[n][n],
      parent[n],
      dist[n];
  memset(graph, 0, sizeof(graph[0][0]) * n * n);

  for (i=0; i<m; i++) {
    scanf("%d %d %d", &s, &t, &b);
    graph[s-1][t-1] = b;
  }

  dijkstra(graph, 0, parent, dist);
  printf("\n");
}
