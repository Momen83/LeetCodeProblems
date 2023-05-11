class Solution {
public:
    int dp[501][501];
    int solve(int i,int j , vector<int>& nums1, vector<int>& nums2 ) {
        if (i ==nums1.size() || j==nums2.size()){
            return 0;
        }
        int &ans = dp[i][j];
        if(ans !=-1)return ans;
        if(nums1[i] ==nums2[j]) {
            ans = solve(i+1 , j+1 , nums1,nums2)+1;
        }

        else {
            ans = max(solve(i , j+1 , nums1,nums2) , solve(i+1 , j , nums1,nums2) );
        }

        return ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
            memset(dp , -1 ,sizeof(dp));
            
            return solve(0,0 , nums1 , nums2);
    }
};
