class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        sort(p.begin() , p.end());
        int n = p.size();
        vector<int>range;
        int left = 0;
        for(int i = 0 ; i<n;i++){
            while(left <n &&p[left] <=p[i]+k){
                left++;
            }
            range.push_back(left - i);
        }
        
        vector<int>mxRange(n,0);
        mxRange[n-1] =range[n-1];
        
        for(int i = n-2 ;i>=0;i--){
            mxRange[i] = max(range[i] , mxRange[i+1]);
        }
        int mxAns = 0;
         for(int i = 0 ;i<n;i++){
           int val = 0;
             if(range[i] + i  <n){
                 val = mxRange[range[i] + i];
             }
             mxAns = max(mxAns , val + range[i]);
        }
        
        return mxAns;
    }
};
