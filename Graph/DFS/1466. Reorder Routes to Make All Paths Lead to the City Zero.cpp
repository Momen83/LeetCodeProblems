class Solution {
public:
    vector<int> graph[50001];
    vector<int>graph2[50001];
    bool vis[50001];
      queue<int>q;
    int cnt = 0;
    bool ok =false;
    void dfs(int node){
        vis[node] =true;
        for(auto ch:graph[node]){
            if(!vis[ch]){
                cnt++;
                dfs(ch);
            }
        }
        for(auto ch:graph2[node]){
            if(!vis[ch]){
                q.push(ch);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {

      for(int i = 0 ;i<connections.size();i++){
          graph[connections[i][0]].push_back(connections[i][1]);
          graph2[connections[i][1]].push_back(connections[i][0]);
      }
      int ans = 0;
    
      q.push(0);
      while(!q.empty()){
          int s = q.front();
          q.pop();
          dfs(s);
          ans+=cnt;
          cnt = 0;
      }
    
      return ans;

    }
};
