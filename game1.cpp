#include<iostream>
#include<cstdio>
#include<ctime> //���ڲ��������(ϵͳʱ�����)
#include<cstring>
#include<string>
#include<cmath>
#include<conio.h>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int Max,cntE[20],cntM[20],cntB[5],totM = 17,totE = 17,mode,lMode,boKing,sco = 100,hisco = 0;
int lChu[100],lSize,ifChun = 1,lLen,lang = 1,ifGod,dif = 2,ifJiao = 0,win,lose;
int chun,lenColl[20],maxPage = 7,tri[20],bomb[20],useful[20],dou[20],si[20],kingsman[2],oppor,speGame;
int haDou,haSin,plaType = 1,calcThree[20],termi,usercho,rating;
char edi = 'n';
long long money = 3000;
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING",};
string achCNStack[25] = {
    "","���쵽��","��һ��ʤ��","��ʤ����","�޼᲻��","ʤ���˱��ҳ���","����褣�������","С��","����","���ɵй�",
    "�����޷���int����","����","����Σ��","�����Ʋ�","��ͷ��ʼ","���ⰻȻ","������һ����!","E32021�ر���ף","���ֿ���"};
string achENStack[25] = {
    "","The East Wind is coming","First Victory!","It's a piece of cake","A winner of all times",
    "It's easy to fail than success","Is the robot smarter than me?","Can afford!","Billionare","Richer than America(Not China)",
    "Can't be measured by int","Rich in abs","Financial crysis","Get close to break","Start again!","You can touch the spring in the air",
    "I am 1 year old!","Special Celebration for E32021","Happy Shopping on Steam Summer Sale 2021!"};
string descripCN[25] = {
    "","���1�ִ���","���1��ʤ��","���10��ʤ��","���50��ʤ��","�����5��","�����20��","�ܵ�������10000","�ܵ�������30000","�ܵ�������500000",
    "�ܵ�������2147480000","�ܵ�������-10000","�ܵ�������-50000","�ܵ�������-1000000","�������ͣ����ó���","���20�δ���","��һ������汾�����5����Ϸ",
    "��E3�ر�������1����Ϸ","���Ĵ��ر�������10����Ϸ"};
string descripEN[25] = {
    "","Do Spring in 1 game","Win for the first time","Win for 10 times","Win for 50 times","Be beaten for 5 times","Be beaten for 20 times",
    "Get 10000 credits","Get 30000 credits","Get 500000 credits","Get 2147480000 credits","Lower than -10000 credits","Lower than -50000 credits",
    "Lower than -1000000 credits","Credits are getting too low, so that I have to reset it for you","Finish 20 Springs",
    "Finish 5 games in the 1st Anniversary Edition","Finish only one game in E3 Special Edition","Finish 10 games in Steam Summer Sale Special Edition"};
string achMonCN[20] = {"Ԫ","��","��","��","��","��","��","��","��","ʮ","ʮһ","ʮ��"};
string achMonEN[20] = {"January","Febrary","March","April","May","June","July","August","September","October","November","December"};
struct acheivement{
    int ifGet;
    int day;
    int mon;
    int yr;
};
acheivement ach[1005];
void readVars(){
    ifstream input("data.txt");
    input>>money>>hisco>>ifGod>>win>>lose>>dif;
    for (int i=1;i<=20;i++){ //��ʹ��18��
        input>>ach[i].ifGet>>ach[i].day>>ach[i].mon>>ach[i].yr;
    }
    input>>speGame>>plaType>>rating;
    if (edi == 'n') speGame = 0;
    input.close();
}
void writeVars(){
    ofstream output;
    output.open("data.txt");
    output<<money<<endl<<hisco<<endl<<lang<<endl<<ifGod<<endl<<win<<endl<<lose<<endl<<dif<<endl;
    for (int i=1;i<=20;i++){
        output<<ach[i].ifGet<<" "<<ach[i].day<<" "<<ach[i].mon<<" "<<ach[i].yr<<endl;
    }
    output<<speGame<<endl<<plaType<<endl<<rating<<endl;
    output.close();
}
void Clear(){
	for (int i=0;i<15;i++){
		if (i<=12) cardNum[i] = 4;
		else cardNum[i] = 1;
	}
    memset(cntE,0,sizeof(cntE));
    memset(cntM,0,sizeof(cntM));
    memset(cntB,0,sizeof(cntB));
    memset(si,0,sizeof(si));
    memset(dou,0,sizeof(dou));
    memset(tri,0,sizeof(tri));
    memset(bomb,0,sizeof(bomb));
    memset(useful,0,sizeof(useful));
    oppor = 0;
    kingsman[0] = 0;
    totM = 17;
    totE = 17;
    ifJiao = 0;
    lMode = 0;
    sco = 100;
    ifChun = 1;
    termi = 0; //��ʼ������
}
void Back(){
    money = 3000;
    hisco = 0;
    win = 0;
    lose = 0;
    rating = 0;
    for (int i=1;i<=20;i++) ach[i].ifGet = 0;
}
void nextPage(){
    char uc[10];
    gets(uc);
    cin.getline(uc,10);
    system("cls");
}
void ran(){
    srand(time(0));
    int num = 0,r;
    while (num!=37){
        r = rand()%15;
        if (cardNum[r] == 0) continue;
        cardNum[r]--;
        if (num < 17) cntM[r]++;
        if (num > 19) cntE[r]++;
        if (num > 16 && num < 20) cntB[num-17] = r;
        num++;
    }
}
int calc(){ //δ�Ż�
    int a;
    if (lenOU == 1) a = 1;
    else if (lenOU == 2 && Max == 2){
        if (boKing == 1) lMode = 0;
        a = 2;
    }
    else if (lenOU == 3 && Max == 3) a = 3;
    else if (lenOU == 4 && Max >= 3){
        if (Max == 3) a = 4;
        if (Max == 4){
            lMode = 0;
            a = 5;
        }
    }
    else if (lenOU == 5){
        if (Max == 3){
            if (lenColl[2] == 1) a = 6;
            else a = -1;
        }
        else if (Max == 1 && lenOU+Ou[0]<13) a = 7;
        else a = -1;
    }
    else if (lenOU == 6){
        if (Max == 2 && lenOU/2+Ou[0]<13){
            if (lenColl[2] == 3) a = 8;
            else a = -1;
        }
        else if (Max == 3){
            if (lenColl[3] == 2) a = 9;
            else a = -1;
        }
        else if (Max == 4) a = 10;
        else if (Max == 1 && lenOU+Ou[0]<13) a = 7;
        else a = -1;
    }
    else if (lenOU == 8){
        if (Max == 4){
            if (lenColl[2] == 2) a = 10;
            else a = -1;
        }
        else if (Max == 3){
            if (lenColl[3] == 2) a = 12;
            else a = -1;
        }
        else if (Max == 2 && lenOU/2+Ou[0]<13){
            if (lenColl[2] == 4) a = 8;
            else a = -1;
        }
        else if (Max == 1 && lenOU+Ou[0]<13) a = 7;
        else a = -1;
    }
    else if (lenOU == 10){
        if (Max == 3){
            if (lenColl[3] == 2 && lenColl[2] == 2) a = 13;
            else a = -1;
        }
        else if (Max == 2 && lenOU/2+Ou[0]<13){
            if (lenColl[2] == 5) a = 8;
            else a = -1;
        }
        else if (Max == 1 && lenOU+Ou[0]<13) a = 7;
        else a = -1;
    }
    else if (lenOU > 6 && Max == 1) a = 7;
    else if (lenOU > 10 && Max == 2){
        if (lenOU%2 == 0 && lenColl[2] == lenOU/2 && lenOU/2+Ou[0]<13) a = 8;
        else a = -1;
    }
    else a = -1;
    if (lenColl[3]>=3) a = 14;
    return a;
}
int Save(){ //δ�Ż�
    int Good = 0;
    int i = 0;
    if (mode == 5) i = Ou[0]+1;
    else if (mode == 2 && boKing) i = 15;
    for (i;i<15;i++){
        if (cntE[i]>3){
            cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]-=4;
            totE-=4;
            Good = 1;
            lLen = 4;
            lMode = 5;
            break;
        }
    }
    if (Good == 0 && kingsman[0] == 1){
        cout<<"SMALL KING"<<endl;
        Good = 1;
        totE-=2;
        lChu[++lSize] = 14;
        cntE[13]--;
        cntE[14]--;
        lLen = 2;
        lMode = 2;
    }
    return Good;
}
void beat(){
    int canChu = 0;
    lLen = lenOU;
    lSize = -1;
    lMode = mode;
    if (mode == 1){ //����
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>0){
                cout<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]--;
                totE--;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 2){ //����
        if (boKing) sco*=4;
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>1){
                cout<<cardStack[i]<<" "<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=2;
                totE-=2;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 3){ //������
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>2){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=3;
                totE-=3;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 4){ //����һ
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>2){
                for (int j=0;j<13;j++){ //ȥ���Ż�
                    if ((cntE[j]>0 && j!=i) || cntE[j]>3){
                        cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
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
        lLen--;
    }
    else if (mode == 5){ //ը��
        sco*=2;
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż����˴��������д�С��
            if (cntE[i]>3){
                sco*=2;
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=4;
                totE-=4;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 6){ //������
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>2){
                for (int j=0;j<13;j++){ //ȥ���Ż�
                    if (cntE[j]>1 && j!=i){
                        cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        cntE[j]-=2;
                        cntE[i]-=3;
                        totE-=5;
                        canChu = 1;
                        break;
                    }
                }
                break;
            }
        }
        lLen-=2;
    }
    else if (mode == 7){ //˳��
        int cnt = 0;
        for (int i=Ou[0]+1;i<12;i++){ //ȥ����2�Ż�
            if (cntE[i]>0) cnt++;
            else cnt = 0;
            if (cnt == lenOU){
                for (int j=i-lenOU+1;j<=i;j++){
                    cout<<cardStack[j]<<" ";
                    cntE[j]--;
                    totE--;
                }
                lChu[++lSize] = i-lenOU+1;
                cout<<endl;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 8){ //����
        int cnt = 0;
        for (int i=Ou[0]+1;i<12;i++){ //ȥ����2�Ż�
            if (cntE[i]>1) cnt+=2;
            else cnt = 0;
            if (cnt == lenOU){
                for (int j=i-(lenOU/2)+1;j<=i;j++){
                    cout<<cardStack[j]<<" "<<cardStack[j]<<" ";
                    cntE[j]-=2;
                    totE-=2;
                }
                lChu[++lSize] = i-(lenOU/2)+1;
                cout<<endl;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 9){ //С�ɻ�
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>2){
                for (int j=i+1;j<13;j++){ //ȥ���Ż�
                    if (cntE[j]>2){
                        cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        cntE[i]-=3;
                        cntE[j]-=3;
                        totE-=6;
                        canChu = 1;
                        j = 12;
                        i = 12;
                        break;
                    }
                }
            }
            break;
        }
        lLen = 3;
    }
    else if (mode == 10){ //�Ĵ���
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>3){
                for (int j=0;j<13;j++){ //ȥ���Ż�
                    if (cntE[j]>1 && j!=i){
                        cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        cntE[i]-=4;
                        cntE[j]-=2;
                        totE-=6;
                        canChu = 1;
                        j = 12;
                        i = 12;
                        break;
                    }
                }
            }
            break;
        }
        lLen = 4;
    }
    else if (mode == 11){ //���ֳ���
        for (int i=0;i<15;i++){
            if (cntE[i]>0){
                cout<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]--;
                totE--;
                canChu = 1;
                lMode = 1;
                lLen = 1;
                break;
            }
        }
    }
    else if (mode == 12){ //�зɻ�
        sco*=2;
        int cnt1 = 0,cnt2 = 0,v[20] = {},tmp[10] = {};
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>2){
                cnt1++;
                v[i] = 1;
                tmp[cnt1-1] = i;
            }
            if (cnt1 == 2){ //��ʼѰ�ҵ���
                for (int j=0;j<13;j++){ //ȥ���Ż�
                    if (cntE[j]>0 && v[j] == 0){
                        cnt2++;
                        v[j] = 1;
                        tmp[cnt2+cnt1-1] = j;
                    }
                    if (cnt2 == 2){
                        sco*=2;
                        for (int k=0;k<4;k++){
                            if (k<2){
                                cout<<cardStack[tmp[k]]<<" "<<cardStack[tmp[k]]<<" "<<cardStack[tmp[k]]<<" ";
                                cntE[tmp[k]]-=3;
                                totE-=3;
                            }
                            else{
                                cout<<cardStack[tmp[k]]<<" ";
                                cntE[tmp[k]]--;
                                totE--;
                            }
                        }
                        lChu[++lSize] = tmp[0];
                        cout<<endl;
                        canChu = 1;
                        break;
                    }
                }
                break;
            }
        }
        lLen = 3;
    }
    else if (mode == 13){ //��ɻ�
        sco*=3;
        int cnt1 = 0,cnt2 = 0,v[20] = {},tmp[10] = {};
        for (int i=Ou[0]+1;i<13;i++){ //ȥ���Ż�
            if (cntE[i]>2){
                cnt1++;
                v[i] = 1;
                tmp[cnt1-1] = i; //�±��0��ʼ
            }
            if (cnt1 == 2){ //��ʼѰ�Ҷ���
                for (int j=0;j<13;j++){ //ȥ���Ż�
                    if (cntE[j]>1 && v[j] == 0){
                        cnt2++;
                        v[j] = 1;
                        tmp[cnt2+cnt1-1] = j;
                    }
                    if (cnt2 == 2){
                        sco*=3;
                        for (int k=0;k<4;k++){
                            if (k<2){
                                cout<<cardStack[tmp[k]]<<" "<<cardStack[tmp[k]]<<" "<<cardStack[tmp[k]]<<" ";
                                cntE[tmp[k]]-=3;
                                totE-=3;
                            }
                            else{
                                cout<<cardStack[tmp[k]]<<" "<<cardStack[tmp[k]]<<" ";
                                cntE[tmp[k]]-=2;
                                totE-=2;
                            }
                        }
                        lChu[++lSize] = tmp[0];
                        cout<<endl;
                        canChu = 1;
                        break;
                    }
                }
                break;
            }
        }
        lLen = 3;
    }
    else if (mode == 14){
        int a = -1;
    }
    else{
        if (!ifGod){
            if (lang == 1) printf("����δ���ƻ��Ƴ�����\n");
            else if (lang == 2) printf("Feature not included or you have put the Wrong Card\n");
            canChu = 1;
            lMode = 0;
        }
        
    }
    if (canChu == 0){
        if (totM<=6){
            if (!Save()){
                if (lang == 1) cout<<"Ҫ����"<<endl;
                else if (lang == 2) cout<<"Can't afford"<<endl;
                lMode = 0;
                lLen = 0;
            }
        }
        else{
            if (lang == 1) cout<<"Ҫ����"<<endl;
            else if (lang == 2) cout<<"Can't afford"<<endl;
            lMode = 0;
            lLen = 0;
        }
    }
    else ifChun++;
}
void initBeat(){ //δ�Ż�
    int doub = 0,sig = 0;
    memset(si,0,sizeof(si));
    memset(dou,0,sizeof(dou));
    memset(tri,0,sizeof(tri));
    memset(bomb,0,sizeof(bomb));
    memset(useful,0,sizeof(useful));
    kingsman[0] = 0;
    haDou = 0;
    haSin = 0;
    oppor = 0;
    oppor+=cntE[12];
    useful[12]+=6;
    if (cntE[13] == 1 && cntE[14] == 1){
        kingsman[0] = 1; //�����ж�
        oppor+=4;
    }
    for (int i=0;i<13;i++){ //ȥ���Ż�
        if (cntE[i]>3){
            bomb[i] = 1;
            useful[i]+=7;
            oppor+=3;
        }
        if (cntE[i]>2){
            tri[i] = 1;
            useful[i]+=3;
            oppor+=2;
        }
        if (cntE[i]>1) doub++;
        else{
            if (doub>=3){
                for (int j=i-doub;j<=i-1;j++){
                    dou[j] = 1;
                    useful[j]+=2;
                }
                haDou = 1;
                oppor++;
            }
            doub = 0;
        }
        if (cntE[i] >= 1) sig++;
        else{
            if (sig>=5){
                for (int j=i-sig;j<=i-1;j++){
                    si[j] = 1;
                    useful[j]++;
                }
                haSin = 1;
                oppor++;
            }
            sig = 0;
        }
    }
}
int weigh(int left,int right,int length){ //δ�Ż�
    int Min = 0x7fffffff,mpos = -1;
    if (length == 6){
        for (int i=left;i<=right;i++){
            if (cntE[i] >= 3 && cntE[i+1] >= 3 && (useful[i]+useful[i+1])<Min){
                Min = useful[i]+useful[i+1];
                mpos = i;
            }
        }
    }
    else{
        for (int i=left;i<=right;i++){
            if (useful[i]<Min && cntE[i]>=length){
                Min = useful[i];
                mpos = i;
            }
        }
    }
    return mpos;
}
void selfOut(){ //δ�Ż�
    int cntT = 0,cntD = 0,cntS = 0,flag = 2;
    for (int i=0;i<13;i++){
        if (cntE[i]>=3){
            cntT++;
        }
        else if (cntE[i]>=2){
            cntD++;
        }
        else if (cntE[i] == 1){
            cntS++;
        }
    }
    if (cntT>=2){
        if (cntD>=2){
            int i,j;
            if (plaType == 1){
                i = weigh(Ou[0]+1,10,6);
                if (i == -1) flag = 1;
            }
            else if (plaType == 2) i = weigh(Ou[0]+1,11,3);
            if (i!=-1){
                cntE[i]-=3;
                if (plaType == 1) j = i+1;
                else if (plaType == 2) j = weigh(Ou[0]+1,11,3);
                if (j!=-1){
                    cntE[j]-=3;
                    int k = weigh(0,12,2);
                    if (k!=-1){
                        cntE[k]-=2;
                        int p = weigh(0,12,2);
                        if (p!=-1){
                            sco*=3;
                            if (i>j) swap(i,j);
                            if (k>p){
                                swap(k,p);
                                cntE[k]-=2;
                            }
                            else cntE[p]-=2;
                            cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[k]<<" "<<cardStack[k]<<" "<<cardStack[p]<<" "<<cardStack[p]<<endl;
                            lChu[++lSize] = i;
                            totE-=10;
                            lMode = 13;
                            j = 12;
                            i = 12;
                        }
                        else cntE[k]+=2;
                    }
                    else cntE[j]+=3;
                }
                else cntE[i]+=3;
            }
            lLen = 6;
        }
        else if (cntD == 1 || cntS >=2){
            int i,j;
            if (plaType == 1){
                i = weigh(Ou[0]+1,10,6);
                if (i == -1) flag = 1;
            }
            else if (plaType == 2) i = weigh(Ou[0]+1,11,3);
            if (i!=-1){
                cntE[i]-=3;
                if (plaType == 1) j = i+1;
                else if (plaType == 2) j = weigh(Ou[0]+1,11,3);
                if (j!=-1){
                    cntE[j]-=3;
                    int k = weigh(0,14,1);
                    if (k!=-1){
                        cntE[k]--;
                        int p = weigh(0,14,1);
                        if (p!=-1){
                            sco*=2;
                            if (i>j) swap(i,j);
                            if (k>p){
                                swap(k,p);
                                cntE[k]--;
                            }
                            else cntE[p]--;
                            cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[k]<<" "<<cardStack[p]<<endl;
                            lChu[++lSize] = i;
                            totE-=8;
                            lMode = 12;
                            j = 12;
                            i = 12;
                        }
                        else cntE[k]++;
                    }
                    else cntE[j]+=3;
                }
                else cntE[i]+=3;
            }
        lLen = 6;
        }
        else{
            int i,j;
            if (plaType == 1){
                i = weigh(Ou[0]+1,10,6);
                if (i == -1) flag = 1;
            }
            else if (plaType == 2) i = weigh(Ou[0]+1,11,3);
            if (i!=-1){
                cntE[i]-=3;
                if (plaType == 1) j = i+1;
                else if (plaType == 2) j = weigh(Ou[0]+1,11,3);
                if (j!=-1){
                    sco*=2;
                    if (i>j){
                        swap(i,j);
                        cntE[i]-=3;
                    }
                    else cntE[j]-=3;
                    cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                    lChu[++lSize] = i;
                    totE-=6;
                    j = 12;
                    i = 12;
                }
                else cntE[i]+=3;
            }
            lLen = 6;
        }
    }
    if (cntT == 1 || flag == 1){
        if (cntD>=1){
            int i = weigh(0,12,3);
            if (i!=-1){
                cntE[i]-=3;
                int j = weigh(0,12,2);
                if (j!=-1){
                    cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                    cntE[j]-=2;
                    totE-=5;
                    lChu[++lSize] = i;
                    lMode = 6;
                }
                else cntE[i]+=3;
            }
            lLen = 3;
        }
        else if (cntS>=1){
            int i = weigh(0,12,3);
            if (i!=-1){
                cntE[i]-=3;
                int j = weigh(0,14,1);
                if (j!=-1){
                    cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<endl;
                    cntE[j]--;
                    totE-=4;
                    lChu[++lSize] = i;
                    lMode = 4;
                }
                else cntE[i]+=3;
            }
            lLen = 3;
        }
        else{
            int i = weigh(0,12,3);
            if (i!=-1){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=3;
                totE-=3;
                lMode = 3;
            }
        }
    }
    else if (cntT == 0){
        if (haDou == 1){
            int cnt = 0,Max = -1,mpos = -1;
            for (int i=0;i<12;i++){ //ȥ����2�Ż�
                if (dou[i] == 1){
                    int tmp = i;
                    cnt = 0;
                    while (dou[tmp]!=0){
                        cnt++;
                        tmp++;
                    }
                    if (cnt>Max){
                        Max = cnt;
                        mpos = i;
                    }
                    i = tmp;
                }
            }
            for (int i=mpos;i<=mpos+Max-1;i++){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" ";
                cntE[i]-=2;
                totE-=2;
            }
            lMode = 8;
            lChu[++lSize] = mpos;
            cout<<endl;
            lLen = Max*2;
        }
        else if (haSin == 1){
            int cnt = 0,Max = -1,mpos = -1;
            for (int i=0;i<12;i++){ //ȥ����2�Ż�
                if (si[i] == 1){
                    int tmp = i;
                    cnt = 0; //2->2
                    while (si[tmp]!=0){
                        cnt++; //���Ż��ռ�
                        tmp++;
                    }
                    if (cnt>Max){
                        Max = cnt;
                        mpos = i;
                    }
                    i = tmp;
                }
            }
            for (int i=mpos;i<=mpos+Max-1;i++){
                cout<<cardStack[i]<<" ";
                cntE[i]--;
                totE--;
            }
            lChu[++lSize] = mpos;
            lMode = 7;
            cout<<endl;
            lLen = Max;
        }
        else{
            //�˴����������Լ�ֻʣһ�������ŵ�����
            int i = weigh(0,12,2);
            if (i!=-1){
                cout<<cardStack[i]<<" "<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                lLen = 2;
                cntE[i]-=2;
                totE-=2;
                lMode = 2;
            }
            else{
                int i = weigh(0,14,1);
                if (i!=-1){
                    cout<<cardStack[i]<<endl;
                    lChu[++lSize] = i;
                    lLen = 1;
                    cntE[i]--;
                    totE--;
                    lMode = 1;
                }
            }
        }
    }
}
void beat2(){ //�����Ż�
    int canChu = 0;
    lLen = lenOU;
    lSize = -1;
    lMode = mode;
    initBeat();
    if (mode == 1){
        int i = weigh(Ou[0]+1,14,1);
        if (i!=-1){
            cout<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]--;
            totE--;
            canChu = 1;
        }
    }
    else if (mode == 2){ //����
        if (boKing) sco*=4;
        int i = weigh(Ou[0]+1,14,2);
        if (i!=-1){
            cout<<cardStack[i]<<" "<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]-=2;
            totE-=2;
            canChu = 1;
        }
    }
    else if (mode == 3){ //������
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]-=3;
            totE-=3;
            canChu = 1;
        }
    }
    else if (mode == 4){ //����һ
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(0,14,1);
            if (j!=-1){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<endl;
                cntE[j]--;
                totE-=4;
                lChu[++lSize] = i;
                canChu = 1;
            }
            else cntE[i]+=3;
        }
        lLen--;
    }
    else if (mode == 5){ //ը��
        sco*=2;
        int i = weigh(Ou[0]+1,12,4);
        if (i!=-1){
            sco*=2;
            cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]-=4;
            totE-=4;
            canChu = 1;
        }
    }
    else if (mode == 6){ //������
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(0,12,2);
            if (j!=-1){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                cntE[j]-=2;
                totE-=5;
                lChu[++lSize] = i;
                canChu = 1;
            }
            else cntE[i]+=3;
        }
        lLen-=2;
    }
    else if (mode == 7){ //˳��
        int cntSi,Min = 0x7fffffff,mpos = -1;
        for (int i=Ou[0]+1;(i+lenOU-1)<12;i++){ //ȥ����2�Ż�
            if (si[i] == 1 && si[i+lenOU-1] == 1){
                cntSi = 0;
                for (int j=i;j<=i+lenOU-1;j++){
                    cntSi+=useful[i];
                }
                if (cntSi<Min){
                    Min = cntSi;
                    mpos = i;
                }
            }
        }
        if (mpos!=-1){
            for (int i=mpos;i<=mpos+lenOU-1;i++){
                cout<<cardStack[i]<<" ";
                cntE[i]--;
                totE--;
            }
            lChu[++lSize] = mpos;
            cout<<endl;
            canChu = 1;
        }
    }
    else if (mode == 8){ //����
        int cntDo,Min = 0x7fffffff,mpos = -1;
        for (int i=Ou[0]+1;(i+lenOU/2-1)<12;i++){ //ȥ����2�Ż�
            if (dou[i] == 1 && dou[i+lenOU/2-1] == 1){
                cntDo = 0;
                for (int j=i;j<=i+lenOU-1;j++){
                    cntDo+=useful[i];
                }
                if (cntDo<Min){
                    Min = cntDo;
                    mpos = i;
                    cout<<cardStack[mpos]<<endl;
                }
            }
        }
        if (mpos!=-1){
            for (int i=mpos;i<=mpos+lenOU/2-1;i++){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" ";
                cntE[i]-=2;
                totE-=2;
            }
            lChu[++lSize] = mpos;
            cout<<endl;
            canChu = 1;
        }
    }
    else if (mode == 9){ //С�ɻ�
        int i,j;
        if (plaType == 1) i = weigh(Ou[0]+1,10,6);
        else if (plaType == 2) i = weigh(Ou[0]+1,11,3);
        if (i!=-1){
            cntE[i]-=3;
            if (plaType == 1) j = i+1;
            else if (plaType == 2) j = weigh(Ou[0]+1,11,3);
            if (j!=-1){
                sco*=2;
                if (i>j) swap(i,j);
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                lChu[++lSize] = i;
                cntE[j]-=3;
                totE-=6;
                canChu = 1;
                j = 12;
                i = 12;
            }
            else cntE[i]+=3;
        }
        lLen = 6;
    }
    else if (mode == 10){ //�Ĵ���
        int i = weigh(Ou[0]+1,12,4);
        if (i!=-1){
            cntE[i]-=4;
            int j = weigh(0,12,1);
            cntE[j]--;
            if (j!=-1){
                int k = weigh(0,12,1);
                if (k!=-1){
                    if (j>k){
                        swap(j,k);
                        cntE[j]--;
                    }
                    else cntE[k]--;
                    cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[k]<<endl;
                    lChu[++lSize] = i;
                    totE-=6;
                    canChu = 1;
                    j = 12;
                    i = 12;
                }
                else cntE[j]++;
            }
            else cntE[i]+=4;
        }
        lLen = 4;
    }
    else if (mode == 11){ //���ֳ���
        selfOut();
        canChu = 1;
    }
    else if (mode == 12){ //�зɻ�
        sco*=2;
        int i,j;
        if (plaType == 1) i = weigh(Ou[0]+1,10,6);
        else if (plaType == 2) i = weigh(Ou[0]+1,11,3);
        if (i!=-1){
            cntE[i]-=3;
            if (plaType == 1) j = i+1;
            else if (plaType == 2) j = weigh(Ou[0]+1,11,3);
            if (j!=-1){
                cntE[j]-=3;
                int k = weigh(0,14,1);
                if (k!=-1){
                    cntE[k]--;
                    int p = weigh(0,14,1);
                    if (p!=-1){
                        sco*=2;
                        if (i>j) swap(i,j);
                        if (k>p) swap(k,p);
                        cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[k]<<" "<<cardStack[p]<<endl;
                        lChu[++lSize] = i;
                        cntE[p]--;
                        totE-=8;
                        canChu = 1;
                        j = 12;
                        i = 12;
                    }
                    else cntE[k]++;
                }
                else cntE[j]+=3;
            }
            else cntE[i]+=3;
        }
        lLen = 6;
    }
    else if (mode == 13){ //��ɻ�
        sco*=3;
        int i,j;
        if (plaType == 1) i = weigh(Ou[0]+1,10,6);
        else if (plaType == 2) i = weigh(Ou[0]+1,11,3);
        if (i!=-1){
            cntE[i]-=3;
            if (plaType == 1) j = i+1;
            else if (plaType == 2) j = weigh(Ou[0]+1,11,3);
            if (j!=-1){
                cntE[j]-=3;
                int k = weigh(0,12,2);
                if (k!=-1){
                    cntE[k]-=2;
                    int p = weigh(0,12,2);
                    if (p!=-1){
                        sco*=3;
                        if (i>j) swap(i,j);
                        if (k>p) swap(k,p);
                        cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[k]<<" "<<cardStack[k]<<" "<<cardStack[p]<<" "<<cardStack[p]<<endl;
                        lChu[++lSize] = i;
                        cntE[p]-=2;
                        totE-=10;
                        canChu = 1;
                        j = 12;
                        i = 12;
                    }
                    else cntE[k]+=2;
                }
                else cntE[j]+=3;
            }
            else cntE[i]+=3;
        }
        lLen = 6;
    }
    else if (mode == 14){
        int a = 1;
        a++;
    }
    else{
        if (!ifGod){
            if (lang == 1) printf("����δ���ƻ��Ƴ�����\n");
            else if (lang == 2) printf("Feature not included or you have put the Wrong Card\n");
            canChu = 1;
            lMode = 0;
        }
    }
    if (canChu == 0){
        if (totM<=10){
            if (!Save()){
                if (lang == 1) cout<<"Ҫ����"<<endl;
                else if (lang == 2) cout<<"Can't afford"<<endl;
                lMode = 0;
                lLen = 0;
            }
        }
        else{
            if (lang == 1) cout<<"Ҫ����"<<endl;
            else if (lang == 2) cout<<"Can't afford"<<endl;
            lMode = 0;
            lLen = 0;
        }
    }
    else ifChun++;
}
void pre(){
    initBeat();
    int who = 0;
    if (lang == 1) printf("�е�����: 1.3�� 2.2�� 3.1�� 4.����\n");
    else if (lang == 2) printf("Want to be the landlord?: 1.Very 2.Fine 3.Maybe 4.Definitely Not\n");
    char iwant;
    scanf("%s",&iwant);
    system("cls");
    if (iwant == 't' || iwant == 'T'){
        totM = 0;
        termi = 1;
        return;
    }
    iwant = iwant-'0';
    if (iwant == 1){
        if (lang == 1) printf("��е��˵���!\n");
        else if (lang == 2) printf("You are the Landlord now!\n");
    }
    else if (iwant != 4){
        if (oppor>=6){
            if (lang == 1) printf("���ֽ�3�֣�������\n");
            else if (lang == 2) printf("The Rival has a strong wish to be the landlord.\n");
            sco*=3;
            who = 1;
        }
        else if (oppor>=4 && iwant == 3){
            if (lang == 1) printf("���ֽ�2�֣�������\n��Ҫ���� 1.3�� 2.����\n");
            else if (lang == 2) printf("The Rival want to get this position\nAre you going to fight for this? 1.Yes 2.Not interested\n");
            scanf("%s",&iwant);
            iwant = iwant - '0';
            if (iwant == 1){
                if (lang == 1) printf("��е��˵���!\n");
                else if (lang == 2) printf("You are the Landlord now!\n");
            }
            else{
                sco*=2;
                who = 1;
            }
        }
        else if (oppor<4){
            if (lang == 1) printf("��е��˵���!\n");
            else if (lang == 2) printf("You are the Landlord now!\n");
        }
	}
    else{
    	if (oppor>=6){
            if (lang == 1) printf("���ֽ�3��\n");
            else if (lang == 2) printf("The Rival has a strong wish to be the landlord.\n");
            sco*=3;
        }
        else if (oppor>=4){
            if (lang == 1) printf("���ֽ�2��\n");
            else if (lang == 2) printf("The Rival is interested in this position.\n");
            sco*=2;
        }
        else{
            if (lang == 1) printf("���ֽ�1��\n");
            else if (lang == 2) printf("The Rival gives it a go\n");
            sco*=1;
        }
        who = 1;
	}
    if (who == 0){
        for (int i = 0;i < 3;i++) cntM[cntB[i]]++;
    	totM += 3;
        sco *= (4-iwant);
    }
    else if (who == 1){
        for (int i=0;i<3;i++) cntE[cntB[i]]++;
    	totE += 3;
        ifChun--;
    }
    if (lang == 1) cout<<"��������: "<<cardStack[cntB[0]]<<" "<<cardStack[cntB[1]]<<" "<<cardStack[cntB[2]];
    else if (lang == 2) cout<<"Special Cards for The Landlord: "<<cardStack[cntB[0]]<<" "<<cardStack[cntB[1]]<<" "<<cardStack[cntB[2]];
    printf("\n\n");
    if (lang == 1) printf("�����: ");
    else if (lang == 2) printf("Your Cards: ");
    for (int i=0;i<15;i++) for (int j=0;j<cntM[i];j++) cout<<cardStack[i]<<" ";
    if (lang == 1) printf("\n��������: %d\n",totE);
    else if (lang == 2) printf("\nRival has %d cards\n",totE);
    if (ifGod == 1){
        if (lang == 1) printf("���ֵ���: ");
        else if (lang == 2) printf("Rival's Cards: ");
        for (int i=0;i<15;i++) for (int j=0;j<cntM[i];j++) cout<<cardStack[i]<<" ";
        printf("\n");
    }
    if (who == 1){
        mode = 11;
        if (lang == 1) printf("���ֳ���: ");
        else if (lang == 2) printf("Rival has put: ");
        if (dif == 1) beat();
        else if (dif == 2) beat2();
    }
    char t[10];
    gets(t);
}
int findCuo(){
    mode = calc();
    if (mode == -1) return 1;
    else if (lMode != mode && lMode!=0) return 1;
    else return 0;
}
void ingame(){
    if (ifJiao) printf("\n");
    if (lang == 1) printf("�����: ");
    else if (lang == 2) printf("Your Cards: ");
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    if (lang == 1) printf("\n��������: %d\n",totE);
    else if (lang == 2) printf("\nRival has %d cards\n",totE);
    if (ifGod == 1){
        if (lang == 1){
            printf("���ֵ���: ");
            for (int i=0;i<15;i++){
                int k = 0;
                while (k<cntE[i]){
                    cout<<cardStack[i]<<" ";
                    k++;
                }
            }
            printf("\n");
        }
        else if (lang == 2){
            printf("Rival's Cards: ");
            for (int i=0;i<15;i++){
                int k = 0;
                while (k<cntE[i]){
                    cout<<cardStack[i]<<" ";
                    k++;
                }
            }
            printf("\n");
        }
    }
    if (ifJiao == 0){
        ifJiao = 1;
        pre();
        if (termi) return;
    }
    char ou[105];
    cin.getline(ou,105);
    system("cls");
    if ((ou[0] == 't' || ou[0] == 'T' || ou[0] == 'e' || ou[0] == 'E') && ifGod == 1){
        totM = 0;
        termi = 1;
        return;
    }
    if (ou[0] == -46 || ou[0] == '0' || ou[0] == 'C' || ou[0] == 'c'){
        Ou[0] = -46;
        mode = 11;
        if (lang == 1) printf("���ֳ���: ");
        else if (lang == 2) printf("Rival has put: ");
        if (dif == 1) beat();
        else if (dif == 2) beat2();
        return;
    }
    lenOU = strlen(ou);
    int size = -1,fakeLen = lenOU,tag,basket[105] = {},Cuo = 0;
    memset(lenColl,0,sizeof(lenColl));
    Max = 0;
    boKing = 0;
    for (int i=0;i<fakeLen;i++){
        tag = -1;
        if (ou[i] == ' '){
            lenOU--;
            continue;
        }
        else if (ou[i] > '1' && ou[i] <= '9'){
            if (ou[i] == '2') Ou[++size] = 12;
            else Ou[++size] = ou[i] - '0' - 3;
        }
        else if (ou[i] == 'J' || ou[i] == 'j') Ou[++size] = 8;
        else if (ou[i] == 'Q' || ou[i] == 'q') Ou[++size] = 9;
        else if (ou[i] == 'K' || ou[i] == 'k'){
            if (i!=fakeLen-1){
                if (ou[i+1] == 'I' || ou[i+1] == 'i'){
                    Ou[++size] = 14;
                    lenOU -= 3;
                    tag = 1;
                    i += 3;
                }
                else Ou[++size] = 10;
            }
            else Ou[++size] = 10;
        }
        else if (ou[i] == 'A' || ou[i] == 'a') Ou[++size] = 11;
        else if (ou[i] == 'S' || ou[i] == 's'){
            Ou[++size] = 13; //��ӦSMALL
            lenOU -= 4;
            i += 4;
        }
        else if (ou[i] == '1' && i+1<fakeLen){
            if (ou[i+1] == '0'){
                Ou[++size] = 7; //��Ӧ10
                lenOU -= 1;
                i += 1;
            }
            else{
                Cuo = 1;
                break;
            }
        }
        else{
            Cuo = 1;
            if (!ifGod) break;
        }
        if (tag == 1){
            boKing = 1;
            basket[13] += 1;
            if (basket[13] > Max) Max = basket[13];
        }
        else{
            basket[Ou[size]] += 1; // ������������ͬ��
            if (basket[Ou[size]] > Max) Max = basket[Ou[size]]; //��Ҫ��KING��SMALL������ȥ
        }
        if (cntM[Ou[size]] == 0){
            Cuo = 1;
            size--;
            if (!ifGod) break;
        }
        else{
            cntM[Ou[size]]--;
            totM--;
        }
    }
    int cont = 0,flag = 2;
    for (int i=0;i<15;i++){
        if (basket[i]!=0) lenColl[basket[i]]++;
        if (flag == 2 && basket[i] == 3 && plaType == 1) flag = 1;
        if (flag == 1 && basket[i]!=3 && plaType == 1) flag = 0;
        if (plaType == 1 && basket[i] == 3 && flag == 1) cont++;
    }
    if (plaType == 1 && cont!=lenColl[3] && lenColl[3]>1) Cuo = 1;
    if (ifGod) Cuo = 0;
    if (Cuo == 0) Cuo = findCuo();
    if (Cuo == 0 && lMode != 0){
        int tmpcnt = 0;
        for (int i=0;i<=size;i++){
            if (Ou[i] > lChu[lSize]){
                tmpcnt++;
            }
        }
        if (tmpcnt<lLen) Cuo = 1;
        if (mode == 13 && tmpcnt == 4) Cuo = 1;
    }
    if (ifGod) Cuo = 0;
    if (Cuo == 1){
        for (int i=size;i>=0;i--){
            cntM[Ou[size--]]++;
            totM++;
        }
        if (lang == 1) printf("�Ƴ�����\n");
        else if (lang == 2) printf("Wrong Card!\n");
        ingame();
    }
    else{
        if (totM == 0){
            if (mode == 5 || mode == 12) sco*=2;
            else if (mode == 13) sco*=3;
            else if (mode == 2 && boKing == 1){
                sco*=4;
            }
            return;
        }
        else{
            if (lang == 1) printf("���ֳ���: ");
            else if (lang == 2) printf("Rival has put: ");
            if (dif == 1) beat();
            else if (dif == 2) beat2();
        }
    }
}
void rules(){
    if (lang == 1) printf("��Ϊ˫�˶�����������Ժ����̽ϵͣ��Ż��ϲ�Ļ����˶Դ�\n");
    else if (lang == 2) printf("This is Beat The Landlord, you can play cards with a stupid and slow robot\n");
    if (lang == 1) printf("�������£�\n");
    else if (lang == 2) printf("The rules are: \n");
    if (lang == 1) printf("1.���ƣ�����Գ��ȶ��ֵ�����ֵ�����1����\n");
    else if (lang == 2) printf("1.Single Card: You can put 1 card that is BIGGER than Rival's\n");
    if (lang == 1) printf("2.���ӣ�����Գ��ȶ��ֵ�����ֵ�����2���ƣ�����������ֵ�ϱ������\n");
    else if (lang == 2) printf("2.Double Cards: You can put 2 cards with THE SAME POINT, and they are BIGGER than Rival's\n");
    if (lang == 1) printf("3.����һ������Գ�4���ƣ����������Ƶ���ֵ������ͬ�Ҵ��ڶ��������������Ƶ���ֵ\n");
    else if (lang == 2) printf("3.Three Plus One: You can put 3 cards with THE SAME POINT, and they are BIGGER than Rival's,the other one can be anything you like\n");
    if (lang == 1) printf("4.ը������Ϊ���֣���ը��������ͬ���ƣ���ըָSMALL+KING\n");
    else if (lang == 2) printf("4.Bomb��It can be 4 cards that have the same point, or SMALL+KING, which is the BIGGEST one in the game\n");
    if (lang == 1) printf("5.������������Գ�5���ƣ����а���3��һ���ĺ�һ������\n");
    else if (lang == 2) printf("5.Three Plus Two: 5 cards, three of them is like that of Three Plus One, the other two is like a Double Cards\n");
    if (lang == 1) printf("6.С�ɻ�������Գ�6���ƣ����а�������3��һ������������Ϊ1\n");
    else if (lang == 2) printf("6.Small Plane: 6 cards, contain two sets of Three Cards\n");
    if (lang == 1) printf("7.�зɻ�������Գ�8���ƣ�����һ��С�ɻ�������������\n");
    else if (lang == 2) printf("7.Middle Plane: 8 cards, contain a Small Plane and two cards of whatever you like\n");
    if (lang == 1) printf("8.��ɻ�������Գ�10���ƣ����а���һ��С�ɻ�����������\n");
    else if (lang == 2) printf("8.Big Plane: 10 cards, contain a Small Plane and two sets of Double Cards\n");
    if (lang == 1) printf("9.˳�ӣ�����Գ����ڵ���5���ƣ�����ÿ���Ƽ�Ĳ�Ϊ1\n");
    else if (lang == 2) printf("9.Silk Road��You can put more than 5 cards, the difference of every connected ones must be the SAME\n");
    if (lang == 1) printf("10.���ԣ�����Գ�����6���ƣ����а���3�����ϵĶ��ӣ���ÿ�����Ӽ�Ĳ�Ϊ1\n");
    else if (lang == 1) printf("10.Silk Road on Sea��More than 6 cards, the difference of every connected Double Cards must be the SAME\n");
    if (lang == 1) printf("11.�Ĵ���������Գ�һ��ը��������ŵ��ƻ���������\n");
    else if (lang == 2) printf("11.Gone With The Bomb: A bomb and two single or two double cards\n");
    if (lang == 1) printf("�����û�и�����ƣ������Ҫ���𡯻�0��\n");
    else if (lang == 2) printf("If you don't have a bigger one, please put ��Can't afford�� or ��0��\n");
    if (lang == 1) printf("���һ���Ȱ������Ƴ��꣬��ʤ��\n");
    else if (lang == 2) printf("If one of you has put all of his(her) cards, he(her) WINS\n");
    if (lang == 1) printf("������ǵ���������һ���Խ������ƶ����꣬����û��һ�γ��ƻ��ᣬ����ô���ӱ�����\n");
    else if (lang == 2) printf("If you are the landlord and put all of you cards in a row, the Rival can't get any chance to put any cards, you do Spring with bonus\n");
    if (lang == 1) printf("�������ũ��������ֻ�ö��ֳ���һ���ƣ��㽫���ͬ���ý���\n");
    else if (lang == 2) printf("If you are a farmer and only give one chance to the Rival, youn will receive the same bonus\n");
    if (lang == 1) printf("��������Է���\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    nextPage();
    return;
}
void sett(){
    if (lang == 1) printf("1.�ϵ�ģʽ�����Կ������ֵ��ƣ����ӳ����еĴ��󣬲��ҿ����á�t����ֹ��Ϸ\n");
    else if (lang == 2) printf("1.God Mode: If enabled, you can see The Rival's cards, ignore any kind of error in putting, and you can even use 't' to terminate current game\n");
    if (lang == 1) printf("2.�Ѷ����ã����Ѷ��£�����ֻ�����������Ľ��ơ����ƣ�����ǿ�ͳ��ƿ����ö��ָ��в����ԣ����Ž��ƣ��������\n");
    else if (lang == 2) printf("2.Difficulty Setting: In easy mode,The Rival only put and take the smallest cards; but enhanced mode let The Rival use some strategies, take least costing cards and put cards as much as possible\n");
    if (lang == 1) printf("3.�ɻ�ģʽ����ѡ�����ѽ����������ڴ˲���׸��\n");
    else if (lang == 2) printf("3.Plane Mode: There are some description in Options, further explanation is not needed\n");
    if (lang == 1) printf("��������Է���\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    nextPage();
}
void hel(){
    if (lang == 1) printf("1.��Ϸ���� 2.�������� 3.����\n");
    else if (lang == 2) printf("1.Rules 2.Settings 3.Back\n");
    int uc;
    scanf("%d",&uc);
    system("cls");
    if (uc == 1) rules();
    else if (uc == 2) sett();
    if (uc == 3) return;
    else hel();
}
void about(){
    if (lang == 1) printf("��������: 8/10/2021\n");
    else if (lang == 2) printf("Release Date: 8/10/2021\n");
    if (lang == 1) printf("�汾��: 2.2.7\n");
    else if (lang == 2) printf("Ver: 2.2.7\n");
    if (edi == 'n'){
        if (lang == 1) printf("C++��ʽ��\n");
        else if (lang == 2) printf("C++ stable channel\n");
    }
    else if (edi == 'b'){
        if (lang == 1) printf("C++���԰�\n");
        else if (lang == 2) printf("C++ beta channel\n");
    }
    else if (edi == 'a'){
        if (lang == 1) printf("��������\n");
        else if (lang == 2) printf("Anniversary Edition\n");
    }
    else if (edi == 'e'){
        if (lang == 1) printf("E32021�ر��\n");
        else if (lang == 2) printf("E32021 Special Edition\n");
    }
    else if (edi == 's'){
        if (lang == 1) printf("Steam2021�Ĵ��ر��\n");
        else if (lang == 2) printf("Steam Summer Sale 2021 Special Edition\n");
    }
    else if (edi == 'g'){
        if (lang == 1) printf("7.6����\n");
        else if (lang == 2) printf("July 6th Say Goodbye Edition\n");
    }
    if (lang == 1) printf("������������κ����⣬����ϵ������\n��Ŀ��ҳ: https://github.com/bowenOne580/Onegit/tree/��������Ŀ \nQQ: 2797269898\n");
    else if (lang == 2) printf("If you meet any kind of problem(s), please feel free to contact the developer.\nProject Homepage: https://github.com/bowenOne580/Onegit/tree/��������Ŀ \nQQ: 2797269898\n");
    if (lang == 1) printf("��������Է���\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    nextPage();
    printf("\n");
    return;
}
void acheive(){ //δ�Ż�
    if (lang == 1) printf("���Ѵ�ɵĳɾ�:\n");
    else if (lang == 2) printf("The achievements you have reached\n");
    int f = 0;
    for (int i=1;i<=18;i++){
        if (ach[i].ifGet == 1){
            if (lang == 1) cout<<achCNStack[i]<<endl;
            else if (lang == 2) cout<<achENStack[i]<<endl;
            if (lang == 1){
                printf("����ʱ��: %d��",ach[i].yr);
                cout<<achMonCN[ach[i].mon]<<"��"<<ach[i].day<<"��"<<endl;
            }
            else if (lang == 2){
                printf("Unlock Time: ");
                cout<<achMonEN[ach[i].mon]<<" "<<ach[i].day;
                if (ach[i].day%10 == 1) printf("st ");
                else if (ach[i].day%10 == 2) printf("nd ");
                else if (ach[i].day%10 == 3) printf("rd ");
                else printf("th ");
                cout<<ach[i].yr<<endl;
            }
            printf("\n");
            f = 1;
        }
    }
    if (!f){
        if (lang == 1) printf("��\n\n");
        else if (lang == 2) printf("None\n\n");
    }
    f = 0;
    if (lang == 1) printf("��������Լ����鿴\n");
    else if (lang == 2) printf("Press any key to access more information\n");
    char uc2[10];
    gets(uc2);
    cin.getline(uc2,10);
    printf("\n");
    if (lang == 1) printf("δ�����ĳɾ�:\n");
    else if (lang == 2) printf("Locked Achievements:\n");
    for (int i=1;i<=18;i++){
        if (ach[i].ifGet == 0){
            if (lang == 1) cout<<achCNStack[i]<<endl<<"��������: "<<descripCN[i]<<endl<<endl;
            else if (lang == 2) cout<<achENStack[i]<<endl<<"Unlock Way: "<<descripEN[i]<<endl<<endl;
            f = 1;
        }
    }
    if (!f){
        if (lang == 1) printf("���ѽ���ȫ���ɾ�!\n\n");
        else if (lang == 2) printf("You have achieved all of them!\n\n");
    }
    if (lang == 1) printf("��������Է���\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    char uc[10];
    cin.getline(uc,10);
    printf("\n");
    system("cls");
    return;
}
void language(){
    printf("1.����\n2.English\n");
    scanf("%d",&lang);
    printf("\n");
    system("cls");
}
void option(){
    if (lang == 1) printf("1.�ϵ�ģʽ: ");
    else if (lang == 2) printf("1.God Mode: ");
    if (ifGod == 0) printf("Disabled\n");
    else printf("Enabled\n");
    if (lang == 1) printf("2.�Ѷ�����: ");
    else if (lang == 2) printf("2.Difficulty Setting: ");
    if (dif == 1){
        if (lang == 1) printf("��\n");
        else if (lang == 2) printf("Easy\n");
    }
    else if (dif == 2){
        if (lang == 1) printf("��ǿ��\n");
        else if (lang == 2) printf("Enhanced\n");
    }
    if (lang == 1) printf("3.�ɻ�ģʽ��");
    else if (lang == 2) printf("3.Plane Type: ");
    if (plaType == 1){
        if (lang == 1) printf("����\n");
        else if (lang == 2) printf("Classic\n");
    }
    else if (plaType == 2){
        if (lang == 1) printf("��\n");
        else if (lang == 2) printf("Loose\n");
    }
    if (lang == 1) printf("4.������Ϸ\n");
    else if (lang == 2) printf("4.Reset Game\n");
    if (lang == 1) printf("5.����\n");
    else if (lang == 2) printf("5.Back\n");
    int uc;
    scanf("%d",&uc);
    system("cls");
    if (uc == 1){
        if (lang == 1) printf("��1�����ã���0�Խ���\n");
        else if (lang == 2) printf("Press 1 to enable, 0 to disable\n");
        scanf("%d",&uc);
        if (uc == 1) ifGod = 1;
        else ifGod = 0;
    }
    else if (uc == 2){
        if (lang == 1) printf("1.�� 2.��ǿ��\n");
        else if (lang == 2) printf("1.Easy 2.Enhanced\n");
        scanf("%d",&uc);
        if (uc == 1) dif = 1;
        else dif = 2;
    }
    else if (uc == 3){
        if (lang == 1) printf("1.����(ֻ�ܳ����ŵ���) 2.��(ֻҪ����һ������)\n");
        else if (lang == 2) printf("1.Classic(The cards must be continuous) 2.Loose(As long as it fits the style of Classic)\n");
        scanf("%d",&uc);
        if (uc == 1) plaType = 1;
        else plaType = 2;
    }
    else if (uc == 4){
        if (lang == 1) printf("�������Ҫɾ������������?\n1.��  2.��\n");
        else if (lang == 2) printf("Do you really want to delete all saves?\n1.Yes  2.No\n");
        scanf("%d",&uc);
        if (uc == 1) Back();
    }
    printf("\n");
    system("cls");
}
void markAch(int i){
    if (lang == 1) cout<<"��ɳɾ�: "<<achCNStack[i]<<endl;
    else if (lang == 2) cout<<"Reach an achievement: "<<achENStack[i]<<endl;
    ach[i].ifGet = 1;
    struct tm *local;
    time_t t;
    t = time(0);
    local = localtime(&t);
    ach[i].day = local->tm_mday;
    ach[i].mon = local->tm_mon;
    ach[i].yr = local->tm_year+1900;
}
void checkach(){
    if (ifChun == 1 && ach[1].ifGet == 0) markAch(1);
    if (win == 1 && ach[2].ifGet == 0) markAch(2);
    if (win == 10 && ach[3].ifGet == 0) markAch(3);
    if (win == 50 && ach[4].ifGet == 0) markAch(4);
    if (lose == 5 && ach[5].ifGet == 0) markAch(5);
    if (lose == 20 && ach[6].ifGet == 0) markAch(6);
    if (money>=10000 && ach[7].ifGet == 0) markAch(7);
    if (money>=30000 && ach[8].ifGet == 0) markAch(8);
    if (money>=500000 && ach[9].ifGet == 0) markAch(9);
    if (money>=2147480000 && ach[10].ifGet == 0) markAch(10);
    if (money<=-10000 && ach[11].ifGet == 0) markAch(11);
    if (money<=-50000 && ach[12].ifGet == 0) markAch(12);
    if (money<=-1000000 && ach[13].ifGet == 0) markAch(13);
    if (money<=-5000000 && ach[14].ifGet == 0){
        markAch(14);
        money = 3000;
        hisco = 0;
    }
    if (ifChun == 1 && ach[15].ifGet == 0 && chun==20) markAch(15);
    if (edi == 'a' && ach[16].ifGet == 0 && speGame==5) markAch(16);
    if (edi == 'e' && ach[17].ifGet == 0) markAch(17);
    if (edi == 's' && ach[18].ifGet == 0 && speGame==10) markAch(18);
}
void stat(){
    if ((win+lose) != 0) rating = int((double(win)/(win+lose))*100);
    if (lang == 1){
        printf("����ܵ���: %lld\n",money);
        printf("��߷���: %d\n",hisco);
        printf("��ʤ����: %d\n",win);
        printf("�ܾܰ���: %d\n",lose);
        printf("ʤ��: %d",rating);
    }
    else if (lang == 2){
        printf("Your credits: %lld\n",money);
        printf("Highest score: %d\n",hisco);
        printf("You win for %d times\n",win);
        printf("But you lose for %d times\n",lose);
        printf("Possibility of Winning: %d",rating);
    }
    puts("%\n");
    if (!ifGod){
        if (lang == 1) printf("�����޷������˽����ϵĸ�������\n\n");
        else if (lang == 2) printf("Only God can see more on this page\n\n");
        if (lang == 1) printf("��������Է���\n");
        else if (lang == 2) printf("Press any key to go back to the previous page\n");
        char uc[10];
        gets(uc);
        cin.getline(uc,10);
        printf("\n");
        system("cls");
        return;
    }
    if (lang == 1) printf("1.�޸ĵ���\n2.�޸ĳɾʹ�����\n3.����\n");
    else if (lang == 2) printf("1.Modify Credits\n2.Modify Acheivements\n3.Back\n");
    long long uc;
    scanf("%lld",&uc);
    system("cls");
    if (uc == 1){
        if (lang == 1) printf("��Ҫ�޸�Ϊ: ");
        else if (lang == 2) printf("Want to change to: ");
        scanf("%lld",&uc);
        money = uc;
    }
    else if (uc == 2){
        if (lang == 1) printf("�޸���һ��ɾ�?(0��ʾȫѡ)\n");
        else if (lang == 2) printf("Change which acheivement?(0 stands for ALL)\n");
        scanf("%lld",&uc);
        int uc2;
        if (uc > 0 && uc<=16){
            if (lang == 1) printf("�޸�Ϊ(1Ϊ�Ѵ�ɣ�0Ϊδ���): ");
            else if (lang == 2) printf("Change to(1 for acheived, 0 for locked):");
            scanf("%d",&uc2);
            if (uc2) markAch(uc);
            else ach[uc].ifGet = 0;
        }
        else if (uc == 0){
            if (lang == 1) printf("�޸�Ϊ(1Ϊ�Ѵ�ɣ�0Ϊδ���): ");
            else if (lang == 2) printf("Change to(1 for acheived, 0 for locked):");
            scanf("%d",&uc2);
            for (int i=1;i<=16;i++){
                if (uc2) markAch(i);
                else ach[i].ifGet = 0;
            }
        }
        else{
            while (uc>16 || uc<0){
                if (lang == 1) printf("���޴˳ɾͣ�����ϸ�˶�\n\n");
                else if (lang == 2) printf("This achievement is not available, please check your input carefully\n\n");
                if (lang == 1) printf("�޸���һ��ɾ�?(0��ʾȫѡ)\n");
                else if (lang == 2) printf("Change which acheivement?(0 stands for ALL)\n");
                scanf("%lld",&uc);
            }
            int uc2;
            if (lang == 1) printf("�޸�Ϊ(1Ϊ�Ѵ�ɣ�0Ϊδ���): ");
            else if (lang == 2) printf("Change to(1 for acheived, 0 for locked):");
            scanf("%d",&uc2);
            if (uc != 0 && uc<=16){
                if (uc2) markAch(uc);
                else ach[uc].ifGet = 0;
            }
            else if (uc == 0){
                for (int i=1;i<=16;i++){
                    if (uc2) markAch(i);
                    else ach[i].ifGet = 0;
                }
            }
        }
    }
    else if (uc == 3){
        printf("\n");
        return;
    }
    printf("\n");
}
void nbdata(int i){
    if (i == 1){
        if (lang == 1) printf("����ʱ��:2021.6.13 17:42\n");
        else if (lang == 2) printf("Post Time:6/13/2021 17:42\n");
        if (lang == 1) printf("����ҳ��������!\n");
        else if (lang == 2) printf("Notice Board is out now!\n");
    }
    else if (i == 2){
        if (lang == 1) printf("����ʱ��:2021.6.13 17:45\n");
        else if (lang == 2) printf("Post Time:6/13/2021 17:45\n");
        if (lang == 1) printf("E32021���ѿ�Ļ\n��չ��ַ:\nhttps://www.bilibili.com/blackboard/activity-E32021.html\nhttps://e3expo.com/watch (����Ҫ����)\n");
        else if (lang == 2) printf("E32021 is open to watch now!\nAttend on Website:\nhttps://www.bilibili.com/blackboard/activity-E32021.html\nhttps://e3expo.com/watch (Might need proxy in China)\n");
    }
    else if (i == 3){
        if (lang == 1) printf("����ʱ��:2021.6.13 18:36\n");
        else if (lang == 2) printf("Post Time:6/13/2021 18:36\n");
        if (lang == 1) printf("E3�ر�汾����!�׸������Ȱ���Ϸ����!\n�ر�ɾ��ѿ��ã����ڳɾͽ����в鿴\n");
        else if (lang == 2) printf("E3 Special Edition out now!For Gamers!\nSpecial Acheivement is available, please check out in Acheivements\n");
    }
    else if (i == 4){
        if (lang == 1) printf("����ʱ��:2021.6.16 19:48\n");
        else if (lang == 2) printf("Post Time:6/16/2021 19:49\n");
        if (lang == 1) printf("E3�ر����ѽ���\n�п��ٽ�����ʱ����һ��С���£�Ԥף����2110���ͬѧ�п�˳��!\n");
        else if (lang == 2) printf("E3 Special Event has ended\nThe Final Test is coming, I will just update the program by little, hope everyone in Class 2110 will get the best grade!\n");
    }
    else if (i == 5){
        if (lang == 1) printf("����ʱ��:2021.6.24 0:18\n");
        else if (lang == 2) printf("Post Time:6/24/2021 0:18\n");
        if (lang == 1) printf("�ش�汾����:����ϵͳ����\n��Ҳ����ζ�Ż����˽��ܱ����Ƶ����ӣ�ѡ������ʺϵĲ��ԣ�\n���ǣ�����ÿһ���ش���£��������Ŵ��СС��bug����ǿ�ͳ��Ʒ�ʽ�������ԣ��������⣬�����½⡣\n�����������������⣬��鿴֧�ֽ��档\n");
        else if (lang == 2) printf("Major Update: Upgrade The Card-Putting System\nThis means the Rival can now tell the difference among some strategies!\nBut, unfrotunately, there are many bugs in this enhanced system.\nIf you come across some unexpected errors, please go to the Support page on start-up.\n");
    }
    else if (i == 6){
        if (lang == 1) printf("����ʱ��:2021.6.24 23:12\n");
        else if (lang == 2) printf("Post Time:6/24/2021 23:12\n");
        if (lang == 1) printf("Steam�Ĵٽ���6.25�տ�ʼ��\n�ر������ߣ��µĳɾͽ��ܻ�ȡ��ף��λ���ֿ��֣�\n25�� 16:24���£��Ĵٽ���https://store.steampowered.com/ ����ò�Ʋ��Ǻܴ󣬵������кܶ�ֵ�ù����\n");
        else if (lang == 2) printf("The Steam Summer Sale 2021 is starting on June 25!\nSpecial event is open now, new achievement is added, happy shopping everybody!\nUpdate on 6/25 16:24 Sale Pagehttps://store.steampowered.com/ Not much, but you can still find good games with delicious discount to buy\n");
    }
    else if (i == 7){
        if (lang == 1) printf("����ʱ��:2021.7.6 16:13\n");
        else if (lang == 2) printf("Post Time:7/6/2021 16:13\n");
        if (lang == 1) printf("�ش�֪ͨ:\n����������������ѧϰ�е���Ҫ�ڵ㣬����У�ڻ��Ǳ�̣��ֿ��ǵ��Դ���Ϸ�Ĳ����Ż��ѽӽ�ƿ�����ʾ�����ʱֹͣ����\n�������ܵ��޸������ƣ���෢���³���ϵͳ���ڵ�����õ��˽������Ҳ���л������࣬����������汾�������������������������������ƣ���ѡ���ڴ�ֹͣ����\n��������������κν��������ʲô���⣬�������ϵ�ң��һὫ�����źã�Ϊ֮��ĸ�����׼��\n�����������У�������Ҫ��ʱ���£���δ�����ܸ���ǰ��\n");
        else if (lang == 2) printf("Attention!\nSince I am between a rock and a hard place, things just rush to me in a second, considering I have nothing to do with making this game better, I have to say, I decide to put it aside for a while\nWhen the new putting system appeared, many problems came along, after two weeks of hard work, there are no longer any visible problems, so I decide to leave this game alone\nIf you have any questions or suggestions, please feel good to contact me, I won't deal with it right away, but I will put them carefully for future updates\nThe life is long, but we need to give up something in the right time, I believe this will lead a better future.\n");
    }
}
void notboard(){ //δ�Ż�
    int uc = 4,page = 7,ifRead = 1;
    while (uc!=3){
        system("cls");
        if (uc == 2){
            if (page>=maxPage){
                if (lang == 1) printf("������ǰһҳ!\n");
                else if (lang == 2) printf("You are on the first page now!\n");
                ifRead = 0;
            }
            else{
                page++;
                ifRead = 1;
            }
        }
        else if (uc == 1){
            if (page<=1){
                if (lang == 1) printf("�������һҳ!\n");
                else if (lang == 2) printf("You have already reached the last page!\n");
                ifRead = 0;
            }
            else{
                page--;
                ifRead = 1;
            }
        }
        else if (uc != 4) {
            printf("\n");
            return;
        }
        if (ifRead) nbdata(page);
        printf("\n");
        if (lang == 1) printf("1.��һҳ 2.��һҳ 3.�˳�\n");
        else if (lang == 2) printf("1.Next Page 2.Previous Page 3.Quit\n");
        scanf("%d",&uc);
    }
}
void runPro(){
    writeVars();
    ifJiao = 0;
    system("cls");
    if (lang == 1) printf("1.��ʼ\n2.����/Language\n3.ѡ��\n4.����\n5.�ɾ�\n6.ͳ��\n7.����\n8.����\n9.�˳�\n");
    else if (lang == 2) printf("1.Start\n2.Language/����\n3.Options\n4.Notice\n5.Acheivements\n6.Statistics\n7.Help\n8.About\n9.Quit\n");
    scanf("%d",&usercho);
    system("cls");
   if (usercho == 1){
       Clear();
       ran(); //���ƺ�������
       while (totM > 0 && totE > 0) ingame();
       if (termi){
           if (lang == 1) printf("������ǰ��ֹ�˾���Ϸ�����������ᱻ��¼\n");
           else if (lang == 2) printf("You have terminated this game earlier than expected, the scores made in this game won't be recorded.\n");
           char uc[4];
           cin.getline(uc,4);
           gets(uc);
           system("cls");
           return;
       }
       if (ifChun == 1){
           chun++;
           sco*=2;
       }
       if (totM == 0){
           win++;
           if (lang == 1) printf("��Ӯ��!\n��ĵ÷�: %d\n",sco);
           else if (lang == 2) printf("You Win!\nYour Score: %d\n",sco);
           if (edi != 'z') money+=sco;
           else money-=10000000;
           if (sco>hisco){
               hisco = sco;
               if (lang == 1) printf("�������߼�¼: %d��\n",hisco);
               else if (lang == 2) printf("Your new record: %d points\n",hisco);
           }
           if (lang == 1) printf("��������%lld����!\n\n",money);
           else if (lang == 2) printf("You have %lld points now!\n\n",money);
       }
       else{
           lose++;
           if (lang == 1) printf("������!\n���ֵ÷�: %d\n",sco);
           else if (lang == 2) printf("You Lose!\nRival's Score: %d\n",sco);
           money-=sco;
           if (lang == 1) printf("�㻹��%lld��\n\n",money);
           else if (lang == 2) printf("You have %lld points\n\n",money);
       }
       if (edi!='n') speGame++;
       checkach();
       char uc[2];
       gets(uc);
   }
   else if (usercho == 2) language();
   else if (usercho == 3) option();
   else if (usercho == 4) notboard();
   else if (usercho == 5) acheive();
   else if (usercho == 6) stat();
   else if (usercho == 7) hel();
   else if (usercho == 8) about();
}
int main(){
    readVars();
    while (usercho != 9) runPro();
    return 0;
}
