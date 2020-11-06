#include<iostream>
#include<cstring>
using namespace std;
int map[105][105] = {0};
int perfect[105][105];
int m,n,ans=0x7fffffff;
int next[4][2] = {{0,1},{0,-1},{-1,0},{1,0}} ;
void dfs(int x,int y,int sum,int flag)
{
//判断边界
	if(x<1||x>m||y<1||y>m) return;
//剪枝的条件
	if(sum>=perfect[x][y]) return;
//记忆当前最优解 标记！
	perfect[x][y]=sum;
//到达终点条件
	if(x==m&&y==m)
	{
		if(sum<ans) ans = sum;
		return ;
	}
//遍历每一种可能
	for(int i=0; i<4; i++)
	{
		int tx = x+next[i][0];
		int ty = y+next[i][1];
//如果有颜色 是否花费金币
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
