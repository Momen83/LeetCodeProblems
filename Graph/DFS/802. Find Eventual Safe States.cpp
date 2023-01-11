class Solution {
public:
     int col[10001];
     bool dfs(int node ,  vector<vector<int>>&adj  ){
         if(col[node]){
             return col[node] ==2;
         }
         col[node] = 1;
         for(auto ch:adj[node]){
            if (col[ch] == 1 || !dfs(ch, adj))
                return false;
         }
         col[node] = 2;
         return true;
     }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        vector<vector<int>>adj = vector<vector<int>>(graph.size());
        for(int i = 0;i<graph.size() ; i++){
                  for(int j = 0 ;j<graph[i].size();j++){
                     adj[i].push_back(graph[i][j]);
                  }
            }
        for(int i =0 ; i<adj.size();i++){
            if(dfs(i,adj))ans.push_back(i);
        }
        return ans;
    }
};
