class Solution {
public:
    const int Mod = 1e9 + 7;
    int dp[100001];
  
    int solve(string &s , int start , int k) {
        if(start ==s.size()){
            return 1;
        }

        int &ans = dp[start];
        if(ans !=-1)return ans;
        ans =  0;
           long long val = 0;
        for(int end = start ; end <s.size() ; end++){
           val = val * 10 + (s[end] - '0');
            if(val >k || val <1){
                break;
            }
            ans = ((ans %Mod) + (solve(s , end + 1,k)%Mod))%Mod;
        }
        return ans;
    }
    int numberOfArrays(string s, int k) {
        memset(dp , -1 ,sizeof(dp));
        return solve(s , 0 , k);
    }
};
