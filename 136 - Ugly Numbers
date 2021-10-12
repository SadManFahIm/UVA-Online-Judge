#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,n,i,ar[1599]={0},x,y,z;
    a=b=c=n=1;
    ar[1]=1;
    while(n!=1501)
    {
        //cout<<ar[n]<<endl;
        x=2*ar[a];
        y=3*ar[b];
        z=5*ar[c];
        ar[++n]=min(x,min(y,z));
        if(ar[n]==x)
            a++;
        if(ar[n]==y)
            b++;
            if(ar[n]==z)
            c++;
    }
    cout<<"The 1500'th ugly number is "<<ar[1500]<<"."<<endl;
}
