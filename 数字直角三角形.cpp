#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int num=1,a1=a;
	for (int i=0;i<a;i++)
	{
		for (int j=0;j<a1;j++)
		{
			if (num<10){
				cout<<0<<num;
			}
			else{
				cout<<num;
			}
			num++;
		}
		cout<<endl;
		a1--;
	}
	return 0;
}

