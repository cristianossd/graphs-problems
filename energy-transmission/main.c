#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int e, l, label[101], test_num = 1;

int depth_search(int g[][e], int from, int to) {
  int node;

  label[from] = 1;
  for (node=0; node<e; node++)
    if (g[from][node] == 1 && label[node] == 0)
      depth_search(g, node, to);

  return label[to] == 1;
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
  memset(label, 0, sizeof(label[0]) * e);
  // reading the input
  for (i=0; i<l; i++) {
    scanf("%d %d\n", &x, &y);
    graph[x-1][y-1] = 1;
    graph[y-1][x-1] = 1;
  }

  for (i=0; i<e; i++) {
    for (j=0; j<e; j++) {
      if (!depth_search(graph, i, j))
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
