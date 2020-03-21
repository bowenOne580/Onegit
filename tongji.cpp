#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("tongji.in");
ofstream cout("tongji.out");
int main(){
	std::ios::sync_with_stdio(false);
	char a[105]={};
	cin.getline(a,100);
	int d=0,x=0,s=0,b=0;
	for (int i=0;i<strlen(a);i++)
	{
		if (a[i]>='A'&&a[i]<='Z') d++;
		else if (a[i]>='a'&&a[i]<='z') x++;
		else if (a[i]>='0'&&a[i]<='9') s++;
		else if (a[i]==' ') b++;
	}
	b=strlen(a)-d-x-s-b;
	cout<<d<<" "<<x<<" "<<s<<" "<<b;
	cin.close();
	cout.close();
	return 0;
}

