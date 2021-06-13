#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,beth,path,uc;
char ucs[105];
int main()
{
    printf("输入时区:\n1.北京时间\n2.太平洋时间\n");
    scanf("%d",&uc);
    printf("输入时间(xx:xx):\n");
    scanf("%s",&ucs);
    printf("转换结果:");
    int len = strlen(ucs);
    if (int(ucs[3]) == -70 || int(ucs[2]) == -70){
        if (len == 5){
            len--;
            ucs[2] = ucs[3];
            ucs[3] = ucs[4];
        }
        else{
            len--;
            ucs[3] = ucs[4];
            ucs[4] = ucs[5];
        }
    }
    if (len == 4){
        m = (int(ucs[2]-'0'))*10+int(ucs[3]-'0');
        if (uc == 1) beth = int(ucs[0]-'0');
        else path = int(ucs[0]-'0');
    }
    else{
        m = (int(ucs[3]-'0'))*10+int(ucs[4]-'0');
        if (uc == 1) beth = (int(ucs[0]-'0'))*10+int(ucs[1]-'0');
        else path = (int(ucs[0]-'0'))*10+int(ucs[1]-'0');
    }
    if (uc == 1){
        path = beth-15;
        if (path<0){
            printf("前一天的");
            path+=24;
        }
        printf("%d",path);
    }
    else{
        beth = path+15;
        if (beth>=24){
            printf("第二天的");
            beth%=24;
        }
        printf("%d",beth);
    }
    if (m) printf(":");
    if (m<10 && m) printf("0");
    if (m) printf("%d",m);
    if (!m) printf("点");
    printf("\n");
    system("pause");
    return 0;
}
