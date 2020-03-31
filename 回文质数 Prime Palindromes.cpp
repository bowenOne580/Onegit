#include<iostream>
using namespace std;
bool zhi(int a){
	int flag=1;
	if (a==2||a%2!=0){
		for (int i=2;i*i<=a;i++){
		if (a%i==0){
			flag=0;
			break;
		}
		}
	}
	else{
		flag=0;
	}
	if (flag==1){
		return true;
	}
	else{
		return 0;
	}
}
bool hui(int a){
	 int y=a,num=0;
	 while (y!=0){
	 	num=num*10+y%10;
	 	y/=10;
	 }
	 if (num==a){
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
}
int main(){
	int a,b;
	cin>>a>>b;
	for (int i=a;i<=b;i++)
	{
		if (hui(i)){
			if (zhi(i)){
				cout<<i<<endl;
			}
		}
		if (i>10000000){
			break;
		}
	}
	return 0;
}

