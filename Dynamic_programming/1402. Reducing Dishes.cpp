class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& satisfaction , int idx , int time){
        if(idx ==satisfaction.size()){
            return 0;
        }
        int op1 = 0;
        int op2 = 0;
        int &ret = dp[idx][time];
        if(ret!=INT_MIN){
            return ret;
        }
        op1 = solve(satisfaction , idx+1 , time+1) + satisfaction[idx] * time;
        op2 = solve(satisfaction , idx+1 , time);
        return ret = max(op1 , op2);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        for(int i = 0 ; i<=500 ;i++){
          for(int j =0 ; j<=500;j++){
              dp[i][j] = INT_MIN;
          }
        }
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction , 0 ,1);
    }
};
