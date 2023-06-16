class Solution {
public:
    vector<vector<long long>>pascal;
    const int Mod = 1e9 + 7;
    long long solve(vector<int>&nums ) {
        int n = nums.size() ;
        if(n < 3){
            return 1;
        }
        vector<int>left;
        vector<int>right;
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i] <nums[0]){
                left.push_back(nums[i]);
            }
           else{
                right.push_back(nums[i]);
           }
        }
         int k = left.size();
         long long leftWays = solve(left) % Mod;
         long long rightWays = solve(right) % Mod;

         return ((leftWays * rightWays) %Mod * (pascal[n - 1][k]))%Mod;
		
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascal = vector<vector<long long>>(n + 5,vector<long long>(n + 5,0));
        for(int i = 0 ; i<=n;i++) {
            pascal[i][0] = pascal[i][i]  = 1;
        }
        for(int i = 0 ; i <=n ; i++) {
            for(int j = 1 ; j<i ; j++) {
                if(i !=j){
                pascal[i][j] = ((pascal[i - 1][j - 1] %Mod) + (pascal[i - 1] [j] %Mod))%Mod; 
                }
            }
        }
    
        return solve(nums) - 1;
        //   
    }
};
/*
      0 1 2 3
    0 1
    1 1 1
    2 1   1
    3 1     1

*/
