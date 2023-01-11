class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    void dfs(int node , vector<vector<int>>& graph ){
         temp.push_back(node);
        if(node  == graph.size() - 1){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto ch :graph[node]){
          dfs(ch,graph);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,graph);
        return ans;
    }
};
