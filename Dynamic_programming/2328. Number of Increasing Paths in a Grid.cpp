class Solution {
public:
    int dx[4] = {+1,-1,+0,+0};
    int dy[4] = {+0,+0,+1,-1};
    long long dp[1001][1001];
    const int Mod = 1e9 + 7;
    long long  solve(int i , int j ,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[i].size() ;
        if(i == n && j ==m){
            return 0;
        }
        long long  &ans = dp[i][j];
        if(ans !=-1)return ans;
        ans = 0;
        for(int ii = 0 ; ii < 4 ; ii++){
            int newX = i + dx[ii];
            int newY = j + dy[ii];
            if(newX >=0 && newX < n && newY >=0 && newY < m) {
                if(grid[i][j] < grid[newX][newY]){
                    ans = (ans%Mod + ((solve(newX,newY,grid) + 1)%Mod))%Mod;
                }
            }
        }
        return ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        long long ans = 0;
        memset(dp , -1 ,sizeof(dp));
        for(int i = 0 ; i< grid.size() ; i ++){
            for(int j = 0 ; j<grid[i].size() ; j++) {
                  ans = (ans%Mod + ((solve(i,j,grid) + 1)%Mod))%Mod;
            }
        }
        return ans;
    }
};
