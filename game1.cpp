#include<iostream>
#include<cstdio>
#include<ctime> //���ڲ��������(ϵͳʱ�����)
#include<cstring>
#include<string>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int basket[105],Max = -1,cntE[20],cntM[20],cntB[5],totM = 17,totE = 17;
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING",};
int ifJiao = 0;
void ran(){
    srand(time(0)); //��֤ÿ�ε��Ʋ�һ��
    int num = 0,r;
    while (num!=37){
        r = rand()%15;
        if (cardNum[r] == 0) continue;
        cardNum[r]--;
        if (num < 17) cntM[r]++;
        if (num > 19) cntE[r]++;
        if (num > 16 && num < 20) cntB[num-16] = r;
        num++;
    }
}
int calc(){
    int a;
    if (lenOU == 1) a = 1;
    else if (lenOU == 2) a = 2;
    else if (lenOU == 3) a = 3;
    else if (lenOU == 4){
        if (Max == 3) a = 4;
        if (Max == 4) a = 5;
    }
    else if (lenOU == 5){
        if (Max == 3) a = 6;
        else a = 7;
    }
    else if (lenOU == 6){
        if (Max == 2) a = 8;
        else if (Max == 4) a = 9;
        else a = 10;
    }
    else if (Ou[0] == -46) a = 11;
    else a = -1;
    return a;
}
void beat(){
    int mode = calc(),canChu = 0;
    if (mode == 1){
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>0){
                cout<<cardStack[i]<<endl;
                cntE[i]--;
                totE--;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 2){
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>1){
                cout<<cardStack[i]<<cardStack[i]<<endl;
                cntE[i]-=2;
                totE-=2;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 3){
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>2){
                cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<endl;
                cntE[i]-=3;
                totE-=3;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 4){
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>2){
                for (int j=0;j<15;j++){
                    if (cntE[j]>0){
                        cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[j]<<endl;
                        cntE[j]--;
                        cntE[i]-=3;
                        totE-=4;
                        canChu = 1;
                        break;
                    }
                }
                break;
            }
        }
    }
    else if (mode == 5){
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>3){
                cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[i]<<endl;
                cntE[i]-=4;
                totE-=4;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 11){
        for (int i=0;i<15;i++){
            if (cntE[i]>0){
                cout<<cardStack[i]<<endl;
                cntE[i]--;
                totE--;
                canChu = 1;
                break;
            }
        }
    }
    else{
        cout<<"����δ���ƻ��Ƴ�����"<<endl;
        canChu = 1;
    }
    if (canChu == 0) cout<<"Ҫ����"<<endl;
}
void pre(){
    cout<<"�е�����:1.3�� 2.2�� 3.1�� 4.����"<<endl;
    int iwant;
    cin>>iwant;
    if (iwant != 4) for (int i=0;i<3;i++){
        cntM[cntB[i]]++;
        totM++;
    }
    else for (int i=0;i<3;i++){
        cntE[cntB[i]]++;
        totE++;
    }
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    cout<<endl;
}
void ingame(){
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    cout<<endl;
    if (ifJiao == 0){
        ifJiao = 1;
        pre();
    }
    char ou[105];
    scanf("%s",&ou);
    if (ou[0] == -46){
        Ou[0] = -46;
        beat();
        return;
    }
    lenOU = strlen(ou);
    int size = -1,fakeLen = lenOU,tag;
    for (int i=0;i<fakeLen;i++){
        tag = -1;
        if (ou[i] > '1' && ou[i] <= '9'){
            if (ou[i] == '2'){
                Ou[++size] = 12;
            }
            else{
                Ou[++size] = ou[i] - '0' - 3;
            }
        }
        else if (ou[i] == 'J') Ou[++size] = 8;
        else if (ou[i] == 'Q') Ou[++size] = 9;
        else if (ou[i] == 'K'){
            if (i!=fakeLen-1){
                if (ou[i+1] == 'I'){
                    Ou[++size] = 14;
                    lenOU -= 3;
                    tag = 1;
                    i += 3;
                }
                else Ou[++size] = 10;
            }
            else Ou[++size] = 10;
        }
        else if (ou[i] == 'A') Ou[++size] = 11;
        else if (ou[i] == 'S'){
            Ou[++size] = 13; //��ӦSMALL
            lenOU -= 4;
            i += 4;
        }
        else if (ou[i] == '1'){
            Ou[++size] = 7; //��Ӧ10
            lenOU -= 1;
            i += 1;
        }
        if (tag == 1){
            basket[13] += 1;
            if (basket[13] > Max) Max = basket[13];
        }
        else{
            basket[Ou[size]] += 1; // ������������ͬ��
            if (basket[Ou[size]] > Max) Max = basket[Ou[size]]; //��Ҫ��KING��SMALL������ȥ
        }
        cntM[Ou[size]]--;
        totM--;
    }
    beat();
}
void hel(){
    cout<<"��Ϊ˫�˶�����������Ժ����̽ϵͣ��Ż��ϲ�Ļ����˶Դ�"<<endl;
    cout<<"Ŀǰ���кܶ�δ�޸���©���������������GitHub�ύissue���һἰʱ����"<<endl;
    cout<<"�������£�"<<endl;
    cout<<"1.���ƣ�����Գ��ȶ��ֵ�����ֵ�������"<<endl;
    cout<<"2.���ӣ�����Գ��ȶ��ֵ�����ֵ����������ƣ�����������ֵ�ϱ������"<<endl;
    cout<<"3.����һ������Գ������ƣ����������Ƶ���ֵ������ͬ�Ҵ��ڶ��������������Ƶ���ֵ��������ڣ����������ĵ������Ʊ�����ڶ��ֵĵ�������"<<endl;
    cout<<"4.ը������Ϊ���֣���ը��������ͬ���ƣ���ըָSMALL+KING"<<endl;
    cout<<"5.���������˹��ܻ�δ����"<<endl;
    cout<<"���һ���Ȱ������Ƴ��꣬��ʤ��"<<endl;
    cout<<endl;
}
void about(){
    cout<<"Release Date:4/11/2021"<<endl;
    cout<<"C++ Experimental Beta"<<endl;
    cout<<"��ΪC++���԰棬��δ������ϣ�����������չʾ֮��"<<endl;
    cout<<endl;
}
void runPro(){
    ifJiao = 0;
    cout<<"1:��ʼ"<<endl<<"2.����"<<endl<<"3.����"<<endl<<"4.�˳�"<<endl;
    int uc;
    cin>>uc;
    if (uc == 1){
        ran(); //���ƺ�������
        while (totM > 0 && totE > 0) ingame();
        runPro();
    }
    else if (uc == 2) {
        hel();
        runPro();
    }
    else if (uc == 3) {
        about();
        runPro();
    }
    else return;
}
int main(){
    runPro();
    return 0;
}
