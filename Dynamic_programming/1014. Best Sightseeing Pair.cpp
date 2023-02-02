class Solution {
public:
   int dp[50001][2];
   int solve(vector<int>& values,int idx , int isSum){
       if(idx ==values.size()){
           return -1e9;
       }
       int &ret = dp[idx][isSum];
       if(ret!=INT_MAX)return ret;
       ret = -1e9; 
       int leave = -1e9;
     leave = solve(values ,idx+1 , isSum);
       if(isSum ==0 ){
           int op = solve(values , idx+1 , 1) + values[idx] + idx;
           
           ret = max({ret , leave ,op });
       }
       if(isSum ==1){
           int op = values[idx] - idx;
           ret = max({ret , leave ,op });
       }
       return ret;
   }
    int maxScoreSightseeingPair(vector<int>& values) {
       for(int i = 0 ;i<50001;i++){
           dp[i][0] = dp[i][1] = INT_MAX;
       }   
       return solve(values,0 , 0); 
    }
};
