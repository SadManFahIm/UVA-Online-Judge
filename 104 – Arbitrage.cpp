#include<cstdio>
#include<cstring>
using namespace std;
void floyd(int n);
void print(int x, int y, int p);
#define N 20
int seq[N][N][N];
double table[N][N][N];
int main(void){
    int n;
    while(scanf("%d",&n) != EOF){
        memset(seq,0,sizeof(seq));
        memset(table,0,sizeof(table));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if( i != j){
                    scanf("%lf",&table[i][j][0]);
                    seq[i][j][0]=i;
                }
        floyd(n);
    }
    return 0;
}
void floyd(int n){
    for(int p=1;p<n;++p){
        for(int i=0;i<n;++i)
            for(int k=0;k<n;++k)
                for(int j=0;j<n;++j)
                    if(table[i][k][p-1]*table[k][j][0] > table[i][j][p]){
                        table[i][j][p] = table[i][k][p-1]*table[k][j][0];
                        seq[i][j][p]=k;
                    }
        for(int i=0;i<n;++i){
            if(table[i][i][p] > 1.01){
                print(i,i,p);
                printf("\n");
                return;
            }
        }
    }
    printf("no arbitrage sequence exists\n");
}
void print(int x, int y, int p){
    if(p == -1){
        printf("%d",x+1);
    }else{
        print(x,seq[x][y][p],p-1);
        printf(" %d",y+1);
    }
}
