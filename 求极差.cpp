#include<iostream>
using namespace std;
int main(){
	int a,n;
	cin>>n;
	int bi=-1,sm=1001;
	for (int i=0;i<n;i++)
	{
		cin>>a;
		if (a>bi){
			bi=a;
		}
		if (a<sm){
			sm=a;
		}
	}
	cout<<bi-sm;
	return 0;
}

