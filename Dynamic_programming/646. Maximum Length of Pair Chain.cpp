class Solution {
public:
    int dp[1001][1002];
    int solve(vector<vector<int>>& pairs,int index ,int prevIdx){
        if(index == pairs.size()) {
            return 0;
        }
        int &ans = dp[index][prevIdx];
        if(ans !=-1) return ans;
        int op1 = 0 , op2 = 0;
        op2 = solve(pairs, index + 1 , prevIdx);
        if(prevIdx == 1001 || pairs[prevIdx][1] < pairs[index][0] ) {
            op1 = solve(pairs, index + 1, index) + 1;
        }
        return ans = max(op1,op2);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(pairs,0,1001);
    }
};
