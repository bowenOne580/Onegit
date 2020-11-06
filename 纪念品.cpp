#include<iostream>
#include<cstring>
using namespace std;
int dp[10005]= {0};
int price[105][10005]= {0};
int main()
{
	int T,M,N;
	cin>>T>>N>>M;
	for(int i=1; i<=T; i++)
		for(int j=1; j<=N; j++)
			cin>>price[i][j];
	for(int i=2; i<=T; i++) //天
	{
		int maxn = 0; //第N天能够求得的最大利润
		memset(dp,0,sizeof(dp));
		for(int j=1; j<=N; j++) //商品类别
		{
			for(int k=price[i-1][j]; k<=M; k++) //有多少本金
			{
//dp[k] = max(有K元不买卖,dp[k-price[t-1][n]]+今天的价格-昨天的价格)
				dp[k] = max(dp[k],dp[k-price[i-1][j]]+price[i][j]-price[i-1]
				            [j]) ;
				maxn = max(maxn,dp[k]);
			}
		}
		M += maxn;
	}
	cout<<M;
	return 0;
}
