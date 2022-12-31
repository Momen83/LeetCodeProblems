class Solution {
public:
int dp[101][4];
int solve(int idx ,int prev,vector<int>&nums){
    if(idx>=nums.size())return 0;
    int &ret= dp[idx][prev];
    if(ret!=-1)return ret;
    int op1=0,op2=0;
    if(prev==3 || idx!=nums.size()-1){
        op1=solve(idx+2,idx!=0?prev:idx,nums)+nums[idx];
    }
    op2=solve(idx+1,prev,nums);
    return ret=max(op1,op2);
}
    int rob(vector<int>& nums) {
        for(int i=0;i<101;i++){
            for(int j=0;j<4;j++){
                dp[i][j]=-1;
            }
        }
        return solve(0,3,nums);
    }
};
