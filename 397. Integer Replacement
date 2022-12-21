class Solution {
public:
   map<int,int>dp;
   int solve(int n)
   {
       if(n==1){
           return 0;
       }
       if(dp.find(n)!=dp.end()){
           return dp[n];
       }
      if(n%2==0){
          dp[n] = solve(n/2) + 1;
      }
      else{
          if(n == INT_MAX){
              dp[n] = solve(n-1);
          }
          else
          dp[n] = min(solve(n-1) ,solve(n+1) )+1;
      }
      return dp[n];
   }
    int integerReplacement(int n) {
       return solve(n);
    }
};
