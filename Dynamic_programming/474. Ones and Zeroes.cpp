class Solution {
public:
    int dp[601][101][101];
    vector<pair<int,int>>oz;
    int cz,co;
    int solve(int idx , int cntZeros , int cntOnes ) {
            if(cntZeros > cz || cntOnes > co){
                return INT_MIN;
            }
            if (idx == oz.size()){
                return cntZeros <=cz && cntOnes <=co ? 0 : INT_MIN;
            }
            int &ans = dp[idx][cntZeros][cntOnes];
            if (ans != -1) return ans;
            ans = 0;
            int op1 = solve(idx + 1 , cntZeros + oz[idx].second , cntOnes + oz[idx].first) + 1;
            int op2 = solve(idx + 1, cntZeros , cntOnes);
            ans =  max({op1 , op2 , ans});
            return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        cz = m;
        co = n;
         for(int i = 0 ; i < strs.size() ; i++) {
             int z = 0 , o =0;
             for(int j = 0 ; j < strs[i].size() ; j++){
                 if(strs[i][j] =='0')z++;
                 else o++;
             }
             oz.push_back({o,z});
         }
         memset(dp , -1 ,sizeof(dp));
         return solve(0,0,0);
    }
};
