class Solution {
public:
    int taken[(1<<20) + 1];
    int total , maxJumb;
    bool solve(int mask ,int total){
    //When this state go it before
       if(taken[mask] !=-1){
           return taken[mask];
       }
    // When other player arrive to win state
       if(total <=0){
           return false;
       }
        for(int m = 0 ;m<maxJumb ; m++){
        //When this bit not taken before and come from loss state
          if(!(mask & (1<<m))  &&!solve(mask |1<<m , total - m-1)){
            taken[mask] = 1 ;
            return true;
          }
        }
        //The player arrive to lose state
        taken[mask] = 0;
        return false;
        
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int cnt = 0;
       int sum = (maxChoosableInteger * (maxChoosableInteger+ 1))/2;
       //When Total sum of them less than desiredTotal
       if(sum <desiredTotal)return false;
       //When max number greater than total
       if(maxChoosableInteger >=desiredTotal)return true;
       for(int i= 0 ; i<=(1<<20); i++ )taken[i] = -1;
       maxJumb = maxChoosableInteger;
        return solve(0 ,desiredTotal );
    }
};
