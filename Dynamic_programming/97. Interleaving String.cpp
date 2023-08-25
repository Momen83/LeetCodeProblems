class Solution {
public:
    int dp[101][101];
    int solve(string &s1 , string &s2 , string &s3 , int i , int j)
    {
       
        if(i + j == s3.size())
        {
            return 1;
        }
        
        int & ans = dp[i][j];
        if(ans !=-1) return ans;
        ans = 0;
        if(i + 1 <=s1.size() && s3[i + j] == s1[i]){
            ans |= solve(s1,s2,s3,i + 1 , j);
        }
        if(j + 1 <= s2.size() && s3[i + j] == s2[j]){
            ans |= solve(s1,s2,s3,i , j + 1);
        }
        
       
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        int ans = solve(s1,s2,s3,0,0);
        return ans;
        
    }
};
