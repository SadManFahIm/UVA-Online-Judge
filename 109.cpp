#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct point {
 int x, y;
};

point piv;

int cross(point c, point a, point b) {
 int x1 = a.x - c.x;
 int x2 = b.x - c.x;
 int y1 = a.y - c.y;
 int y2 = b.y - c.y;
 return x1 * y2 - x2 * y1;
}

bool operator <(point a, point b) {
 return cross(piv, a, b) < 0;
}

int main() {
 int n = 0, m;
 vector<point> p[20];

 //double area[20];
 double area;
 point hull[20][101];
 int h[20];

 double sol = 0;
 point fire;
 bool alive[101];

 //freopen("109.in","r",stdin);

 cin >> m;
 while (m != -1) {
  for (int j = 0; j < m; j++) {
   point pp;
   cin >> pp.x >> pp.y;
   p[n].push_back(pp);
  }
  n++;
  cin >> m;
 }

    //1. find Convex Hull
 for (int i = 0; i < n; i++) {
  int mn = 0;
  for (int j = 1; j < p[i].size(); j++)
   if (p[i][j].x < p[i][mn].x || p[i][j].x == p[i][mn].x && p[i][j].y < p[i][mn].y)
    mn = j;
  piv = p[i][mn];
  p[i][mn] = p[i][0];
  p[i][0] = piv;
  sort(p[i].begin() + 1, p[i].end());

  p[i].push_back(piv);
  hull[i][0] = p[i][0];
  hull[i][1] = p[i][1];
  h[i] = 2;
  for (int j = 2; j < p[i].size(); j++) {
   while (h[i] >= 2 && cross(hull[i][h[i] - 2], hull[i][h[i] - 1], p[i][j]) > 0)
    h[i]--;
   hull[i][h[i]++] = p[i][j];
  }
 }

    //2. Is Missile land inside a convex hull, then find area and sum
 memset(alive, true, sizeof(alive));
 while (cin >> fire.x >> fire.y) {
  for (int i = 0; i < n; i++)
   if (alive[i]) {
       // Check missile is in convex hull
    bool mark = true;
    for (int j = 1; j < h[i]; j++) {
     if (cross(hull[i][j - 1], hull[i][j], fire) > 0) {
      mark = false;
      break;
     }
    }
    if (mark) {
     alive[i] = false;
                    // Inside- Yes
     area = 0;
              for (int j = 1; j < h[i]; j++)
                area += hull[i][j - 1].x * hull[i][j].y - hull[i][j].x * hull[i][j - 1].y;
                    area =area/2;
     sol += area;
    }
   }
 }
 printf("%.2f\n", abs(sol));

 return 0;
}