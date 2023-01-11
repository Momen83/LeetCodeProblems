class Solution {
public:
   vector<int> graph[100001];
   int dfs(int node , int p , vector<bool>& hasApple ){
       if(graph[node].empty()){
           return 0;
       }
       int c = 0;
       int ans = 0;
       for(auto ch:graph[node]){
           if(ch!=p){
              c = dfs(ch,node,hasApple);
              if(hasApple[ch] || c >0){
                  ans += c + 2;
              }
           }
       }
       return ans;
   }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i = 0 ;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,-1,hasApple);
    }
};
