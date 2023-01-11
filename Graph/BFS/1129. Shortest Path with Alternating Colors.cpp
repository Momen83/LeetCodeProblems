class Solution {
public:
    vector<int>rE[401];
    vector<int>bE[401];
    bool vis[401][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         for(int i = 0 ;i<redEdges.size();i++){
             rE[redEdges[i][0]].push_back(redEdges[i][1]);
         }
          for(int i = 0 ;i<blueEdges.size();i++){
             bE[blueEdges[i][0]].push_back(blueEdges[i][1]);
         }
         queue<pair<int,int>>q;
         vector<int>dis(n,-1);
         q.push({0,0});
         q.push({0,1});
         vis[0][0] = vis[0][1] = true;
         int level = 0;
         while(!q.empty()){
             int sz = q.size();
             while(sz--){
                int node = q.front().first;
             int c = q.front().second;
             q.pop();
             if(dis[node] == -1){
                 dis[node] = level;
             }
             auto g = (c==1 ?bE:rE);
               for(auto ch:g[node]){
                   if(!vis[ch][c]){
                             vis[ch][c] = true;
                             q.push({ch,!c});
                   }
               }
             }
             level++;
             
        }

         return dis;
    }
};
