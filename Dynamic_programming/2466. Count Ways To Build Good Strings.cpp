class Solution {
public:
    int dp[100001];
    const int Mod = 1e9 + 7;
    int solve(int sz  , int &low , int &high , int &zero , int &one ){
        if(sz >high )return 0;
        int &ans = dp[sz];
        if(ans !=-1)return ans;
        ans = 0;
        int inc = (sz >=low && sz<=high);
        ans = (ans%Mod +   (inc + (solve(sz + zero , low ,high , zero , one)))%Mod)%Mod;
        ans =(ans %Mod + (solve(sz + one , low , high , zero , one))%Mod)%Mod;

        return ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        memset(dp , -1 ,sizeof(dp));
        return solve(0 , low ,high , zero , one);;
    }
};
