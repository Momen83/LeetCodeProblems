class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int mxCapcity = jug1Capacity + jug2Capacity;
        int steps[4] = {jug1Capacity , -jug1Capacity , jug2Capacity , -jug2Capacity};
        vector<bool>vis(mxCapcity+1);
        vis[0] = true;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = true;
            if(targetCapacity == curr)return true;
            for(int i = 0 ;i<4;i++){
                int nextStep = curr + steps[i];
                if(nextStep >=0 && nextStep <=mxCapcity &&!vis[nextStep]){
                    q.push(nextStep);
                }
            }
        }
        return false;
    }
};
