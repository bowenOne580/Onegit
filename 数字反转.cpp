#include<bits/stdc++.h>
using namespace std;
long long s[11]={},n,k=0,a=1;
int main()
{
    memset(s,0,sizeof(n));
    cin>>n;
    for(int i=1;i<=10;i++) s[i]=n/a%10,a*=10;
    a=1000000000;
    for(int i=1;i<=10;i++) k+=s[i]*a,a/=10;
    while(k%10==0) k/=10;
    cout<<k;
    return 0;
}
