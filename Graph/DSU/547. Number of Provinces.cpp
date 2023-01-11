class Solution {
public:
int par[201];
int GroupSize[201];
int cnt;
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
    //cout<<p1<<' '<<p2<<'\n';
    //cout<<u<<' '<<v<<'\n';
    if(p1==p2)return;
    if(GroupSize[p1] >GroupSize[p2])swap(p1,p2);
    par[p1]=par[p2];
    GroupSize[p2]+=GroupSize[p1];
    cnt--;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        init(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j])
                Merge(i,j);
            }
        }
    
        return cnt;
    }
};
