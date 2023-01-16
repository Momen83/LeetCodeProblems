class Solution {
public:
int par[30001];
int GroupSize[30001];
void init(int sz){
    for(int i=0;i<sz;i++){
        par[i]=i;
        GroupSize[i]=1;
    }
   
}
int find( int u){
    if(u==par[u])return u;
    return par[u]=find(par[u]);
}
void Merge(int u,int v){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2)return;
    if(GroupSize[p1] >GroupSize[p2])swap(p1,p2);
    par[p1]=par[p2];
    GroupSize[p2]+=GroupSize[p1];
}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        init(n);
        vector<vector<int>>Graph;
        Graph = vector<vector<int>>(n+1);
        int ans = 0;
        for(int i = 0 ; i<edges.size();i++){
            Graph[edges[i][0]].push_back(edges[i][1]);
            Graph[edges[i][1]].push_back(edges[i][0]);
        }
         map<int, vector<int>> freq;
        for(int i = 0 ;i<n;i++){
            freq[vals[i]].push_back(i);
        }

        for(int i = 0 ;i<freq.size();i++){
          for(int j = 0 ;j<freq[i].size();j++){
              int node = freq[i][j];
               for(auto ch :Graph[node]){
                   if(vals[node]>=vals[ch]){
                       Merge(ch, node);
                   }
               }
          }
         map<int,int>fr;
          for(auto e:freq[i]){
              fr[find(e)] ++;
          }
           for(auto ff:fr){
               ans+= (ff.second * (ff.second+1))/2;
          }
        }
        
        return ans;
    }
};
