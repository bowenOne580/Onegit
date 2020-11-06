#include <iostream>
using namespace std;
int w[105], val[105];
int dp[1005];
int main()
{
	int t,m;
	cin>>t>>m;
	for(int i=1; i<=m; i++)
		cin>>w[i]>>val[i];
	for(int i=1; i<=m; i++)
		for(int j=t; j>=w[i]; j--) //注意是倒序！！！ 只能放一个！
// 做与不做中的较优解 = （付出代价后剩余的价值最优解 + 得到的回报） PK 什么都
			不做
			dp[j]=max(dp[j-w[i]]+val[i], dp[j]);
	cout<<dp[t];
	return 0;
}
/*关于倒序部分的注解
假设 背包容量C为 10 物品重量W为5 价值V 为5
如果是正序
dp[0] = 0
dp[5]=dp[5-w]+V = dp[0]+5
dp[10]=dp[10-w]+V = dp[5]+5 = 10
显然是错的，因为是01背包，只有一个物品，只能装一次，价值为5。
但是这种思路就是 完全背包 的思路 ，见下题。
*/
