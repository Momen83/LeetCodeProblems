class Solution {
public:
    int dp[101][101][201];
    int solve(string &s1 , string &s2 , string &s3 , int i , int j , int k)
    {
       
        if(k == s3.size())
        {
            return i == s1.size() && j== s2.size();
        }
        
        int & ans = dp[i][j][k];
        if(ans !=-1) return ans;
        ans = 0;
        if(i + 1 <=s1.size() && s3[k] == s1[i]){
            ans |= solve(s1,s2,s3,i + 1 , j , k + 1);
        }
        if(j + 1 <= s2.size() && s3[k] == s2[j]){
            ans |= solve(s1,s2,s3,i , j + 1 , k + 1);
        }
             if(i + 1 <= s1.size())
             {
                  ans |= solve(s1 ,s2 ,s3 ,i+1 , j , k);
             }
             if(j + 1 <= s2.size())
             {
                  ans |= solve(s1 ,s2 ,s3 ,i , j + 1 , k);
             }
       
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        int ans = solve(s1,s2,s3,0,0,0);
        return ans;
        
    }
};
