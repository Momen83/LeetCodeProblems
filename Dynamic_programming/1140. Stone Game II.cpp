int dp[101][101][2];
vector<int>pref;
int solve(vector<int>& piles,int index , int m , int turn )
{
    if(index ==piles.size()){
        return 0 ;
    }
    //turn 0 -> Alice , turn 1 ->Bob
    int &ret = dp[index][m][turn];
    if(ret!=-1)return ret;
    ret = (!turn ?0 :INT_MAX);
    int sumStones = 0;
    for(int x = 1 ; x <= m * 2 ; x++){

        int nextIndex = index + (x - 1);
        if(nextIndex >=piles.size())break;
        sumStones += piles[nextIndex];
        if(turn ==0)
        {
            int sum2 =  solve(piles,nextIndex + 1 ,max(m,x),!turn);
            ret = max(ret , sumStones + sum2);
        }
        else
        {
            int sum3 = solve(piles,nextIndex + 1 ,max(m,x),!turn);
            ret = min(ret , sum3);
        }
    }
    return ret;
}
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        for(int i = 0 ; i<=100;i++){
            for(int j =0 ;j<=100;j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        } 
       return solve(piles,0,1,0);
    }
    // 1 1
};
