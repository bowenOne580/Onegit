#include<iostream>
#include<cstdio>
#include<ctime> //用于产生随机数(系统时间随机)
#include<cstring>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int basket[105],Max = -1;
string myCard[105],enemyCard[105],boss[8],cardStack[20] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A","SMALL","KING",};
int ifJiao = 0;
void ran(){
    srand(time(0)); //保证每次的牌不一样
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
        cout<<"功能未完善或牌出错了";
    }
}
void pre(){
    cout<<"叫地主吗:1.3分 2.2分 3.1分 4.不叫"<<endl;
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
        else if (ou[i] == 'I') Ou[size] = 18; //对应KING
        else if (ou[i] == 'S') Ou[++size] = 17;
        else if (ou[i] == '0') Ou[size] = 10;
        basket[ou[size]] += 1;
        if (basket[ou[size]] > Max) Max = basket[ou[size]];
    }
    beat();
}
void hel(){
    cout<<"此为双人斗地主，你可以和智商较低，优化较差的机器人对打"<<endl;
    cout<<"目前还有很多未修复的漏洞，如果发现请在GitHub提交issue，我会及时处理"<<endl;
    cout<<"规则如下："<<endl;
    cout<<"1.单牌：你可以出比对手的牌数值更大的牌"<<endl;
    cout<<"2.对子：你可以出比对手的牌数值更大的两张牌，但它们在数值上必须相等"<<endl;
    cout<<"3.三带一：你可以出四张牌，其中三张牌的数值必须相同且大于对手所出的三张牌的数值，如果等于，则你所出的第四张牌必须大于对手的第四张牌"<<endl;
    cout<<"4.炸弹：分为两种，王炸和四张相同的牌，王炸指SMALL+KING"<<endl;
    cout<<"5.三带二：此功能还未开发"<<endl;
    cout<<"如果一方先把所有牌出完，即胜利"<<endl;
    cout<<endl;
}
void about(){
    cout<<"Release Date:2/28/2021"<<endl;
    cout<<"C++ Experimental Beta"<<endl;
    cout<<"此为C++测试版，尚未开发完毕，仅作调试与展示之用"<<endl;
    cout<<endl;
}
void runPro(){
    ifJiao = 0;
    cout<<"1:开始"<<endl<<"2.帮助"<<endl<<"3.关于"<<endl<<"4.退出"<<endl;
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
    ran(); //发牌和排序函数
    //以下为执行部分
    runPro();
    return 0;
}
