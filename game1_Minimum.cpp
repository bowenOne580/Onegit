#include<iostream>
#include<cstdio>
#include<ctime> //用于产生随机数(系统时间随机)
#include<cstring>
#include<string>
#include<cmath>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int Max,cntE[20],cntM[20],cntB[5],totM = 17,totE = 17,mode,lMode,boKing,sco = 100,hisco = 0;
int lChu[100],lSize,ifChun = 1,lLen,lang = 1,ifGod,ifJiao = 0,win,lose;
int chun,lenColl[20],maxPage = 6,tri[20],bomb[20],useful[20],dou[20],si[20],kingsman[2],oppor,speGame;
int haDou,haSin,plaType = 1,calcThree[20];
long long money = 3000;
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING",};
void readVars(){
    bool a = freopen("test.txt","r",stdin);
    if (!a) return;
    scanf("%lld",&money);
    scanf("%d",&hisco);
    scanf("%d",&lang);
    scanf("%d",&ifGod);
    scanf("%d",&win);
    scanf("%d",&lose);
    scanf("%d",&plaType);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}
void writeVars(){
    freopen("test.txt","w",stdout);
    printf("%lld\n",money);
    printf("%d\n",hisco);
    printf("%d\n",lang);
    printf("%d\n",ifGod);
    printf("%d\n",win);
    printf("%d\n",lose);
    printf("%d\n",plaType);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
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
}
void Back(){
    money = 3000;
    hisco = 0;
    win = 0;
    lose = 0;
}
void ran(){
    int flag = 0;
    if (lang == 1) printf("想定制牌组吗？ 1.好的 2.算了\n");
    else if (lang == 2) printf("Want to modify your cards?! 1.YES! 2.Forget it!\n");
    int uc;
    scanf("%d",&uc);
    if (uc == 1){
        flag = 1;
        int r;
        if (lang == 1) printf("输入自己的牌(17张)\n");
        else if (lang == 2) printf("Enter your own 17 cards\n");
        char ui[105];
        getchar();
        cin.getline(ui,105);
        int fakeLen = strlen(ui);
        for (int i=0;i<fakeLen;i++){
            if (ui[i] == ' ') continue;
            else if (ui[i] > '1' && ui[i] <= '9'){
                if (ui[i] == '2') cntM[12]++;
                else cntM[ui[i]-'0'-3]++;
            }
            else if (ui[i] == 'J' || ui[i] == 'j') cntM[8]++;
            else if (ui[i] == 'Q' || ui[i] == 'q') cntM[9]++;
            else if (ui[i] == 'K' || ui[i] == 'k'){
                if (i!=fakeLen-1){
                    if (ui[i+1] == 'I' || ui[i+1] == 'i'){
                        cntM[14]++;
                        i += 3;
                    }
                    else cntM[10]++;
                }
                else cntM[10]++;
            }
            else if (ui[i] == 'A' || ui[i] == 'a') cntM[11]++;
            else if (ui[i] == 'S' || ui[i] == 's'){
                cntM[13]++; //对应SMALL
                i += 4;
            }
            else if (ui[i] == '1' && i+1<fakeLen){
                cntM[7]++; //对应10
                i += 1;
            }
        }
        if (lang == 1) printf("输入对手的牌(17张)\n");
        else if (lang == 2) printf("Enter The Rival's 17 cards\n");
        cin.getline(ui,105);
        fakeLen = strlen(ui);
        for (int i=0;i<fakeLen;i++){
            if (ui[i] == ' ') continue;
            else if (ui[i] > '1' && ui[i] <= '9'){
                if (ui[i] == '2') cntE[12]++;
                else cntE[ui[i]-'0'-3]++;
            }
            else if (ui[i] == 'J' || ui[i] == 'j') cntE[8]++;
            else if (ui[i] == 'Q' || ui[i] == 'q') cntE[9]++;
            else if (ui[i] == 'K' || ui[i] == 'k'){
                if (i!=fakeLen-1){
                    if (ui[i+1] == 'I' || ui[i+1] == 'i'){
                        cntE[14]++;
                        i += 3;
                    }
                    else cntE[10]++;
                }
                else cntE[10]++;
            }
            else if (ui[i] == 'A' || ui[i] == 'a') cntE[11]++;
            else if (ui[i] == 'S' || ui[i] == 's'){
                cntE[13]++; //对应SMALL
                i += 4;
            }
            else if (ui[i] == '1' && i+1<fakeLen){
                cntE[7]++; //对应10
                i += 1;
            }
        }
        if (lang == 1) printf("输入地主牌(3张)\n");
        else if (lang == 2) printf("Enter 3 Landlord Cards\n");
        cin.getline(ui,105);
        fakeLen = strlen(ui);
        for (int i=0;i<fakeLen;i++){
            if (ui[i] == ' ') continue;
            else if (ui[i] > '1' && ui[i] <= '9'){
                if (ui[i] == '2') cntB[i] = 12;
                else cntB[i] = ui[i]-'0'-3;
            }
            else if (ui[i] == 'J' || ui[i] == 'j') cntB[i] = 8;
            else if (ui[i] == 'Q' || ui[i] == 'q') cntB[i] = 9;
            else if (ui[i] == 'K' || ui[i] == 'k'){
                if (i!=fakeLen-1){
                    if (ui[i+1] == 'I' || ui[i+1] == 'i'){
                        cntB[i] = 14;
                        i += 3;
                    }
                    else cntB[i] = 10;
                }
                else cntB[i] = 10;
            }
            else if (ui[i] == 'A' || ui[i] == 'a') cntB[i] = 11;
            else if (ui[i] == 'S' || ui[i] == 's'){
                cntB[i] = 13; //对应SMALL
                i += 4;
            }
            else if (ui[i] == '1' && i+1<fakeLen){
                cntB[i] = 7; //对应10
                i += 1;
            }
        }
    }
    if (flag == 0){
        srand(time(0)); //保证每次的牌不一样
        int num = 0,r;
        while (num!=37){
            r = rand()%15;
            if (cardNum[r] == 0) continue;
            cardNum[r]--;
            if (num < 17) cntE[r]++;
            if (num > 19){
                cntM[r]++;
            }
            if (num > 16 && num < 20) cntB[num-17] = r;
            num++;
        }
    }
}
int calc(){
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
int Save(){
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
void initBeat(){
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
        kingsman[0] = 1; //对王判断
        oppor+=4;
    }
    for (int i=0;i<13;i++){ //去王优化
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
int weigh(int left,int right,int length){
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
void selfOut(){
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
            for (int i=0;i<12;i++){ //去王和2优化
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
            for (int i=0;i<12;i++){ //去王和2优化
                if (si[i] == 1){
                    int tmp = i;
                    cnt = 0; //2->2
                    while (si[tmp]!=0){
                        cnt++; //有优化空间
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
            //此处还需增加自己只剩一张与两张的特判
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
void beat2(){
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
    else if (mode == 2){ //对子
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
    else if (mode == 3){ //三不带
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]-=3;
            totE-=3;
            canChu = 1;
        }
    }
    else if (mode == 4){ //三带一
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
    else if (mode == 5){ //炸弹
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
    else if (mode == 6){ //三带二
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
    else if (mode == 7){ //顺子
        int cntSi,Min = 0x7fffffff,mpos = -1;
        for (int i=Ou[0]+1;(i+lenOU-1)<12;i++){ //去王和2优化
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
    else if (mode == 8){ //连对
        int cntDo,Min = 0x7fffffff,mpos = -1;
        for (int i=Ou[0]+1;(i+lenOU/2-1)<12;i++){ //去王和2优化
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
    else if (mode == 9){ //小飞机
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
    else if (mode == 10){ //四带二
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
    else if (mode == 11){ //对手出牌
        selfOut();
        canChu = 1;
    }
    else if (mode == 12){ //中飞机
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
    else if (mode == 13){ //大飞机
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
            if (lang == 1) printf("功能未完善或牌出错了\n");
            else if (lang == 2) printf("Feature not included or you have put the Wrong Card\n");
            canChu = 1;
            lMode = 0;
        }
    }
    if (canChu == 0){
        if (totM<=10){
            if (!Save()){
                if (lang == 1) cout<<"要不起"<<endl;
                else if (lang == 2) cout<<"Can't afford"<<endl;
                lMode = 0;
                lLen = 0;
            }
        }
        else{
            if (lang == 1) cout<<"要不起"<<endl;
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
    if (lang == 1) printf("叫地主吗？: 1.3分 2.2分 3.1分 4.不叫\n");
    else if (lang == 2) printf("Want to be the landlord?: 1.Very 2.Fine 3.Maybe 4.Definitely Not\n");
    int iwant;
    scanf("%d",&iwant);
    if (iwant == 10){
        totM = 0;
        return;
    }
    if (iwant == 1){
        if (lang == 1) printf("你叫到了地主!\n");
        else if (lang == 2) printf("You are the Landlord now!\n");
        for (int i=0;i<3;i++) cntM[cntB[i]]++;
    	totM += 3;
        sco*=(4-iwant);
    }
    else if (iwant != 4){
        if (oppor>=6){
            if (lang == 1) printf("对手叫3分，抢地主\n");
            else if (lang == 2) printf("The Rival has a strong wish to be the landlord.\n");
            for (int i=0;i<3;i++) cntE[cntB[i]]++;
    	    totE += 3;
            ifChun--;
            sco*=3;
            who = 1;
        }
        else if (oppor>=4 && iwant == 3){
            if (lang == 1) printf("对手叫2分，抢地主\n你要抢吗？ 1.3分 2.不叫\n");
            else if (lang == 2) printf("The Rival want to get this position\nAre you going to fight for this? 1.Yes 2.Not interested\n");
            scanf("%d",&iwant);
            if (iwant == 1){
                if (lang == 1) printf("你叫到了地主!\n");
                else if (lang == 2) printf("You are the Landlord now!\n");
                for (int i=0;i<3;i++) cntM[cntB[i]]++;
    	        totM += 3;
                sco*=(4-iwant);
            }
            else{
                for (int i=0;i<3;i++) cntE[cntB[i]]++;
    	        totE += 3;
                ifChun--;
                sco*=2;
                who = 1;
            }
        }
        else if (oppor<4){
            if (lang == 1) printf("你叫到了地主!\n");
            else if (lang == 2) printf("You are the Landlord now!\n");
            for (int i=0;i<3;i++) cntM[cntB[i]]++;
    	    totM += 3;
            sco*=(4-iwant);
        }
	}
    else{
    	if (oppor>=6){
            if (lang == 1) printf("对手叫3分\n");
            else if (lang == 2) printf("The Rival has a strong wish to be the landlord.\n");
        }
        else if (oppor>=4){
            if (lang == 1) printf("对手叫2分\n");
            else if (lang == 2) printf("The Rival is interested in this position.\n");
        }
        else{
            if (lang == 1) printf("对手叫1分\n");
            else if (lang == 2) printf("The Rival gives it a go\n");
        }
        for (int i=0;i<3;i++) cntE[cntB[i]]++;
    	totE += 3;
        ifChun--;
        who = 1;
	}
    if (lang == 1) cout<<"地主牌是: "<<cardStack[cntB[0]]<<" "<<cardStack[cntB[1]]<<" "<<cardStack[cntB[2]]<<endl;
    else if (lang == 2) cout<<"Special Cards for The Landlord: "<<cardStack[cntB[0]]<<" "<<cardStack[cntB[1]]<<" "<<cardStack[cntB[2]]<<endl;
    printf("\n");
    if (lang == 1) printf("你的牌: ");
    else if (lang == 2) printf("Your Cards: ");
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    if (lang == 1) printf("\n对手牌数: %d\n",totE);
    else if (lang == 2) printf("\nRival has %d cards\n",totE);
    if (lang == 1){
        printf("对手的牌: ");
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
    if (who == 1){
        mode = 11;
        if (lang == 1) printf("对手出了: ");
        else if (lang == 2) printf("Rival has put: ");
        beat2();
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
    if (lang == 1) printf("你的牌: ");
    else if (lang == 2) printf("Your Cards: ");
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    if (lang == 1) printf("\n对手牌数: %d\n",totE);
    else if (lang == 2) printf("\nRival has %d cards\n",totE);
    if (lang == 1){
        printf("对手的牌: ");
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
    if (ifJiao == 0){
        ifJiao = 1;
        pre();
    }
    char ou[105];
    cin.getline(ou,105);
    if ((ou[0] == 't' || ou[0] == 'T' || ou[0] == 'e' || ou[0] == 'E') && ifGod == 1){
        totM = 0;
        return;
    }
    if (ou[0] == -46 || ou[0] == '0' || ou[0] == 'C' || ou[0] == 'c'){
        Ou[0] = -46;
        mode = 11;
        if (lang == 1) printf("对手出了: ");
        else if (lang == 2) printf("Rival has put: ");
        beat2();
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
            Ou[++size] = 13; //对应SMALL
            lenOU -= 4;
            i += 4;
        }
        else if (ou[i] == '1' && i+1<fakeLen){
            if (ou[i+1] == '0'){
                Ou[++size] = 7; //对应10
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
            basket[Ou[size]] += 1; // 负责计算最大相同数
            if (basket[Ou[size]] > Max) Max = basket[Ou[size]]; //需要将KING和SMALL包含进去
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
        if (lang == 1) printf("牌出错了\n");
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
            if (lang == 1) printf("对手出了: ");
            else if (lang == 2) printf("Rival has put: ");
            beat2();
        }
    }
}
void about(){
    if (lang == 1) printf("发行日期: 7/5/2021\n");
    else if (lang == 2) printf("Release Date: 7/5/2021\n");
    if (lang == 1) printf("版本号: -1.0\n");
    else if (lang == 2) printf("Ver: Whatever\n");
    if (lang == 1) printf("精简测试版\n");
    else if (lang == 2) printf("Testing Channel\n");
    if (lang == 1) printf("如果你遇到了任何问题，请联系开发者\n项目主页: https://github.com/bowenOne580/Onegit/tree/斗地主项目 \nQQ: 2797269898\n");
    else if (lang == 2) printf("If you meet any kind of problem(s), please feel free to contact the developer.\nProject Homepage: https://github.com/bowenOne580/Onegit/tree/斗地主项目 \nQQ: 2797269898\n");
    if (lang == 1) printf("按任意键以返回\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    char uc[10];
    gets(uc);
    cin.getline(uc,10);
    printf("\n");
    return;
}
void language(){
    printf("1.中文\n2.English\n");
    int uc;
    scanf("%d",&uc);
    lang = uc;
    printf("\n");
}
void option(){
    if (lang == 1) printf("1.上帝模式: ");
    else if (lang == 2) printf("1.God Mode: ");
    if (ifGod == 0) printf("Disabled\n");
    else printf("Enabled\n");
    if (lang == 1) printf("2.飞机模式：");
    else if (lang == 2) printf("2.Plane Type: ");
    if (plaType == 1){
        if (lang == 1) printf("经典(测试版)\n");
        else if (lang == 2) printf("Classic(Beta)\n");
    }
    else if (plaType == 2){
        if (lang == 1) printf("宽泛\n");
        else if (lang == 2) printf("Loose\n");
    }
    if (lang == 1) printf("3.重置游戏\n");
    else if (lang == 2) printf("3.Reset Game\n");
    if (lang == 1) printf("4.返回\n");
    else if (lang == 2) printf("4.Back\n");
    int uc;
    scanf("%d",&uc);
    if (uc == 1){
        if (lang == 1) printf("按1以启用，按0以禁用\n");
        else if (lang == 2) printf("Press 1 to enable, 0 to disable\n");
        scanf("%d",&uc);
        if (uc == 1) ifGod = 1;
        else ifGod = 0;
    }
    else if (uc == 2){
        if (lang == 1) printf("1.经典(只能出连着的牌) 2.宽泛(只要牌型一样即可)\n");
        else if (lang == 2) printf("1.Classic(The cards must be continuous) 2.Loose(As long as it fits the style of Classic)\n");
        scanf("%d",&uc);
        if (uc == 1) plaType = 1;
        else plaType = 2;
    }
    else if (uc == 3){
        if (lang == 1) printf("你真的想要删除所有数据吗?\n1.是  2.否\n");
        else if (lang == 2) printf("Do you really want to delete all saves?\n1.Yes  2.No\n");
        scanf("%d",&uc);
        if (uc == 1) Back();
    }
    printf("\n");
}
void stat(){
    if (lang == 1) printf("你的总点数: %lld\n",money);
    else if (lang == 2) printf("Your credits: %lld\n",money);
    if (lang == 1) printf("最高分数: %d\n",hisco);
    else if (lang == 2) printf("Highest score: %d\n",hisco);
    if (lang == 1) printf("总胜局数: %d\n",win);
    else if (lang == 2) printf("You win for %d times\n",win);
    if (lang == 1) printf("总败局数: %d\n",lose);
    else if (lang == 2) printf("But you lose for %d times\n",lose); 
    if (win+lose == 0){
        if (lang == 1) printf("胜率: 未知\n");
        else if (lang == 2) printf("Possibility of Winning: Unknown\n");
    }
    else{
        if (lang == 1) if(win+lose!=0) printf("胜率: %d",int((double(win)/(win+lose))*100));
        else if (lang == 2) printf("Possibility of Winning: %d",int((double(win)/(win+lose))*100));
        cout<<"%"<<endl;
    }
    printf("\n");
}
void runPro(){
    writeVars();
    ifJiao = 0;
    if (lang == 1) printf("1.开始\n2.语言/Language\n3.选项\n4.统计\n5.关于\n6.退出\n");
    else if (lang == 2) printf("1.Start\n2.Language/语言\n3.Options\n4.Statistics\n5.About\n6.Quit\n");
    int uc;
    scanf("%d",&uc);
    if (uc == 1){
        ran(); //发牌和排序函数
        while (totM > 0 && totE > 0) ingame();
        if (ifChun == 1){
            chun++;
            sco*=2;
        }
        if (totM == 0){
            win++;
            if (lang == 1) printf("你赢了!\n你的得分: %d\n",sco);
            else if (lang == 2) printf("You Win!\nYour Score: %d\n",sco);
            if (sco>hisco){
                hisco = sco;
                if (lang == 1) printf("你的新最高记录: %d分\n",hisco);
                else if (lang == 2) printf("Your new record: %d points\n",hisco);
            }
            if (lang == 1) printf("你现在有%lld点了!\n\n",money);
            else if (lang == 2) printf("You have %lld points now!\n\n",money);
        }
        else{
            lose++;
            if (lang == 1) printf("你输了!\n对手得分: %d\n",sco);
            else if (lang == 2) printf("You Lose!\nRival's Score: %d\n",sco);
            money-=sco;
            if (lang == 1) printf("你还有%lld点\n\n",money);
            else if (lang == 2) printf("You have %lld points\n\n",money);
        }
        printf("\n");
        Clear();
        runPro();
    }
    else if (uc == 2){
        language();
        runPro();
    }
    else if (uc == 3){
        option();
        runPro();
    }
    else if (uc == 4){
        stat();
        runPro();
    }
    else if (uc == 5){
        about();
        runPro();
    }
    else return;
}
int main(){
    readVars();
    runPro();
    return 0;
}
