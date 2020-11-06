#include<iostream>
#include<cstring>
using namespace std;
int map[105][105] = {0};
int perfect[105][105];
int m,n,ans=0x7fffffff;
int next[4][2] = {{0,1},{0,-1},{-1,0},{1,0}} ;
void dfs(int x,int y,int sum,int flag)
{
//�жϱ߽�
	if(x<1||x>m||y<1||y>m) return;
//��֦������
	if(sum>=perfect[x][y]) return;
//���䵱ǰ���Ž� ��ǣ�
	perfect[x][y]=sum;
//�����յ�����
	if(x==m&&y==m)
	{
		if(sum<ans) ans = sum;
		return ;
	}
//����ÿһ�ֿ���
	for(int i=0; i<4; i++)
	{
		int tx = x+next[i][0];
		int ty = y+next[i][1];
//�������ɫ �Ƿ񻨷ѽ��
		if(map[tx][ty])
		{
			if(map[tx][ty]==map[x][y]) dfs(tx,ty,sum,0);
			else dfs(tx,ty,sum+1,0);
		}
		else if(flag ==0 )
		{
			map[tx][ty] = map[x][y];
			dfs(tx,ty,sum+2,1);
			map[tx][ty] = 0;
		}
	}
}
int main()
{
	cin>>m>>n;
	memset(perfect,0x7f,sizeof(perfect));
	for(int i=0; i<n; i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		map[x][y]=c+1;
	}
	dfs(1,1,0,0) ;
	if(ans!=0x7fffffff) cout<<ans;
	else cout<<-1;
	return 0;
}
