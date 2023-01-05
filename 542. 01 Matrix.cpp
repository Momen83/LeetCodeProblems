class Solution {
public:
    int dx[4] = {+1,-1,+0,+0};
    int dy[4] = {+0,+0,+1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n = mat.size();
         int m = mat[0].size();
      vector<vector<int>>dis(n,vector<int>(m,1e9));
      queue<pair<int,int>>q;
      for(int i = 0 ;i<n;i++){
          for(int j = 0 ;j<m;j++){
              if(mat[i][j] == 0){
                  q.push({i,j});
                  dis[i][j] = 0;
              }
      }
      }
      while(!q.empty())
      {
            pair<int,int>curr = q.front();
            q.pop();
            for(int i = 0 ;i<4;i++){
              int newX =dx[i] + curr.first;
              int newY =dy[i] + curr.second;
              if(newX <0  || newX ==n ||newY <0 ||newY == m ||mat[newX][newY] ==0){
                  continue;
              }
              mat[newX][newY] = 0;
              if(dis[newX][newY] >dis[curr.first][curr.second] + 1){
                dis[newX][newY] = dis[curr.first][curr.second] + 1;
                q.push({newX,newY});
              }
      }
      
    }
    return dis;
}
};
