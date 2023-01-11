class Solution {
public:
bool vis[101][101];
int dfs(int i , int j , vector<vector<int>>& grid ){
    if(i <0 || i==grid.size() ||j<0 ||j==grid[i].size()){
        return 0 ;
    }
    if(vis[i][j]  ||grid[i][j] ==1){
        return 1 ;
    }
    vis[i][j] = true;
    int ans = 1;
    ans &= dfs(i+1, j ,grid);
    ans &= dfs(i-1, j ,grid);
    ans &= dfs(i,j+1 ,grid);
    ans &= dfs(i,j-1 ,grid);
    return ans;

}
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
       for(int i  = 0 ;i<grid.size();i++){
           for(int j = 0 ;j<grid[i].size();j++){
               if(grid[i][j] ==0 &&!vis[i][j]){
                   ans += dfs(i,j,grid);
               }
           }
       }
       return ans; 
    }
};
