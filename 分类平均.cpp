#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	double sum1=0,sum2=0,num1=0,num2=0;
	for (int i=1;i<=a;i++)
	{
		if (i%b==0){
			sum1+=i;
			num1++;
		}
		else{
			sum2+=i;
			num2++;
		}
	} 
	cout<<fixed<<setprecision(1)<<sum1/num1<<" "<<sum2/num2;
	return 0;
}

