class Solution {
    int  dfs(int[][] grid , int i , int j){
        if(i<0 ||i ==grid.length ||j <0 ||j==grid[i].length ||grid[i][j] ==0)
        return 0 ;
        grid[i][j] = 0;
        int ans = 0;
        ans += dfs(grid,i+1,j) +  dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1) +1;
        return ans;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int cnt = 0;
        for(int i  = 0;i<grid.length;i++){
            for(int j = 0;j<grid[i].length;j++){
                if(grid[i][j] ==1){
                    cnt = Math.max(cnt,dfs(grid,i,j));
                    
                }
            }
        }
        return cnt/4;
    }
}
