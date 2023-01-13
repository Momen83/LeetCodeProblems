class Solution {
public:
    vector<int>Graph[100001];
    int subTree[100001];
    string label;
    int ans = 1;
    int dfs(int node , int p){
         if(Graph[node].empty()){
           return 1;
         }
         int path1 = 0 , path2 = 0;
        for(auto ch:Graph[node]){
         
                int len = dfs(ch,node);
                if(label[node] !=label[ch]){
                   if(len >path1){
                       path2 = path1;
                       path1 = len;
                   }
                   else if(len >path2){
                       path2 = len;
                   }
                }
        }
        ans = max({ans, path1+path2 + 1});
        return path1 + 1 ;
    }
    int longestPath(vector<int>& parent, string s) {
      for(int i = 1 ;i<parent.size();i++){
          Graph[parent[i]].push_back(i);
      }
      label = s;
      dfs(0,-1);
      return ans;
    }
};
