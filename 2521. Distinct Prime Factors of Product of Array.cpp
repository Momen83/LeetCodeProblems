class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<bool>freq(1001);
        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            for(int j = 2 ;j*j<=val;j++){
                while(val%j==0){
                    freq[j] =true;
                    val/=j;
                }
            }
            if(val >1)freq[val] = true;
        }
        int cnt = 0;
        for(int i = 2;i<=1000;i++){
            cnt+=(freq[i] ==true);
        }
        return cnt;
    }
};
