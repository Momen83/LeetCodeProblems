class Solution {
public:
   bool vis[501][501];
   void dfs(vector<vector<int>>& grid , int i ,int j){
       if(i ==grid.size()||i<0  ||j== grid[i].size()||j<0 || grid[i][j] ==0){
           return ;
       } 
       grid[i][j] = 0;
       dfs(grid,i+1,j);
       dfs(grid ,i,j+1);
       dfs(grid,i-1,j);
       dfs(grid,i,j-1);
   }
    int numEnclaves(vector<vector<int>>& grid) {
       memset(vis,false , sizeof(vis));
       int cnt = 0;
       for(int i  = 0 ;i<grid.size() ; i++) {
           for(int j = 0;j<grid[i].size();j++){
               if(i == 0 || i == grid.size()-1 ||j ==0 ||j==grid[0].size()-1){
                   dfs(grid,i,j);
               }
           }
       }
         for(int i  = 0 ;i<grid.size() ; i++) {
           for(int j = 0;j<grid[i].size();j++){
               if(grid[i][j]){
                  cnt++;
               }
           }
       }
       return cnt;
    }
};