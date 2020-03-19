#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	char a[55]={};
	cin>>n>>a;
	for (int i=0;i<strlen(a);i++)
	{
		a[i]=(a[i]-'a'+n)%26+'a';
	}
	cout<<a;
	return 0;
}

