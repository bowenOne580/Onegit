#include<bits/stdc++.h>
using namespace std;
double a,b,c,p,ans;
int main() {
    cin>>a>>b>>c;
    p=(a+b+c)*0.5;
    ans=sqrt((p-a)*(p-b)*(p-c)*p);
    printf("%0.1f\n",ans);
    return 0;
}
