class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int ans  = 1;
        int xEnd = points[0][1];
        int idx = 1;
        while(idx<n)
        {
           xEnd = min(xEnd ,points[idx][1] );
           if(xEnd <points[idx][0] || xEnd >points[idx][1]){
               ans++;
               xEnd = points[idx][1];
           }
           idx++;
        }
        return ans;

    }
};
