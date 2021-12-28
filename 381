#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
 int testcase;
 int S, T;
 int test[105][105], bonus[105], absent[105];
 int G[105];
 scanf("%d", &testcase);
 puts("MAKING THE GRADE OUTPUT");
 while(testcase--) {
  scanf("%d %d", &S, &T);
  for(int i = 0; i < S; i++) {
   for(int j = 0; j < T; j++) {
    scanf("%d", &test[i][j]);
   }
   scanf("%d %d", &bonus[i], &absent[i]);
  }
  double avg[105], adjAvg[105];
  double mean = 0, sd = 0, avgG = 0;
  for(int i = 0; i < S; i++) {
   sort(test[i], test[i]+T);
   int start = 0;
   if(T > 2) start = 1;
   avg[i] = 0;
   for(int j = start; j < T; j++) {
    avg[i] += test[i][j];
   }
   avg[i] /= T - start;
   avg[i] = floor(avg[i]);
   mean += avg[i];
  }
  mean /= S;
  for(int i = 0; i < S; i++) {
   sd += (avg[i] - mean)*(avg[i] - mean);
  }
  sd = sqrt(sd / S);
  if(sd < 1)
   sd = 1;
  for(int i = 0; i < S; i++) {
   adjAvg[i] = avg[i] + (bonus[i]/2)*3;
  }
  for(int i = 0; i < S; i++) {
   if(adjAvg[i] >= mean + sd)
    G[i] = 0;
   else if(adjAvg[i] >= mean)
    G[i] = 1;
   else if(adjAvg[i] >= mean - sd)
    G[i] = 2;
   else 
    G[i] = 3;
  }
  for(int i = 0; i < S; i++) {
   if(absent[i] == 0)
    G[i]--;
   else 
    G[i] += absent[i]/4;
   G[i] = min(max(G[i], 0), 4);
   avgG += 4 - G[i];
  }
  avgG /= S;        
  printf("%.1lf\n", avgG);
 }
 puts("END OF OUTPUT");
 return 0;
}
