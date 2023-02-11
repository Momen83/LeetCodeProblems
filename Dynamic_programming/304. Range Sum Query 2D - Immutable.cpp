class NumMatrix {
public:
    vector<vector<int>>dp;
      int n ,m;
    NumMatrix(vector<vector<int>>& matrix) {
         n = matrix.size();
         m = matrix[0].size();
        dp = vector<vector<int>>(n+5 , vector<int>(m+5 , 0));
        for(int i = 1 ; i <=m;i++){
            dp[1][i] = dp[1][i-1] +matrix[0][i-1]; 
        }
        for(int i = 1 ; i<=n;i++){
            dp[i][1] = dp[i-1][1] + matrix[i-1][0];
        }
        for(int i = 2 ;i<=n;i++){
            for(int j = 2 ; j<=m;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j] -  dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    
       
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       int ans =dp[row2+1][col2+1];
        ans-=dp[row1][col2+1];
        ans-=dp[row2+1][col1];
        ans+=dp[row1][col1];
      return ans;
    }
};
