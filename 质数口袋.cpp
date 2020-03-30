#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int sum=0,i=2,num=0;
	while (sum<=a)
	{
		int flag=1;
		for (int j=2;j<=i/2;j++)
		{
			if (i%j==0){
				flag=0;
				break;
			}
		}
		if (flag==1){
			sum+=i;
			if (sum<=a){
				num++;
				cout<<i<<endl;
			}
		}
		i++;
	}
	cout<<num;
	return 0;
}

