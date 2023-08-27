class Solution {
public:
    int dp[2001][2001];
    unordered_map<int,int>pos;
    int solve(int idx , int step , vector<int>&stones) {
        //cout<<idx<<' '<<step<<'\n';
        if(idx == stones.size() - 1){
            return 1;
        }
        int &ret = dp[idx][step];
        if(ret !=-1) return ret;
        ret = 0;
        if(pos.find(stones[idx] + step) != pos.end()){
            ret |= solve(pos[stones[idx] + step] , step ,stones);
        }
        if(pos.find(stones[idx] + step + 1) != pos.end()){
            ret |= solve(pos[stones[idx] + step + 1] , step  + 1 ,stones);
        }
        if(step - 1  > 0 && pos.find(stones[idx] + step - 1) != pos.end()){
            ret |= solve(pos[stones[idx] + step - 1] , step - 1 ,stones);
        }
        return ret;
        
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        if(stones[1] - stones[0] !=1 ) return false;
        for(int i = 0 ; i < stones.size() ; i++) {
            pos[stones[i]] = i;
        }
        return solve(1,1 , stones);
    }
   
};
