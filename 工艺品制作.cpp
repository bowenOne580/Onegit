#include<iostream>
using namespace std;
int w,x,h,q,x1,y1,z1,x2,y2,z2;
int a[25][25][25];
int main(){
	cin>>w>>x>>h>>q;
	while (q--){
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		for (int i=x1-1;i<x2;i++){
			for (int j=y1-1;j<y2;j++){
				for (int k=z1-1;k<z2;k++){
					a[i][j][k]=1;
				}
			}
		}
	}
	int num=0;
	for (int i=0;i<w;i++){
		for (int j=0;j<x;j++){
			for (int k=0;k<h;k++){
				if (a[i][j][k]==0){
					num++;
				}				
			}
		}
	}
	cout<<num;
	return 0;
}

