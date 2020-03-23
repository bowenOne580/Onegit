#include<iostream>
using namespace std;
int main(){
	int m,t,s;
	cin>>m>>t>>s;
	int time=s/t;
	if (s%t!=0){
		time=s/t+1;
	}
	if (time>m){
		cout<<0;
	}
	else{
		cout<<m-time;
	}
	return 0;
}

