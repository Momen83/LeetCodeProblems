class Solution {
public:
    int memo[100001];
    int solve(vector<int>&nums,int idx){
        //cout<<idx<<'\n';
        if(idx <0)return 1;
        int &ans = memo[idx];
        if(ans !=-1)return ans;
        ans = 0;
        if(idx > 0 && nums[idx] - nums[idx - 1] ==0){
            ans |=solve(nums,idx - 2);
        }
        if(idx > 1 )
        {
            bool ok = (nums[idx] ==nums[idx-1] &&
                       nums[idx] == nums[idx - 2]);
            bool ok2 = (nums[idx] - 1 == nums[idx - 1]
                        && nums[idx] - 2 == nums[idx - 2]);
            if(ok ||ok2)
            ans |= solve(nums,idx -  3);
        }
        return ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return solve(nums,nums.size() - 1);
    }
};
