class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long mxSize = 2e5 + 5;
        vector<long long >dp(mxSize , 0);
        for(int i = questions.size() - 1 ; i >=0 ;i--){
            dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1] , dp[i + 1] );
        }
        return dp[0];

    }
};
