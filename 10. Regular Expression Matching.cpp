class Solution {
public:
 int dp[51][51];
 string ss,pp;
int solve(int i, int j){
    
    if(j ==pp.size()){
        return i ==ss.size();
    }
    int &ret =dp[i][j];
    if(ret!=-1){
        return ret;
    } 
    ret = 1;
    bool match = false;
    if(i<ss.size() &&(pp[j] =='.' ||ss[i] ==pp[j])){
        match = true;
    }
    if(j+1<pp.size() &&pp[j+1] =='*'){
        //match with preceding j+1 element
        int op1 = solve(i,j+2);
        int op2 = match &&solve(i+1,j);
        ret &= (op1|| op2 );
    }
    else{
        int op =solve(i+1,j+1);
        ret &=(op &&match);

    }
    return ret;
}
bool isMatch(string s, string p) {
 memset(dp,-1,sizeof(dp));
 ss = s;
 pp = p;
 return solve(0,0);
}
};
