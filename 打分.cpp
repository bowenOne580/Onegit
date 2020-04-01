#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n,a;
	cin>>a;
	float sum=0,bi=-1,sm=11;
	for (int i=0;i<a;i++){
		cin>>n;
		if (n>bi){
			bi=n;
		}
		if (n<sm){
			sm=n;
		}
		sum+=n;
	} 
	cout<<fixed<<setprecision(2)<<(sum-bi-sm)/(a-2);
	return 0;
}

