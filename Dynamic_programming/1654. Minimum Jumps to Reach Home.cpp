class Solution {
public:
    bool isForbidden[7001];
    int memo[7001][2];
    int forwardJumb , backwardJumb , target;
    int solve(int start , bool isBack){
        if(start >7000 ||start <0 ||isForbidden[start])
            return 1e9;
       if(start ==target)
           return 0 ; 
     int &ret =memo[start][isBack];
      if(ret!=-1){
          return ret;
      }
    int op1 = 1e9 , op2 = 1e9;
    ret = 1e9;
    if(!isBack)
    op1 = solve(start - backwardJumb, true) + 1;
    op2 = solve(start + forwardJumb , false) + 1;
    return ret =min(op1,op2) ; 

    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int i = 0 ;i<forbidden.size();i++){
            isForbidden[forbidden[i]] = true;
        }
        for(int i = 0 ;i<7001;i++){
           memo[i][0] = memo[i][1] = -1;
        }
        forwardJumb = a;
        backwardJumb = b;
        target = x;
        int val = solve(0,false);
        return val >=1e9 ?-1:val;
    }
};
