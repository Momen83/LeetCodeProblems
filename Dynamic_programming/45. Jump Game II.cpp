class Solution {
public:
   int jump(vector<int>& nums) {
       int n=nums.size();
  vector<int>dp(n);
  for(int i=0;i<n;i++)dp[i]=INT_MAX;
  dp[0]=0;
  for(int i=0;i<n;i++)
  {
    
      for(int j=1;j<=nums[i];j++){
          if(i+j<nums.size())
          {
               dp[i+j]=min(dp[i+j],dp[i]+1);
          }
        
      }
  }
    return dp[nums.size()-1];
}
};
