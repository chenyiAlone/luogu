#include<iostream>
#define MAXN 101
using namespace std;
int main()
{
    int n, a[MAXN], sum[MAXN]={0}, d;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int ave = sum[n]/n;
    int count=0; 
    for(int i=1; i<=n; i++)
    {
        if(sum[i]>i*ave) //sumstd[i]=i*ave, 向后面均匀一些 
        {
            d = sum[i]-i*ave;
            sum[i] -= d;
            a[i] -= d;
            a[i+1] += d;
            count++;
        }                    
    }
    for(int i=n; i>=1; i--)
    {
        if(a[i]>ave) //向前面均匀一些 
        {
            d = a[i]-ave;
            a[i] -= d;
            a[i-1] += d;
            sum[i-1] += d;
            count++;
        }                    
    }
    cout << count;
     return 0;
}