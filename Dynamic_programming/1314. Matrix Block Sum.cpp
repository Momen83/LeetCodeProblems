class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp;
        dp = vector<vector<int>>(n+5 , vector<int>(m+5 , 0));
        for(int i = 1 ; i <=m;i++){
            dp[1][i] = dp[1][i-1] +mat[0][i-1]; 
        }
        for(int i = 1 ; i<=n;i++){
            dp[i][1] = dp[i-1][1] + mat[i-1][0];
        }
         for(int i = 2 ;i<=n;i++){
            for(int j = 2 ; j<=m;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j] -  dp[i-1][j-1] + mat[i-1][j-1];
            }
        }
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ;j<m;j++){
                int row1 = max(i-k , 0);
                int col1 = max(j-k , 0);
                int row2 = min(i+k , n-1); 
                int col2 = min(j+k , m-1);
                int ans =dp[row2+1][col2+1];
                ans-=dp[row1][col2+1];
                ans-=dp[row2+1][col1];
                ans+=dp[row1][col1];
                mat[i][j] = ans;
            }
        }
        return mat;
    }
};
