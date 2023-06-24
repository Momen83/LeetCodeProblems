#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DSU{
    public:
    vector<int>parent;
    vector<int>Group;
    DSU(int n){
        for(int i = 0 ; i <=n ; i++){
            parent.push_back(i);
            Group.push_back(1);
        }
    }
   int find(int u) {
       if(parent[u] ==u)return u;
       return parent[u] = find(parent[u]);
   }
    void Merge(int u , int v) {
        int p1 = find(u);
        int p2 = find(v);
        if(p1 ==p2){
            return;
        }
        else{
            if(Group[p1] > Group[p2])swap(p1,p2);
            parent[p1] = p2;
            Group[p2] += Group[p1];

        }
    }
    int getSize(int node) {
        int p = find(node);
        return Group[p];
    }
};
int main() {
    int n;cin>>n;
    DSU ds(n);
    int q;cin>>q;
    while(q--) {
        char op;cin>>op;
        if(op =='M') {
            int u ,v;cin>>u>>v;
            ds.Merge(u, v);
        }
        else{
            int node;cin>>node;
            cout<<ds.getSize(node)<<'\n';
        }
    }
}
