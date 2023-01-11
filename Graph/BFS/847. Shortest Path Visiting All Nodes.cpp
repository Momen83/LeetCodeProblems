class Solution {
public:

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int total = (1<<n)-1;

        queue<pair<int, pair<int,int>>> q;
        set<pair<int,int>> vis;
        for(int i=0;i<n;i++){
            int mask = (1<<i);
            vis.insert({i,mask});
            q.push({i,{0,mask}});
        }
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second.first;
            int mask = q.front().second.second;
            q.pop();

            for(auto ch: graph[node]){
                int newmask = (mask | (1<<ch));
                
                if(newmask == total)return dist+1;
                else if(vis.count({ch,newmask}))continue;
                else{
                    q.push({ch, {dist+1, newmask}});
                    vis.insert({ch, newmask});
                }
            }
        }
        return 0;
    }
    
};
