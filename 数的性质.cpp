#include<iostream>
using namespace std;
int main(){
	int x;
	cin>>x;
	int num=0,num1=0;
	if (x%2==0){
		num=1;
	} 
	if (x>4&&x<=12){
		num1=1;
	}
	if (num==1&&num1==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	cout<<" ";
	if (num==1||num1==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	cout<<" ";
	if (num!=num1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	cout<<" ";
	if (num!=1&&num1!=1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

