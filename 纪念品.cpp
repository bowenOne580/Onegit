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
	for(int i=2; i<=T; i++) //��
	{
		int maxn = 0; //��N���ܹ���õ��������
		memset(dp,0,sizeof(dp));
		for(int j=1; j<=N; j++) //��Ʒ���
		{
			for(int k=price[i-1][j]; k<=M; k++) //�ж��ٱ���
			{
//dp[k] = max(��KԪ������,dp[k-price[t-1][n]]+����ļ۸�-����ļ۸�)
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
