class Solution {
public:
    int dx[4] = {+1,-1,+0,+0};
    int dy[4] = {+0,+0,+1,-1};
    vector<pair<int,int>>temp;
    int n , m;
    int cntOnes = 0;
    void dfs(vector<vector<int>>& grid , int i , int j ){
        if( i <0  || i ==n ||j <0 ||j == m ||grid[i][j] ==0){
            return;
        }
        temp.push_back({i,j});
        cntOnes++;
        grid[i][j] = 0;
        for(int ii = 0 ;ii<4;ii++){
              int newX =dx[ii] + i; 
              int newY =dy[ii] + j;
              dfs(grid,newX,newY);      
    }
    }
    int shortestBridge(vector<vector<int>>& grid) {
          n = grid.size();
          m = grid[0].size();
          vector<vector<pair<int,int>>>total;
          
       for(int i = 0 ;i<n;i++){
          for(int j = 0 ;j<m;j++){
              if(grid[i][j] == 1){
               dfs(grid,i,j);
               total.push_back(temp);
               temp.clear();
               
             }
      }
    }
    int ans = 0;
    int idx = 1;
    while(total[0].size() !=cntOnes &&idx <total.size()){
        int mn = 1e9;
        for(int j = 0 ; j <total[0].size()  && idx <total.size();j++){
            for(int k = 0 ;k<total[idx].size(); k++){
                int disX = abs(total[0][j].first  - total[idx][k].first);
                int disY = abs(total[0][j].second  - total[idx][k].second);
                mn = min(mn , disX+disY - 1);
            }
        }
          ans+=mn;
         for(int k = 0 ;k<total[idx].size(); k++){
             total[0].push_back(total[idx][k]);
         }
         //cout<<total[0].size()<<'\n';
         idx++;
    }
    return ans;
    }
};
