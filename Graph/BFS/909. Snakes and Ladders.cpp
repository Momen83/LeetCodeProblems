class Solution {
public:
   int nextMove[401];
    int snakesAndLadders(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size(); 
        int currVal = 1;
        int turn = false;
        for(int i = row-1 ;i>=0;i-- ){
            int inc = 1;
            int start = 0;
            if(turn){
                inc = -1;
                start = col-1;
            }
            while(start >=0  && start<col){
                nextMove[currVal] = (board[i][start] ==-1 ? currVal+1:board[i][start]);
                currVal++;
                start+=inc;
            }
            turn = !turn;
        }
     int size = row * row;
       vector<int>dis(size+ 1, 1e9);
       vector<int>par(size+1 , -1);
       queue<int>q;
       q.push(1);
       dis[1] = 0;
       while(!q.empty()){
           int curr = q.front();
           q.pop();
               
               for(int i = curr+1 ;i<=min(curr+6 ,size);i++){
                int next = i;
                 if(nextMove[i] !=i+1){
                   next = nextMove[i];
                 }
                 if(dis[next] ==1e9){
                    dis[next] = dis[curr] + 1 ;
                    q.push(next);
                 }
                 
               }
           }
        
        
        return dis[size] ==1e9 ?-1:dis[size];
    }
};
