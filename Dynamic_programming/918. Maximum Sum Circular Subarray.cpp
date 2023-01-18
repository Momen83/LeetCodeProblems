class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = -1e9;
        int n = nums.size();
        for(int i = 0 ;i<nums.size();i++){
            mx = max(mx,nums[i]);
        }
        if(mx <0)return mx;
        int sumSuff , sumPref = 0;
        vector<int>mxSuff(n+1 , -1e9);
        int mxSum = -1e9;
        
        for(int i = n-1 ;i>=0;i--){
            sumSuff+=nums[i];
            mxSuff[i] = max(mxSuff[i+1] , sumSuff);
            mxSum = max(mxSuff[i] , mxSum);
        }
        int sum = 0;
          for(int i = 0 ;i<nums.size();i++){
            if(sum+nums[i] >=0 ){
                 mxSum = max(mxSum , max(sum  ,sum+nums[i]));
                 sum+=nums[i];
            }
            else{
                mxSum = max(sum,mxSum);
                sum = 0;
            }
             sumPref +=nums[i];
             mxSum = max(mxSum ,sumPref );
              mxSum = max(mxSum , sumPref + mxSuff[i+1] );
        }
        mxSum = max(sum ,mxSum);
        return mxSum;
    }
};
