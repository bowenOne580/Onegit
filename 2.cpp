#include<iostream>
#include<cstring> 
using namespace std;
char a1[1001];
int a[1001],b,c[1001];
int main(){
	cin>>a1>>b;
	int lena=strlen(a1);
	for (int i=0;i<lena;i++)
	{
		a[lena-i-1]=a1[i]-48;
	}
	int x=0;//½øÎ»
	for (int i=0;i<lena;i++)
	{
		c[i]=a[i]*b+x;
		x=c[i]/10;
		c[i]%=10;
 	} 
 	c[lena]=x;
 	while(c[lena]==0&&lena>0)
 	{
 		lena--;
	}
	for (int i=lena;i>=0;i--)
	{
		cout<<c[i];
	}
	return 0;
}

