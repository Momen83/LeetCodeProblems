class Solution {
public:
struct DSU
{
    vector<int>parent;
    vector<int>GroupSize;
    vector<int>edges;
    DSU(int n , int m)
    {
        int mxSize = max(n , m ) + 5;
        parent = vector<int>(mxSize);
        GroupSize = vector<int>(mxSize);
        edges = vector<int>(mxSize , 0);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            GroupSize[i] = 1;
        }
    }

    int find(int i)
    {
        if(parent[i] == i)  return i;

        return parent[i] = find(parent[i]);
    }

    bool SameGroup(int x, int y)
    {
        int leader1 = find(x);
        int leader2 = find(y);

        return leader1 == leader2;
    }


    void update(int x, int y)
    {

        int u = find(x);
        int v = find(y);
        if(u == v) {edges[u] ++;  return;}

        else
        {
            if(GroupSize[u]> GroupSize[v])swap(u,v);
            parent[u] =  v;
            GroupSize[v] += GroupSize[u];
            //cout<<v<<'\n';
            edges[v] += edges[u] + 1;
        }
    }

    int GetSize(int x)
    {
        int leader = find(x);
        return GroupSize[leader];
    }
    int GetEdges(int x){
        int leader = find(x);
        return edges[leader];
    }
};
int calulateConnected(vector<vector<int>>& edges , DSU &temp , int t) {

      int cntConnected = 0;

      for(int i = 0 ; i<edges.size() ; i++) {
         int u = edges[i][1];
         int v = edges[i][2];
         int type = edges[i][0];
         if(type ==t) {

             if(!temp.SameGroup(u,v)) {
              cntConnected++;
              temp.update(u,v);
            }
         }
        
      }

      return cntConnected;
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      DSU AliceCommon  = DSU(n ,n);
      DSU BobCommon = DSU(n,n);
      int CommonConnected = calulateConnected(edges,AliceCommon ,3);
      BobCommon.parent = AliceCommon.parent;
      BobCommon.GroupSize = BobCommon.GroupSize;
      int AliceConnected = calulateConnected(edges , AliceCommon,1);
      int BobConnected = calulateConnected(edges , BobCommon,2);

    
      if(CommonConnected + AliceConnected !=n-1  || CommonConnected + BobConnected !=n-1  )return -1;

      int unusedEdges = edges.size() - (CommonConnected + AliceConnected  + BobConnected);
      return unusedEdges;
      
    }
};
