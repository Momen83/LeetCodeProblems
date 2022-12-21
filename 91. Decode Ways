class Solution {
public:
string ss;
int n;
int dp[101];
void clr()
{
     for(int i=0;i<101;i++)dp[i]=-1;
}int solve(int idx)
{
     if(idx==n)return 1;
     int op1=0;
     int op2=0;
     int &ret=dp[idx];
     if(~ret)return ret;
     ret=0;
     if(ss[idx]=='0' )return -1e9;
     if(idx+1<=n &&ss[idx]!='0')op1=max(solve(idx+1),0);
     if(idx+2<=n)
     {
          int val=(ss[idx]-'0')*10 + (ss[idx+1]-'0');
          if(val!=0 &&val<=26 )op2=max(0,solve(idx+2));
     }
     return ret=op1+op2;
}
    int numDecodings(string s) {
       ss=s;
       n=ss.size();
        if(s[0]=='0'){
         return 0;
       }
  clr();
  return solve(0);
    }
};
