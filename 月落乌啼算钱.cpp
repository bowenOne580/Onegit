#include<iostream>
using namespace std;
long long a=1,b=1,c=0;///��Ϊn<=48,���Դ�һ��
int n,i;
int main()
{
    cin>>n;
    for (i=3;i<=n;i++)
    {///ע���ˣ����ʵ� ���ˣ�����
        c=a+b;
        a=b;
        b=c;
    }
    cout<<c<<".00";///".00"��Ϊ�˷�������.......
    return 0;
}
