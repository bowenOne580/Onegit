#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int d;
	if (a>b){
		d=b;
		b=a;
		a=d;
		if (a>c){
			cout<<c<<" "<<a<<" "<<b;
		}
		else if (b>c){
			cout<<a<<" "<<c<<" "<<b;
		}
		else{
			cout<<a<<" "<<b<<" "<<c;
		}
	}
	else{
		if (a>c){
			cout<<c<<" "<<a<<" "<<b;
		}
		else if (b>c){
			cout<<a<<" "<<c<<" "<<b;
		}
		else{
			cout<<a<<" "<<b<<" "<<c;
		}
	}
	return 0;
}

