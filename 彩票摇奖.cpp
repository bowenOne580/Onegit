#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int prize[7]={};
	int a[7]={};
	for (int i=0;i<7;i++){
		cin>>a[i];
	}
	int num;
	int b[7]={};
	for (int i=0;i<n;i++){
		num=0;
		for (int i=0;i<7;i++){
			cin>>b[i];
		}
		for (int j=0;j<7;j++){
			for (int k=0;k<7;k++){
				if (b[j]==a[k]){
					num++;
					break;
				}
			}
		}
		if (num>0){
		prize[7-num]+=1;
	}
	}
	for (int i=0;i<7;i++){
		cout<<prize[i]<<" ";
	}
	return 0;
}

