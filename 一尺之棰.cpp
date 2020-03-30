#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int num=1; 
	while (a!=1){
		a/=2;
		num++;
	} 
	cout<<num;
	return 0;
}

