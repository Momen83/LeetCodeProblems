class Solution {
public:
    const int  Mod = 1e9 + 7;
    int numTilings(int n) {
        vector<int>dp(n + 5,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4 ; i <=n ;i++){
             dp[i] = (((dp[i - 1] * 2)%Mod) + (dp[i - 3]%Mod))%Mod;
        }
        return dp[n];
        
    }
};
