class Solution {
public:
int dp[50001];
pair<int,int> vis[50001];
int steps(int idx,vector<int>&arr){
if(idx<0 ||idx>=arr.size())return 0;
if(arr[idx]==0)return 1;
 int &ret=dp[idx];
 if(vis[idx].first==1 &&vis[idx].second==1)return ret;
 if(vis[idx].first!=1)
  vis[idx].first=1;
  else vis[idx].second=1;
  ret=0;
 int op1=steps(idx+arr[idx],arr);
 int op2=steps(idx-arr[idx],arr);
 ret=max({ret,op1,op2});
 return ret;
}
    bool canReach(vector<int>& arr, int start) {
        return steps(start,arr);
    }
};
