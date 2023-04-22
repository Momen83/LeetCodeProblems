class Solution {
public:
    int dp[501][501];
    int solve(string &s,int start , int end){
        if(start >end){
            return 0;
        }
        int &ret = dp[start][end];
        if(ret !=-1){
            return ret;
        }
        ret = (s[start] == s[end] ?solve(s , start +1 , end - 1)
        : min(solve(s , start +1 , end ) +1 , solve(s , start, end - 1) + 1));
        return ret;
    }
    int minInsertions(string s) {
        memset(dp , -1 ,sizeof(dp));
        return solve(s , 0 , s.size() - 1);
    }
};
