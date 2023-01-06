class Solution {
public:
  int dx[4] = {+1,-1,+0,+0};
  int dy[4] = {+0,+0,+1,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int n = maze.size();
         int m = maze[0].size();
           vector<vector<int>>dis(n,vector<int>(m,1e9));
           queue<pair<int,int>>q;
           int eX  = entrance[0];
           int eY =  entrance[1];
           dis[eX][eY] = 0;
           maze[eX][eY] = '+';
           q.push({eX,eY});
           while(!q.empty())
           {
                pair<int,int>curr = q.front();
                q.pop();
                for(int i = 0 ;i<4;i++){
              int newX =dx[i] + curr.first;
              int newY =dy[i] + curr.second;
              if(newX <0  || newX ==n ||newY <0 ||newY == m ||maze[newX][newY] =='+'){
                  continue;
              }
               maze[newX][newY] ='+';
              if(dis[newX][newY] >dis[curr.first][curr.second] + 1){
                dis[newX][newY] = dis[curr.first][curr.second] + 1;
                q.push({newX,newY});
              }
          }
         }
         int mnDis = 1e9;
         for(int i = 0 ;i<n;i++){
             for(int j = 0 ;j<m;j++){
                 if(i ==0 ||i ==n-1 ||j ==0 ||j ==m-1){
                     if(i !=eX ||j !=eY){
                         mnDis = min(mnDis,dis[i][j]);
                     }
                 }
             }
         }
         return mnDis ==1e9 ?-1 :mnDis;
    }
};
