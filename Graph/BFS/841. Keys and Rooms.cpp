class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n = rooms.size();
       queue<int>q;
       vector<int>vis(n,false);
       vis[0] = true;
       for(int i =  0 ;i<rooms[0].size();i++){
           q.push(rooms[0][i]);
       }
       while(!q.empty()){
           int curr = q.front();
           q.pop();
           vis[curr] = true;
           for(auto ch:rooms[curr]){
               if(!vis[ch]){
                   q.push(ch);
               }
           }
       }
       bool ok =true;
       for(int i = 0 ;i<n;i++)ok &=vis[i];
       return ok;
    }
};
