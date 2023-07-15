class Solution {
public:
    vector<vector<int>>dp;
    int getNext(vector<vector<int>>& events,int left,int key){
        int right=events.size()-1;
        int nextCurr=events.size();
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(events[mid][0]>=key){
                nextCurr=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return nextCurr;
    }
    int solve(vector<vector<int>>& events,int index , int k) {
        if(index == events.size())return 0;
        int &ret = dp[index][k];
        
        if(ret != -1)return ret;
      
        ret = solve(events, index + 1 , k);
        if(k){
            int nextIndex = getNext(events,index , events[index][1] + 1);
            ret = max(ret , events[index][2]  + solve(events,nextIndex , k - 1));
        }
        return ret;
    }
    int maxValue(vector<vector<int>>& events, int k) {
         dp = vector<vector<int>>(events.size()+1,vector<int>(k+1,-1));
        sort(events.begin() , events.end());
        return solve(events,0,k);
    }
};

