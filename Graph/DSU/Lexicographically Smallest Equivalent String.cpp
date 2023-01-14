class Solution {
public:
int par[26];
void init(int sz){
    for(int i=0;i<sz;i++){
        par[i]=i;
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
    if(p1 <p2)swap(p1,p2);
    par[p1]=par[p2];
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        init(26);
        int sz = s1.size();
        for(int i = 0 ;i<sz;i++){
            Merge(s1[i] - 'a' , s2[i] - 'a');
        }
         sz = baseStr.size();
         for(int i = 0 ; i<26;i++){
             find(i);
         }
        for(int i = 0 ; i <sz;i++){
            baseStr[i] = par[baseStr[i]-'a'] + 'a';
        }
        return baseStr;
    }
};
