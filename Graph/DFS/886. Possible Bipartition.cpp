class Solution {
public:
   int col[2001];
   bool isCycle;
   void dfs(vector<vector<int>>&adj,int node , int c){
       col[node] =c;
       for(auto ch :adj[node]){
           if(col[ch] ==-1){
               dfs(adj,ch, c^1);
           }
           else if (col[ch] == col[node]){
               isCycle = true;
           }
       }
   }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        isCycle = false;
       for(int i = 1 ;i<=n;i++)col[i] = -1;
        vector<vector<int>>adj;
        adj = vector<vector<int>>(n+1);
        for(int i = 0 ;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i = 1;i<=n;i++){
            if(col[i] ==-1){
                dfs(adj,i,0);
                if(isCycle)return false;
            }
        }
        return true;
    }
};
