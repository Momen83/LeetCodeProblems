class Solution {
public:
 double dp[101][101];
 double pref[101];
    double solve(vector<int>& nums,int idx,int subs){
          if(idx == nums.size())
            return 0;
        double &ret = dp[idx][subs];
        if(ret != -1)
        return ret ;

        if(subs == 1)
        {
          
            int sz = nums.size() - idx;
            double av = (pref[nums.size()] - pref[idx])/sz;
            return av;
        }

         ret = 0;
        double sum = 0;

        for(int i = idx ; i<=nums.size()-subs ; i++)
        {
            sum+= nums[i];
            int sz = (i-idx+1);
            double op =  solve(nums, i+1 , subs-1 ) +(sum/sz);
            ret = max(ret ,op);
        }

        return ret;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        for(int i = 0 ;i<101;i++){
            for(int j = 0 ;j<101;j++){
                dp[i][j] = -1;
            }
        }
        pref[0] = 0.0 ;
        for(int i  = 0 ;i<nums.size();i++){
            pref[i+1] = pref[i] + nums[i];
        }
        
        return solve(nums,0 ,k);

    }
};
