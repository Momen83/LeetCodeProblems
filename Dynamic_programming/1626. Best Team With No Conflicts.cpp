class Solution {
public:
   int dp[1001][1003];
    int solve(vector<pair<int,int>>&total,int idx , int prev){
        if(idx == total.size()){
            return 0;
        }
        int &ret = dp[idx][prev];
        if(ret!=-1)return ret;
        int take = 0;
        int leave = 0;
        ret = 0;
        if(prev == 1002 || total[idx].second <=total[prev].second){
           take = solve(total , idx+1 , idx) + total[idx].second;
           leave = solve(total , idx+1 , prev);
           ret = max(take ,leave);
        }
        else{
            leave = solve(total , idx+1 , prev);
            ret = max(ret , leave);
        }
        return ret;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       int n= scores.size(); 
       int mx = 0;
       vector<pair<int,int>>total;
       for(int i  = 0 ; i< n;i++){
          total.push_back({ages[i] , scores[i]});
       }
       sort(total.begin(), total.end() , greater<pair<int,int>>());
       memset(dp, -1 ,sizeof(dp));
       return solve(total, 0,1002);
       }
};
