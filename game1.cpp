#include<iostream>
#include<cstdio>
#include<ctime> //���ڲ��������(ϵͳʱ�����)
#include<cstring>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int basket[105],Max = -1;
string myCard[105],enemyCard[105],boss[8],cardStack[20] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A","SMALL","KING",};
int ifJiao = 0;
void ran(){
    srand(time(0)); //��֤ÿ�ε��Ʋ�һ��
    int num = 0,r,cnt[20] = {};
    while (num!=37){
        r = rand()%15;
        if (cardNum[r] == 0) continue;
        cardNum[r]--;
        cnt[r]++;
        if (num == 16){
            int tmp = -1;
            for (int i=0;i<15;i++){
                while (cnt[i]!=0){
                    myCard[++tmp] = cardStack[i];
                    cnt[i]--;
                }
            }
        }
        else if (num == 19){
            int tmp = -1;
            for (int i=0;i<15;i++){
                while (cnt[i]!=0){
                    boss[++tmp] = cardStack[i];
                    cnt[i]--;
                }
            }
        }
        else if (num == 36){
            int tmp = -1;
            for (int i=0;i<15;i++){
                while (cnt[i]!=0){
                    enemyCard[++tmp] = cardStack[i];
                    cnt[i]--;
                }
            }
        }
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
    else a = -1;
    return a;
}
void beat(){
    int mode = calc();
    if (mode == 1){

    }
    else if (mode == 2){

    }
    else if (mode == 3){

    }
    else if (mode == 4){

    }
    else if (mode == 5){

    }
    else{
        cout<<"����δ���ƻ��Ƴ�����";
    }
}
void pre(){
    cout<<"�е�����:1.3�� 2.2�� 3.1�� 4.����"<<endl;
    int iwant;
    cin>>iwant;
    if (iwant>0){
        for (int i=0;i<3;i++){
            myCard[i+17] = boss[i];
        }
    }
    else{
        for (int i=0;i<3;i++){
            enemyCard[i+17] = boss[i];
        }
    }
}
void ingame(){
    for (int i=0;i<17;i++){
        cout<<myCard[i]<<" ";
    }
    cout<<endl;
    if (ifJiao == 0){
        ifJiao = 1;
        pre();
    }
    char ou[105];
    scanf("%s",&ou);
    lenOU = strlen(ou);
    int size = 0;
    for (int i=0;i<lenOU;i++){
        if (ou[i] >= '1' && ou[i] <= '9'){
            if (ou[i] == 2){
                Ou[++size] = 16;
            }
            else{
                Ou[++size] = ou[i] - '0';
            }
        }
        else if (ou[i] == 'J') Ou[++size] = 11;
        else if (ou[i] == 'Q') Ou[++size] = 12;
        else if (ou[i] == 'K') Ou[++size] = 13;
        else if (ou[i] == 'A') Ou[++size] = 14;
        else if (ou[i] == 'I') Ou[size] = 18; //��ӦKING
        else if (ou[i] == 'S') Ou[++size] = 17;
        else if (ou[i] == '0') Ou[size] = 10;
        basket[ou[size]] += 1;
        if (basket[ou[size]] > Max) Max = basket[ou[size]];
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
    cout<<"Release Date:2/28/2021"<<endl;
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
        ingame();
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
    ran(); //���ƺ�������
    //����Ϊִ�в���
    runPro();
    return 0;
}
