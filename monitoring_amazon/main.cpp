#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define SIZE 1000
#define NEIGHBORS_NUM 2

int n;
bool label[SIZE];
int coord_x[SIZE];
int coord_y[SIZE];

int graph[SIZE][NEIGHBORS_NUM];

void swap(int& a, int& b) {
 int tmp = a;
 a = b;
 b = tmp;
}

inline bool precede(int a, int b) {
 if (coord_x[a] == coord_x[b])
   return coord_y[a] < coord_y[b];
 else
  if (coord_x[a] < coord_x[b])
    return true;
  else
    return false;
}

void sort(int& a, int& b, int& range0, int& range1) {
 if (range1 < range0 || (range1 == range0 && precede(b, a))) {
  swap(range0, range1);
  swap(a, b);
 }
}

void range_calc() {
 for (int i = 0; i < n; i++) {
  graph[i][0] = -1;
  graph[i][1] = -1;
  int range0 = 0;
  int range1 = 0;

  for (int j = 0; j < n; j++) {
   if (j != i) {
    int rx = coord_x[i] - coord_x[j];
    int ry = coord_y[i] - coord_y[j];
    int range = rx*rx + ry*ry;

    if (graph[i][0] == -1) {
     graph[i][0] = j;
     range0 = range;
    }
    else if (graph[i][1] == -1) {
     graph[i][1] = j;
     range1 = range;

     sort(graph[i][0], graph[i][1], range0, range1);
    }
    else {
     if (range == range1) {
      if (precede(j, graph[i][1])) {
       graph[i][1] = j;
      }

      sort(graph[i][0], graph[i][1], range0, range1);
     }
     else if (range1 > range) {
      graph[i][1] = j;
      range1 = range;

      sort(graph[i][0], graph[i][1], range0, range1);
     }
    }
   }
  }
 }
}

void depth_search(int node) {
 label[node] = true;

 for (int i = 0; i < NEIGHBORS_NUM; i++) {
  if (!label[graph[node][i]])
    depth_search(graph[node][i]);
 }
}

int main() {
 while (scanf("%d\n", &n) == 1) {
  if (n == 0)
    break;

  for (int i = 0; i < n; i++) {
   scanf("%d %d\n", &coord_x[i], &coord_y[i]);
  }

  range_calc();
  for (int i = 0; i < n; i++)
    label[i] = false;

  depth_search(0);
  bool reachable = true;

  for (int i = 0; i < n; i++) {
   if (!label[i]) {
    reachable = false;
    break;
   }
  }

  if (reachable)
    printf("All stations are reachable.\n");
  else
    printf("There are stations that are unreachable.\n");
 }

 return 0;
}
