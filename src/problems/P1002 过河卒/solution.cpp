#include<cstdio>
const int Const[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};
long long DP[21][21]={1};
bool mark[21][21];
int main() {
    int nx,ny,hx,hy;
    scanf("%d%d%d%d",&nx,&ny,&hx,&hy);
    for(int i=0;i<9;++i)
        if(hx+Const[0][i]>=0&&hx+Const[0][i]<=nx&&hy+Const[1][i]>=0&&hy+Const[1][i]<=ny)
            mark[hx+Const[0][i]][hy+Const[1][i]]=1;
    for(int i=0;i<=nx;++i)
        for(int j=0;j<=ny;++j) {
            if(i)
                DP[i][j]+=DP[i-1][j];
            if(j)
                DP[i][j]+=DP[i][j-1];
            DP[i][j]*=!mark[i][j];
        }
    printf("%lld",DP[nx][ny]);
    return 0;
}