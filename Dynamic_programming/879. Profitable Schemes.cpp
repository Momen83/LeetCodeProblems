class Solution {
public:
    int mnProfit;
    vector<int>g,p;
    const int Mod = 1e9 + 7;
    int dp[101][101][101];
    int solve(int index ,  int totalProfit , int totalPeople){
        if(index == g.size()){
            return totalProfit >=mnProfit;
        }
       
        int &ans = dp[index][totalProfit][totalPeople];
        if(ans !=-1)return ans;
        ans = 0;
        if(totalPeople - g[index]  >=0){
            if(totalProfit + p[index] >=mnProfit){
                ans = (ans%Mod + (solve(index + 1 , mnProfit , totalPeople - g[index] ) %Mod))%Mod;
            }
            else{
                  ans = (ans%Mod + (solve(index + 1 , totalProfit + p[index] , totalPeople - g[index] ) %Mod))%Mod;
            }
        }
        ans = (ans%Mod + (solve(index + 1 , totalProfit , totalPeople ) %Mod))%Mod;
        return ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
       memset(dp , -1 ,sizeof(dp));
       mnProfit = minProfit;
       g= group;
       p = profit;
       return solve(0 , 0 , n);
    }
};
