class Solution {
public:
    int target;
    vector<int>people_val;
    vector<int>ans;
    int memo[60][(1 << 16) + 1];
    int solve(int idx , int mask) {
        if(idx ==people_val.size()){
            return mask == target ? 0 : 1e9;
        }
        int &ret = memo[idx][mask];
        if(ret != -1) return ret;
        ret = solve(idx + 1 , mask);
        ret = min(ret , solve(idx  + 1 ,mask | people_val[idx]) + 1);
        return ret;
    }
    void buildPath(int idx , int mask) {
          if(idx ==people_val.size()){
            return;
        }
        if(solve(idx + 1 , mask) < solve(idx  + 1 ,mask | people_val[idx]) + 1)
        {
            buildPath(idx + 1 , mask);
        }
        else{
            ans.push_back(idx);
            buildPath(idx + 1 , mask | people_val[idx]);
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string,int>mp;
        memset(memo , -1 ,sizeof(memo));
        target = 0;
        int p = 1;
        for(int i = 0 ; i < req_skills.size() ;i++ ){
            target = (target | p);
            mp[req_skills[i]] = p;
            p = p * 2;
        }
        for(int i = 0 ; i < people.size() ; i++){
            int val = 0;
            for(int j = 0 ; j < people[i].size() ; j++) {
                val = (val | mp[people[i][j]]);
            }
            people_val.push_back(val);
        }
        int res = solve(0,0);
        buildPath(0,0);
        return ans;
        
    }
};
