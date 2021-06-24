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
int lChu[100],lSize,ifChun = 1,lLen,lang = 1,ifGod,dif = 2,ifJiao = 0,win,lose;
int chun,lenColl[20],maxPage = 5,tri[20],bomb[20],useful[20],dou[20],si[20],kingsman[2],oppor;
int haDou,haSin;
char edi = 'n';
long long money = 3000;
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING",};
string achCNStack[25] = {"","春天到了","第一场胜仗","常胜将军","无坚不摧","胜败乃兵家常事","即生瑜，何生亮","小康","富翁","富可敌国","富到无法用int衡量","负翁","金融危机","濒临破产","从头开始","春意盎然","斗地主一岁了!","E32021特别庆祝"};
string achENStack[25] = {"","The East Wind is coming","First Victory!","It's a piece of cake","A winner of all times","It's easy to fail than success","Is the robot smarter than me?","Can afford!","Billionare","Richer than America(Not China)","Can't be measured by int","Rich in abs","Financial crysis","Get close to break","Start again!","You can touch the spring in the air","I am 1 year old!","Special Celebration for E32021"};
string descripCN[25] = {"","达成1局春天","获得1场胜利","获得10场胜利","获得50场胜利","被打败5次","被打败20次","总点数超过10000","总点数超过30000","总点数超过500000","总点数超过2147480000","总点数低于-10000","总点数低于-50000","总点数低于-1000000","点数过低，重置程序","完成20次春天","在一周年庆版本中完成5局游戏","在E3特别版中完成1局游戏"};
string descripEN[25] = {"","Do Spring in 1 game","Win for the first time","Win for 10 times","Win for 50 times","Be beaten for 5 times","Be beaten for 20 times","Get 10000 credits","Get 30000 credits","Get 500000 credits","Get 2147480000 credits","Lower than -10000 credits","Lower than -50000 credits","Lower than -1000000 credits","Credits are getting too low, so that I have to reset it for you","Finish 20 Springs","Finish 5 games in the 1st Anniversary Edition","Finish only one game in E3 Special Edition"};
string achMonCN[20] = {"元","二","三","四","五","六","七","八","九","十","十一","十二"};
string achMonEN[20] = {"January","Febrary","March","April","May","June","July","August","September","October","November","December"};
struct acheivement{
    int ifGet;
    int day;
    int mon;
    int yr;
};
acheivement ach[1005];
void readVars(){
    bool a = freopen("score.txt","r",stdin);
    if (!a){
        return;
    }
    scanf("%lld",&money);
    scanf("%d",&hisco);
    scanf("%d",&lang);
    scanf("%d",&ifGod);
    scanf("%d",&win);
    scanf("%d",&lose);
    scanf("%d",&dif);
    for (int i=1;i<=20;i++){ //已使用17个
        scanf("%d%d",&ach[i].ifGet,&ach[i].day);
        cin>>ach[i].mon>>ach[i].yr;
    }
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}
void writeVars(){
    freopen("score.txt","w",stdout);
    printf("%lld\n",money);
    printf("%d\n",hisco);
    printf("%d\n",lang);
    printf("%d\n",ifGod);
    printf("%d\n",win);
    printf("%d\n",lose);
    printf("%d\n",dif);
    for (int i=1;i<=20;i++){
        printf("%d %d ",ach[i].ifGet,ach[i].day);
        cout<<ach[i].mon<<" "<<ach[i].yr<<endl;
    }
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
    for (int i=1;i<=20;i++){
        ach[i].ifGet = 0;
    }
}
void ran(){
    srand(time(0)); //保证每次的牌不一样
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
        else if (Max == 1) a = 7;
        else a = -1;
    }
    else if (lenOU == 6){
        if (Max == 2){
            if (lenColl[2] == 3) a = 8;
            else a = -1;
        }
        else if (Max == 3){
            if (lenColl[3] == 2) a = 9;
            else a = -1;
        }
        else if (Max == 4){
            if (lenColl[2] == 1) a = 10;
            else a = -1;
        }
        else if (Max == 1) a = 7;
        else a = -1;
    }
    else if (lenOU == 8){
        if (Max == 3){
            if (lenColl[3] == 2) a = 12;
            else a = -1;
        }
        else if (Max == 2){
            if (lenColl[2] == 4) a = 8;
            else a = -1;
        }
        else if (Max == 1) a = 7;
        else a = -1;
    }
    else if (lenOU == 10){
        if (Max == 3){
            if (lenColl[3] == 2 && lenColl[2] == 2) a = 13;
            else a = -1;
        }
        else if (Max == 2){
            if (lenColl[2] == 5) a = 8;
            else a = -1;
        }
        else a = -1;
    }
    else if (lenOU > 6 && Max == 1) a = 7;
    else if (lenOU > 10 && Max == 2){
        if (lenOU%2 == 0 && lenColl[2] == lenOU/2) a = 8;
        else a = -1;
    }
    else a = -1;
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
void beat(){
    int canChu = 0;
    lLen = lenOU;
    lSize = -1;
    lMode = mode;
    if (mode == 1){ //单牌
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
    else if (mode == 2){ //对子
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
    else if (mode == 3){ //三不带
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
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
    else if (mode == 4){ //三带一
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
            if (cntE[i]>2){
                for (int j=0;j<13;j++){ //去王优化
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
    else if (mode == 5){ //炸弹
        sco*=2;
        for (int i=Ou[0]+1;i<13;i++){ //去王优化，此处还需特判大小王
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
    else if (mode == 6){ //三带二
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
            if (cntE[i]>2){
                for (int j=0;j<13;j++){ //去王优化
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
    else if (mode == 7){ //顺子
        int cnt = 0;
        for (int i=Ou[0]+1;i<12;i++){ //去王和2优化
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
    else if (mode == 8){ //连对
        int cnt = 0;
        for (int i=Ou[0]+1;i<12;i++){ //去王和2优化
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
    else if (mode == 9){ //小飞机
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
            if (cntE[i]>2){
                for (int j=i+1;j<13;j++){ //去王优化
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
    else if (mode == 10){ //四带二
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
            if (cntE[i]>3){
                for (int j=0;j<13;j++){ //去王优化
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
    else if (mode == 11){ //对手出牌
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
    else if (mode == 12){ //中飞机
        sco*=2;
        int cnt1 = 0,cnt2 = 0,v[20] = {},tmp[10] = {};
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
            if (cntE[i]>2){
                cnt1++;
                v[i] = 1;
                tmp[cnt1-1] = i;
            }
            if (cnt1 == 2){ //开始寻找单牌
                for (int j=0;j<13;j++){ //去王优化
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
    else if (mode == 13){ //大飞机
        sco*=3;
        int cnt1 = 0,cnt2 = 0,v[20] = {},tmp[10] = {};
        for (int i=Ou[0]+1;i<13;i++){ //去王优化
            if (cntE[i]>2){
                cnt1++;
                v[i] = 1;
                tmp[cnt1-1] = i; //下标从0开始
            }
            if (cnt1 == 2){ //开始寻找对子
                for (int j=0;j<13;j++){ //去王优化
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
    else{
        if (!ifGod){
            if (lang == 1) printf("功能未完善或牌出错了\n");
            else if (lang == 2) printf("Feature not included or you have put the Wrong Card\n");
            canChu = 1;
            lMode = 0;
        }
        
    }
    if (canChu == 0){
        if (totM<=6){
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
    if (cntE[13] == 1 && cntE[14] == 1){
        kingsman[0] = 1; //对王判断
        oppor+=4;
    }
    for (int i=0;i<13;i++){ //去王优化
        if (cntE[i]>3){
            bomb[i] = 1;
            useful[i]+=4;
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
                for (int j=i-doub+1;j<=i;j++){
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
                for (int j=i-sig+1;j<=i;j++){
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
    for (int i=left;i<=right;i++){
        if (useful[i]<Min && cntE[i]>=length){
            Min = useful[i];
            mpos = i;
        }
    }
    return mpos;
}
void selfOut(){
    int cntT = 0,cntD = 0,cntS = 0;
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
    int Max = -1,cur = 0;
    if (cntT>=2){
        if (cntD>=2){
            int i = weigh(0,12,3);
            if (i!=-1){
                cntE[i]-=3;
                int j = weigh(0,12,3);
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
            int i = weigh(0,12,3);
            if (i!=-1){
                cntE[i]-=3;
                int j = weigh(0,12,3);
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
            int i = weigh(0,12,3);
            if (i!=-1){
                cntE[i]-=3;
                int j = weigh(0,12,3);
                if (j!=-1){
                    sco*=2;
                    if (i>j) swap(i,j);
                    cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                    lChu[++lSize] = i;
                    cntE[j]-=3;
                    totE-=6;
                    j = 12;
                    i = 12;
                }
                else cntE[i]+=3;
            }
            lLen = 6;
        }
    }
    else if (cntT == 1){
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
            lLen-=2;
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
            lLen--;
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
    else{
        if (haDou == 1){
            int cnt = 0,Max = -1,mpos = -1;
            for (int i=0;i<12;i++){ //去王和2优化
                if (dou[i] == 1){
                    int tmp = i;
                    while (dou[tmp]!=0){
                        cnt++;
                        tmp++;
                    }
                    i = tmp;
                    if (cnt>Max){
                        Max = cnt;
                        mpos = i-cnt;
                    }
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
        }
        else if (haSin == 1){
            int cnt = 0,Max = -1,mpos = -1;
            for (int i=0;i<12;i++){ //去王和2优化
                if (si[i] == 1){
                    int tmp = i;
                    while (si[tmp]!=0){
                        cnt++;
                        tmp++;
                    }
                    i = tmp;
                    if (cnt>Max){
                        Max = cnt;
                        mpos = i-cnt;
                    }
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
        }
        else{
            //此处还需增加自己只剩一张与两张的特判
            int i = weigh(0,14,2);
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
        int cnt = 0,cntSi,Min = 0x7fffffff,mpos = -1;
        for (int i=Ou[0]+1;(i+lenOU-1)<12;i++){ //去王和2优化
            if (si[i] == 1 && si[i+lenOU-1] == 1){
                cntSi = 0;
                for (int j=i;j<=i+lenOU-1;j++){
                    cntSi+=useful[i];
                    if (cntSi<Min){
                        Min = cntSi;
                        mpos = i;
                    }
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
        int cnt = 0,cntDo,Min = 0x7fffffff,mpos = -1;
        for (int i=Ou[0]+1;(i+lenOU/2-1)<12;i++){ //去王和2优化
            if (dou[i] == 1 && dou[i+lenOU/2-1] == 1){
                cntDo = 0;
                for (int j=i;j<=i+lenOU-1;j++){
                    cntDo+=useful[i];
                    if (cntDo<Min){
                        Min = cntDo;
                        mpos = i;
                    }
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
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(Ou[0]+1,12,3);
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
            int j = weigh(0,12,2);
            if (j!=-1){
                cout<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[i]<<" "<<cardStack[j]<<" "<<cardStack[j]<<endl;
                lChu[++lSize] = i;
                cntE[j]-=2;
                totE-=6;
                canChu = 1;
                j = 12;
                i = 12;
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
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(Ou[0]+1,12,3);
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
        int i = weigh(Ou[0]+1,12,3);
        if (i!=-1){
            cntE[i]-=3;
            int j = weigh(Ou[0]+1,12,3);
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
    if (who == 1){
        mode = 11;
        if (lang == 1) printf("对手出了: ");
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
            if (ou[i] == '2'){
                Ou[++size] = 12;
            }
            else{
                Ou[++size] = ou[i] - '0' - 3;
            }
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
    for (int i=0;i<15;i++){
        if (basket[i]!=0) lenColl[basket[i]]++;
    }
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
            if (dif == 1) beat();
            else if (dif == 2) beat2();
        }
    }
}
void hel(){
    if (lang == 1) printf("此为双人斗地主，你可以和智商较低，优化较差的机器人对打\n");
    else if (lang == 2) printf("This is Beat The Landlord, you can play cards with a stupid and slow robot\n");
    if (lang == 1) printf("目前还有很多未修复的漏洞，如果发现请在GitHub提交issue，我会及时处理\n");
    else if (lang == 2) printf("There are still many unfixed bugs, if you have unfortunately met some of them, please create an issue on Github. I will fix it as soon as possible\n");
    if (lang == 1) printf("规则如下：\n");
    else if (lang == 2) printf("The rules are: \n");
    if (lang == 1) printf("1.单牌：你可以出比对手的牌数值更大的1张牌\n");
    else if (lang == 2) printf("1.Single Card: You can put 1 card that is BIGGER than Rival's\n");
    if (lang == 1) printf("2.对子：你可以出比对手的牌数值更大的2张牌，但它们在数值上必须相等\n");
    else if (lang == 2) printf("2.Double Cards: You can put 2 cards with THE SAME POINT, and they are BIGGER than Rival's\n");
    if (lang == 1) printf("3.三带一：你可以出4张牌，其中三张牌的数值必须相同且大于对手所出的三张牌的数值\n");
    else if (lang == 2) printf("3.Three Plus One: You can put 3 cards with THE SAME POINT, and they are BIGGER than Rival's,the other one can be anything you like\n");
    if (lang == 1) printf("4.炸弹：分为两种，王炸和四张相同的牌，王炸指SMALL+KING\n");
    else if (lang == 2) printf("4.Bomb：It can be 4 cards that have the same point, or SMALL+KING, which is the BIGGEST one in the game\n");
    if (lang == 1) printf("5.三带二：你可以出5张牌，其中包含3张一样的和一个对子\n");
    else if (lang == 2) printf("5.Three Plus Two: 5 cards, three of them is like that of Three Plus One, the other two is like a Double Cards\n");
    if (lang == 1) printf("6.小飞机：你可以出6张牌，其中包含两组3张一样的且牌数差为1\n");
    else if (lang == 2) printf("6.Small Plane: 6 cards, contain two sets of Three Cards\n");
    if (lang == 1) printf("7.中飞机：你可以出8张牌，包含一个小飞机和任意两张牌\n");
    else if (lang == 2) printf("7.Middle Plane: 8 cards, contain a Small Plane and two cards of whatever you like\n");
    if (lang == 1) printf("8.大飞机：你可以出10张牌，其中包含一个小飞机和两个对子\n");
    else if (lang == 2) printf("8.Big Plane: 10 cards, contain a Small Plane and two sets of Double Cards\n");
    if (lang == 1) printf("9.顺子：你可以出大于等于5张牌，其中每张牌间的差为1\n");
    else if (lang == 2) printf("9.Silk Road：You can put more than 5 cards, the difference of every connected ones must be the SAME\n");
    if (lang == 1) printf("10.连对：你可以出大于6张牌，其中包含3个以上的对子，且每个对子间的差为1\n");
    else if (lang == 1) printf("10.Silk Road on Sea：More than 6 cards, the difference of every connected Double Cards must be the SAME\n");
    if (lang == 1) printf("如果你没有更大的牌，请出‘要不起’或‘0’\n");
    else if (lang == 2) printf("If you don't have a bigger one, please put ‘Can't afford’ or ‘0’\n");
    if (lang == 1) printf("如果一方先把所有牌出完，即胜利\n");
    else if (lang == 2) printf("If one of you has put all of his(her) cards, he(her) WINS\n");
    if (lang == 1) printf("如果你是地主，并且一次性将所有牌都出完，对手没有一次出牌机会，将获得春天加倍奖励\n");
    else if (lang == 2) printf("If you are the landlord and put all of you cards in a row, the Rival can't get any chance to put any cards, you do Spring with bonus\n");
    if (lang == 1) printf("如果你是农名，并且只让对手出了一次牌，你将获得同样得奖励\n");
    else if (lang == 2) printf("If you are a farmer and only give one chance to the Rival, youn will receive the same bonus\n");
    if (lang == 1) printf("按任意键以返回\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    char uc[10];
    gets(uc);
    cin.getline(uc,10);
    printf("\n");
    return;
}
void about(){
    if (lang == 1) printf("发行日期: 6/24/2021\n");
    else if (lang == 2) printf("Release Date: 6/24/2021\n");
    if (lang == 1) printf("版本号: 2.2.0\n");
    else if (lang == 2) printf("Ver: 2.2.0\n");
    if (lang == 1) printf("此为C++正式版，大部分功能已可用，可能有少量bug\n");
    else if (lang == 2) printf("C++ stable channel, most features are available, might has a few bugs\n");
    if (lang == 1) printf("按任意键以返回\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    char uc[10];
    gets(uc);
    cin.getline(uc,10);
    printf("\n");
    return;
}
void acheive(){
    if (lang == 1) printf("你已达成的成就:\n");
    else if (lang == 2) printf("The achievements you have reached\n");
    int f = 0;
    for (int i=1;i<=17;i++){
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
    for (int i=1;i<=17;i++){
        if (ach[i].ifGet == 0){
            if (lang == 1) cout<<achCNStack[i]<<endl<<"解锁条件: "<<descripCN[i]<<endl<<endl;
            else if (lang == 2) cout<<achENStack[i]<<endl<<"Unlock Way: "<<descripEN[i]<<endl<<endl;
            f = 1;
        }
    }
    if (!f){
        if (lang == 1) printf("你已解锁全部成就!\n\n");
        else if (lang == 2) printf("You have achieved all of them!\n\n");
    }
    if (lang == 1) printf("按任意键以返回\n");
    else if (lang == 2) printf("Press any key to go back to the previous page\n");
    char uc[10];
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
    if (lang == 1) printf("2.难度设置: ");
    else if (lang == 2) printf("2.Difficulty Setting: ");
    if (dif == 1){
        if (lang == 1) printf("简单\n");
        else if (lang == 2) printf("Easy\n");
    }
    else if (dif == 2){
        if (lang == 1) printf("增强型(测试版)\n");
        else if (lang == 2) printf("Enhanced(Beta)\n");
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
        if (lang == 1) printf("1.简单 2.增强型(尚在开发中)\n");
        else if (lang == 2) printf("1.Easy 2.Enhanced(Developing)\n");
        scanf("%d",&uc);
        if (uc == 1) dif = 1;
        else dif = 2;
    }
    else if (uc == 3){
        if (lang == 1) printf("你真的想要删除所有数据吗?\n1.是  2.否\n");
        else if (lang == 2) printf("Do you really want to delete all saves?\n1.Yes  2.No\n");
        scanf("%d",&uc);
        if (uc == 1) Back();
    }
    printf("\n");
}
void markAch(int i){
    if (lang == 1) cout<<"达成成就: "<<achCNStack[i]<<endl;
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
        if (edi == 'a' && ach[16].ifGet == 0 && win+lose == 5) markAch(16);
        if (edi == 'e' && ach[17].ifGet == 0) markAch(17);
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
    if (lang == 1) printf("胜率: %d",int((double(win)/(win+lose))*100));
    else if (lang == 2) printf("Possibility of Winning: %d",int((double(win)/(win+lose))*100));
    cout<<"%"<<endl;
    if (!ifGod){
        if (lang == 1) printf("凡人无法看见此界面上的更多内容\n\n");
        else if (lang == 2) printf("Only God can see more on this page\n\n");
        if (lang == 1) printf("按任意键以返回\n");
        else if (lang == 2) printf("Press any key to go back to the previous page\n");
        char uc[10];
        gets(uc);
        cin.getline(uc,10);
        printf("\n");
        return;
    }
    if (lang == 1) printf("1.修改点数\n2.修改成就达成情况\n3.返回\n");
    else if (lang == 2) printf("1.Modify Credits\n2.Modify Acheivements\n3.Back\n");
    long long uc;
    scanf("%lld",&uc);
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
}
void notboard(){
    int uc = 1,page = 5,ifRead = 1;
    while (uc!=3){
        if (ifRead) nbdata(page);
        printf("\n");
        if (lang == 1) printf("1.下一页 2.上一页 3.退出\n");
        else if (lang == 2) printf("1.Next Page 2.Previous Page 3.Quit\n");
        scanf("%d",&uc);
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
        else{
            printf("\n");
            return;
        }
    }
}
void sup(){
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
void runPro(){
    writeVars();
    ifJiao = 0;
    if (lang == 1) printf("1.开始\n2.语言/Language\n3.选项\n4.公告\n5.成就\n6.统计\n7.帮助\n8.支持\n9.关于\n10.退出\n");
    else if (lang == 2) printf("1.Start\n2.Language/语言\n3.Option\n4.Notice\n5.Acheivements\n6.Statistics\n7.Help\n8.Support\n9.About\n10.Quit\n");
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
        checkach();
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
        notboard();
        runPro();
    }
    else if (uc == 5){
        acheive();
        runPro();
    }
    else if (uc == 6){
        stat();
        runPro();
    }
    else if (uc == 7){
        hel();
        runPro();
    }
    else if (uc == 8){
        sup();
        runPro();
    }
    else if (uc == 9){
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
