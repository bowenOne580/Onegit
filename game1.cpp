#include<iostream>
#include<cstdio>
#include<ctime> //���ڲ��������(ϵͳʱ�����)
#include<cstring>
#include<string>
using namespace std;
int cardNum[20] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1},lenOU,sumOU,Ou[105];
int Max,cntE[20],cntM[20],cntB[5],totM = 17,totE = 17,mode,lMode,boKing;
int lChu[100],lSize;
string cardStack[20] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "SMALL","KING",};
int ifJiao = 0;
void Clear(){
	for (int i=0;i<15;i++){
		if (i<=12) cardNum[i] = 4;
		else cardNum[i] = 1;
	}
    memset(cntE,0,sizeof(cntE));
    memset(cntM,0,sizeof(cntM));
    memset(cntB,0,sizeof(cntB));
    totM = 17;
    totE = 17;
    ifJiao = 0;
    lMode = 0;
}
void ran(){
    srand(time(0)); //��֤ÿ�ε��Ʋ�һ��
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
        if (Max == 3) a = 6;
        else if (Max == 1) a = 7;
        else a = -1;
    }
    else if (lenOU == 6){
        if (Max == 2) a = 8;
        else if (Max == 3) a = 9;
        else if (Max == 4) a = 10;
        else if (Max == 1) a = 7;
        else a = -1;
    }
    else if (lenOU == 8){
        if (Max == 3) a = 12;
    }
    else if (lenOU == 10){
        if (Max == 3) a = 13;
    }
    else if (lenOU > 6 && Max == 1) a = 7;
    else a = -1;
    return a;
}
int Save(){
    int Good = 0;
    for (int i=0;i<15;i++){
        if (cntE[i]>3){
            cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[i]<<endl;
            lChu[++lSize] = i;
            cntE[i]-=4;
            totE-=4;
            Good = 1;
            break;
        }
    }
    return Good;
}
void beat(){
    int canChu = 0;
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
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>1){
                cout<<cardStack[i]<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=2;
                totE-=2;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 3){ //������
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>2){
                cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=3;
                totE-=3;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 4){ //����һ
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>2){
                for (int j=0;j<15;j++){
                    if (cntE[j]>0 && j!=i || cntE[j]>3){
                        cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        lChu[++lSize] = j;
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
    else if (mode == 5){ //ը��
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>3){
                cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[i]<<endl;
                lChu[++lSize] = i;
                cntE[i]-=4;
                totE-=4;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 6){ //������
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>2){
                for (int j=0;j<15;j++){
                    if (cntE[j]>1 && j!=i){
                        cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[j]<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        lChu[++lSize] = j;
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
    }
    else if (mode == 7){
        int cnt = 0;
        for (int i=Ou[0]+1;i<12;i++){
            if (cntE[i]>0) cnt++;
            else cnt = 0;
            if (cnt == lenOU){
                for (int j=i-lenOU+1;j<=i;j++){
                    cout<<cardStack[j];
                    lChu[++lSize] = j;
                    cntE[j]--;
                    totE--;
                }
                cout<<endl;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 8){
        int cnt = 0;
        for (int i=Ou[0]+1;i<13;i++){
            if (cntE[i]>1) cnt+=2;
            else cnt = 0;
            if (cnt == lenOU){
                for (int j=i-(lenOU/2)+1;j<=i;j++){
                    cout<<cardStack[j]<<cardStack[j];
                    lChu[++lSize] = j;
                    cntE[j]-=2;
                    totE-=2;
                }
                cout<<endl;
                canChu = 1;
                break;
            }
        }
    }
    else if (mode == 9){
        int cnt = 0;
        for (int i=Ou[0]+1;i<13;i++){
            if (cntE[i]>2){
                for (int j=i+1;j<13;j++){
                    if (cntE[j]>2){
                        cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[j]<<cardStack[j]<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        lChu[++lSize] = j;
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
    }
    else if (mode == 10){
        for (int i=Ou[0]+1;i<15;i++){
            if (cntE[i]>3){
                for (int j=0;j<15;j++){
                    if (cntE[j]>1 && j!=i){
                        cout<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[i]<<cardStack[j]<<cardStack[j]<<endl;
                        lChu[++lSize] = i;
                        lChu[++lSize] = j;
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
    }
    else if (mode == 11){ //���ֳ���
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
    else if (mode == 12){
        int cnt1 = 0,cnt2 = 0,v[20] = {},tmp[10] = {};
        for (int i=Ou[0]+1;i<13;i++){
            if (cntE[i]>2){
                cnt1++;
                v[i] = 1;
                tmp[cnt1-1] = i;
            }
            if (cnt1 == 2){
                for (int j=0;j<15;j++){
                    if (cntE[j]>0 && v[j] == 0){
                        cnt2++;
                        v[j] = 1;
                        tmp[cnt2+cnt1-1] = j;
                    }
                    if (cnt2 == 2){
                        for (int k=0;k<4;k++){
                            if (k<2){
                                cout<<cardStack[tmp[k]]<<cardStack[tmp[k]]<<cardStack[tmp[k]];
                                cntE[k]-=3;
                                totE-=3;
                            }
                            else{
                                cout<<cardStack[tmp[k]];
                                cntE[k]--;
                                totE--;
                            }
                        }
                        cout<<endl;
                        lChu[++lSize] = tmp[0];
                        lChu[++lSize] = tmp[2];
                        canChu = 1;
                        break;
                    }
                }
                break;
            }
        }
    }
    else if (mode == 13){
        int cnt1 = 0,cnt2 = 0,v[20] = {},tmp[10] = {};
        for (int i=Ou[0]+1;i<13;i++){
            if (cntE[i]>2){
                cnt1++;
                v[i] = 1;
                tmp[cnt1-1] = i;
            }
            if (cnt1 == 2){
                for (int j=0;j<15;j++){
                    if (cntE[j]>1 && v[j] == 0){
                        cnt2++;
                        v[j] = 1;
                        tmp[cnt2+cnt1-1] = j;
                    }
                    if (cnt2 == 2){
                        for (int k=0;k<4;k++){
                            if (k<2){
                                cout<<cardStack[tmp[k]]<<cardStack[tmp[k]]<<cardStack[tmp[k]];
                                cntE[k]-=3;
                                totE-=3;
                            }
                            else{
                                cout<<cardStack[tmp[k]]<<cardStack[tmp[k]];
                                cntE[k]-=2;
                                totE-=2;
                            }
                        }
                        cout<<endl;
                        lChu[++lSize] = tmp[0];
                        lChu[++lSize] = tmp[2];
                        canChu = 1;
                        break;
                    }
                }
                break;
            }
        }
    }
    else{
        cout<<"����δ���ƻ��Ƴ�����"<<endl;
        canChu = 1;
        lMode = 0;
    }
    if (canChu == 0){
        if (totM<=6){
            if (!Save()){
                cout<<"Ҫ����"<<endl;
                lMode = 0;
            }
        }
        else{
            cout<<"Ҫ����"<<endl;
            lMode = 0;
        }
    }
}
void pre(){
    printf("�е�����:1.3�� 2.2�� 3.1�� 4.����\n");
    int iwant;
    scanf("%d",&iwant);
    if (iwant != 4){
    	for (int i=0;i<3;i++) cntM[cntB[i]]++;
    	totM += 3;
	}
    else{
    	for (int i=0;i<3;i++) cntE[cntB[i]]++;
    	totE += 3;
	}
    printf("�����: ");
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    printf("��������: %d\n",totE);
    if (iwant == 4){
        mode = 11;
        printf("���ֳ���: ");
        beat();
    }
}
int findCuo(){
    mode = calc();
    if (mode == -1) return 1;
    else if (lMode != mode && lMode!=0 && lMode!=11) return 1;
    else return 0;
}
void ingame(){
    printf("�����: ");
    for (int i=0;i<15;i++){
        int k = 0;
        while (k<cntM[i]){
            cout<<cardStack[i]<<" ";
            k++;
        }
    }
    printf("��������: %d\n",totE);
    if (ifJiao == 0){
        ifJiao = 1;
        pre();
    }
    char ou[105];
    scanf("%s",ou);
    if (ou[0] == -46){
        Ou[0] = -46;
        mode = 11;
        printf("���ֳ���: ");
        beat();
        return;
    }
    lenOU = strlen(ou);
    int size = -1,fakeLen = lenOU,tag,basket[105] = {},Cuo = 0;
    Max = 0;
    boKing = 0;
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
            
        }
        else{
            Cuo = 1;
            break;
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
            break;
        }
        cntM[Ou[size]]--;
        totM--;
    }
    if (Cuo == 0) Cuo = findCuo();
    if (Cuo == 0 && lMode != 0){
        int tmpcnt = 0;
        for (int i=0;i<=size;i++){
            if (Ou[i] <= lChu[lSize]){
                if (lSize>1){
                    if (lChu[lSize-1] >= Ou[i]) Cuo = 1;
                    else{
                        if (tmpcnt == 0) tmpcnt++;
                        else Cuo = 1;
                    }
                }
                else Cuo = 1;
                if (Cuo == 1) break;
            }
        }
    }
    if (Cuo == 1){
        for (int i=size;i>=0;i--){
            cntM[Ou[size--]]++;
            totM++;
        }
        printf("�Ƴ�����\n");
        ingame();
    }
    else{
        if (totM == 0) return;
        else{
            printf("���ֳ���: ");
            beat();
        }
    }
}
void hel(){
    printf("��Ϊ˫�˶�����������Ժ����̽ϵͣ��Ż��ϲ�Ļ����˶Դ�\n");
    printf("Ŀǰ���кܶ�δ�޸���©���������������GitHub�ύissue���һἰʱ����\n");
    printf("�������£�\n");
    printf("1.���ƣ�����Գ��ȶ��ֵ�����ֵ�������\n");
    printf("2.���ӣ�����Գ��ȶ��ֵ�����ֵ����������ƣ�����������ֵ�ϱ������\n");
    printf("3.����һ������Գ������ƣ����������Ƶ���ֵ������ͬ�Ҵ��ڶ��������������Ƶ���ֵ��������ڣ����������ĵ������Ʊ�����ڶ��ֵĵ�������\n");
    printf("4.ը������Ϊ���֣���ը��������ͬ���ƣ���ըָSMALL+KING\n");
    printf("5.���������˹��ܻ�δ����\n");
    printf("���һ���Ȱ������Ƴ��꣬��ʤ��\n\n");
}
void about(){
    printf("Release Date:5/3/2021\n");
    printf("C++ Edition 2.1.3.0\n");
    printf("��ΪC++��ʽ��,�󲿷ֹ����ѿ��ã�����������bug\n\n");
}
void runPro(){
    ifJiao = 0;
    printf("1:��ʼ\n2.����\n3.����\n4.�˳�\n");
    int uc;
    scanf("%d",&uc);
    if (uc == 1){
        ran(); //���ƺ�������
        while (totM > 0 && totE > 0) ingame();
        if (totM == 0) printf("You Win!\n");
        else printf("You Lose!\n");
        Clear();
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
