class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pref(n+1);
        int mxDiff = 1e9 , idx  = 0;
        for(int i = 0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }
        for(int i = 0;i<n;i++){
            int f =  pref[i+1]/(i+1);
            int s =  0 ;
            if(n-i-1!=0){
               s = (pref[n] - pref[i+1]) /(n-i-1);
            }
            if(mxDiff >abs(f-s)){
                mxDiff = abs(f-s);
                idx = i;
            }
        }
        return idx;
    }
};
