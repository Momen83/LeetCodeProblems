class Solution {
public:
    vector<int>dis1 , dis2;
    vector<int>Graph[100001];
    
     void BFS(int node , vector<int>&dis){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
         int curr = q.front();
         q.pop();
         for(auto ch:Graph[curr]){
           if(dis[ch] >dis[curr] + 1){
              dis[ch] = dis[curr] + 1;
              q.push(ch);
           }
         }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n =edges.size();
        dis1 = vector<int>(n , 1e9);
        dis2 = vector<int>(n , 1e9);
        for(int i = 0 ; i<edges.size(); i++){
           if(edges[i]!=-1){
               Graph[i].push_back(edges[i]);
           }
        }
        dis1[node1] = 0;
        dis2[node2] = 0;
        BFS(node1 , dis1);
        BFS(node2 , dis2);
        int mxDis = 1e9 ;
        int mxIndex = -1;
        for(int i = 0 ;i<n;i++){
            if(dis1[i] !=1e9 &&dis2[i] !=1e9){
                int mx = max(dis1[i],dis2[i]);
                if(mxDis >mx){
                    mxDis = mx;
                    mxIndex = i;
                }
            }
        }
        return mxIndex;
    }
};
