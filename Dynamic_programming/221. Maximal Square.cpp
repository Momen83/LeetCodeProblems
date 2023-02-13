class Solution {
public:
 int sumRegion(vector<vector<int>>dp,int row1, int col1, int row2, int col2) {
       int ans =dp[row2+1][col2+1];
        ans-=dp[row1][col2+1];
        ans-=dp[row2+1][col1];
        ans+=dp[row1][col1];
      return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int  m = matrix[0].size();
        vector<vector<int>>dp;
        dp = vector<vector<int>>(n+5 , vector<int>(m+5 , 0));
        int mxAns = 0;
      for(int i = 0 ; i<n;i++){
          for(int j = 0 ; j<m;j++){
              if(matrix[i][j] =='1'){
                  dp[i+1][j+1] = min({dp[i][j+1] , dp[i][j] , dp[i+1][j]}) + 1;
                  mxAns = max(dp[i+1][j+1], mxAns);
              }
          }
      }
         return mxAns*mxAns;
    }
};
