class Solution {
public:
    int dp[101][101];
    int solve (vector<int>&cuts,int l , int r)
    {
        if(r - l ==1)return 0;
        int &ans = dp[l][r];
        if(ans !=-1)return ans;
        ans = INT_MAX;
        for(int m = l + 1 ;  m  < r ;m++ )
        {
            int op = solve(cuts,l,m) + solve(cuts,m ,  r) + (cuts[r] - cuts[l]);

            ans = min(ans , op );
        }
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int>cuts2;
        cuts2.push_back(0);
        cuts2.push_back(n);
        for(int i = 0 ; i<cuts.size() ; i++){
            cuts2.push_back(cuts[i]);
        }
        memset(dp , -1 ,sizeof(dp));
        sort(cuts2.begin() , cuts2.end());
        return solve(cuts2 , 0 , cuts2.size() - 1);

    }
};
