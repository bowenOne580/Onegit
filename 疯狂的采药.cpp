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
		for(int j=w[i]; j<=t; j++) //ע�������򣡣��� ��Ϊ���ԷŶ��
// ���벻���еĽ��Ž� = ���������ۺ�ʣ��ļ�ֵ���Ž� + �õ��Ļر��� PK ʲô��
			����
			dp[j]=max(dp[j-w[i]]+val[i], dp[j]);
	cout<<dp[t];
	return 0;
}
