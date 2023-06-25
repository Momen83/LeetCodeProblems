class Solution {
public:
    int dp[101][201];
    int fi;
    const int Mod = 1e9 + 7;

    int solve(vector<int>& locations,int val , int fuel) {
    
        if(fuel < 0){ 
            return 0;
        }
        int ans = 0;
        if(val  == fi)ans++;
        if(dp[val][fuel] !=-1) return dp[val][fuel]; 
          
        for(int i  = 0 ; i < locations.size() ; i++){
            if(i != val)
            {
          
            int cost = abs(locations[val ] - locations[i]);
        
            ans = ((ans % Mod) + (solve(locations,i,fuel - cost)%Mod))%Mod;
            }
         
            }
        
        return dp[val][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        fi = finish;
        memset(dp , -1 ,sizeof(dp));
        return solve(locations , start,fuel);
    }
};
