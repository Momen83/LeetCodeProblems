class Solution {
public:
int par[100001];
int GroupSize[100001];
int cnt;
int add = 0;
void init(int sz){
    for(int i=0;i<sz;i++){
        par[i]=i;
        GroupSize[i]=1;
    }
   cnt=sz;
}
int find( int u){
    if(u==par[u])return u;
    return par[u]=find(par[u]);
}
void Merge(int u,int v){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2){
       add++;
       return;
    }
    if(GroupSize[p1] >GroupSize[p2])swap(p1,p2);
    par[p1]=par[p2];
    GroupSize[p2]+=GroupSize[p1];
    cnt--;
}
    int makeConnected(int n, vector<vector<int>>& connections) {
             init(n);
             for(int i=0;i<connections.size();i++){
              Merge(connections[i][0] , connections[i][1]);
              }
        return cnt-1 <=add ?cnt-1 :-1;
    }
};
