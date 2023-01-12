class Solution {
public:
vector<int>Graph[100001];
int freq[100001][26];
void dfs(int node , int p , string &label){
      freq[node][label[node]-'a']++;
      for(auto ch:Graph[node]){
     if(ch !=p){
          dfs(ch,node,label);
         for(int i = 0 ;i<26;i++){
           freq[node][i]  += freq[ch][i];
         }

     }
  } 

}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(int i = 0 ;i<edges.size();i++){
           Graph[edges[i][0]].push_back(edges[i][1]);
           Graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1 , labels);
        vector<int>ans(n);
        for(int i = 0 ;i<n;i++){
            int cnt = 0;
            ans[i] = freq[i][labels[i] - 'a'];
        }
        return ans;

    }
};
