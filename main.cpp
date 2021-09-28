#include<bits/stdc++.h>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int Max,cntE[20],cntM[20],cntB[5],totM = 17,totE = 17,mode,lMode,boKing,sco = 100,hisco = 0;
int lChu[100],lSize,ifChun = 1,lLen,lang = 1,ifGod,dif = 2,ifJiao = 0,win,lose;
int chun,lenColl[20],maxPage = 7,tri[20],bomb[20],useful[20],dou[20],si[20],kingsman[2],oppor,speGame;
int haDou,haSin,plaType = 1,calcThree[20],termi,usercho,rating,sma,roun,rounds[105],cl = 1;
int cntAch = 20;
char edi = 'n';
long long money = 3000;
struct carO{
    string cards[25];
    int id;
} cardOut[105];
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING"};
string achCNStack[25] = {
        "","春天到了","第一场胜仗","常胜将军","无坚不摧","胜败乃兵家常事","即生瑜，何生亮","小康","富翁","富可敌国",
        "富到无法用int衡量","负翁","金融危机","濒临破产","从头开始","春意盎然","斗地主一岁了!","E32021特别庆祝","剁手快乐"};
string achENStack[25] = {
        "","The East Wind Is Coming","First Victory!","It's A Piece Of Cake To Beat You","A Winner Of All Time",
        "It's Easier To Fail Than To Success","Is The Robot Smarter Than Me?","Can Afford!","Billionare","Richer Than America(Not China)",
        "Can't Be Measured By Int","Rich In Abs Value","Financial Crysis","Running Out Of Money","Start Again!","Can Feel Spring In The Air Now!",
        "I Am 1 Year Old!","Special Celebration For E32021","Happy Shopping on Steam Summer Sale 2021!"};
string descripCN[25] = {
        "","达成1局春天","获得1场胜利","获得10场胜利","获得50场胜利","被打败5次","被打败20次","总点数超过10000","总点数超过30000","总点数超过500000",
        "总点数超过2147480000","总点数低于-10000","总点数低于-50000","总点数低于-1000000","点数过低，重置程序","完成20次春天","在一周年庆版本中完成5局游戏",
        "在E3特别版中完成1局游戏","在夏促特别版中完成10局游戏"};
string descripEN[25] = {
        "","Do Spring in 1 game(You can find the description of Spring in Help->Rules)","Win for the first time","Win for 10 times","Win for 50 times","Defeated for 5 times","Defeated for 20 times",
        "Get 10000 credits","Get 30000 credits","Get 500000 credits","Get 2147483647 credits","Lower than -10000 credits","Lower than -50000 credits",
        "Lower than -1000000 credits","Credits are getting too low, so that I have to reset it for you","Do 20 Springs",
        "Finish 5 games in the 1st Anniversary Edition","Finish one game in E3 Special Edition","Finish 10 games in Steam Summer Sale Special Edition"};
string achMonCN[20] = {"元","二","三","四","五","六","七","八","九","十","十一","十二"};
string achMonEN[20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
struct acheivement{
    int ifGet,day,mon,yr;
} ach[1005];
void readVars(){
    ifstream input("data.txt");
    input>>money>>hisco>>lang>>ifGod>>win>>lose>>dif;
    //已使用18个
    for (int i = 1;i <= cntAch;i++) input>>ach[i].ifGet>>ach[i].day>>ach[i].mon>>ach[i].yr;
    input>>speGame>>plaType>>rating>>cl;
    if (edi == 'n') speGame = 0;
    input.close();
}
void writeVars(){
    ofstream output;
    output.open("data.txt");
    output<<money<<endl<<hisco<<endl<<lang<<endl<<ifGod<<endl<<win<<endl<<lose<<endl<<dif<<endl;
    for (int i=1;i<=cntAch;i++) output<<ach[i].ifGet<<" "<<ach[i].day<<" "<<ach[i].mon<<" "<<ach[i].yr<<endl;
    output<<speGame<<endl<<plaType<<endl<<rating<<endl<<cl<<endl;
    output.close();
}
void clearScr(){
    system("cls");
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
    for (int i=1;i<=cntAch;i++) ach[i].ifGet = 0;
}
void nextPage(){
    char uc[10];
    getchar();
    cin.getline(uc,10);
    if (cl) clearScr();
}
void initBeat(){ //未优化
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
int calc(){ //未优化
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
int Save(){ //未优化
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
void beat(){
    if (lang == 1) printf("请等待新出牌系统推出，你现在可以切换到增强版\n");
    else if (lang == 2) printf("Please wait for the new putting system, you can use Enhanced DIfficulty setting instead\n");
}
int weigh(int left,int right,int length){ //未优化
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
void selfOut(){ //未优化
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
            int i = weigh(0,12,2);
            if (i!=-1){
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
                int i = weigh(0,14,1);
                if (i!=-1){
                    cardOut[roun].cards[0] = cardStack[i];
                    cardOut[roun].id = 1;
                    rounds[roun] = 0;
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
void beat2(){ //急需优化
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
        if (dif == 1) beat();
        else if (dif == 2) beat2();
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
        char uc[10];
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
        if (dif == 1) beat();
        else if (dif == 2) beat2();
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
        if (dif == 1) beat();
        else if (dif == 2) beat2();
    }
}
void rules(){
    int uc = 0;
    while (uc!=16){
        if (uc!=0) nextPage();
        if (lang == 1) printf("想要查询哪个规则?\n");
        else if (lang == 2) printf("Which rule do you want to learn about?\n");
        if (lang == 1) printf("1.单牌\n2.对子\n3.三不带\n4.三带一\n5.三带二\n6.炸弹\n7.小飞机\n8.中飞机\n9.大飞机\n10.顺子\n11.连对\n12.四带二\n13.牌的大小\n14.决出胜负\n15.春天\n16.返回\n");
        else if (lang == 2) printf("1.Single Card\n2.Double Cards\n3.Triple Cards\n4.Three And One\n5.Three And Two\n6.Bomb\n7.Micro Plane\n8.Middle Plane\n9.Big Plane\n10.Silk Road\n11.Silk Road on Sea\n12.Gone With The Bomb\n13.Card Compare\n14.Winner Or Loser\n15.Spring\n16.Back\n");
        scanf("%d",&uc);
        if (cl) clearScr();
        if (uc == 1){
            if (lang == 1) printf("1.单牌：你可以出比对手的牌数值更大的1张牌\n");
            else if (lang == 2) printf("1.Single Card: You can put 1 card that is strictly bigger than Rival's\n");
        }
        else if (uc == 2){
            if (lang == 1) printf("2.对子：你可以出比对手的牌数值更大的2张牌，但它们在数值上必须相等\n");
            else if (lang == 2) printf("2.Double Cards: You can put 2 cards with the same point, and they are strictly bigger than Rival's\n");
        }
        else if (uc == 3){
            if (lang == 1) printf("3.三不带：你可以出比对手牌值更大的三张牌，但它们在数值上必须相等\n");
            else if (lang == 2) printf("3.Triple Cards: You can put 3 cards with the same point, and they are strictly bigger than Rival's\n");
        }
        else if (uc == 4){
            if (lang == 1) printf("4.三带一：你可以出4张牌，其中三张牌的数值必须相同且大于对手所出的三张牌的数值\n");
            else if (lang == 2) printf("4.Three Plus One: You can put 3 cards with the same point, and they are strictly bigger than Rival's,the other one can be anything you like\n");
        }
        else if (uc == 5){
            if (lang == 1) printf("5.三带二：你可以出5张牌，其中包含3张一样的和一个对子\n");
            else if (lang == 2) printf("5.Three Plus Two: You can put 5 cards, three of them is like that of Triple Cards, and they are strictly bigger than Rival's, the other two is like a Double Cards\n");
        }
        else if (uc == 6){
            if (lang == 1) printf("6.炸弹：分为两种，王炸和四张相同的牌，王炸指SMALL+KING。炸弹可以压过所有不是炸弹的牌，数值更大的炸弹可以压过小的，王炸可以压过任意牌\n");
            else if (lang == 2) printf("6.Bomb：It can be 4 cards that have the same point, if the Rival put a bomb, they must be strictly bigger than Rival's bomb. SMALL+KING is also a bomb, which is the biggest cards in this game\n");
        }
        else if (uc == 7){
            if (lang == 1) printf("7.小飞机：你可以出6张牌，其中包含两组3张一样的且牌数差为1\n");
            else if (lang == 2) printf("7.Micro Plane: You can put 6 cards, which contain two sets of Three Cards\n");
        }
        else if (uc == 8){
            if (lang == 1) printf("8.中飞机：你可以出8张牌，包含一个小飞机和任意两张牌\n");
            else if (lang == 2) printf("8.Middle Plane: You can put 8 cards, which contain a Micro Plane and two cards of whatever you like\n");
        }
        else if (uc == 9){
            if (lang == 1) printf("9.大飞机：你可以出10张牌，其中包含一个小飞机和两个对子\n");
            else if (lang == 2) printf("9.Big Plane: You can put 10 cards, contain a Micro Plane and two sets of Double Cards\n");
        }
        else if (uc == 10){
            if (lang == 1) printf("10.顺子：你可以出大于等于5张牌，其中每张牌间的差为1\n");
            else if (lang == 2) printf("10.Silk Road：You can put 5 or more than 5 cards, the difference of every two continuous cards must be the same\n");
        }
        else if (uc == 11){
            if (lang == 1) printf("11.连对：你可以出大于6张牌，其中包含3个以上的对子，且每个对子间的差为1\n");
            else if (lang == 1) printf("11.Silk Road on Sea：You can put more than 3 Double Cards, the difference of every two continuous Double Cards must be the same\n");
        }
        else if (uc == 12){
            if (lang == 1) printf("12.四带二：你可以出一个炸弹外加两张单牌或两个对子\n");
            else if (lang == 2) printf("12.Gone With The Bomb: A bomb and two Single Card or two Double Cards\n");
        }
        else if (uc == 13){
            if (lang == 1) printf("13.牌的大小：3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < J < Q < K < A < 2 < SMALL < KING\n");
            else if (lang == 2) printf("13.Cards Compare: 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < J < Q < K < A < 2 < SMALL < KING\n");
            if (lang == 1) printf("           炸弹大于任何不是炸弹的牌，王炸最大\n");
            else if (lang == 2) printf("                  Bomb is bigger than any cards that are not Bomb, but SMALL+KING is the biggest among all cards\n");
            if (lang == 1) printf("           如果你没有更大的牌，请出‘要不起’或‘0’\n");
            else if (lang == 2) printf("                  If you don't have a bigger one, please put ‘Can't afford’ or ‘0’\n");
        }
        else if (uc == 14){
            if (lang == 1) printf("14.决出胜负：如果一方先把所有牌出完，即胜利\n");
            else if (lang == 2) printf("14.Winner Or Loser: If you put all your cards earlier than Rival, you win, otherwise you lose\n");
        }
        else if (uc == 15){
            if (lang == 1) printf("15.春天：如果你是地主，并且一次性将所有牌都出完，对手没有一次出牌机会，将获得春天加倍奖励\n");
            else if (lang == 2) printf("15.Spring: If you are the landlord and put all of you cards in a row so that the Rival can't get any chance to put any cards, you do a Spring, and you will get bonus for it\n");
            if (lang == 1) printf("        如果你是农名，并且只让对手出了一次牌，你将获得同样得奖励\n");
            else if (lang == 2) printf("           If you aren't a Landlord and only give one chance to the Rival, youn will receive the same bonus\n");
        }
    }
    return;
}
void sett(){ //待完善
    int uc = 0;
    while (uc!=4) {
        if (uc != 0) nextPage();
        if (lang == 1) printf("想要查询哪个设置?\n");
        else if (lang == 2) printf("Which setting do you want to learn about?\n");
        if (lang == 1) printf("1.上帝模式\n2.难度\n3.飞机模式\n4.返回\n");
        else if (lang == 2) printf("1.God Mode\n2.Difficulty\n3.Plane Mode\n4.Back\n");
        scanf("%d",&uc);
        if (cl) clearScr();
        if (uc == 1){
            if (lang == 1) printf("1.上帝模式：可以看见对手的牌，无视出牌中的错误，并且可以用‘t’终止游戏\n");
            else if (lang == 2) printf("1.God Mode: If enabled, you can see The Rival's cards, ignore any kind of error in putting, and you can even use 't' to terminate current game\n");
        }
        else if (uc == 2){
            if (lang == 1) printf("2.难度：简单难度下，对手只会进行最基本的接牌、出牌；而增强型出牌可以让对手更有策略性，择优接牌，尽多出牌\n");
            else if (lang == 2) printf("2.Difficulty: In easy mode,The Rival only put and take the smallest cards; but enhanced mode let The Rival use some strategies, take least costing cards and put cards as much as possible\n");
        }
        else if (uc == 3){
            if (lang == 1) printf("3.飞机模式：在选项中已进行详述，在此不再赘述\n");
            else if (lang == 2) printf("3.Plane Mode: There are descriptions in Options, please go there for more details\n");
        }
    }
}
void hel(){
    if (lang == 1) printf("1.游戏规则 2.各项设置 3.返回\n");
    else if (lang == 2) printf("1.Rules 2.Settings 3.Back\n");
    int uc;
    scanf("%d",&uc);
    if (cl) clearScr();
    if (uc == 1) rules();
    else if (uc == 2) sett();
    if (uc == 3) return;
    else hel();
}
void about(){ //可以用数组表示edition以使代码更美观
    if (lang == 1) printf("发行日期: 9/28/2021\n");
    else if (lang == 2) printf("Release Date: 9/28/2021\n");
    if (lang == 1) printf("版本信息: 2.4.0 ");
    else if (lang == 2) printf("Version: 2.4.0 ");
    if (edi == 'n'){
        if (lang == 1) printf("正式版\n");
        else if (lang == 2) printf("Stable Channel\n");
    }
    else if (edi == 'b'){
        if (lang == 1) printf("测试版\n");
        else if (lang == 2) printf("Beta Channel\n");
    }
    else if (edi == 'a'){
        if (lang == 1) printf("周年纪念版\n");
        else if (lang == 2) printf("Anniversary Edition\n");
    }
    else if (edi == 'e'){
        if (lang == 1) printf("E32021特别版\n");
        else if (lang == 2) printf("E32021 Special Edition\n");
    }
    else if (edi == 's'){
        if (lang == 1) printf("Steam2021夏促特别版\n");
        else if (lang == 2) printf("Steam Summer Sale 2021 Special Edition\n");
    }
    else if (edi == 'g'){
        if (lang == 1) printf("7.6告别版\n");
        else if (lang == 2) printf("July 6th Say Goodbye Edition\n");
    }
    printf("\n");
    if (lang == 1) printf("此程序受MIT许可证约束\n");
    else if (lang == 2) printf("This program is shared and protected under the MIT License\n");
    printf("Copyright(c)2021 Bowen Wan\n");
    printf("\n");
    if (lang == 1) printf("如果你遇到了任何问题，请联系开发者\n项目主页: www.github.com/bowenOne580/Onegit\nQQ: 2797269898\n");
    else if (lang == 2) printf("If you come across any error(s), please feel free to contact with the developer\nProject Homepage: www.github.com/bowenOne580/Onegit\nQQ: 2797269898\n");
    nextPage();
    return;
}
void acheive(){ //需要重新设计页面
    if (lang == 1) printf("你已达成的成就:\n");
    else if (lang == 2) printf("The achievements you have reached:\n");
    int f = 0;
    for (int i=1;i<=18;i++){
        if (ach[i].ifGet == 1){
            if (lang == 1) cout<<achCNStack[i]<<endl;
            else if (lang == 2) cout<<achENStack[i]<<endl;
            if (lang == 1){
                printf("解锁时间: %d年",ach[i].yr);
                cout<<achMonCN[ach[i].mon]<<"月"<<ach[i].day<<"日"<<endl;
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
            if (lang == 1) cout<<"你曾经: "<<descripCN[i]<<endl<<endl;
            else if (lang == 2) cout<<"You once: "<<descripEN[i]<<endl<<endl;
            printf("\n");
            f = 1;
        }
    }
    if (!f){
        if (lang == 1) printf("无\n\n");
        else if (lang == 2) printf("None\n\n");
    }
    f = 0;
    if (lang == 1) printf("按任意键以继续查看\n");
    else if (lang == 2) printf("Press any key to access more information\n");
    char uc2[10];
    gets(uc2);
    cin.getline(uc2,10);
    printf("\n");
    if (lang == 1) printf("未解锁的成就:\n");
    else if (lang == 2) printf("Locked Achievements:\n");
    for (int i=1;i<=18;i++){
        if (ach[i].ifGet == 0){
            if (lang == 1) cout<<achCNStack[i]<<endl<<"解锁条件: "<<descripCN[i]<<endl<<endl;
            else if (lang == 2) cout<<achENStack[i]<<endl<<"Unlock Way: "<<descripEN[i]<<endl<<endl;
            f = 1;
        }
    }
    if (!f){
        if (lang == 1) printf("祝贺!你已解锁全部成就!\n\n");
        else if (lang == 2) printf("Congratulations! You have unlocked all of them!\n\n");
    }
    char uc[10];
    cin.getline(uc,10);
    printf("\n");
    if (cl) clearScr();
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
    int uc;
    scanf("%d",&uc);
    if (cl) clearScr();
    if (uc == 1){
        if (lang == 1) printf("1.启用 2.禁用\n");
        else if (lang == 2) printf("1.Enable 2.Disable\n");
        scanf("%d",&ifGod);
        if (ifGod != 1) ifGod = 0;
    }
    else if (uc == 2){
        if (lang == 1) printf("1.简单 2.增强型\n");
        else if (lang == 2) printf("1.Easy 2.Enhanced\n");
        scanf("%d",&dif);
    }
    else if (uc == 3){
        if (lang == 1) printf("1.经典(只能出连着的牌) 2.宽泛(只要牌型一样即可)\n");
        else if (lang == 2) printf("1.Classic(The cards must be continuous) 2.Loose(As long as it fits the style of Classic)\n");
        scanf("%d",&plaType);
    }
    else if (uc == 4){
        if (lang == 1) printf("1.简短 2.完整\n");
        else if (lang == 2) printf("1.Short 2.Complete\n");
        scanf("%d",&cl);
        if (cl == 2) cl = 0;
    }
    else if (uc == 5){
        if (lang == 1) printf("你真的想要删除所有数据吗?\n1.是  2.否\n");
        else if (lang == 2) printf("Do you really want to delete all your data?\n1.Yes  2.No\n");
        scanf("%d",&uc);
        if (uc == 1) Back();
    }
    printf("\n");
    if (cl) clearScr();
}
void markAch(int i){
    if (lang == 1) cout<<"你已达成: "<<achCNStack[i]<<"!"<<endl;
    else if (lang == 2) cout<<"You have just reached an achievement: "<<achENStack[i]<<"!"<<endl;
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
    puts("%\n");
    if (!ifGod){
        if (lang == 1) printf("凡人无法看见此界面上的更多内容\n\n");
        else if (lang == 2) printf("Only God can have access to this page\n\n");
        char uc[10];
        gets(uc);
        cin.getline(uc,10);
        printf("\n");
        if (cl) clearScr();
        return;
    }
    if (lang == 1) printf("1.修改点数\n2.修改成就达成情况\n3.返回\n");
    else if (lang == 2) printf("1.Modify Credits\n2.Modify Acheivements\n3.Back\n");
    long long uc;
    scanf("%lld",&uc);
    if (cl) clearScr();
    if (uc == 1){
        if (lang == 1) printf("想要修改为: ");
        else if (lang == 2) printf("Want to change to: ");
        scanf("%lld",&uc);
        money = uc;
    }
    else if (uc == 2){
        if (lang == 1) printf("修改哪一项成就?(0表示全选)\n");
        else if (lang == 2) printf("Change which acheivement?(0 stands for ALL)\n");
        scanf("%lld",&uc);
        int uc2;
        if (uc > 0 && uc<=16){
            if (lang == 1) printf("修改为(1为已达成，0为未达成): ");
            else if (lang == 2) printf("Change to(1 for acheived, 0 for locked):");
            scanf("%d",&uc2);
            if (uc2) markAch(uc);
            else ach[uc].ifGet = 0;
        }
        else if (uc == 0){
            if (lang == 1) printf("修改为(1为已达成，0为未达成): ");
            else if (lang == 2) printf("Change to(1 for acheived, 0 for locked):");
            scanf("%d",&uc2);
            for (int i=1;i<=16;i++){
                if (uc2) markAch(i);
                else ach[i].ifGet = 0;
            }
        }
        else{
            while (uc>16 || uc<0){
                if (lang == 1) printf("暂无此成就，请仔细核对\n\n");
                else if (lang == 2) printf("This achievement is not available, please check your input carefully\n\n");
                if (lang == 1) printf("修改哪一项成就?(0表示全选)\n");
                else if (lang == 2) printf("Change which acheivement?(0 stands for ALL)\n");
                scanf("%lld",&uc);
            }
            int uc2;
            if (lang == 1) printf("修改为(1为已达成，0为未达成): ");
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
        if (lang == 1) printf("发布时间:2021.6.13 17:42\n");
        else if (lang == 2) printf("Post Time:6/13/2021 17:42\n");
        if (lang == 1) printf("公告页面已上线!\n");
        else if (lang == 2) printf("Notice Board is out now!\n");
    }
    else if (i == 2){
        if (lang == 1) printf("发布时间:2021.6.13 17:45\n");
        else if (lang == 2) printf("Post Time:6/13/2021 17:45\n");
        if (lang == 1) printf("E32021现已开幕\n参展地址:\nhttps://www.bilibili.com/blackboard/activity-E32021.html\nhttps://e3expo.com/watch (可能要代理)\n");
        else if (lang == 2) printf("E32021 is open to watch now!\nAttend on Website:\nhttps://www.bilibili.com/blackboard/activity-E32021.html\nhttps://e3expo.com/watch (Might need proxy in China)\n");
    }
    else if (i == 3){
        if (lang == 1) printf("发布时间:2021.6.13 18:36\n");
        else if (lang == 2) printf("Post Time:6/13/2021 18:36\n");
        if (lang == 1) printf("E3特别版本发布!献给所有热爱游戏的人!\n特别成就已可用，请在成就界面中查看\n");
        else if (lang == 2) printf("E3 Special Edition out now!For Gamers!\nSpecial Acheivement is available, please check out in Acheivements\n");
    }
    else if (i == 4){
        if (lang == 1) printf("发布时间:2021.6.16 19:48\n");
        else if (lang == 2) printf("Post Time:6/16/2021 19:49\n");
        if (lang == 1) printf("E3特别活动现已结束\n中考临近，暂时发布一个小更新，预祝所有2110班的同学中考顺利!\n");
        else if (lang == 2) printf("E3 Special Event has ended\nThe Final Test is coming, I will just update the program by little, hope everyone in Class 2110 will get the best grade!\n");
    }
    else if (i == 5){
        if (lang == 1) printf("发布时间:2021.6.24 0:18\n");
        else if (lang == 2) printf("Post Time:6/24/2021 0:18\n");
        if (lang == 1) printf("重大版本更新:出牌系统升级\n这也就意味着机器人将能辨别出牌的优劣，选择简单且适合的策略！\n但是，几乎每一次重大更新，都伴随着大大小小的bug，增强型出牌方式仅供测试，如有问题，还请谅解。\n如果你真的碰到了问题，请查看支持界面。\n");
        else if (lang == 2) printf("Major Update: Upgrade The Card-Putting System\nThis means the Rival can now tell the difference among some strategies!\nBut, unfrotunately, there are many bugs in this enhanced system.\nIf you come across some unexpected errors, please go to the Support page on start-up.\n");
    }
    else if (i == 6){
        if (lang == 1) printf("发布时间:2021.6.24 23:12\n");
        else if (lang == 2) printf("Post Time:6/24/2021 23:12\n");
        if (lang == 1) printf("Steam夏促将于6.25日开始！\n特别活动已上线，新的成就将能获取，祝各位剁手快乐！\n25日 16:24更新：夏促界面https://store.steampowered.com/ 力度貌似不是很大，但还是有很多值得购买的\n");
        else if (lang == 2) printf("The Steam Summer Sale 2021 is starting on June 25!\nSpecial event is open now, new achievement is added, happy shopping everybody!\nUpdate on 6/25 16:24 Sale Pagehttps://store.steampowered.com/ Not much, but you can still find good games with delicious discount to buy\n");
    }
    else if (i == 7){
        if (lang == 1) printf("发布时间:2021.7.6 16:13\n");
        else if (lang == 2) printf("Post Time:7/6/2021 16:13\n");
        if (lang == 1) printf("重大通知:\n由于现在我正处于学习中的重要节点，无论校内还是编程，又考虑到对此游戏的策略优化已接近瓶颈，故决定暂时停止更新\n经过两周的修复与完善，许多发布新出牌系统初期的问题得到了解决，我也从中获益良多，我相信这个版本在质量上已趋于完美，无需更多的完善，便选择在此停止更新\n不过，如果你有任何建议或碰见什么问题，你可以联系我，我会将其分类放好，为之后的更新做准备\n在人生长河中，我们需要及时放下，在未来才能更好前进\n");
        else if (lang == 2) printf("Attention!\nSince I am between a rock and a hard place, things just rush to me in a second, considering I have nothing to do with making this game better, I have to say, I decide to put it aside for a while\nWhen the new putting system appeared, many problems came along, after two weeks of hard work, there are no longer any visible problems, so I decide to leave this game alone\nIf you have any questions or suggestions, please feel good to contact me, I won't deal with it right away, but I will put them carefully for future updates\nThe life is long, but we need to give up something in the right time, I believe this will lead a better future.\n");
    }
}
void notboard(){ //未优化
    int uc = 4,page = 7,ifRead = 1;
    while (uc!=3){
        if (cl) clearScr();
        if (uc == 2){
            if (page>=maxPage){
                if (lang == 1) printf("已是最前一页!\n");
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
                if (lang == 1) printf("已是最后一页!\n");
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
        if (lang == 1) printf("1.下一页 2.上一页 3.退出\n");
        else if (lang == 2) printf("1.Next Page 2.Previous Page 3.Quit\n");
        scanf("%d",&uc);
    }
}
void runPro(){
    writeVars();
    ifJiao = 0;
    if (cl) clearScr();
    if (lang == 1) printf("1.开始\n2.语言/Language\n3.生成错误报告\n4.选项\n5.公告\n6.成就\n7.统计\n8.帮助\n9.关于\n10.退出\n");
    else if (lang == 2) printf("1.Start\n2.Language/语言\n3.Create Error Report\n4.Options\n5.Notice\n6.Acheivements\n7.Statistics\n8.Help\n9.About\n10.Quit\n");
    scanf("%d",&usercho);
    if (cl) clearScr();
    if (usercho == 1){
        Clear();
        ran(); //发牌和排序函数
        while (totM > 0 && totE > 0) ingame();
        if (termi){
            if (lang == 1) printf("你已提前终止此局游戏，分数将不会被记录\n");
            else if (lang == 2) printf("You have terminated this game earlier than expected, the scores made in this game won't be recorded.\n");
            char uc[4];
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
        if (edi!='n') speGame++;
        checkach();
        char uc[2];
        gets(uc);
    }
    else if (usercho == 2) language();
    else if (usercho == 3){
        creErr();
        char uc[10];
        getchar();
        cin.getline(uc,5);
    }
    else if (usercho == 4) option();
    else if (usercho == 5) notboard();
    else if (usercho == 6) acheive();
    else if (usercho == 7) stat();
    else if (usercho == 8) hel();
    else if (usercho == 9) about();
}
int main(){
    readVars();
    while (usercho != 10) runPro();
    return 0;
}
