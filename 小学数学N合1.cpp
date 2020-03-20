#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout<<3<<endl<<12<<endl<<2<<endl;
    } else if (T == 4) {
        printf("%.3lf\n",500.0/3.0);
    } else if (T == 5) {
        cout<<15<<endl;
    } else if (T == 6) {
        cout<<sqrt(6*6+9*9)<<endl;
    } else if (T == 7) {
        cout<<110<<endl<<90<<endl<<0<<endl;
    } else if (T == 8) {
        double const pi=3.141593;
        double const r=5;
        cout<<pi*r*2<<endl<<pi*r*r<<endl<<4.0/3*pi*r*r*r<<endl;
    } else if (T == 9) {
        cout<<22<<endl;
    } else if (T == 10) {
        cout<<9<<endl;
    } else if (T == 11) {
        cout<<100.0/(8-5)<<endl;
    } else if (T == 12) {
        cout<<13<<endl<<"R"<<endl;
    } else if (T == 13) {
        double const pi=3.141593;
        double V=pi*4*4*4*4/3+pi*10*10*10*4/3;
        cout<<floor(pow(V,1.0/3))<<endl;
    } else if (T == 14) {
        cout<<50<<endl;
    }
    return 0;
}
