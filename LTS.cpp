#include<bits/stdc++.h>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int Max,cntE[20],cntM[20],cntB[5],totM = 17,totE = 17,mode,lMode,boKing,sco = 100,hisco = 0;
int lChu[100],lSize,ifChun = 1,lLen,lang = 1,ifGod,dif = 2,ifJiao = 0,win,lose;
int chun,lenColl[20],maxPage = 7,tri[20],bomb[20],useful[20],dou[20],si[20],kingsman[2],oppor,speGame;
int haDou,haSin,plaType = 1,calcThree[20],termi,rating,sma,roun,rounds[105],cl = 1;
int cntAch = 18,usc,usercho;
char edi = 'n',uc[10];
long long money = 3000;
struct carO{
    string cards[25];
    int id;
} cardOut[105];
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING",};
void readVars(){
    ifstream input("data.txt");
    input>>money>>hisco>>lang>>ifGod>>win>>lose>>plaType>>rating>>cl;
    input.close();
}
void writeVars(){
    ofstream output;
    output.open("data.txt");
    output<<money<<endl<<hisco<<endl<<lang<<endl<<ifGod<<endl<<win<<endl<<lose<<endl<<plaType<<endl<<rating<<endl<<cl<<endl;
    output.close();
}
void clearScr(){
    system("cls");
}
void nextPage(){
    getchar();
    cin.getline(uc,10);
    if (cl) clearScr();
}
void Clear(){
	for (int i=0;i<=12;i++) cardNum[i] = 4;
    for (int i=13;i<=14;i++) cardNum[i] = 1; //大小王
    memset(cntE,0,sizeof(cntE));
    memset(cntM,0,sizeof(cntM));
    memset(cntB,0,sizeof(cntB));
    memset(si,0,sizeof(si));
    memset(dou,0,sizeof(dou));
    memset(tri,0,sizeof(tri));
    memset(bomb,0,sizeof(bomb));
    memset(useful,0,sizeof(useful));
    for (int i=0;i<=roun;i++) for (int j=0;j<=20;j++) cardOut[i].cards[j].clear();
    roun = oppor = kingsman[0] = ifJiao = lMode = termi = 0;
    totM = totE = 17;
    sco = 100;
    ifChun = 1;
}
void Back(){
    money = 3000;
    hisco = win = lose = rating = 0;
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
void ran(){
    int flag = 0;
    if (lang == 1) printf("想定制牌组吗？ 1.好的 2.算了\n");
    else if (lang == 2) printf("Want to modify your cards?! 1.YES! 2.Forget it!\n");
    int uc;
    scanf("%d",&uc);
    if (uc == 1){
        flag = 1;
        int r;
        if (cl) clearScr();
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
        if (cl) clearScr();
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
        if (cl) clearScr();
        if (lang == 1) printf("输入地主牌(3张)\n");
        else if (lang == 2) printf("Enter 3 Landlord Cards\n");
        cin.getline(ui,105);
        fakeLen = strlen(ui);
        int now = 0;
        for (int i=0;i<fakeLen;i++){
            if (ui[i] == ' ') continue;
            else if (ui[i] > '1' && ui[i] <= '9'){
                if (ui[i] == '2') cntB[now++] = 12;
                else cntB[now++] = ui[i]-'0'-3;
            }
            else if (ui[i] == 'J' || ui[i] == 'j') cntB[now++] = 8;
            else if (ui[i] == 'Q' || ui[i] == 'q') cntB[now++] = 9;
            else if (ui[i] == 'K' || ui[i] == 'k'){
                if (i!=fakeLen-1){
                    if (ui[i+1] == 'I' || ui[i+1] == 'i'){
                        cntB[now++] = 14;
                        i += 3;
                    }
                    else cntB[now++] = 10;
                }
                else cntB[now++] = 10;
            }
            else if (ui[i] == 'A' || ui[i] == 'a') cntB[now++] = 11;
            else if (ui[i] == 'S' || ui[i] == 's'){
                cntB[now++] = 13; //对应SMALL
                i += 4;
            }
            else if (ui[i] == '1' && i+1<fakeLen){
                cntB[now++] = 7; //对应10
                i += 1;
            }
        }
    }
    if (flag == 0){
        clearScr();
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
        initBeat();
        int op1 = oppor;
        for (int i=0;i<=14;i++){
            swap(cntM[i],cntE[i]);
        }
        initBeat();
        int op2 = oppor;
        if (op2<op1){
            for (int i=0;i<=14;i++){
                swap(cntM[i],cntE[i]);
            }
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
    for (;i<15;i++){
        if (cntE[i]>3){
            cardOut[roun].cards[0] = cardStack[i];
            cardOut[roun].cards[1] = cardStack[i];
            cardOut[roun].cards[2] = cardStack[i];
            cardOut[roun].cards[3] = cardStack[i];
            cardOut[roun].id = 1;
            rounds[roun] = 3;
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
        cardOut[roun].cards[0] = cardStack[13];
        cardOut[roun].cards[1] = cardStack[14];
        cardOut[roun].id = 1;
        rounds[roun] = 1;
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
void creErr(){
    ofstream output("error.log");
    if (lang == 1) output<<"本次出牌记录如下："<<endl;
    else if (lang == 2) output<<"This game is recorded as following: "<<endl;
    for (int i=0;i<=roun;i++){
        if (i == 0){
            if (lang == 1) output<<"对手的牌：";
            else if (lang == 2) output<<"Rival's cards: ";
        }
        if (i == 1){
            if (lang == 1) output<<"你的牌：";
            else if (lang == 2) output<<"Your cards: ";
        }
        if (cardOut[i].id == 1){
            if (lang == 1) output<<"对手出牌：";
            else if (lang == 2) output<<"Rival put: ";
        }
        else if (cardOut[i].id == 2){
            if (lang == 1) output<<"你出了：";
            else if (lang == 2) output<<"You put: ";
        }
        for (int j=0;j<=rounds[i];j++){
            output<<cardOut[i].cards[j]<<" ";
        }
        output<<endl;
    }
    output.close();
    if (lang == 1) printf("已生成错误文件\n");
    else if (lang == 2) printf("Error file has been created\n");
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
    roun++;
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
                i = weigh(0,10,6);
                if (i == -1) flag = 1;
            }
            else if (plaType == 2) i = weigh(0,11,3);
            if (i!=-1){
                cntE[i]-=3;
                if (plaType == 1) j = i+1;
                else if (plaType == 2) j = weigh(0,11,3);
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
                            cardOut[roun].cards[0] = cardStack[i];
                            cardOut[roun].cards[1] = cardStack[i];
                            cardOut[roun].cards[2] = cardStack[i];
                            cardOut[roun].cards[3] = cardStack[j];
                            cardOut[roun].cards[4] = cardStack[j];
                            cardOut[roun].cards[5] = cardStack[j];
                            cardOut[roun].cards[6] = cardStack[k];
                            cardOut[roun].cards[7] = cardStack[k];
                            cardOut[roun].cards[8] = cardStack[p];
                            cardOut[roun].cards[9] = cardStack[p];
                            cardOut[roun].id = 1;
                            rounds[roun] = 9;
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
                i = weigh(0,10,6);
                if (i == -1) flag = 1;
            }
            else if (plaType == 2) i = weigh(0,11,3);
            if (i!=-1){
                cntE[i]-=3;
                if (plaType == 1) j = i+1;
                else if (plaType == 2) j = weigh(0,11,3);
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
                            cardOut[roun].cards[0] = cardStack[i];
                            cardOut[roun].cards[1] = cardStack[i];
                            cardOut[roun].cards[2] = cardStack[i];
                            cardOut[roun].cards[3] = cardStack[j];
                            cardOut[roun].cards[4] = cardStack[j];
                            cardOut[roun].cards[5] = cardStack[j];
                            cardOut[roun].cards[6] = cardStack[k];
                            cardOut[roun].cards[7] = cardStack[p];
                            cardOut[roun].id = 1;
                            rounds[roun] = 7;
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
                i = weigh(0,10,6);
                if (i == -1) flag = 1;
            }
            else if (plaType == 2) i = weigh(0,11,3);
            if (i!=-1){
                cntE[i]-=3;
                if (plaType == 1) j = i+1;
                else if (plaType == 2) j = weigh(0,11,3);
                if (j!=-1){
                    sco*=2;
                    if (i>j){
                        swap(i,j);
                        cntE[i]-=3;
                    }
                    else cntE[j]-=3;
                    cardOut[roun].cards[0] = cardStack[i];
                    cardOut[roun].cards[1] = cardStack[i];
                    cardOut[roun].cards[2] = cardStack[i];
                    cardOut[roun].cards[3] = cardStack[j];
                    cardOut[roun].cards[4] = cardStack[j];
                    cardOut[roun].cards[5] = cardStack[j];
                    cardOut[roun].id = 1;
                    rounds[roun] = 5;
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
                    cardOut[roun].cards[0] = cardStack[i];
                    cardOut[roun].cards[1] = cardStack[i];
                    cardOut[roun].cards[2] = cardStack[i];
                    cardOut[roun].cards[3] = cardStack[j];
                    cardOut[roun].cards[4] = cardStack[j];
                    cardOut[roun].id = 1;
                    rounds[roun] = 4;
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
                    cardOut[roun].cards[0] = cardStack[i];
                    cardOut[roun].cards[1] = cardStack[i];
                    cardOut[roun].cards[2] = cardStack[i];
                    cardOut[roun].cards[3] = cardStack[j];
                    cardOut[roun].id = 1;
                    rounds[roun] = 3;
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
                cardOut[roun].cards[0] = cardStack[i];
                cardOut[roun].cards[1] = cardStack[i];
                cardOut[roun].cards[2] = cardStack[i];
                cardOut[roun].id = 1;
                rounds[roun] = 2;
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
            int pos = 0;
            for (int i=mpos;i<=mpos+Max-1;i++){
                cardOut[roun].cards[pos++] = cardStack[i];
                cardOut[roun].cards[pos++] = cardStack[i];
                cardOut[roun].id = 1;
                cntE[i]-=2;
                totE-=2;
            }
            rounds[roun] = pos-1;
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
            int pos = 0;
            for (int i=mpos;i<=mpos+Max-1;i++){
                cardOut[roun].cards[pos++] = cardStack[i];
                cardOut[roun].id = 1;
                cntE[i]--;
                totE--;
            }
            rounds[roun] = pos-1;
            lChu[++lSize] = mpos;
            lMode = 7;
            cout<<endl;
            lLen = Max;
        }
        else{
            int i = weigh(0,12,2),j = weigh(0,14,1);
            if (totM == 1) j = 0x7fffffff;
            else if (totM == 2) i = 0x7fffffff;
            if (i<=j && i!=-1){
                i = weigh(0,12,2);
                cardOut[roun].cards[0] = cardStack[i];
                cardOut[roun].cards[1] = cardStack[i];
                cardOut[roun].id = 1;
                rounds[roun] = 1;
                lChu[++lSize] = i;
                lLen = 2;
                cntE[i]-=2;
                totE-=2;
                lMode = 2;
            }
            else{
                if (totM == 1){
                    for (int i=14;i>=0;i--){
                        if (cntE[i]>=1){
                            j = i;
                            break;
                        }
                    }
                }
                if (j!=-1){
                    cardOut[roun].cards[0] = cardStack[j];
                    cardOut[roun].id = 1;
                    rounds[roun] = 0;
                    lChu[++lSize] = j;
                    lLen = 1;
                    cntE[j]--;
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
            cardOut[roun].cards[0] = cardStack[i];
            cardOut[roun].id = 1;
            rounds[roun] = 0;
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
            cardOut[roun].cards[0] = cardStack[i];
            cardOut[roun].cards[1] = cardStack[i];
            cardOut[roun].id = 1;
            rounds[roun] = 1;
            lChu[++lSize] = i;
            cntE[i]-=2;
            totE-=2;
            canChu = 1;
        }
    }
    else if (mode == 3){ //三不带
        int i = weigh(sma+1,12,3);
        if (i!=-1){
            cardOut[roun].cards[0] = cardStack[i];
            cardOut[roun].cards[1] = cardStack[i];
            cardOut[roun].cards[2] = cardStack[i];
            cardOut[roun].id = 1;
            rounds[roun] = 2;
            lChu[++lSize] = i;
            cntE[i]-=3;
            totE-=3;
            canChu = 1;
        }
    }
    else if (mode == 4){ //三带一
        int i = weigh(sma+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(0,14,1);
            if (j!=-1){
                cardOut[roun].cards[0] = cardStack[i];
                cardOut[roun].cards[1] = cardStack[i];
                cardOut[roun].cards[2] = cardStack[i];
                cardOut[roun].cards[3] = cardStack[j];
                cardOut[roun].id = 1;
                rounds[roun] = 3;
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
        int i = weigh(sma+1,12,4);
        if (i!=-1){
            sco*=2;
            cardOut[roun].cards[0] = cardStack[i];
            cardOut[roun].cards[1] = cardStack[i];
            cardOut[roun].cards[2] = cardStack[i];
            cardOut[roun].cards[3] = cardStack[i];
            cardOut[roun].id = 1;
            rounds[roun] = 3;
            lChu[++lSize] = i;
            cntE[i]-=4;
            totE-=4;
            canChu = 1;
        }
    }
    else if (mode == 6){ //三带二
        int i = weigh(sma+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(0,12,2);
            if (j!=-1){
                cardOut[roun].cards[0] = cardStack[i];
                cardOut[roun].cards[1] = cardStack[i];
                cardOut[roun].cards[2] = cardStack[i];
                cardOut[roun].cards[3] = cardStack[j];
                cardOut[roun].cards[4] = cardStack[j];
                cardOut[roun].id = 1;
                rounds[roun] = 4;
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
            int pos = 0;
            for (int i=mpos;i<=mpos+lenOU-1;i++){
                cardOut[roun].cards[pos++] = cardStack[i];
                cardOut[roun].id = 1;
                cntE[i]--;
                totE--;
            }
            rounds[roun] = pos-1;
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
                }
            }
        }
        if (mpos!=-1){
            int pos = 0;
            for (int i=mpos;i<=mpos+lenOU/2-1;i++){
                cardOut[roun].cards[pos++] = cardStack[i];
                cardOut[roun].cards[pos++] = cardStack[i];
                cardOut[roun].id = 1;
                cntE[i]-=2;
                totE-=2;
            }
            rounds[roun] = pos-1;
            lChu[++lSize] = mpos;
            cout<<endl;
            canChu = 1;
        }
    }
    else if (mode == 9){ //小飞机
        int i,j;
        if (plaType == 1) i = weigh(sma+1,10,6);
        else if (plaType == 2) i = weigh(sma+1,11,3);
        if (i!=-1){
            cntE[i]-=3;
            if (plaType == 1) j = i+1;
            else if (plaType == 2) j = weigh(sma+1,11,3);
            if (j!=-1){
                sco*=2;
                if (i>j) swap(i,j);
                cardOut[roun].cards[0] = cardStack[i];
                cardOut[roun].cards[1] = cardStack[i];
                cardOut[roun].cards[2] = cardStack[i];
                cardOut[roun].cards[3] = cardStack[j];
                cardOut[roun].cards[4] = cardStack[j];
                cardOut[roun].cards[5] = cardStack[j];
                cardOut[roun].id = 1;
                rounds[roun] = 5;
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
        int i = weigh(sma+1,12,4);
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
                    cardOut[roun].cards[0] = cardStack[i];
                    cardOut[roun].cards[1] = cardStack[i];
                    cardOut[roun].cards[2] = cardStack[i];
                    cardOut[roun].cards[3] = cardStack[i];
                    cardOut[roun].cards[4] = cardStack[j];
                    cardOut[roun].cards[5] = cardStack[j];
                    cardOut[roun].id = 1;
                    rounds[roun] = 5;
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
        if (plaType == 1) i = weigh(sma+1,10,6);
        else if (plaType == 2) i = weigh(sma+1,11,3);
        if (i!=-1){
            cntE[i]-=3;
            if (plaType == 1) j = i+1;
            else if (plaType == 2) j = weigh(sma+1,11,3);
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
                        cardOut[roun].cards[0] = cardStack[i];
                        cardOut[roun].cards[1] = cardStack[i];
                        cardOut[roun].cards[2] = cardStack[i];
                        cardOut[roun].cards[3] = cardStack[j];
                        cardOut[roun].cards[4] = cardStack[j];
                        cardOut[roun].cards[5] = cardStack[j];
                        cardOut[roun].cards[6] = cardStack[k];
                        cardOut[roun].cards[7] = cardStack[p];
                        cardOut[roun].id = 1;
                        rounds[roun] = 7;
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
        if (plaType == 1) i = weigh(sma+1,10,6);
        else if (plaType == 2) i = weigh(sma+1,11,3);
        if (i!=-1){
            cntE[i]-=3;
            if (plaType == 1) j = i+1;
            else if (plaType == 2) j = weigh(sma+1,11,3);
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
                        cardOut[roun].cards[0] = cardStack[i];
                        cardOut[roun].cards[1] = cardStack[i];
                        cardOut[roun].cards[2] = cardStack[i];
                        cardOut[roun].cards[3] = cardStack[j];
                        cardOut[roun].cards[4] = cardStack[j];
                        cardOut[roun].cards[5] = cardStack[j];
                        cardOut[roun].cards[6] = cardStack[k];
                        cardOut[roun].cards[7] = cardStack[k];
                        cardOut[roun].cards[8] = cardStack[p];
                        cardOut[roun].cards[9] = cardStack[p];
                        cardOut[roun].id = 1;
                        rounds[roun] = 9;
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
                if (lang == 1){
                    cout<<"要不起"<<endl;
                    cardOut[roun].cards[0] = "要不起";
                    cardOut[roun].id = 1;
                    rounds[roun] = 0;
                }
                else if (lang == 2){
                    cout<<"Can't afford"<<endl;
                    cardOut[roun].cards[0] = "Can't afford";
                    cardOut[roun].id = 1;
                    rounds[roun] = 0;
                }
                lMode = 0;
                lLen = 0;
            }
        }
        else{
            if (lang == 1){
                cout<<"要不起"<<endl;
                cardOut[roun].cards[0] = "要不起";
                cardOut[roun].id = 1;
                rounds[roun] = 0;
            }
            else if (lang == 2){
                cout<<"Can't afford"<<endl;
                cardOut[roun].cards[0] = "Can't afford";
                cardOut[roun].id = 1;
                rounds[roun] = 0;
            }
            lMode = 0;
            lLen = 0;
        }
    }
    else ifChun++;
    if (!lMode) return;
    if (lang == 1) printf("对手出了: ");
    else if (lang == 2) printf("Rival has put: ");
    for (int i=0;i<=rounds[roun];i++){
        cout<<cardOut[roun].cards[i]<<" ";
    }
}
void pre(){
    initBeat();
    int who = 0;
    if (lang == 1) printf("叫地主吗？: 1.3分 2.2分 3.1分 4.不叫\n");
    else if (lang == 2) printf("Want to be the Landlord?: 1.Very 2.Fine 3.Maybe 4.Definitely Not\n");
    char iwant;
    scanf("%s",&iwant);
    if (cl) clearScr();
    if ((iwant == 't' || iwant == 'T') && ifGod == 1){
        totM = 0;
        termi = 1;
        return;
    }
    iwant = iwant-'0';
    if (iwant == 1){
        if (lang == 1) printf("你叫到了地主!\n");
        else if (lang == 2) printf("You are the Landlord now!\n");
    }
    else if (iwant != 4){
        if (oppor>=6){
            if (lang == 1) printf("对手叫3分，抢地主\n");
            else if (lang == 2) printf("The Rival has a strong wish to be the landlord\n");
            sco*=3;
            who = 1;
        }
        else if (oppor>=4 && iwant == 3){
            if (lang == 1) printf("对手叫2分，抢地主\n你要抢吗？ 1.3分 2.不叫\n");
            else if (lang == 2) printf("The Rival want to get this position\nAre you going to fight for this? 1.Willing to 2.Not interested\n");
            scanf("%s",&iwant);
            iwant = iwant - '0';
            if (iwant == 1){
                if (lang == 1) printf("你叫到了地主!\n");
                else if (lang == 2) printf("You are the Landlord now!\n");
            }
            else{
                sco*=2;
                who = 1;
            }
        }
        else if (oppor<4){
            if (lang == 1) printf("你叫到了地主!\n");
            else if (lang == 2) printf("You are the Landlord now!\n");
        }
    }
    else{
        if (oppor>=6){
            if (lang == 1) printf("对手叫3分\n");
            else if (lang == 2) printf("The Rival has a strong wish to be the landlord.\n");
            sco*=3;
        }
        else if (oppor>=4){
            if (lang == 1) printf("对手叫2分\n");
            else if (lang == 2) printf("The Rival is interested in this position.\n");
            sco*=2;
        }
        else{
            if (lang == 1) printf("对手叫1分\n");
            else if (lang == 2) printf("The Rival gives it a try\n");
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
    if (lang == 1) cout<<"地主牌是: "<<cardStack[cntB[0]]<<" "<<cardStack[cntB[1]]<<" "<<cardStack[cntB[2]];
    else if (lang == 2) cout<<"Extra Cards for The Landlord: "<<cardStack[cntB[0]]<<" "<<cardStack[cntB[1]]<<" "<<cardStack[cntB[2]];
    printf("\n\n");
    if (lang == 1) printf("你的牌: ");
    else if (lang == 2) printf("Your Cards: ");
    for (int i=0;i<15;i++) for (int j=0;j<cntM[i];j++) cout<<cardStack[i]<<" ";
    if (lang == 1) printf("\n对手牌数: %d\n",totE);
    else if (lang == 2) printf("\nRival has %d cards\n",totE);
    if (ifGod == 1){
        if (lang == 1) printf("对手的牌: ");
        else if (lang == 2) printf("Rival's Cards: ");
        for (int i=0;i<15;i++){
            for (int j=0;j<cntE[i];j++){
                cout<<cardStack[i]<<" ";
            }
        }
        printf("\n");
    }
    int pos = 0;
    for (int i=0;i<15;i++){
        for (int j=0;j<cntE[i];j++){
            cardOut[roun].cards[pos] = cardStack[i];
            pos++;
        }
    }
    rounds[roun] = pos-1;
    roun++;
    pos = 0;
    for (int i=0;i<15;i++){
        for (int j=0;j<cntM[i];j++){
            cardOut[roun].cards[pos] = cardStack[i];
            pos++;
        }
    }
    rounds[roun] = pos-1;
    if (who == 1){
        roun++;
        mode = 11;
        beat2();
    }
    char t[10];
    gets(t);
    cout<<endl;
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
    if (totE<=3){
        if (lang == 1) printf("\n对手只有%d张牌了!\n",totE);
        else if (lang == 2) printf("\nBe aware! Rival only has %d cards now!\n",totE);
    }
    else {
        if (lang == 1) printf("\n对手牌数: %d\n",totE);
        else if (lang == 2) printf("\nRival has %d cards\n",totE);
    }
    if (ifGod == 1){
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
    }
    if (ifJiao == 0){
        ifJiao = 1;
        pre();
        if (termi) return;
    }
    char ou[105];
    cin.getline(ou,100);
    if (cl) clearScr();
    if (ou[0] == 'w'){
        creErr();
        cin.getline(uc,5);
        totM = 0;
        termi = 1;
        return;
    }
    if ((ou[0] == 't' || ou[0] == 'T' || ou[0] == 'e' || ou[0] == 'E') && ifGod == 1){
        totM = 0;
        termi = 1;
        return;
    }
    if (ou[0] == -46 || ou[0] == '0' || ou[0] == 'C' || ou[0] == 'c'){
        Ou[0] = -46;
        mode = 11;
        beat2();
        return;
    }
    lenOU = strlen(ou);
    if (lenOU == 0){
        if (lang == 1) printf("你还没有出牌\n");
        else if (lang == 2) printf("You have not put any cards yet\n");
        return;
    }
    int Size = -1,fakeLen = lenOU,tag,basket[105] = {},Cuo = 0;
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
            if (ou[i] == '2') Ou[++Size] = 12;
            else Ou[++Size] = ou[i] - '0' - 3;
        }
        else if (ou[i] == 'J' || ou[i] == 'j') Ou[++Size] = 8;
        else if (ou[i] == 'Q' || ou[i] == 'q') Ou[++Size] = 9;
        else if (ou[i] == 'K' || ou[i] == 'k'){
            if (i!=fakeLen-1){
                if (ou[i+1] == 'I' || ou[i+1] == 'i'){
                    Ou[++Size] = 14;
                    lenOU -= 3;
                    tag = 1;
                    i += 3;
                }
                else Ou[++Size] = 10;
            }
            else Ou[++Size] = 10;
        }
        else if (ou[i] == 'A' || ou[i] == 'a') Ou[++Size] = 11;
        else if (ou[i] == 'S' || ou[i] == 's'){
            Ou[++Size] = 13; //对应SMALL
            lenOU -= 4;
            i += 4;
        }
        else if (ou[i] == '1' && i+1<fakeLen){
            if (ou[i+1] == '0'){
                Ou[++Size] = 7; //对应10
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
            basket[Ou[Size]] += 1; // 负责计算最大相同数
            if (basket[Ou[Size]] > Max) Max = basket[Ou[Size]]; //需要将KING和SMALL包含进去
        }
        if (cntM[Ou[Size]] == 0){
            Cuo = 1;
            Size--;
            if (!ifGod) break;
        }
        else{
            cntM[Ou[Size]]--;
            totM--;
        }
    }
    if (!Cuo) sort(Ou,Ou+Size);
    int cont = 0,flag = 2;
    sma = 1000;
    for (int i=0;i<15;i++){
        if (basket[i]>=3) sma = min(sma,i);
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
        for (int i=0;i<=Size;i++){
            if (Ou[i] > lChu[lSize]){
                tmpcnt++;
            }
        }
        if (tmpcnt<lLen) Cuo = 1;
        if (mode == 13 && tmpcnt == 4) Cuo = 1;
    }
    if (ifGod) Cuo = 0;
    if (Cuo == 1){
        for (int i=Size;i>=0;i--){
            cntM[Ou[Size--]]++;
            totM++;
        }
        if (lang == 1) printf("牌出错了\n");
        else if (lang == 2) printf("Wrong Card!\n");
        if (roun == 1) return;
        if (lang == 1) printf("对手出了: ");
        else if (lang == 2) printf("Rival has put: ");
        for (int i=0;i<=rounds[roun];i++){
            cout<<cardOut[roun].cards[i]<<" ";
        }
        return;
    }
    roun++;
    int flen = strlen(ou);
    for (int i=0;i<=Size;i++){
        cardOut[roun].cards[i] = cardStack[Ou[i]];
    }
    cardOut[roun].id = 2;
    rounds[roun] = lenOU;
    roun++;
    if (totM == 0){
        if (mode == 5 || mode == 12) sco*=2;
        else if (mode == 13) sco*=3;
        else if (mode == 2 && boKing == 1){
            sco*=4;
        }
        return;
    }
    else{
        beat2();
    }
}
void about(){
    if (lang == 1) printf("发行日期: 2/10/2023\n");
    else if (lang == 2) printf("Release Date: 2/10/2023\n");
    if (lang == 1) printf("版本信息: 1.0.2\n");
    else if (lang == 2) printf("Version: 1.0.2\n");
    if (lang == 1) printf("长期服务版本\n");
    else if (lang == 2) printf("LTS(Long Time Service) Channel\n");
    printf("\n");
    if (lang == 1) printf("此程序受MIT许可证约束\n");
    else if (lang == 2) printf("This program is shared and protected under the MIT License\n");
    printf("Copyright(c)2023 Bowen Wan\n");
    printf("\n");
    if (lang == 1) printf("如果你遇到了任何问题，请联系开发者\n项目主页: www.github.com/bowenOne580/Onegit\nQQ: 2797269898\n");
    else if (lang == 2) printf("If you come across any error(s), please feel free to contact with the developer\nProject Homepage: www.github.com/bowenOne580/Onegit\nQQ: 2797269898\n");
    nextPage();
    return;
}
void language(){
    printf("1.中文\n2.English\n");
    scanf("%d",&lang);
    if (cl) clearScr();
}
void option(){
    if (lang == 1) printf("1.上帝模式: ");
    else if (lang == 2) printf("1.God Mode: ");
    if (ifGod == 0){
        if (lang == 1) printf("禁用\n");
        else if (lang == 2) printf("Disabled\n");
    }
    else{
        if (lang == 1) printf("启用\n");
        else if (lang == 2) printf("Enabled\n");
    }
    if (lang == 1) printf("2.难度: ");
    else if (lang == 2) printf("2.Difficulty: ");
    if (dif == 1){
        if (lang == 1) printf("简单\n");
        else if (lang == 2) printf("Easy\n");
    }
    else if (dif == 2){
        if (lang == 1) printf("增强型\n");
        else if (lang == 2) printf("Enhanced\n");
    }
    if (lang == 1) printf("3.飞机模式：");
    else if (lang == 2) printf("3.Plane Type: ");
    if (plaType == 1){
        if (lang == 1) printf("经典\n");
        else if (lang == 2) printf("Classic\n");
    }
    else if (plaType == 2){
        if (lang == 1) printf("宽泛\n");
        else if (lang == 2) printf("Loose\n");
    }
    if (lang == 1) printf("4.显示模式：");
    else if (lang == 2) printf("4.Display Mode:");
    if (cl == 1){
        if (lang == 1) printf("简短\n");
        else if (lang == 2) printf("Short\n");
    }
    else if (cl == 0){
        if (lang == 1) printf("完整\n");
        else if (lang == 2) printf("Complete\n");
    }
    if (lang == 1) printf("5.重置游戏\n");
    else if (lang == 2) printf("5.Reset Game\n");
    if (lang == 1) printf("6.返回\n");
    else if (lang == 2) printf("6.Back\n");
    scanf("%d",&usc);
    if (cl) clearScr();
    if (usc == 1){
        if (lang == 1) printf("1.启用 2.禁用\n");
        else if (lang == 2) printf("1.Enable 2.Disable\n");
        scanf("%d",&ifGod);
        if (ifGod != 1) ifGod = 0;
    }
    else if (usc == 2){
        if (lang == 1) printf("1.简单 2.增强型\n");
        else if (lang == 2) printf("1.Easy 2.Enhanced\n");
        scanf("%d",&dif);
    }
    else if (usc == 3){
        if (lang == 1) printf("1.经典(只能出连着的牌) 2.宽泛(只要牌型一样即可)\n");
        else if (lang == 2) printf("1.Classic(The cards must be continuous) 2.Loose(As long as it fits the style of Classic)\n");
        scanf("%d",&plaType);
    }
    else if (usc == 4){
        if (lang == 1) printf("1.简短 2.完整\n");
        else if (lang == 2) printf("1.Short 2.Complete\n");
        scanf("%d",&cl);
        if (cl == 2) cl = 0;
    }
    else if (usc == 5){
        if (lang == 1) printf("你真的想要删除所有数据吗?\n1.是  2.否\n");
        else if (lang == 2) printf("Do you really want to delete all your data?\n1.Yes  2.No\n");
        scanf("%d",&usc);
        if (usc == 1) Back();
    }
    printf("\n");
    if (cl) clearScr();
}
void stat(){
    if ((win+lose) != 0) rating = int((double(win)/(win+lose))*100);
    if (lang == 1){
        printf("你的总点数: %lld\n",money);
        printf("最高分数: %d\n",hisco);
        printf("总胜局数: %d\n",win);
        printf("总败局数: %d\n",lose);
        printf("胜率: %d",rating);
    }
    else if (lang == 2){
        printf("Your credits: %lld\n",money);
        printf("Highest score: %d\n",hisco);
        printf("You win for %d times\n",win);
        printf("But you lose for %d times\n",lose);
        printf("Possibility of Winning: %d",rating);
    }
    puts("%");
    nextPage();
}
void runPro(){
    writeVars();
    ifJiao = 0;
    if (cl) clearScr();
    if (lang == 1) printf("1.开始\n2.语言/Language\n3.生成错误报告\n4.选项\n5.统计\n6.关于\n7.退出\n");
    else if (lang == 2) printf("1.Start\n2.Language/语言\n3.Create Error Report\n4.Options\n5.Statistics\n6.About\n7.Quit\n");
    scanf("%d",&usercho);
    if (cl) clearScr();
    if (usercho == 1){
        Clear();
        ran(); //发牌和排序函数
        while (totM > 0 && totE > 0) ingame();
        if (termi){
            if (lang == 1) printf("你已提前终止此局游戏，分数将不会被记录\n");
            else if (lang == 2) printf("You have terminated this game earlier than expected, the scores made in this game won't be recorded.\n");
            cin.getline(uc,4);
            if (cl) clearScr();
            return;
        }
        if (ifChun == 1){
            chun++;
            sco*=2;
        }
        if (totM == 0){
            win++;
            if (lang == 1) printf("你赢了!\n你的得分: %d\n",sco);
            else if (lang == 2) printf("You Win!\nYour Score: %d\n",sco);
            if (edi != 'z') money+=sco;
            else money-=10000000;
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
        gets(uc);
    }
    else if (usercho == 2) language();
    else if (usercho == 3){
        creErr();
        getchar();
        cin.getline(uc,10);
    }
    else if (usercho == 4) option();
    else if (usercho == 5) stat();
    else if (usercho == 6) about();
}
int main(){
    readVars();
    while (usercho!=7) runPro();
    return 0;
}
