class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& matrix,int i , int j){
        if(i ==matrix.size()-1 ){
            return matrix[i][j] ;
        }
        int &ret = dp[i][j];
        if(ret !=-1)return ret;
        ret = 1e9;
        if(i+1 <matrix.size() &&j-1 >=0){
            ret = min(ret ,matrix[i][j] + solve(matrix , i+1,j-1));
        }
         if(i+1 <matrix.size() &&j+1 <matrix[0].size()){
            ret = min(ret ,matrix[i][j] + solve(matrix , i+1,j+1));
        }
         if(i+1 <matrix.size() ){
            ret = min(ret ,matrix[i][j] + solve(matrix , i+1,j));
        }
        return ret;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, -1 ,sizeof(dp));
        int ans = 1e9;
        for(int i = 0 ; i<matrix.size();i++){
            ans = min(ans , solve(matrix , 0 , i));
        }
        return ans;
    }
      

       
};
