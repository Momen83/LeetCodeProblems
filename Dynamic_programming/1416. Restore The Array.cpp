class Solution {
public:
    const int Mod = 1e9 + 7;
    int dp[100001];
    long long get_val(string &s , int st ,int en){
        long long ans = 0;
        for(int i = st ; i<=en ;i++){
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
    int solve(string &s , int start , int k) {
        if(start ==s.size()){
            return 1;
        }
        if(s[start] =='0'){
            return 0;
        }
        int &ans = dp[start];
        if(ans !=-1)return ans;
        ans =  0;
        for(int end = start ; end <s.size() ; end++){
            long long val = get_val(s , start , end) ;
            if(val >k){
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
