#include<iostream>
using namespace std;
long long a=1,b=1,c=0;///因为n<=48,所以大一点
int n,i;
int main()
{
    cin>>n;
    for (i=3;i<=n;i++)
    {///注意了，精彩的 来了！！！
        c=a+b;
        a=b;
        b=c;
    }
    cout<<c<<".00";///".00"是为了符合题意.......
    return 0;
}
