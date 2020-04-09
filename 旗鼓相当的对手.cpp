#include<iostream>
#include<cmath>
using namespace std;
struct per{
	int a;
	int b;
	int c;
};
per a[1000];
int main(){
	int n,num=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for (int j=0;j<n;j++){
		for (int i=j+1;i<n;i++){
		if (abs(a[j].a-a[i].a)<=5 && abs(a[j].b-a[i].b)<=5 && abs(a[j].c-a[i].c)<=5 && abs(a[i].a+a[i].b+a[i].c-a[j].a-a[j].b-a[j].c)<=10){
			num++;
		}
	}
	}
	cout<<num;
	return 0;
}

