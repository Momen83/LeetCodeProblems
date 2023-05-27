class Solution {
public:
    int dp[50001];
     int  solve(vector<int>& stoneValue,int index) {
        if(index ==stoneValue.size()) {
            return 0;
        }
        if(dp[index]!=INT_MIN)return dp[index];
        int res = INT_MIN;
        int sum = 0;
        for(int t = index ; t <min(index + 3,(int)stoneValue.size()) ; t++ )
        {
            sum +=stoneValue[t];
            res = max(res , sum - solve(stoneValue , t + 1)); 
        }
        return dp[index] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
            for(int i = 0 ; i<=50000 ; i++)
            {
                dp[i] = INT_MIN;
            }
            int ans = solve(stoneValue , 0);
            if(ans > 0)return "Alice";
            else if(ans <0)return "Bob";
            else return "Tie";
    }
};
