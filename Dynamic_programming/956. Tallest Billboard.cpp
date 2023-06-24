class Solution {
public:
    int dp[21][10001];
    int solve(vector<int>& rods,int index , int sum) {
        if(index ==rods.size()){
            return sum == 5000 ? 0 : INT_MIN;
        }
        int &ans = dp[index][sum];
        if(ans !=INT_MIN)return ans;
        // First option  take element to first set
        ans = max(ans , rods[index] + solve(rods,index + 1 ,sum + rods[index]));
      // Second option   take element to second set
       ans = max(ans ,  solve(rods,index + 1 ,sum - rods[index]));
       // Third option leave element
       ans = max(ans , solve(rods , index + 1 , sum));

       return ans;
    }
    int tallestBillboard(vector<int>& rods) {
        for(int i = 0 ; i < 21 ; i++ ) {
            for(int j = 0 ; j < 10001 ; j++){
                dp[i][j] = INT_MIN;
            }
        }
        return solve(rods , 0 , 5000);
    }
};
