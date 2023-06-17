class Solution {
public:
    vector<int>pref1;
    vector<int>pref2;
    int dp[1001][1001];
    int solve(int i , int j , string &s1 , string &s2) {
        if(i ==s1.size() ){
            return pref2[s2.size()] - pref2[j];
        }
        if(j ==s2.size()) {
              return pref1[s1.size()] - pref1[i];
        }
        int &ans = dp[i][j];
        if(ans !=-1)return ans;
        ans = 0;
        if(s1[i] ==s2[j]){
            ans = solve(i + 1 , j + 1 ,s1 ,s2);
        }
        else{
            
            int op1 = solve(i + 1 , j , s1,s2) + int(s1[i]);
            int op2 = solve(i  , j + 1 , s1,s2) + int(s2[j]);
            ans = min(op1 ,op2 );
        }
        return ans;

    }
    int minimumDeleteSum(string s1, string s2) {
        pref1.push_back(0);
        pref2.push_back(0);
        memset(dp , -1 ,sizeof(dp));
        for(int i = 0 ; i <s1.size() ; i++ ) {
            pref1.push_back(pref1.back() + int(s1[i]));
        }
         for(int i = 0 ; i <s2.size() ; i++ ) {
            pref2.push_back(pref2.back() + int(s2[i]));
        }

        return solve(0,0,s1,s2);
    }
};
