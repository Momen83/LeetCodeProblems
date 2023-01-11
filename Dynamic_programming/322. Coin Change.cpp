class Solution {
public:
vector<long long>dp;
long long solve(int sum ,vector<int>&coinChange){
    if(sum==0)return 0;
    long long &ret=dp[sum];
    if(ret!=-1)return ret;
    ret=1e10;
    for(int i=0;i<coinChange.size();i++){
        if(sum-coinChange[i]>=0){
            ret=min(ret,solve(sum-coinChange[i],coinChange) +1);
        }
    }
    return ret;
}
    int coinChange(vector<int>& coins, int amount) {
        dp=vector<long long>(amount+1,-1);
        long long res=solve(amount,coins);
      return res>=1e10 ?-1:res;
    }
};
