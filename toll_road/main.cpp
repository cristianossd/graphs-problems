#include <stdio.h>
#include <queue>
using namespace std;
#define NODE_LIMIT 50
#define RANGE_LIMIT 100000000

int graph[NODE_LIMIT][NODE_LIMIT];
int range[NODE_LIMIT];

void dijkstra(int n, int source) {
 for (int i = 0; i < n; i++) {
  range[i] = RANGE_LIMIT;
 }

 range[source] = 0;
 priority_queue<pair<int, int> > heap;
 heap.push(make_pair(0, source));

 while (!heap.empty()) {
  int u = heap.top().second;
  heap.pop();

  for (int i = 0; i < n; i++) {
   if (graph[u][i] == 1 && range[u] + 1 <= range[i]) {
    range[i] = range[u] + 1;
    heap.push(make_pair(range[i], i));
   }
  }
 }
}

int main() {
 int c, e, l, p, o, d;
 int test_num = 0;
 int toll_road[101];

 while (1) {
  scanf("%d %d %d %d", &c, &e, &l, &p);
  if (c == 0 && e == 0 && l == 0 && p == 0)
    break;

  for (int i = 0; i < c; i++)
   for (int j = 0; j < c; j++)
    graph[i][j] = 0;

  for (int i = 0; i < e; i++) {
   scanf("%d %d", &o, &d);
   graph[o-1][d-1] = 1;
   graph[d-1][o-1] = 1;
  }

  dijkstra(c, l-1);

  printf("Teste %d\n", ++test_num);
  bool first = true;
  for (int i = 0; i < c; i++) {
   if (i != l-1 && range[i] <= p) {
    if (first) printf("%d", i+1);
    else printf(" %d", i+1);
    first = false;
   }
  }
  printf("\n\n");
 }
 return 0;
}
