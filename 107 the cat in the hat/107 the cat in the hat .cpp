#include<iostream>
#include<cstdio>
#include<cmath>
#define ERROR 1e-8
using namespace std;

int main(){
  int H, num, m, N;
   #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
   #endif


  while( scanf( "%d%d", &H, &num ) != EOF && !(H == 0 && num == 0)){
    if( H == 1 && num == 1 ){
      printf( "0 1\n");
      continue;
    }

    m = 1;
    while( H != (int)(pow(pow(num,1.0/m)+1.0, m)+ERROR) ) m++;
    N = (int)(pow(num,1.0/m)+ERROR);
    if( N != 1 ) printf( "%d %d\n", (1-num)/(1-N), (H-num)*N+H );
    else printf( "%d %d\n", m, (H-num)*N+H );
  }
  return 0;
}
