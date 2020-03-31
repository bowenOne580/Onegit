#include<iostream>
using namespace std;
int main(){
	int a,a1,n;
	cin>>n>>a;
	int sum=1,bi=0;
	for (int i=1;i<n;i++)
	{
		a1=a;
		cin>>a;
		if (a-a1==1){
			sum++;
		}
		else{
			if (sum>bi){
				bi=sum;
			}
			sum=1;
		}
	}
	cout<<bi;
	return 0;
}

