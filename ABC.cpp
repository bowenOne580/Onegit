#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[3]={};
	for (int i=0;i<3;i++)
	{
		cin>>a[i];
	}
	sort(a,a+3);
	char a1,b,c;
	cin>>a1>>b>>c;
	cout<<a[a1-65]<<" "<<a[b-65]<<" "<<a[c-65];
	return 0;
}

