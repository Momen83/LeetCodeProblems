class Solution {
public:
    int dp[101][101];
    void  init()
   {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            dp[i][j]=-1;
        }
    }
   }
    bool valid(int x,int y,int n ,int m)
   {
    return (x>=1 &&x<=n &&y>=1 &&y<=m);
   }
    int solve(int i,int j ,int n ,int m)
{
    if(i>n ||j>m)return 0;
    if(i==n &&j==m)return 1;
    if(~dp[i][j])return dp[i][j];
    int op1=0,op2=0;
    if(valid(i+1,j,n,m))
    {
        op1+= solve(i+1,j,n,m);
    }
    if(valid(i,j+1,n,m))
    {
        op2+=solve(i,j+1,n,m);
    }
    return dp[i][j]=op1+op2;
}
    int uniquePaths(int m, int n) {
        init();
        return solve(1,1,m,n);
    }
};
