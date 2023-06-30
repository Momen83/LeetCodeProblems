class Solution {
public:
    int dp[46];
    void clr()
    {
        for(int i=0;i<46;i++)dp[i]=-1;
    }
    int solve(int n)
    {
        if(n==0)return 1;
        if(n<0)return 0;
        if(~dp[n])return dp[n];
        return dp[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        clr();
        return solve(n);
    }
};
