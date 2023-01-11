class Solution(object):
   
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def dfs(grid, i, j):
             if i <0 or i==len(grid) or j <0 or j==len(grid[i])or grid [i][j] =="0":
                return 
             grid[i][j] = "0"
             dfs(grid,i,j-1)
             dfs(grid,i,j+1)
             dfs(grid,i+1,j)
             dfs(grid,i-1,j)
        n = len(grid)
        m = len(grid[0])
        cnt = 0
    
        for i in range(n):
            for j in range(m):
               if grid[i][j] =="1":
                   cnt = cnt+1
                   dfs(grid,i,j)
                   

        return cnt
