#include<cstdio>
#include<cstring>
using namespace std;
int p1,p2,p3;
char a[10000000];
char wd[]="************************************************0123456789*******ABCDEFGHIJKLMNOPQRSTUVWXYZ******abcdefghijklmnopqrstuvwxyz";
int aspace(char c1,char c2)
{
    if(c1>=48 and c1<=57 and c2>=48 and c2<=57) return 1;
    else if(c1>=97 and c1<=122 and c2>=97 and c2<=122) return 2;
    else return false;
}
void c2c(char l,char r)
{
    //printf("HERE!");
    int dxx=0,k=1,xh=1,lon=r-l-1;
    if(p1==2 and aspace(l,r)==2) dxx=32;
    else if(p1==3) xh=0;
    k=p2;
    //printf("%c",l);
    if(p3==1)
    {
        for(int i=l+1;i<r;i++)
        {
            for(int j=1;j<=k;j++) printf("%c",wd[(i-dxx)*xh]);
        }
    } 
    else if(p3==2)
    {
        for(int i=r-1;i>l;i--)
        {
            for(int j=1;j<=k;j++) printf("%c",wd[(i-dxx)*xh]);
        }
    }
    printf("%c",r);
    return;
}
int main()
{
    scanf("%d %d %d\n",&p1,&p2,&p3);
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='-' and a[i+1]>a[i-1] and aspace(a[i-1],a[i+1])) {c2c(a[i-1],a[i+1]);i++;}
        else printf("%c",a[i]);
    }
    return 0;
}