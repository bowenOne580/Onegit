#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,sm=100001;
	for (int i=0;i<n;i++){
		cin>>a;
		if (a<sm){
			sm=a;
		}
	} 
	cout<<sm;
	return 0;
}

