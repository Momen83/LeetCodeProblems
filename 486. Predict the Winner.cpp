class Solution {
public:
pair<int,int>dp[25][25];
pair<int,int> solve(vector<int>&nums,int i, int j , int turn)
{
    if(i >j){
        return {0,0};
    }
    if(dp[i][j].first !=-1 ||dp[i][j].second !=-1)return dp[i][j];
   
    if(turn ==0)
    {
        pair<int,int> op1 = solve(nums, i+1 ,j,!turn);
         pair<int,int> op2 = solve(nums, i ,j-1,!turn);
         op1.first  += nums[i];
         op2.first +=  nums[j];
         if(op1.first >op2.first){
             dp[i][j] = op1;
         }
         else{
             dp[i][j] = op2;
         }
    }
    else
    {
         pair<int,int> op1 = solve(nums, i+1 ,j,!turn);
         pair<int,int> op2 = solve(nums, i ,j-1,!turn);
         op1.second  += nums[i];
         op2.second +=  nums[j];
         if(op1.second >op2.second){
             dp[i][j] = op1;
         }
         else{
             dp[i][j] = op2;
         }
    }
    return dp[i][j];
}
    bool PredictTheWinner(vector<int>& nums) {
        for(int i = 0;i<24;i++)
        {
            for(int j =0;j<24;j++)
            {
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }
        pair<int,int>res = solve(nums,0,nums.size()-1,0);
        return res.first >=res.second;

    }
};
