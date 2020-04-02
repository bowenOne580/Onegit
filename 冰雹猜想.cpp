#include<iostream> 
using namespace std;
int main(){
	int a[1000]={};
	int b;
	cin>>b;
	int i=0;
	while (b!=1){
		a[i]=b;
		if (b%2!=0){
			b*=3;
			b+=1;
		}
		else{
			b/=2;
		}
		i++;
	}
	cout<<1<<" ";
	for (int j=i-1;j>=0;j--){
		cout<<a[j]<<" ";
	}
	return 0;
}

