#include <bits/stdc++.h>
using namespace std;
const long long N=1e4+5,M=1e7+5;
long long t,m,w[N],val[N],dp[M];
int main()
{
	cin>>t>>m;
	for(int i=1; i<=m; i++)
		cin>>w[i]>>val[i];
	for(int i=1; i<=m; i++)
		for(int j=w[i]; j<=t; j++) //注意是正序！！！ 因为可以放多个
// 做与不做中的较优解 = （付出代价后剩余的价值最优解 + 得到的回报） PK 什么都
			不做
			dp[j]=max(dp[j-w[i]]+val[i], dp[j]);
	cout<<dp[t];
	return 0;
}
