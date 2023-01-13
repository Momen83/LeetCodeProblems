class Solution {
public:
   bool matching(string s1 , string s2){
       int cnt = 0 ;
       for(int i = 0 ;i<s1.size();i++){
           cnt+=(s1[i] !=s2[i]);
       }
       return  cnt ==1;
   }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string,bool>vis;
        if(startGene == endGene)return 0;
        queue<string>q;
        int ans = 0;
        q.push(startGene);
        vis[startGene] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                for(int i = 0 ;i<bank.size();i++){
                    if(matching(curr,bank[i]) &&vis.find(bank[i]) ==vis.end()){
                        if(bank[i] ==endGene){
                            return ans+1;
                        }
                        q.push(bank[i]);
                        vis[bank[i]] = true;
                     }
                }
            }
            ans++;
        }
        return -1;
    }
};
