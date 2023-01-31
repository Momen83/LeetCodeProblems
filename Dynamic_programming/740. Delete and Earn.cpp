class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mxSize = *max_element(nums.begin() , nums.end());
        vector<int>freq(mxSize+1);
        vector<int>dp(mxSize+1);
      
        for(int i = 0 ;i<nums.size() ; i++){
            freq[nums[i]]++;
        }
         dp[0] = freq[0] * 0;
        for(int i = 1 ;i<=mxSize;i++){
          dp[i] = max(dp[i-1] ,freq[i]*i+ (i-2 >=0 ? dp[i-2] :0));
        }
        return dp[mxSize];

    }
};
