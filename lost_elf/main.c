#include <stdio.h>
#define LIMIT 102

int shortest,
    graph[LIMIT][LIMIT],
    coast[LIMIT][LIMIT];

void shortest_path(int coord_x, int coord_y, int tax, int x, int y) {
  if ((graph[coord_x][coord_y] == 1 |
       graph[coord_x][coord_y] == 3) &&
       tax < coast[coord_x][coord_y]) {

    coast[coord_x][coord_y] = tax;

    if ((coord_x != x || coord_y != y) &&
         graph[coord_x][coord_y + 1] != -1)
      shortest_path(coord_x, coord_y + 1, tax+1, coord_x, coord_y);

    if ((coord_x + 1 != x || coord_y != y) &&
        graph[coord_x + 1][coord_y] != -1)
      shortest_path(coord_x + 1, coord_y, tax+1, coord_x, coord_y);

    if ((coord_x != x || coord_y - 1 != y) &&
         graph[coord_x][coord_y - 1] != -1)
      shortest_path(coord_x, coord_y-1, tax+1, coord_x, coord_y);

    if ((coord_x - 1 != x || coord_y != y) &&
         graph[coord_x - 1][coord_y] != -1)
      shortest_path(coord_x - 1, coord_y, tax+1, coord_x, coord_y);
  }

  if (graph[coord_x][coord_y] == 0) {
    if (tax < coast[coord_x][coord_y])
      coast[coord_x][coord_y] = tax;
    if (coast[coord_x][coord_y] < shortest)
      shortest = coast[coord_x][coord_y];
  }
}

int read_graph() {
  int i, j, n, m, coord_x, coord_y;

  scanf("%d %d", &n, &m);
  shortest = n*m;

  for (i=0; i<=n+1; i++)
    for (j=0; j<=m+1; j++) {
      graph[i][j] = -1;
      coast[i][j] = n*m;
    }

  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j] == 3) {
        coord_x = i;
        coord_y = j;
      }
    }

  shortest_path(coord_x, coord_y, 0, 0, 0);
  printf("%d\n", shortest);

  return 0;
}

int main() {
  read_graph();

  return 0;
}
