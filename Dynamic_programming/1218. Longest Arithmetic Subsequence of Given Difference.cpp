class Solution {
public:
    //map<int,vector<int>>mp;
     vector<int>pos[40005];
    int longestSubsequence(vector<int>& arr, int difference) {
       for(int i = 0 ; i < arr.size() ; i++) {
           int currVal = arr[i];
           if(arr[i] < 0)  currVal +=30001;
           pos[currVal].push_back(i);
       }
       vector<int>dp(arr.size() , 1);
       for(int i = 0 ; i < arr.size() ; i++) {
           int currVal = arr[i] + difference;
           if(currVal < 0)  currVal +=30001;
           int idx = i + 1 ;
           if(pos[currVal].size() > 0)
           {
                int st = 0 , en = pos[currVal].size() - 1,mid;
                int firstIdx = -1;
                 while(st <= en) {
                    mid = (st + en)/2;
                     
                   if(pos[currVal][mid] >=idx) {
                      firstIdx = pos[currVal][mid];
                      en = mid - 1;
                    }
                     
                   else st = mid + 1;
             }
               
           if(firstIdx !=-1)
              dp[firstIdx] = max(dp[firstIdx] , dp[i] + 1);
               
           }
          
       }

      return *max_element(dp.begin() , dp.end());
     
    }
};
