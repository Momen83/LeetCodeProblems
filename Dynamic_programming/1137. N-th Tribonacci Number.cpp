class Solution {
public:
    int tribonacci(int n) {
        int f = 0 , s = 1 , t =1; 
        if(n ==0)return 0;
        for(int i = 3 ;i<=n;i++){
           int tempT = t;
           int tempS = s;
           t = f+s+t;
           s = tempT;
           f = tempS;
        }
        return t;
    }
};
