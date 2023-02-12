class Solution {
public:
   int s ;
   int inc;
   long long ans;
    int dfs( vector<vector<int>>&Graph , vector<bool>&vis,int node)
    {
    
        vis[node] = 1;
        int cnt = 1;
        for(auto ch:Graph[node]){
            if(!vis[ch]){
              cnt +=  dfs(Graph , vis , ch);
            }
        }
        long long totalCapacity=  cnt /s + (cnt%s !=0?1:0);
        if(node !=0)ans+=totalCapacity;
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
       vector<vector<int>>Graph;
       int n = roads.size() ;
       s = seats;
       Graph = vector<vector<int>>(n+1);
       vector<bool>vis(n+1 ,false);
       for(int i = 0 ; i<n;i++){
           Graph[roads[i][0]].push_back(roads[i][1]);
           Graph[roads[i][1]].push_back(roads[i][0]);
       }
       int cnt = dfs(Graph,vis , 0);
       return ans;


    }
};
