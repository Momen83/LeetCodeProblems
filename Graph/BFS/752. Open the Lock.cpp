class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string, bool>vis;
        int n = target.size();
        string st(n,'0');
        for(int i = 0 ;i<deadends.size();i++){
            vis[deadends[i]] = true;
        }
        queue<pair<string,int>>q;
        if(vis[st])return -1;
        q.push({st,0});
        vis[st] = true;
        while(!q.empty()){
             string lock = q.front().first;
            
             int value = q.front().second;
              q.pop();
             if(lock == target){
                 return value;
             }
            
             for(int i = 0 ;i<lock.size() ; i++){
                 string temp = lock;
                 int op1 = ((lock[i] -'0') + 11)%10;
                 int op2 = ((lock[i]-'0') + 9)%10;
                 temp[i] = op1+'0';
                 if(vis.find(temp) == vis.end()){
                     q.push({temp,value+1});
                     vis[temp] = true;
                 }
                 temp[i] = op2+'0';
                    if(vis.find(temp) == vis.end()){
                     q.push({temp,value+1});
                     vis[temp] = true;
                 }
             }
        }
        return -1;

    }
};
