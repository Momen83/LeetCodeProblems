class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      vector<vector<int>>Graph(n+1);
     int  m = manager.size();
     vector<int>times(n);
      for(int i  = 0;i<m;i++){
          if(manager[i] ==-1)continue;
          Graph[manager[i]].push_back(i);
      }
      queue<pair<int,int>>q;
      q.push({headID,0});

      int ans = 0;
      while(!q.empty()){
          int curr = q.front().first;
          int time = q.front().second;
          time +=informTime[curr];
          q.pop();
          for(auto ch:Graph[curr]){
                 q.push({ch,time});
          }
          ans = max(ans,time);
      }
     return ans;
    }
};
