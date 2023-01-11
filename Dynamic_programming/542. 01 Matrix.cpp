class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n = mat.size();
         int m = mat[0].size();
      vector<vector<int>>dis(n,vector<int>(m,1e9));
       for(int i = 0 ;i<n;i++){
          for(int j = 0 ;j<m;j++){
               if(mat[i][j] == 0){
                  dis[i][j] = 0;
                  continue;
              }
             if(i-1 >=0){
                dis[i][j] = min(dis[i][j], dis[i-1][j]+1);
             }
               if(j-1 >=0){
                dis[i][j] = min(dis[i][j], dis[i][j-1]+1);
             }
          }
      }
      for(int i = n-1 ;i>=0;i--){
          for(int j = m-1 ;j>=0;j--){
               if(mat[i][j] == 0){
                  dis[i][j] = 0;
                  continue;
              }
             if(i+1<n){
                 dis[i][j] = min(dis[i][j], dis[i+1][j]+1);
             }
             if(j+1<m){
                 dis[i][j] = min(dis[i][j], dis[i][j+1]+1);
             }
            
          }
      }
      return dis;

    }
};
