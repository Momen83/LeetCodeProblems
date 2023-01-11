class Solution {
public:
int dp[59];
  int solve(int val){
      
      if(val ==2)return 1;
      int &ret = dp[val];
      if(ret!=-1)return ret;
       ret = 1;
      for(int i =1;i<val;i++){
          int op1 =i * solve(val - i);
          int op2 = i *(val-i);
          ret = max({ret,op1,op2}); 
        
      }
      return ret;
  }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
