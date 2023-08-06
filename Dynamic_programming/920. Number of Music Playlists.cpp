class Solution {
public:
    long long memo[101][101];
    const int Mod = 1e9 + 7;
    long long solve(int songs , int goal , int &again){
        if(songs ==0 && goal ==0) return 1;
        if(songs == 0 || goal ==0) return 0;
        long long &ret = memo[songs][goal];
        if(ret !=-1)return ret;
        ret = 0;
        int pickUnique = (solve(songs - 1 , goal - 1 , again) * songs)%Mod;
        int pickRepated = (solve(songs , goal - 1 , again) * max(songs - again,0))%Mod;
             
        return ret  = (pickUnique + pickRepated) % Mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(memo,-1,sizeof(memo));   
        return solve(n , goal , k);
      
    }
};
