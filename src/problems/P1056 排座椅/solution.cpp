#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std; 
int m,n,k,l,d;//变量名最好起与题目一致的 
int x[1005],y[1005];//横纵坐标数组 
int c[1005],o[1005];//桶排要用的数组
int main() {
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d); 
    for(int i=1;i<=d;i++) { 
        int xi,yi,pi,qi; 
        scanf("%d%d%d%d",&xi,&yi,&pi,&qi); 
        if(xi==pi) 
            x[min(yi,qi)]++;//表示隔开这两排的价值 
        else 
            y[min(xi,pi)]++; //记得取min，即过道与前一个坐标保持一致 
    } 
    for(int i=1;i<=k;i++){//开始桶排 
        int maxn=-1;//为了求出每次的最大值，需要每次扫一遍 
        int p; 
        for(int j=1;j<m;j++){ 
            if(y[j]>maxn){ 
                maxn=y[j]; 
                p=j; 
            } 
        } 
        y[p]=0;//求出max之后一定要记得清零！！否则无论排多少次都是一个答案 
        c[p]++;//桶排不解释 
    } 
    for(int i=1;i<=l;i++){ 
        int maxn=-1; 
        int p; 
        for(int j=1;j<n;j++){ 
            if(x[j]>maxn){ 
                maxn=x[j]; 
                p=j; 
            } 
        } 
        x[p]=0; //同上 
        o[p]++; 
    } 
    for(int i=0;i<1005;i++)//输出答案 
    { 
        if(c[i])//表示需要隔开这行 
            printf("%d ",i); 
    } 
    printf("\n"); 
    for(int i=0;i<1005;i++) 
    { 
        if(o[i]) 
            printf("%d ",i); //同上 
    } 
    return 0; 
}