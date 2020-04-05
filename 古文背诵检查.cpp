#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char ans[1005]={},inputt[1005]={};
	cin.getline(ans,1005);
	cin.getline(inputt,1005);
	int a=1,mark=100;
	for (int i=0;i<strlen(ans);i++){
		if (inputt[i]!='£¬'){
			if (inputt[i]!='¡£'){
				if (ans[i]!=inputt[i]){
				if (a==1){
					cout<<"Completely Wrong!"<<endl;
				}
				cout<<"Position: "<<ans[i-1]<<ans[i]<<ans[i+1]<<endl;
				a=0;
				mark-=10;
			}
			}
		} 
	} 
	if (a==1){
		cout<<"Amazing,you get FULL MARK!"<<endl;
	}
	cout<<mark;
	return 0;
}

