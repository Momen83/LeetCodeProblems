class Solution {
public:
    int dx[8] = {+1,-1,+0,+0,+1,-1,+1,-1};
    int dy[8] = {+0,+0,+1,-1,+1,-1,-1,+1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>>dis(n,vector<int>(m,1e9));
      queue<pair<int,int>>q;
      if(grid[0][0] ==1)return -1;
      q.push({0,0});
      dis[0][0] = 1;
      grid[0][0] = 1;
      while(!q.empty())
      {
          pair<int,int>curr = q.front();
          q.pop();
          for(int i = 0 ;i<8;i++){
              int newX =dx[i] + curr.first;
              int newY =dy[i] + curr.second;
              if(newX <0  || newX ==n ||newY <0 ||newY == m ||grid[newX][newY]){
                  continue;
              }
              grid[newX][newY] = 1;
              if(dis[newX][newY] >dis[curr.first][curr.second] + 1){
                dis[newX][newY] = dis[curr.first][curr.second] + 1;
                q.push({newX,newY});
              }
          }
      }
      return dis[n-1][m-1] ==1e9 ?-1: dis[n-1][m-1];
    }
};
