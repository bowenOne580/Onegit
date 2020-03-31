#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num=1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++){
			if (num<10){
				cout<<0<<num;
			}
			else{
				cout<<num;
			}
			num++;
		}
		cout<<endl;
	}
	num=1;
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		for (int p=0;p<n-i-1;p++){
			cout<<"  ";
		}
		for (int j=n-i-1;j<n;j++){
			if (num<10){
				cout<<0<<num;
			}
			else{
				cout<<num;
			}
			num++;
			
		}
		cout<<endl;
	}
	return 0;
}

