#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n, m, label[2000];

void depth_search(int g[][n], int from) {
  int node;

  if (label[from])
    return;
  label[from] = 1;
  for (node=0; node<n; node++)
    if (g[from][node] == 1 && label[node] == 0)
      depth_search(g, node);
}

int build_graph() {
  int i, j, v, w, p;
  bool response;

  scanf("%d", &n);
  if (n != 0)
    scanf(" %d", &m);
  if (((n == 0)||(m == 0)) ||
      ((n < 2)||(n > 2000)) ||
      ((m < 2)||(m > n*(n-1)/2)))
    return 0;

  int graph[n][n];

  memset(graph, 0, sizeof(graph));
  memset(label, 0, sizeof(label[0]) * n);
  response = true;
  // reading the input
  for (i=0; i<m; i++) {
    scanf("%d %d %d", &v, &w, &p);
    if (p == 1)
      graph[v-1][w-1] = 1;
    else {
      graph[v-1][w-1] = 1;
      graph[w-1][v-1] = 1;
    }
  }

  depth_search(graph, 0);
  for (i=0; i<n; i++)
    if (label[i] == 0)
      response = false;

  if (response) {
    for (i=0; i<n; i++) {
      label[i] = 0;
      for (j=i+1; j<n; j++) {
        if (graph[i][j] == 1 && graph[j][i] == 0) {
          graph[j][i] = 1;
          graph[i][j] = 0;
        }
        else
          if (graph[j][i] == 1 && graph[i][j] == 0) {
            graph[i][j] = 1;
            graph[j][i] = 0;
          }
      }
    }

    depth_search(graph, 0);
  }

  for (i=0; i<n; i++)
    if (label[i] == 0)
      response = false;

  if (response)
    printf("1\n");
  else
    printf("0\n");

  build_graph();
}

int main() {
  build_graph();

  return 0;
}
