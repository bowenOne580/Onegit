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
		for(int j=t; j>=w[i]; j--) //ע���ǵ��򣡣��� ֻ�ܷ�һ����
// ���벻���еĽ��Ž� = ���������ۺ�ʣ��ļ�ֵ���Ž� + �õ��Ļر��� PK ʲô��
			����
			dp[j]=max(dp[j-w[i]]+val[i], dp[j]);
	cout<<dp[t];
	return 0;
}
/*���ڵ��򲿷ֵ�ע��
���� ��������CΪ 10 ��Ʒ����WΪ5 ��ֵV Ϊ5
���������
dp[0] = 0
dp[5]=dp[5-w]+V = dp[0]+5
dp[10]=dp[10-w]+V = dp[5]+5 = 10
��Ȼ�Ǵ�ģ���Ϊ��01������ֻ��һ����Ʒ��ֻ��װһ�Σ���ֵΪ5��
��������˼·���� ��ȫ���� ��˼· �������⡣
*/
