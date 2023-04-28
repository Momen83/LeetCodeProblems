class Solution {
public:
struct DSU
{
    vector<int>parent;
    vector<int>GroupSize;
    vector<int>edges;
    int comp;
    DSU(int n , int m)
    {
        int mxSize = max(n , m ) + 5;
        comp = n;
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
             comp--;
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
    bool isSame(string &s1 , string &s2) {
        int diff = 0;
        if(s1.size() !=s2.size()) return false;
        for(int i = 0 ; i<s1.size() ; i++) {
            if(s1[i] !=s2[i]) {
                diff++;
            }
        }
        return diff == 2 || diff ==0;
    }
};
    int numSimilarGroups(vector<string>& strs) {
       map<string,int>strToId;
       int id = 1;
       for(int i = 0 ; i <strs.size() ; i++) {
           if(strToId.find(strs[i]) ==strToId.end()) {
               strToId[strs[i]] = id++;
           }
       }
        int sz = strToId.size();
        DSU D = DSU(sz ,sz);
       for(int i = 0 ; i<strs.size() ; i++) {
          for(int j = 0  ; j<strs.size() ; j++) {
              if(D.isSame(strs[i],strs[j])) {
                  D.update(strToId[strs[i]],strToId[strs[j]]);
              }
          }
       }
      
        return D.comp;


    }
};
