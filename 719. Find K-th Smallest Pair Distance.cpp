bool isValid(vector<int>& nums,int val , int k){
    int order  = 0;
    int l = 0 , h = 1;
    int n = nums.size();
    while(h<n){
      while(nums[h] - nums[l]  >val)l++;
      order +=(h-l);
      h++;
    }
    return order>=k;
}
class Solution {
public:
    
    int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
      int l = 0 ,r = nums.back() - nums.front();
      int ans = 0 ;
      while(l<=r){
          int mid = l +(r-l)/2;
         if(isValid(nums,mid,k))
         {
           ans = mid;
           r = mid-1;
         }
         else{
           l =mid+1;
         }
      }
      return ans;
    }
};
