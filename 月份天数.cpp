#include<iostream>
using namespace std;
int main(){
	int y,m;
	cin>>y>>m;
	if (m!=2){
		if (m<7){
			if (m%2==0){
				cout<<30;
			}
			else{
				cout<<31;
			}
		}
		else if (m<9){
			cout<<31;
		}
		else{
			if (m%2==0){
				cout<<31;
			}
			else{
				cout<<30;
			}
		}
	}
	else{
		if (y%4==0){
			if (y%100==0&&y%400!=0){
				cout<<28;
			}
			else{
				cout<<29;
			}
		}
		else{
			cout<<28;
		}
	}
	return 0;
}

